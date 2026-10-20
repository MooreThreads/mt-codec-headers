/*
 * Copyright (c) 2026 MOORE THREADS & AFFILIATES.
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef FFMT_MUSA_TYPES_H
#define FFMT_MUSA_TYPES_H

#include "../dynlink_musa.h"
/* Preserve native function-table member spellings across SDK API-name mappings. */
#undef muDeviceGetUuid_v2
#undef muCtxCreate
#undef muCtxSynchronize
#undef muCtxPushCurrent
#undef muCtxPopCurrent
#undef muCtxDestroy
#undef muMemAlloc
#undef muMemAllocPitch
#undef muMemsetD8Async
#undef muMemFree
#undef muMemcpy
#undef muMemcpyAsync
#undef muMemcpy2D
#undef muMemcpy2DAsync
#undef muMemcpyHtoD
#undef muMemcpyHtoDAsync
#undef muMemcpyDtoH
#undef muMemcpyDtoHAsync
#undef muMemcpyDtoD
#undef muMemcpyDtoDAsync
#undef muDevicePrimaryCtxRelease
#undef muDevicePrimaryCtxSetFlags
#undef muDevicePrimaryCtxReset
#undef muStreamQuery
#undef muStreamSynchronize
#undef muStreamDestroy
#undef muStreamAddCallback
#undef muStreamWaitEvent
#undef muEventDestroy
#undef muEventRecord
#undef muLaunchKernel
#undef muModuleGetGlobal
#undef muGraphicsMapResources
#undef muGraphicsUnmapResources
#undef muGraphicsResourceGetMappedPointer
#undef muSignalExternalSemaphoresAsync
#undef muWaitExternalSemaphoresAsync
#undef muArrayCreate
#undef muArray3DCreate
typedef unsigned int GLenum;
typedef unsigned int GLuint;
typedef int32_t ffmt_EGLint;
typedef void *ffmt_EGLStreamKHR;
typedef enum MUGLDeviceList_enum {
    MU_GL_DEVICE_LIST_ALL = 1,
    MU_GL_DEVICE_LIST_CURRENT_FRAME = 2,
    MU_GL_DEVICE_LIST_NEXT_FRAME = 3,
} MUGLDeviceList;
typedef enum MUd3d11DeviceList_enum
{
    MU_D3D11_DEVICE_LIST_ALL = 1,
    MU_D3D11_DEVICE_LIST_CURRENT_FRAME = 2,
    MU_D3D11_DEVICE_LIST_NEXT_FRAME = 3,
} MUd3d11DeviceList;
#define MU_EGL_FRAME_MAX_PLANES 3
/* EGL ABI types copied from the installed SDK musaEGL.h. */
typedef enum MUeglFrameType_enum {
    MU_EGL_FRAME_TYPE_ARRAY = 0,  /**< Frame type MUSA array */
    MU_EGL_FRAME_TYPE_PITCH = 1,  /**< Frame type pointer */
} MUeglFrameType;
typedef enum MUeglColorFormat_enum {
    MU_EGL_COLOR_FORMAT_YUV420_PLANAR              = 0x00,  /**< Y, U, V in three surfaces, each in a separate surface, U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_YUV420_SEMIPLANAR          = 0x01,  /**< Y, UV in two surfaces (UV as one surface) with VU byte ordering, width, height ratio same as YUV420Planar. */
    MU_EGL_COLOR_FORMAT_YUV422_PLANAR              = 0x02,  /**< Y, U, V  each in a separate  surface, U/V width = 1/2 Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YUV422_SEMIPLANAR          = 0x03,  /**< Y, UV in two surfaces with VU byte ordering, width, height ratio same as YUV422Planar. */
    MU_EGL_COLOR_FORMAT_RGB                        = 0x04,  /**< R/G/B three channels in one surface with BGR byte ordering. Only pitch linear format supported. */
    MU_EGL_COLOR_FORMAT_BGR                        = 0x05,  /**< R/G/B three channels in one surface with RGB byte ordering. Only pitch linear format supported. */
    MU_EGL_COLOR_FORMAT_ARGB                       = 0x06,  /**< R/G/B/A four channels in one surface with BGRA byte ordering. */
    MU_EGL_COLOR_FORMAT_RGBA                       = 0x07,  /**< R/G/B/A four channels in one surface with ABGR byte ordering. */
    MU_EGL_COLOR_FORMAT_L                          = 0x08,  /**< single luminance channel in one surface. */
    MU_EGL_COLOR_FORMAT_R                          = 0x09,  /**< single color channel in one surface. */
    MU_EGL_COLOR_FORMAT_YUV444_PLANAR              = 0x0A,  /**< Y, U, V in three surfaces, each in a separate surface, U/V width = Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YUV444_SEMIPLANAR          = 0x0B,  /**< Y, UV in two surfaces (UV as one surface) with VU byte ordering, width, height ratio same as YUV444Planar. */
    MU_EGL_COLOR_FORMAT_YUYV_422                   = 0x0C,  /**< Y, U, V in one surface, interleaved as UYVY. */
    MU_EGL_COLOR_FORMAT_UYVY_422                   = 0x0D,  /**< Y, U, V in one surface, interleaved as YUYV. */
    MU_EGL_COLOR_FORMAT_ABGR                       = 0x0E,  /**< R/G/B/A four channels in one surface with RGBA byte ordering. */
    MU_EGL_COLOR_FORMAT_BGRA                       = 0x0F,  /**< R/G/B/A four channels in one surface with ARGB byte ordering. */
    MU_EGL_COLOR_FORMAT_A                          = 0x10,  /**< Alpha color format - one channel in one surface. */
    MU_EGL_COLOR_FORMAT_RG                         = 0x11,  /**< R/G color format - two channels in one surface with GR byte ordering */
    MU_EGL_COLOR_FORMAT_AYUV                       = 0x12,  /**< Y, U, V, A four channels in one surface, interleaved as VUYA. */
    MU_EGL_COLOR_FORMAT_YVU444_SEMIPLANAR          = 0x13,  /**< Y, VU in two surfaces (VU as one surface) with UV byte ordering, U/V width = Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YVU422_SEMIPLANAR          = 0x14,  /**< Y, VU in two surfaces (VU as one surface) with UV byte ordering, U/V width = 1/2 Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YVU420_SEMIPLANAR          = 0x15,  /**< Y, VU in two surfaces (VU as one surface) with UV byte ordering, U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_Y10V10U10_444_SEMIPLANAR   = 0x16,  /**< Y10, V10U10 in two surfaces (VU as one surface) with UV byte ordering, U/V width = Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_Y10V10U10_420_SEMIPLANAR   = 0x17,  /**< Y10, V10U10 in two surfaces (VU as one surface) with UV byte ordering, U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_Y12V12U12_444_SEMIPLANAR   = 0x18,  /**< Y12, V12U12 in two surfaces (VU as one surface) with UV byte ordering, U/V width = Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_Y12V12U12_420_SEMIPLANAR   = 0x19,  /**< Y12, V12U12 in two surfaces (VU as one surface) with UV byte ordering, U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_VYUY_ER                    = 0x1A,  /**< Extended Range Y, U, V in one surface, interleaved as YVYU. */
    MU_EGL_COLOR_FORMAT_UYVY_ER                    = 0x1B,  /**< Extended Range Y, U, V in one surface, interleaved as YUYV. */
    MU_EGL_COLOR_FORMAT_YUYV_ER                    = 0x1C,  /**< Extended Range Y, U, V in one surface, interleaved as UYVY. */
    MU_EGL_COLOR_FORMAT_YVYU_ER                    = 0x1D,  /**< Extended Range Y, U, V in one surface, interleaved as VYUY. */
    MU_EGL_COLOR_FORMAT_YUV_ER                     = 0x1E,  /**< Extended Range Y, U, V three channels in one surface, interleaved as VUY. Only pitch linear format supported. */
    MU_EGL_COLOR_FORMAT_YUVA_ER                    = 0x1F,  /**< Extended Range Y, U, V, A four channels in one surface, interleaved as AVUY. */
    MU_EGL_COLOR_FORMAT_AYUV_ER                    = 0x20,  /**< Extended Range Y, U, V, A four channels in one surface, interleaved as VUYA. */
    MU_EGL_COLOR_FORMAT_YUV444_PLANAR_ER           = 0x21,  /**< Extended Range Y, U, V in three surfaces, U/V width = Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YUV422_PLANAR_ER           = 0x22,  /**< Extended Range Y, U, V in three surfaces, U/V width = 1/2 Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YUV420_PLANAR_ER           = 0x23,  /**< Extended Range Y, U, V in three surfaces, U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_YUV444_SEMIPLANAR_ER       = 0x24,  /**< Extended Range Y, UV in two surfaces (UV as one surface) with VU byte ordering, U/V width = Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YUV422_SEMIPLANAR_ER       = 0x25,  /**< Extended Range Y, UV in two surfaces (UV as one surface) with VU byte ordering, U/V width = 1/2 Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YUV420_SEMIPLANAR_ER       = 0x26,  /**< Extended Range Y, UV in two surfaces (UV as one surface) with VU byte ordering, U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_YVU444_PLANAR_ER           = 0x27,  /**< Extended Range Y, V, U in three surfaces, U/V width = Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YVU422_PLANAR_ER           = 0x28,  /**< Extended Range Y, V, U in three surfaces, U/V width = 1/2 Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YVU420_PLANAR_ER           = 0x29,  /**< Extended Range Y, V, U in three surfaces, U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_YVU444_SEMIPLANAR_ER       = 0x2A,  /**< Extended Range Y, VU in two surfaces (VU as one surface) with UV byte ordering, U/V width = Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YVU422_SEMIPLANAR_ER       = 0x2B,  /**< Extended Range Y, VU in two surfaces (VU as one surface) with UV byte ordering, U/V width = 1/2 Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YVU420_SEMIPLANAR_ER       = 0x2C,  /**< Extended Range Y, VU in two surfaces (VU as one surface) with UV byte ordering, U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_BAYER_RGGB                 = 0x2D,  /**< Bayer format - one channel in one surface with interleaved RGGB ordering. */
    MU_EGL_COLOR_FORMAT_BAYER_BGGR                 = 0x2E,  /**< Bayer format - one channel in one surface with interleaved BGGR ordering. */
    MU_EGL_COLOR_FORMAT_BAYER_GRBG                 = 0x2F,  /**< Bayer format - one channel in one surface with interleaved GRBG ordering. */
    MU_EGL_COLOR_FORMAT_BAYER_GBRG                 = 0x30,  /**< Bayer format - one channel in one surface with interleaved GBRG ordering. */
    MU_EGL_COLOR_FORMAT_BAYER10_RGGB               = 0x31,  /**< Bayer10 format - one channel in one surface with interleaved RGGB ordering. Out of 16 bits, 10 bits used 6 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER10_BGGR               = 0x32,  /**< Bayer10 format - one channel in one surface with interleaved BGGR ordering. Out of 16 bits, 10 bits used 6 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER10_GRBG               = 0x33,  /**< Bayer10 format - one channel in one surface with interleaved GRBG ordering. Out of 16 bits, 10 bits used 6 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER10_GBRG               = 0x34,  /**< Bayer10 format - one channel in one surface with interleaved GBRG ordering. Out of 16 bits, 10 bits used 6 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER12_RGGB               = 0x35,  /**< Bayer12 format - one channel in one surface with interleaved RGGB ordering. Out of 16 bits, 12 bits used 4 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER12_BGGR               = 0x36,  /**< Bayer12 format - one channel in one surface with interleaved BGGR ordering. Out of 16 bits, 12 bits used 4 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER12_GRBG               = 0x37,  /**< Bayer12 format - one channel in one surface with interleaved GRBG ordering. Out of 16 bits, 12 bits used 4 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER12_GBRG               = 0x38,  /**< Bayer12 format - one channel in one surface with interleaved GBRG ordering. Out of 16 bits, 12 bits used 4 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER14_RGGB               = 0x39,  /**< Bayer14 format - one channel in one surface with interleaved RGGB ordering. Out of 16 bits, 14 bits used 2 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER14_BGGR               = 0x3A,  /**< Bayer14 format - one channel in one surface with interleaved BGGR ordering. Out of 16 bits, 14 bits used 2 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER14_GRBG               = 0x3B,  /**< Bayer14 format - one channel in one surface with interleaved GRBG ordering. Out of 16 bits, 14 bits used 2 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER14_GBRG               = 0x3C,  /**< Bayer14 format - one channel in one surface with interleaved GBRG ordering. Out of 16 bits, 14 bits used 2 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER20_RGGB               = 0x3D,  /**< Bayer20 format - one channel in one surface with interleaved RGGB ordering. Out of 32 bits, 20 bits used 12 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER20_BGGR               = 0x3E,  /**< Bayer20 format - one channel in one surface with interleaved BGGR ordering. Out of 32 bits, 20 bits used 12 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER20_GRBG               = 0x3F,  /**< Bayer20 format - one channel in one surface with interleaved GRBG ordering. Out of 32 bits, 20 bits used 12 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER20_GBRG               = 0x40,  /**< Bayer20 format - one channel in one surface with interleaved GBRG ordering. Out of 32 bits, 20 bits used 12 bits No-op. */
    MU_EGL_COLOR_FORMAT_YVU444_PLANAR              = 0x41,  /**< Y, V, U in three surfaces, each in a separate surface, U/V width = Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YVU422_PLANAR              = 0x42,  /**< Y, V, U in three surfaces, each in a separate surface, U/V width = 1/2 Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_YVU420_PLANAR              = 0x43,  /**< Y, V, U in three surfaces, each in a separate surface, U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_BAYER_ISP_RGGB             = 0x44,  /**< MooreThreads proprietary Bayer ISP format - one channel in one surface with interleaved RGGB ordering and mapped to opaque integer datatype. */
    MU_EGL_COLOR_FORMAT_BAYER_ISP_BGGR             = 0x45,  /**< MooreThreads proprietary Bayer ISP format - one channel in one surface with interleaved BGGR ordering and mapped to opaque integer datatype. */
    MU_EGL_COLOR_FORMAT_BAYER_ISP_GRBG             = 0x46,  /**< MooreThreads proprietary Bayer ISP format - one channel in one surface with interleaved GRBG ordering and mapped to opaque integer datatype. */
    MU_EGL_COLOR_FORMAT_BAYER_ISP_GBRG             = 0x47,  /**< MooreThreads proprietary Bayer ISP format - one channel in one surface with interleaved GBRG ordering and mapped to opaque integer datatype. */
    MU_EGL_COLOR_FORMAT_BAYER_BCCR                 = 0x48,  /**< Bayer format - one channel in one surface with interleaved BCCR ordering. */
    MU_EGL_COLOR_FORMAT_BAYER_RCCB                 = 0x49,  /**< Bayer format - one channel in one surface with interleaved RCCB ordering. */
    MU_EGL_COLOR_FORMAT_BAYER_CRBC                 = 0x4A,  /**< Bayer format - one channel in one surface with interleaved CRBC ordering. */
    MU_EGL_COLOR_FORMAT_BAYER_CBRC                 = 0x4B,  /**< Bayer format - one channel in one surface with interleaved CBRC ordering. */
    MU_EGL_COLOR_FORMAT_BAYER10_CCCC               = 0x4C,  /**< Bayer10 format - one channel in one surface with interleaved CCCC ordering. Out of 16 bits, 10 bits used 6 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER12_BCCR               = 0x4D,  /**< Bayer12 format - one channel in one surface with interleaved BCCR ordering. Out of 16 bits, 12 bits used 4 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER12_RCCB               = 0x4E,  /**< Bayer12 format - one channel in one surface with interleaved RCCB ordering. Out of 16 bits, 12 bits used 4 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER12_CRBC               = 0x4F,  /**< Bayer12 format - one channel in one surface with interleaved CRBC ordering. Out of 16 bits, 12 bits used 4 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER12_CBRC               = 0x50,  /**< Bayer12 format - one channel in one surface with interleaved CBRC ordering. Out of 16 bits, 12 bits used 4 bits No-op. */
    MU_EGL_COLOR_FORMAT_BAYER12_CCCC               = 0x51,  /**< Bayer12 format - one channel in one surface with interleaved CCCC ordering. Out of 16 bits, 12 bits used 4 bits No-op. */
    MU_EGL_COLOR_FORMAT_Y                          = 0x52, /**< Color format for single Y plane. */
    MU_EGL_COLOR_FORMAT_YUV420_SEMIPLANAR_2020     = 0x53, /**< Y, UV in two surfaces (UV as one surface) U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_YVU420_SEMIPLANAR_2020     = 0x54, /**< Y, VU in two surfaces (VU as one surface) U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_YUV420_PLANAR_2020         = 0x55, /**< Y, U, V  each in a separate  surface, U/V width = 1/2 Y width, U/V height= 1/2 Y height. */             
    MU_EGL_COLOR_FORMAT_YVU420_PLANAR_2020         = 0x56, /**< Y, V, U each in a separate surface, U/V width = 1/2 Y width, U/V height
= 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_YUV420_SEMIPLANAR_709      = 0x57, /**< Y, UV in two surfaces (UV as one surface) U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_YVU420_SEMIPLANAR_709      = 0x58, /**< Y, VU in two surfaces (VU as one surface) U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_YUV420_PLANAR_709          = 0x59, /**< Y, U, V  each in a separate  surface, U/V width = 1/2 Y width, U/V height
= 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_YVU420_PLANAR_709          = 0x5A,  /**< Y, V, U each in a separate surface, U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_Y10V10U10_420_SEMIPLANAR_709  = 0x5B, /**< Y10, V10U10 in two surfaces (VU as one surface), U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_Y10V10U10_420_SEMIPLANAR_2020 = 0x5C, /**< Y10, V10U10 in two surfaces (VU as one surface), U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_Y10V10U10_422_SEMIPLANAR_2020 = 0x5D, /**< Y10, V10U10 in two surfaces(VU as one surface) U/V width = 1/2 Y width, U/V height  = Y height. */
    MU_EGL_COLOR_FORMAT_Y10V10U10_422_SEMIPLANAR      = 0x5E, /**< Y10, V10U10 in two surfaces(VU as one surface) U/V width = 1/2 Y width, U/V height  = Y height. */
    MU_EGL_COLOR_FORMAT_Y10V10U10_422_SEMIPLANAR_709  = 0x5F, /**< Y10, V10U10 in two surfaces(VU as one surface) U/V width = 1/2 Y width, U/V height  = Y height. */
    MU_EGL_COLOR_FORMAT_Y_ER                          = 0x60, /**< Extended Range Color format for single Y plane. */
    MU_EGL_COLOR_FORMAT_Y_709_ER                      = 0x61, /**< Extended Range Color format for single Y plane. */
    MU_EGL_COLOR_FORMAT_Y10_ER                        = 0x62, /**< Extended Range Color format for single Y10 plane. */
    MU_EGL_COLOR_FORMAT_Y10_709_ER                    = 0x63, /**< Extended Range Color format for single Y10 plane. */
    MU_EGL_COLOR_FORMAT_Y12_ER                        = 0x64, /**< Extended Range Color format for single Y12 plane. */
    MU_EGL_COLOR_FORMAT_Y12_709_ER                    = 0x65, /**< Extended Range Color format for single Y12 plane. */
    MU_EGL_COLOR_FORMAT_YUVA                          = 0x66, /**< Y, U, V, A four channels in one surface, interleaved as AVUY. */
    MU_EGL_COLOR_FORMAT_YUV                           = 0x67, /**< Y, U, V three channels in one surface, interleaved as VUY. Only pitch linear format supported. */
    MU_EGL_COLOR_FORMAT_YVYU                          = 0x68, /**< Y, U, V in one surface, interleaved as YVYU. */
    MU_EGL_COLOR_FORMAT_VYUY                          = 0x69, /**< Y, U, V in one surface, interleaved as VYUY. */
    MU_EGL_COLOR_FORMAT_Y10V10U10_420_SEMIPLANAR_ER     = 0x6A, /**< Extended Range Y10, V10U10 in two surfaces(VU as one surface) U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_Y10V10U10_420_SEMIPLANAR_709_ER = 0x6B, /**< Extended Range Y10, V10U10 in two surfaces(VU as one surface) U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_Y10V10U10_444_SEMIPLANAR_ER     = 0x6C, /**< Extended Range Y10, V10U10 in two surfaces (VU as one surface) U/V width = Y width, U/V height = Y height. */ 
    MU_EGL_COLOR_FORMAT_Y10V10U10_444_SEMIPLANAR_709_ER = 0x6D, /**< Extended Range Y10, V10U10 in two surfaces (VU as one surface)  U/V width = Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_Y12V12U12_420_SEMIPLANAR_ER     = 0x6E, /**< Extended Range Y12, V12U12 in two surfaces (VU as one surface) U/V width = 1/2 Y width, U/V height = 1/2 Y height. */ 
    MU_EGL_COLOR_FORMAT_Y12V12U12_420_SEMIPLANAR_709_ER = 0x6F, /**< Extended Range Y12, V12U12 in two surfaces (VU as one surface) U/V width = 1/2 Y width, U/V height = 1/2 Y height. */
    MU_EGL_COLOR_FORMAT_Y12V12U12_444_SEMIPLANAR_ER     = 0x70, /**< Extended Range Y12, V12U12 in two surfaces (VU as one surface) U/V width = Y width, U/V height = Y height. */ 
    MU_EGL_COLOR_FORMAT_Y12V12U12_444_SEMIPLANAR_709_ER = 0x71, /**< Extended Range Y12, V12U12 in two surfaces (VU as one surface) U/V width = Y width, U/V height = Y height. */
    MU_EGL_COLOR_FORMAT_MAX
} MUeglColorFormat;
typedef struct MUeglFrame_st {
    union {
        MUarray pArray[3];     /**< Array of MUarray corresponding to each plane*/
        void*   pPitch[3];     /**< Array of Pointers corresponding to each plane*/
    } frame;
    unsigned int width;                 /**< Width of first plane */
    unsigned int height;                /**< Height of first plane */
    unsigned int depth;                 /**< Depth of first plane */
    unsigned int pitch;                 /**< Pitch of first plane */
    unsigned int planeCount;            /**< Number of planes */
    unsigned int numChannels;           /**< Number of channels for the plane */
    MUeglFrameType frameType;           /**< Array or Pitch */
    MUeglColorFormat eglColorFormat;    /**< MUSA EGL Color Format*/
    MUarray_format muFormat;            /**< MUSA Array Format*/
} MUeglFrame_v1;
typedef MUeglFrame_v1 MUeglFrame;

