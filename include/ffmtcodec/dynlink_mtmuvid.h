/*
 * Copyright (c) 2026 MOORE THREADS & AFFILIATES.
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef FFMT_DYNLINK_MTMUVID_H
#define FFMT_DYNLINK_MTMUVID_H

/* FFmpeg compatibility declarations; preserved for configure probes. */
#include "dynlink_muviddec.h"
#include "mtmuvid.h"
#undef muvidMapVideoFrame
#undef muvidUnmapVideoFrame
typedef MUresult MUSAAPI tmuvidCreateVideoSource(MUvideosource *pObj, const char *pszFileName, MUVIDSOURCEPARAMS *pParams);
typedef MUresult MUSAAPI tmuvidCreateVideoSourceW(MUvideosource *pObj, const wchar_t *pwszFileName, MUVIDSOURCEPARAMS *pParams);
typedef MUresult MUSAAPI tmuvidDestroyVideoSource(MUvideosource obj);
typedef MUresult MUSAAPI tmuvidSetVideoSourceState(MUvideosource obj, musaVideoState state);
typedef musaVideoState MUSAAPI tmuvidGetVideoSourceState(MUvideosource obj);
typedef MUresult MUSAAPI tmuvidGetSourceVideoFormat(MUvideosource obj, MUVIDEOFORMAT *pvidfmt, unsigned int flags);
typedef MUresult MUSAAPI tmuvidGetSourceAudioFormat(MUvideosource obj, MUAUDIOFORMAT *paudfmt, unsigned int flags);
typedef MUresult MUSAAPI tmuvidCreateVideoParser(MUvideoparser *pObj, MUVIDPARSERPARAMS *pParams);
typedef MUresult MUSAAPI tmuvidParseVideoData(MUvideoparser obj, MUVIDSOURCEDATAPACKET *pPacket);
typedef MUresult MUSAAPI tmuvidDestroyVideoParser(MUvideoparser obj);
#endif
