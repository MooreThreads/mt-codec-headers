#!/usr/bin/env python3
"""GPU-independent compile, link, runtime and installation regression checks."""
import os
import shutil
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]

def run(args, **kwargs):
    subprocess.run([str(a) for a in args], check=True, **kwargs)

with tempfile.TemporaryDirectory(prefix="ffmt-check-") as tmp:
    tmp = Path(tmp)
    for cc, language, standard in [("cc", "c", "c11"), ("c++", "c++", "c++11")]:
        flags = [cc, "-x", language, "-std=" + standard, "-Wall", "-Wextra", "-Werror", "-I" + str(ROOT / "include")]
        for defines in [[], ["-DMT_HOOKS"]]:
            exe = tmp / "loaders"
            run(flags + defines + [ROOT / "tests/loaders.c", "-o", exe])
            run([exe])
        for header in ["dynlink_loader.h", "dynlink_musa.h", "dynlink_muviddec.h", "dynlink_mtmuvid.h", "mtmuvid.h", "muviddec.h", "mtEncodeAPI.h", "internal/load_musa.h", "internal/load_muvid.h", "internal/load_mtenc.h"]:
            run(flags + ["-", "-ldl", "-o", tmp / "probe"], input=f"#include <ffmtcodec/{header}>\nint main(void) {{ return 0; }}\n", text=True)
        source = os.environ.get("FFMPEG_SOURCE")
        if source:
            text = '''#include "compat/musa/dynlink_loader.h"
void av_log(void *ctx, int level, const char *fmt, ...) { (void)ctx; (void)level; (void)fmt; }
int main(int argc, char **argv) {
    MusaFunctions *a=0; MuvidFunctions *b=0; MtencFunctions *c=0;
    (void)argv;
    if (argc > 1) { musa_load_functions(&a,0); muvid_load_functions(&b,0); mtenc_load_functions(&c,0); }
    musa_free_functions(&a); muvid_free_functions(&b); mtenc_free_functions(&c); return 0;
}
'''
            run(flags + ["-I" + source, "-", "-ldl", "-o", tmp / "adapter"], input=text, text=True)
            run([tmp / "adapter"])
        text = ''.join(f'#include <ffmtcodec/{h}>\n' for h in ["mtEncodeAPI.h", "dynlink_musa.h", "dynlink_muviddec.h", "dynlink_mtmuvid.h"])
        text += 'int main(void) { return sizeof(MUVIDAV1PICPARAMS) == 0 || sizeof(MT_ENC_PIC_PARAMS_AV1) == 0; }\n'
        run(flags + ["-", "-o", tmp / "configure-probe"], input=text, text=True)
        run([tmp / "configure-probe"])
    stage = tmp / "stage"
    run(["make", "-C", ROOT, "install", "DESTDIR=" + str(stage)])
    for header in (ROOT / "include/ffmtcodec").rglob("*.h"):
        assert header.read_bytes() == (stage / "usr/local/include/ffmtcodec" / header.relative_to(ROOT / "include/ffmtcodec")).read_bytes()
    run(["cc", "-x", "c", "-I" + str(stage / "usr/local/include"), "-", "-ldl", "-o", tmp / "installed"], input='#include <ffmtcodec/dynlink_loader.h>\n#include <ffmtcodec/mtmuvid.h>\n#include <ffmtcodec/muviddec.h>\nint main(void){return 0;}\n', text=True)
    installed = stage / "usr/local/include/ffmtcodec"
    sentinels = [installed / "unrelated.h", installed / "internal/unrelated.h"]
    for path in sentinels:
        path.write_text("preserve me\n")
    run(["make", "-C", ROOT, "uninstall", "DESTDIR=" + str(stage)])
    for path in sentinels:
        assert path.read_text() == "preserve me\n"
    for header in (ROOT / "include/ffmtcodec").rglob("*.h"):
        assert not (installed / header.relative_to(ROOT / "include/ffmtcodec")).exists()
    assert not (stage / "usr/local/lib/pkgconfig/ffmtcodec.pc").exists()

# Verify the public loader composes with each public declaration header in either order.
for compat in ["dynlink_musa.h", "dynlink_muviddec.h", "dynlink_mtmuvid.h"]:
    for order in [("dynlink_loader.h", compat), (compat, "dynlink_loader.h")]:
        text = ''.join(f'#include <ffmtcodec/{h}>\n' for h in order)
        text += "int main(void) { MusaFunctions *a=0; MuvidFunctions *b=0; MtencFunctions *c=0; musa_free_functions(&a); muvid_free_functions(&b); mtenc_free_functions(&c); return 0; }\n"
        with tempfile.TemporaryDirectory(prefix="ffmt-order-") as tmp:
            tmp = Path(tmp)
            for cc, lang, std in [("cc", "c", "c11"), ("c++", "c++", "c++11")]:
                run([cc, "-x", lang, "-std=" + std, "-Wall", "-Wextra", "-Werror", "-I" + str(ROOT / "include"), "-", "-ldl", "-o", tmp / "order"], input=text, text=True)
                run([tmp / "order"])

with tempfile.TemporaryDirectory(prefix="ffmt-mingw-") as tmp:
    tmp = Path(tmp)
    for target in ["x86_64-w64-mingw32", "i686-w64-mingw32"]:
        for suffix, language, standard in [("gcc", "c", "c11"), ("g++", "c++", "c++11")]:
            cc = target + "-" + suffix
            if not shutil.which(cc):
                print("SKIP: " + cc + " unavailable")
                continue
            flags = [cc, "-x", language, "-std=" + standard, "-Wall", "-Wextra", "-Werror", "-I" + str(ROOT / "include")]
            for header in ["mtmuvid.h", "muviddec.h", "mtEncodeAPI.h", "dynlink_loader.h", "dynlink_musa.h", "dynlink_muviddec.h", "dynlink_mtmuvid.h"]:
                run(flags + ["-", "-o", tmp / "windows.exe"], input=f"#include <ffmtcodec/{header}>\nint main(void) {{ return 0; }}\n", text=True)
            text = "#include <ffmtcodec/dynlink_loader.h>\nint main(void) { MusaFunctions *a=0; MuvidFunctions *b=0; MtencFunctions *c=0; int r=musa_load_functions(&a,0)+muvid_load_functions(&b,0)+mtenc_load_functions(&c,0); musa_free_functions(&a); muvid_free_functions(&b); mtenc_free_functions(&c); return r; }\n"
            run(flags + ["-", "-o", tmp / "windows.exe"], input=text, text=True)
            print("PASS: " + cc + " headers and native loader link (not executed)")

print("All native loader, header, configure-probe and installation checks passed.")

# Native API symbols must not regress into the removed wrapper layer.
source_roots = [ROOT / "include", ROOT / "tests"]
source_suffixes = {".h", ".c", ".cc", ".cpp", ".in", ".m4"}
for source_root in source_roots:
    for path in source_root.rglob("*"):
        if path.is_file() and path.suffix in source_suffixes:
            text = path.read_text(errors="ignore")
            for symbol in ["FFNV_LIB_HANDLE", "FFNV_LOAD_FUNC", "FFNV_SYM_FUNC", "FFNV_FREE_FUNC", "FFNV_LOG_FUNC", "FFNV_DEBUG_LOG_FUNC", "CudaFunctions", "CuvidFunctions", "NvencFunctions", "cuda_load_functions", "cuda_free_functions", "cuvid_load_functions", "cuvid_free_functions", "nvenc_load_functions", "nvenc_free_functions"]:
                assert symbol not in text, f"removed compatibility symbol remains: {symbol} in {path}"
