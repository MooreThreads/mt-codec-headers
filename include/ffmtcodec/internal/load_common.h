/*
 * Copyright (c) 2026 MOORE THREADS & AFFILIATES.
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef FFMT_LOAD_COMMON_H
#define FFMT_LOAD_COMMON_H

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif
#ifndef FFMT_LIB_HANDLE
#ifdef _WIN32
#define FFMT_LIB_HANDLE HMODULE
#else
#define FFMT_LIB_HANDLE void *
#endif
#endif
#if defined(_WIN32) || defined(__CYGWIN__)
# define MUSA_LIBNAME "mtmusa.dll"
# define MTMUVID_LIBNAME "mtmuvid.dll"
# if defined(_WIN64) || defined(__CYGWIN64__)
#  define MTENC_LIBNAME "mtEncodeAPI64.dll"
# else
#  define MTENC_LIBNAME "mtEncodeAPI32.dll"
# endif
#else
# define MUSA_LIBNAME "libmusa.so.1"
# define MTMUVID_LIBNAME "libvideo_musa.so"
# define MTENC_LIBNAME "libencode_musa.so"
#endif

#ifndef FFMT_LOAD_FUNC
#ifdef _WIN32
#define FFMT_LOAD_FUNC(path) LoadLibraryA(path)
#else
#define FFMT_LOAD_FUNC(path) dlopen((path), RTLD_LAZY)
#endif
#endif
#ifndef FFMT_SYM_FUNC
#ifdef _WIN32
#define FFMT_SYM_FUNC(lib, sym) GetProcAddress((lib), (sym))
#else
#define FFMT_SYM_FUNC(lib, sym) dlsym((lib), (sym))
#endif
#endif
#ifndef FFMT_FREE_FUNC
#ifdef _WIN32
#define FFMT_FREE_FUNC(lib) FreeLibrary(lib)
#else
#define FFMT_FREE_FUNC(lib) dlclose(lib)
#endif
#endif
#ifndef FFMT_LOG_FUNC
#include <stdio.h>
#define FFMT_LOG_FUNC(logctx, msg, ...) fprintf(stderr, (msg), __VA_ARGS__)
#endif
#ifndef FFMT_DEBUG_LOG_FUNC
#define FFMT_DEBUG_LOG_FUNC(logctx, msg, ...) ((void)0)
#endif
#ifdef _WIN32
#define FFMT_CAST_SYMBOL(type, value) ((type *)(void *)(value))
#else
#define FFMT_CAST_SYMBOL(type, value) ((type *)(value))
#endif

#define FFMT_LOAD_LIBRARY(l, path)                                  \
    do {                                                       \
        if (!((l) = FFMT_LOAD_FUNC(path))) {                   \
            FFMT_LOG_FUNC(logctx, "Cannot load %s\n", path);   \
            ret = -1;                                          \
            goto error;                                        \
        }                                                      \
        FFMT_DEBUG_LOG_FUNC(logctx, "Loaded lib: %s\n", path); \
    } while (0)

#define FFMT_LOAD_SYMBOL(fun, tp, symbol)                             \
    do {                                                         \
        if (!((f->fun) = FFMT_CAST_SYMBOL(tp, FFMT_SYM_FUNC(f->lib, symbol)))) {  \
            FFMT_LOG_FUNC(logctx, "Cannot load %s\n", symbol);   \
            ret = -1;                                            \
            goto error;                                          \
        }                                                        \
        FFMT_DEBUG_LOG_FUNC(logctx, "Loaded sym: %s\n", symbol); \
    } while (0)

#define FFMT_LOAD_SYMBOL_OPT(fun, tp, symbol)                                      \
    do {                                                                      \
        if (!((f->fun) = FFMT_CAST_SYMBOL(tp, FFMT_SYM_FUNC(f->lib, symbol)))) {               \
            FFMT_DEBUG_LOG_FUNC(logctx, "Cannot load optional %s\n", symbol); \
        } else {                                                              \
            FFMT_DEBUG_LOG_FUNC(logctx, "Loaded sym: %s\n", symbol);          \
        }                                                                     \
    } while (0)

#define FFMT_GENERIC_LOAD_FUNC_PREAMBLE(T, n, N)     \
    T *f;                                       \
    int ret;                                    \
                                                \
    (void)logctx;                               \
    if (!functions) return -1;                  \
    n##_free_functions(functions);              \
                                                \
    f = *functions = (T*)calloc(1, sizeof(*f)); \
    if (!f)                                     \
        return -1;                              \
                                                \
    FFMT_LOAD_LIBRARY(f->lib, N);

#define FFMT_GENERIC_LOAD_FUNC_FINALE(n) \
    return 0;                       \
error:                              \
    n##_free_functions(functions);  \
    return ret;

#define FFMT_GENERIC_FREE_FUNC()                \
    if (!functions)                        \
        return;                            \
    if (*functions && (*functions)->lib)   \
        FFMT_FREE_FUNC((*functions)->lib); \
    free(*functions);                      \
    *functions = NULL;


#endif
