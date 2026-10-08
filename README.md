# ffmtcodec

面向 FFmpeg 及其他应用的 Moore Threads MUSA/Video Codec SDK header-only 接口包，提供原生 API 声明和运行时加载支持：

- MUSA 驱动、MUVID 解码和 MTENC 编码原生 API；
- 支持 Linux、Windows 和 Cygwin 的运行时动态加载器；
- 公共声明头文件和既有应用使用的 include 路径。

本项目基于 Moore Threads Video Codec SDK 13.0，适用于使用 Moore Threads GPU 及其驱动的运行环境。

## 公共接口

```text
include/ffmtcodec/
├── dynlink_musa.h     MUSA 驱动 API 声明
├── dynlink_loader.h   MUSA、MUVID 和 MTENC 的统一动态加载入口
├── dynlink_muviddec.h MUVID 解码 API 声明
├── dynlink_mtmuvid.h  MUVID 视频源和解析器 API 声明
├── mtmuvid.h          MUVID API 声明
├── muviddec.h         MUVID 解码器 API 声明
├── mtEncodeAPI.h      MTENC 编码 API 声明
└── internal/          loader 内部实现，不作为稳定应用 API
```

新应用建议使用原生 API：

```c
#include <ffmtcodec/dynlink_loader.h>

int main(void)
{
    MusaFunctions *musa = NULL;

    if (musa_load_functions(&musa, NULL) < 0)
        return 1;

    /* 使用 musa->muInit、musa->muDeviceGetCount 等函数 */

    musa_free_functions(&musa);
    return 0;
}
```

对应的 loader API 为：

```c
int musa_load_functions(MusaFunctions **functions, void *logctx);
void musa_free_functions(MusaFunctions **functions);

int muvid_load_functions(MuvidFunctions **functions, void *logctx);
void muvid_free_functions(MuvidFunctions **functions);

int mtenc_load_functions(MtencFunctions **functions, void *logctx);
void mtenc_free_functions(MtencFunctions **functions);
```

loader 提供统一的运行时加载接口，简化应用对 MUSA、MUVID 和 MTENC 运行库的集成。

公共声明头文件保留既有应用使用的类型、函数声明和 include 路径，可供 FFmpeg 及其他应用使用。

## 构建与安装

```sh
make
make install PREFIX=/usr/local DESTDIR=/tmp/ffmtcodec-stage
```

`make` 生成 pkg-config 元数据，`make install` 将头文件和元数据安装到目标目录。应用安装后可以通过 pkg-config 获取头文件路径：

```sh
pkg-config --cflags ffmtcodec
```

该安装目标不包含 `libs/` 目录中的预构建运行库。

## 预构建运行库

仓库的 `libs/` 目录附带 Moore Threads Video Codec SDK 13.0 的 Linux 预构建动态库，并按目标架构组织：

```text
libs/
├── arm64/
├── loongarch64/
├── sw_64/
└── x86_64/
```

各架构目录包含：

```text
libencode_musa.so.13.0
libvideo_musa.so.13.0
```

应用可根据目标架构选择对应目录中的 Linux 动态库，并将其放置在系统运行库搜索路径中，供运行时 loader 加载。Windows 和 Cygwin 表示 loader 的平台支持，不代表仓库提供对应的预构建运行库。

## 验证

```sh
python3 tests/check.py
```

该检查覆盖 C11/C++11 原生 loader 测试、头文件和 include 顺序探针、loader 生命周期、安装/卸载检查，以及工具链可用时的 MinGW-w64 32/64 位交叉编译探针。

验证 FFmpeg 集成所需公共声明头文件和最小 loader adapter 的编译、链接与运行：

```sh
FFMPEG_SOURCE=/path/to/FFmpeg python3 tests/check.py
```

其中 `FFMPEG_SOURCE` 应指向 FFmpeg 源码目录。该检查不是完整 FFmpeg 构建，也不包含 Windows 实际运行、真实 GPU 编码/解码或目标驱动环境下的集成测试。

## 许可证

项目源文件采用 MIT 许可证，完整条款见 [LICENSE.txt](LICENSE.txt)。
