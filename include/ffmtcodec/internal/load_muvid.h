/*
 * Copyright (c) 2026 MOORE THREADS & AFFILIATES.
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef FFMT_LOAD_MUVID_H
#define FFMT_LOAD_MUVID_H

#include "../dynlink_mtmuvid.h"
#include "load_common.h"
typedef struct MuvidFunctions {
    tmuvidGetDecoderCaps *muvidGetDecoderCaps;
    tmuvidCreateDecoder *muvidCreateDecoder;
    tmuvidDestroyDecoder *muvidDestroyDecoder;
    tmuvidDecodePicture *muvidDecodePicture;
    tmuvidGetDecodeStatus *muvidGetDecodeStatus;
    tmuvidReconfigureDecoder *muvidReconfigureDecoder;
    tmuvidMapVideoFrame *muvidMapVideoFrame;
    tmuvidUnmapVideoFrame *muvidUnmapVideoFrame;
    tmuvidCtxLockCreate *muvidCtxLockCreate;
    tmuvidCtxLockDestroy *muvidCtxLockDestroy;
    tmuvidCtxLock *muvidCtxLock;
    tmuvidCtxUnlock *muvidCtxUnlock;

#if !defined(__APPLE__)
    tmuvidCreateVideoSource *muvidCreateVideoSource;
    tmuvidCreateVideoSourceW *muvidCreateVideoSourceW;
    tmuvidDestroyVideoSource *muvidDestroyVideoSource;
    tmuvidSetVideoSourceState *muvidSetVideoSourceState;
    tmuvidGetVideoSourceState *muvidGetVideoSourceState;
    tmuvidGetSourceVideoFormat *muvidGetSourceVideoFormat;
    tmuvidGetSourceAudioFormat *muvidGetSourceAudioFormat;
#endif
    tmuvidCreateVideoParser *muvidCreateVideoParser;
    tmuvidParseVideoData *muvidParseVideoData;
    tmuvidDestroyVideoParser *muvidDestroyVideoParser;

    FFMT_LIB_HANDLE lib;
} MuvidFunctions;

static inline void muvid_free_functions(MuvidFunctions **functions)
{
    FFMT_GENERIC_FREE_FUNC();
}
static inline int muvid_load_functions(MuvidFunctions **functions, void *logctx)
{
    FFMT_GENERIC_LOAD_FUNC_PREAMBLE(MuvidFunctions, muvid, MTMUVID_LIBNAME);

    FFMT_LOAD_SYMBOL_OPT(muvidGetDecoderCaps, tmuvidGetDecoderCaps, "muvidGetDecoderCaps");
    FFMT_LOAD_SYMBOL(muvidCreateDecoder, tmuvidCreateDecoder, "muvidCreateDecoder");
    FFMT_LOAD_SYMBOL(muvidDestroyDecoder, tmuvidDestroyDecoder, "muvidDestroyDecoder");
    FFMT_LOAD_SYMBOL(muvidDecodePicture, tmuvidDecodePicture, "muvidDecodePicture");
    FFMT_LOAD_SYMBOL(muvidGetDecodeStatus, tmuvidGetDecodeStatus, "muvidGetDecodeStatus");
    FFMT_LOAD_SYMBOL(muvidReconfigureDecoder, tmuvidReconfigureDecoder, "muvidReconfigureDecoder");
#ifdef __MUVID_DEVPTR64
    FFMT_LOAD_SYMBOL(muvidMapVideoFrame, tmuvidMapVideoFrame, "muvidMapVideoFrame64");
    FFMT_LOAD_SYMBOL(muvidUnmapVideoFrame, tmuvidUnmapVideoFrame, "muvidUnmapVideoFrame64");
#else
    FFMT_LOAD_SYMBOL(muvidMapVideoFrame, tmuvidMapVideoFrame, "muvidMapVideoFrame");
    FFMT_LOAD_SYMBOL(muvidUnmapVideoFrame, tmuvidUnmapVideoFrame, "muvidUnmapVideoFrame");
#endif
    FFMT_LOAD_SYMBOL(muvidCtxLockCreate, tmuvidCtxLockCreate, "muvidCtxLockCreate");
    FFMT_LOAD_SYMBOL(muvidCtxLockDestroy, tmuvidCtxLockDestroy, "muvidCtxLockDestroy");
    FFMT_LOAD_SYMBOL(muvidCtxLock, tmuvidCtxLock, "muvidCtxLock");
    FFMT_LOAD_SYMBOL(muvidCtxUnlock, tmuvidCtxUnlock, "muvidCtxUnlock");

#if !defined(__APPLE__)
    FFMT_LOAD_SYMBOL(muvidCreateVideoSource, tmuvidCreateVideoSource, "muvidCreateVideoSource");
    FFMT_LOAD_SYMBOL(muvidCreateVideoSourceW, tmuvidCreateVideoSourceW, "muvidCreateVideoSourceW");
    FFMT_LOAD_SYMBOL(muvidDestroyVideoSource, tmuvidDestroyVideoSource, "muvidDestroyVideoSource");
    FFMT_LOAD_SYMBOL(muvidSetVideoSourceState, tmuvidSetVideoSourceState, "muvidSetVideoSourceState");
    FFMT_LOAD_SYMBOL(muvidGetVideoSourceState, tmuvidGetVideoSourceState, "muvidGetVideoSourceState");
    FFMT_LOAD_SYMBOL(muvidGetSourceVideoFormat, tmuvidGetSourceVideoFormat, "muvidGetSourceVideoFormat");
    FFMT_LOAD_SYMBOL(muvidGetSourceAudioFormat, tmuvidGetSourceAudioFormat, "muvidGetSourceAudioFormat");
#endif
    FFMT_LOAD_SYMBOL(muvidCreateVideoParser, tmuvidCreateVideoParser, "muvidCreateVideoParser");
    FFMT_LOAD_SYMBOL(muvidParseVideoData, tmuvidParseVideoData, "muvidParseVideoData");
    FFMT_LOAD_SYMBOL(muvidDestroyVideoParser, tmuvidDestroyVideoParser, "muvidDestroyVideoParser");

    FFMT_GENERIC_LOAD_FUNC_FINALE(muvid);
}


#endif
