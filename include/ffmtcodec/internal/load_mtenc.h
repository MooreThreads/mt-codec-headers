/*
 * Copyright (c) 2026 MOORE THREADS & AFFILIATES.
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef FFMT_LOAD_MTENC_H
#define FFMT_LOAD_MTENC_H

#include "../mtEncodeAPI.h"
#include "load_common.h"
typedef MTENCSTATUS MTENCAPI tMtEncodeAPICreateInstance(MT_ENCODE_API_FUNCTION_LIST *functionList);
typedef MTENCSTATUS MTENCAPI tMtEncodeAPIGetMaxSupportedVersion(uint32_t* version);

typedef struct MtencFunctions {
    tMtEncodeAPICreateInstance *MtEncodeAPICreateInstance;
    tMtEncodeAPIGetMaxSupportedVersion *MtEncodeAPIGetMaxSupportedVersion;

    FFMT_LIB_HANDLE lib;
} MtencFunctions;

static inline void mtenc_free_functions(MtencFunctions **functions)
{
    FFMT_GENERIC_FREE_FUNC();
}
static inline int mtenc_load_functions(MtencFunctions **functions, void *logctx)
{
    FFMT_GENERIC_LOAD_FUNC_PREAMBLE(MtencFunctions, mtenc, MTENC_LIBNAME);

    FFMT_LOAD_SYMBOL(MtEncodeAPICreateInstance, tMtEncodeAPICreateInstance, "MtEncodeAPICreateInstance");
    FFMT_LOAD_SYMBOL(MtEncodeAPIGetMaxSupportedVersion, tMtEncodeAPIGetMaxSupportedVersion, "MtEncodeAPIGetMaxSupportedVersion");

    FFMT_GENERIC_LOAD_FUNC_FINALE(mtenc);
}


#endif
