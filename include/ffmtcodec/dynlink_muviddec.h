/*
 * Copyright (c) 2026 MOORE THREADS & AFFILIATES.
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef FFMT_DYNLINK_MUVIDDEC_H
#define FFMT_DYNLINK_MUVIDDEC_H

/* FFmpeg compatibility declarations; preserved for configure probes. */
#include "dynlink_musa.h"
#include "muviddec.h"
#undef muvidMapVideoFrame
#undef muvidUnmapVideoFrame
typedef MUresult MUSAAPI tmuvidGetDecoderCaps(MUVIDDECODECAPS *pdc);
typedef MUresult MUSAAPI tmuvidCreateDecoder(MUvideodecoder *phDecoder, MUVIDDECODECREATEINFO *pdci);
typedef MUresult MUSAAPI tmuvidDestroyDecoder(MUvideodecoder hDecoder);
typedef MUresult MUSAAPI tmuvidDecodePicture(MUvideodecoder hDecoder, MUVIDPICPARAMS *pPicParams);
typedef MUresult MUSAAPI tmuvidGetDecodeStatus(MUvideodecoder hDecoder, int nPicIdx, MUVIDGETDECODESTATUS* pDecodeStatus);
typedef MUresult MUSAAPI tmuvidReconfigureDecoder(MUvideodecoder hDecoder, MUVIDRECONFIGUREDECODERINFO *pDecReconfigParams);
#if !defined(__MUVID_DEVPTR64) || defined(__MUVID_INTERNAL)
typedef MUresult MUSAAPI tmuvidMapVideoFrame(MUvideodecoder hDecoder, int nPicIdx,
                                             unsigned int *pDevPtr, unsigned int *pPitch,
                                             MUVIDPROCPARAMS *pVPP);
typedef MUresult MUSAAPI tmuvidUnmapVideoFrame(MUvideodecoder hDecoder, unsigned int DevPtr);
#endif
typedef MUresult MUSAAPI tmuvidMapVideoFrame64(MUvideodecoder hDecoder, int nPicIdx, unsigned long long *pDevPtr,
                                               unsigned int *pPitch, MUVIDPROCPARAMS *pVPP);
typedef MUresult MUSAAPI tmuvidUnmapVideoFrame64(MUvideodecoder hDecoder, unsigned long long DevPtr);
typedef MUresult MUSAAPI tmuvidCtxLockCreate(MUvideoctxlock *pLock, MUcontext ctx);
typedef MUresult MUSAAPI tmuvidCtxLockDestroy(MUvideoctxlock lck);
typedef MUresult MUSAAPI tmuvidCtxLock(MUvideoctxlock lck, unsigned int reserved_flags);
typedef MUresult MUSAAPI tmuvidCtxUnlock(MUvideoctxlock lck, unsigned int reserved_flags);
#if defined(__MUVID_DEVPTR64) && !defined(__MUVID_INTERNAL)
#define tmuvidMapVideoFrame tmuvidMapVideoFrame64
#define tmuvidUnmapVideoFrame tmuvidUnmapVideoFrame64
#endif

#endif