/**
  * MUSA EGLSream Connection
  */
typedef struct MUeglStreamConnection_st* MUeglStreamConnection;
typedef MUresult MUSAAPI tmuInit(unsigned int Flags);
typedef MUresult MUSAAPI tmuDriverGetVersion(int *driverVersion);
typedef MUresult MUSAAPI tmuDeviceGetCount(int *count);
typedef MUresult MUSAAPI tmuDeviceGet(MUdevice *device, int ordinal);
typedef MUresult MUSAAPI tmuDeviceGetAttribute(int *pi, MUdevice_attribute attrib, MUdevice dev);
typedef MUresult MUSAAPI tmuDeviceGetName(char *name, int len, MUdevice dev);
typedef MUresult MUSAAPI tmuDeviceGetUuid(MUuuid *uuid, MUdevice dev);
typedef MUresult MUSAAPI tmuDeviceGetUuid_v2(MUuuid *uuid, MUdevice dev);
typedef MUresult MUSAAPI tmuDeviceGetLuid(char* luid, unsigned int* deviceNodeMask, MUdevice dev);
typedef MUresult MUSAAPI tmuDeviceGetByPCIBusId(MUdevice* dev, const char* pciBusId);
typedef MUresult MUSAAPI tmuDeviceGetPCIBusId(char* pciBusId, int len, MUdevice dev);
typedef MUresult MUSAAPI tmuDeviceComputeCapability(int *major, int *minor, MUdevice dev);
typedef MUresult MUSAAPI tmuCtxCreate_v2(MUcontext *pctx, unsigned int flags, MUdevice dev);
typedef MUresult MUSAAPI tmuCtxSynchronize(void);
typedef MUresult MUSAAPI tmuCtxGetCurrent(MUcontext *pctx);
typedef MUresult MUSAAPI tmuCtxSetLimit(MUlimit limit, size_t value);
typedef MUresult MUSAAPI tmuCtxPushCurrent_v2(MUcontext pctx);
typedef MUresult MUSAAPI tmuCtxPopCurrent_v2(MUcontext *pctx);
typedef MUresult MUSAAPI tmuCtxDestroy_v2(MUcontext ctx);
typedef MUresult MUSAAPI tmuMemAlloc_v2(MUdeviceptr *dptr, size_t bytesize);
typedef MUresult MUSAAPI tmuMemAllocPitch_v2(MUdeviceptr *dptr, size_t *pPitch, size_t WidthInBytes, size_t Height, unsigned int ElementSizeBytes);
typedef MUresult MUSAAPI tmuMemAllocManaged(MUdeviceptr *dptr, size_t bytesize, unsigned int flags);
typedef MUresult MUSAAPI tmuMemsetD8Async(MUdeviceptr dstDevice, unsigned char uc, size_t N, MUstream hStream);
typedef MUresult MUSAAPI tmuMemFree_v2(MUdeviceptr dptr);
typedef MUresult MUSAAPI tmuMemcpy(MUdeviceptr dst, MUdeviceptr src, size_t bytesize);
typedef MUresult MUSAAPI tmuMemcpyAsync(MUdeviceptr dst, MUdeviceptr src, size_t bytesize, MUstream hStream);
typedef MUresult MUSAAPI tmuMemcpy2D_v2(const MUSA_MEMCPY2D *pcopy);
typedef MUresult MUSAAPI tmuMemcpy2DAsync_v2(const MUSA_MEMCPY2D *pcopy, MUstream hStream);
typedef MUresult MUSAAPI tmuMemcpyHtoD_v2(MUdeviceptr dstDevice, const void *srcHost, size_t ByteCount);
typedef MUresult MUSAAPI tmuMemcpyHtoDAsync_v2(MUdeviceptr dstDevice, const void *srcHost, size_t ByteCount, MUstream hStream);
typedef MUresult MUSAAPI tmuMemcpyDtoH_v2(void *dstHost, MUdeviceptr srcDevice, size_t ByteCount);
typedef MUresult MUSAAPI tmuMemcpyDtoHAsync_v2(void *dstHost, MUdeviceptr srcDevice, size_t ByteCount, MUstream hStream);
typedef MUresult MUSAAPI tmuMemcpyDtoD_v2(MUdeviceptr dstDevice, MUdeviceptr srcDevice, size_t ByteCount);
typedef MUresult MUSAAPI tmuMemcpyDtoDAsync_v2(MUdeviceptr dstDevice, MUdeviceptr srcDevice, size_t ByteCount, MUstream hStream);
typedef MUresult MUSAAPI tmuGetErrorName(MUresult error, const char** pstr);
typedef MUresult MUSAAPI tmuGetErrorString(MUresult error, const char** pstr);
typedef MUresult MUSAAPI tmuCtxGetDevice(MUdevice *device);

typedef MUresult MUSAAPI tmuDevicePrimaryCtxRetain(MUcontext *pctx, MUdevice dev);
typedef MUresult MUSAAPI tmuDevicePrimaryCtxRelease(MUdevice dev);
typedef MUresult MUSAAPI tmuDevicePrimaryCtxSetFlags(MUdevice dev, unsigned int flags);
typedef MUresult MUSAAPI tmuDevicePrimaryCtxGetState(MUdevice dev, unsigned int *flags, int *active);
typedef MUresult MUSAAPI tmuDevicePrimaryCtxReset(MUdevice dev);

typedef MUresult MUSAAPI tmuStreamCreate(MUstream *phStream, unsigned int flags);
typedef MUresult MUSAAPI tmuStreamQuery(MUstream hStream);
typedef MUresult MUSAAPI tmuStreamSynchronize(MUstream hStream);
typedef MUresult MUSAAPI tmuStreamDestroy_v2(MUstream hStream);
typedef MUresult MUSAAPI tmuStreamAddCallback(MUstream hStream, MUstreamCallback callback, void *userdata, unsigned int flags);
typedef MUresult MUSAAPI tmuStreamWaitEvent(MUstream hStream, MUevent hEvent, unsigned int flags);
typedef MUresult MUSAAPI tmuEventCreate(MUevent *phEvent, unsigned int flags);
typedef MUresult MUSAAPI tmuEventDestroy_v2(MUevent hEvent);
typedef MUresult MUSAAPI tmuEventSynchronize(MUevent hEvent);
typedef MUresult MUSAAPI tmuEventQuery(MUevent hEvent);
typedef MUresult MUSAAPI tmuEventRecord(MUevent hEvent, MUstream hStream);

typedef MUresult MUSAAPI tmuLaunchKernel(MUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, MUstream hStream, void** kernelParams, void** extra);
//typedef MUresult MUSAAPI tmuLinkCreate(unsigned int numOptions, MUjit_option* options, void** optionValues, MUlinkState* stateOut);
//typedef MUresult MUSAAPI tmuLinkAddData(MUlinkState state, MUjitInputType type, void* data, size_t size, const char* name, unsigned int numOptions, MUjit_option* options, void** optionValues);
//typedef MUresult MUSAAPI tmuLinkComplete(MUlinkState state, void** mubinOut, size_t* sizeOut);
//typedef MUresult MUSAAPI tmuLinkDestroy(MUlinkState state);
typedef MUresult MUSAAPI tmuModuleLoadData(MUmodule* module, const void* image);
typedef MUresult MUSAAPI tmuModuleUnload(MUmodule hmod);
typedef MUresult MUSAAPI tmuModuleGetFunction(MUfunction* hfunc, MUmodule hmod, const char* name);
typedef MUresult MUSAAPI tmuModuleGetGlobal(MUdeviceptr *dptr, size_t *bytes, MUmodule hmod, const char* name);
typedef MUresult MUSAAPI tmuTexObjectCreate(MUtexObject* pTexObject, const MUSA_RESOURCE_DESC* pResDesc, const MUSA_TEXTURE_DESC* pTexDesc, const MUSA_RESOURCE_VIEW_DESC* pResViewDesc);
typedef MUresult MUSAAPI tmuTexObjectDestroy(MUtexObject texObject);

typedef MUresult MUSAAPI tmuGLGetDevices_v2(unsigned int* pMusaDeviceCount, MUdevice* pMusaDevices, unsigned int musaDeviceCount, MUGLDeviceList deviceList);
typedef MUresult MUSAAPI tmuGraphicsGLRegisterBuffer(MUgraphicsResource *pMusaResource, GLuint buffer, unsigned int Flags);
typedef MUresult MUSAAPI tmuGraphicsGLRegisterImage(MUgraphicsResource* pMusaResource, GLuint image, GLenum target, unsigned int Flags);
typedef MUresult MUSAAPI tmuGraphicsUnregisterResource(MUgraphicsResource resource);
typedef MUresult MUSAAPI tmuGraphicsMapResources(unsigned int count, MUgraphicsResource* resources, MUstream hStream);
typedef MUresult MUSAAPI tmuGraphicsUnmapResources(unsigned int count, MUgraphicsResource* resources, MUstream hStream);
typedef MUresult MUSAAPI tmuGraphicsSubResourceGetMappedArray(MUarray* pArray, MUgraphicsResource resource, unsigned int arrayIndex, unsigned int mipLevel);
typedef MUresult MUSAAPI tmuGraphicsResourceGetMappedPointer(MUdeviceptr *devPtrOut, size_t *sizeOut, MUgraphicsResource resource);

typedef MUresult MUSAAPI tmuImportExternalMemory(MUexternalMemory* extMem_out, const MUSA_EXTERNAL_MEMORY_HANDLE_DESC* memHandleDesc);
typedef MUresult MUSAAPI tmuDestroyExternalMemory(MUexternalMemory extMem);
typedef MUresult MUSAAPI tmuExternalMemoryGetMappedBuffer(MUdeviceptr* devPtr, MUexternalMemory extMem, const MUSA_EXTERNAL_MEMORY_BUFFER_DESC* bufferDesc);
typedef MUresult MUSAAPI tmuExternalMemoryGetMappedMipmappedArray(MUmipmappedArray* mipmap, MUexternalMemory extMem, const MUSA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC* mipmapDesc);
typedef MUresult MUSAAPI tmuMipmappedArrayGetLevel(MUarray* pLevelArray, MUmipmappedArray hMipmappedArray, unsigned int level);
typedef MUresult MUSAAPI tmuMipmappedArrayDestroy(MUmipmappedArray hMipmappedArray);

typedef MUresult MUSAAPI tmuImportExternalSemaphore(MUexternalSemaphore* extSem_out, const MUSA_EXTERNAL_SEMAPHORE_HANDLE_DESC* semHandleDesc);
typedef MUresult MUSAAPI tmuDestroyExternalSemaphore(MUexternalSemaphore extSem);
typedef MUresult MUSAAPI tmuSignalExternalSemaphoresAsync(const MUexternalSemaphore* extSemArray, const MUSA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS* paramsArray, unsigned int numExtSems, MUstream stream);
typedef MUresult MUSAAPI tmuWaitExternalSemaphoresAsync(const MUexternalSemaphore* extSemArray, const MUSA_EXTERNAL_SEMAPHORE_WAIT_PARAMS* paramsArray, unsigned int numExtSems, MUstream stream);

typedef MUresult MUSAAPI tmuArrayCreate(MUarray *pHandle, const MUSA_ARRAY_DESCRIPTOR* pAllocateArray);
typedef MUresult MUSAAPI tmuArray3DCreate(MUarray *pHandle, const MUSA_ARRAY3D_DESCRIPTOR* pAllocateArray);
typedef MUresult MUSAAPI tmuArrayDestroy(MUarray hArray);

typedef MUresult MUSAAPI tmuEGLStreamProducerConnect(MUeglStreamConnection* conn, ffmt_EGLStreamKHR stream, ffmt_EGLint width, ffmt_EGLint height);
typedef MUresult MUSAAPI tmuEGLStreamProducerDisconnect(MUeglStreamConnection* conn);
typedef MUresult MUSAAPI tmuEGLStreamConsumerDisconnect(MUeglStreamConnection* conn);
typedef MUresult MUSAAPI tmuEGLStreamProducerPresentFrame(MUeglStreamConnection* conn, MUeglFrame eglframe, MUstream* pStream);
typedef MUresult MUSAAPI tmuEGLStreamProducerReturnFrame(MUeglStreamConnection* conn, MUeglFrame* eglframe, MUstream* pStream);

typedef MUresult MUSAAPI tmuD3D11GetDevice(MUdevice *device, void *dxgiAdapter);
typedef MUresult MUSAAPI tmuD3D11GetDevices(unsigned int *deviceCountOut, MUdevice *devices, unsigned int deviceCount, void *d3d11device, MUd3d11DeviceList listType);
typedef MUresult MUSAAPI tmuGraphicsD3D11RegisterResource(MUgraphicsResource *musaResourceOut, void *d3d11Resource, unsigned int flags);

#endif
