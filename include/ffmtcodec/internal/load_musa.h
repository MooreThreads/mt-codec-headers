/*
 * Copyright (c) 2026 MOORE THREADS & AFFILIATES.
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef FFMT_LOAD_MUSA_H
#define FFMT_LOAD_MUSA_H

#include "musa_types.h"
#include "load_common.h"
typedef struct MusaFunctions {
    tmuInit *muInit;
    tmuDriverGetVersion *muDriverGetVersion;
    tmuDeviceGetCount *muDeviceGetCount;
    tmuDeviceGet *muDeviceGet;
    tmuDeviceGetAttribute *muDeviceGetAttribute;
    tmuDeviceGetName *muDeviceGetName;
    tmuDeviceGetUuid *muDeviceGetUuid;
    tmuDeviceGetUuid_v2 *muDeviceGetUuid_v2;
    tmuDeviceGetLuid *muDeviceGetLuid;
    tmuDeviceGetByPCIBusId *muDeviceGetByPCIBusId;
    tmuDeviceGetPCIBusId *muDeviceGetPCIBusId;
    tmuDeviceComputeCapability *muDeviceComputeCapability;
    tmuCtxCreate_v2 *muCtxCreate;
    tmuCtxGetCurrent *muCtxGetCurrent;
    tmuCtxSetLimit *muCtxSetLimit;
    tmuCtxPushCurrent_v2 *muCtxPushCurrent;
    tmuCtxPopCurrent_v2 *muCtxPopCurrent;
    tmuCtxDestroy_v2 *muCtxDestroy;
    tmuMemAlloc_v2 *muMemAlloc;
    tmuMemAllocPitch_v2 *muMemAllocPitch;
    tmuMemAllocManaged *muMemAllocManaged;
    tmuMemsetD8Async *muMemsetD8Async;
    tmuMemFree_v2 *muMemFree;
    tmuMemcpy *muMemcpy;
    tmuMemcpyAsync *muMemcpyAsync;
    tmuMemcpy2D_v2 *muMemcpy2D;
    tmuMemcpy2DAsync_v2 *muMemcpy2DAsync;
    tmuMemcpyHtoD_v2 *muMemcpyHtoD;
    tmuMemcpyHtoDAsync_v2 *muMemcpyHtoDAsync;
    tmuMemcpyDtoH_v2 *muMemcpyDtoH;
    tmuMemcpyDtoHAsync_v2 *muMemcpyDtoHAsync;
    tmuMemcpyDtoD_v2 *muMemcpyDtoD;
    tmuMemcpyDtoDAsync_v2 *muMemcpyDtoDAsync;
    tmuGetErrorName *muGetErrorName;
    tmuGetErrorString *muGetErrorString;
    tmuCtxGetDevice *muCtxGetDevice;

    tmuDevicePrimaryCtxRetain *muDevicePrimaryCtxRetain;
    tmuDevicePrimaryCtxRelease *muDevicePrimaryCtxRelease;
    tmuDevicePrimaryCtxSetFlags *muDevicePrimaryCtxSetFlags;
    tmuDevicePrimaryCtxGetState *muDevicePrimaryCtxGetState;
    tmuDevicePrimaryCtxReset *muDevicePrimaryCtxReset;

    tmuStreamCreate *muStreamCreate;
    tmuStreamQuery *muStreamQuery;
    tmuStreamSynchronize *muStreamSynchronize;
    tmuStreamDestroy_v2 *muStreamDestroy;
    tmuStreamAddCallback *muStreamAddCallback;
    tmuStreamWaitEvent *muStreamWaitEvent;
    tmuEventCreate *muEventCreate;
    tmuEventDestroy_v2 *muEventDestroy;
    tmuEventSynchronize *muEventSynchronize;
    tmuEventQuery *muEventQuery;
    tmuEventRecord *muEventRecord;

    tmuLaunchKernel *muLaunchKernel;
    //tmuLinkCreate *muLinkCreate;
    //tmuLinkAddData *muLinkAddData;
    //tmuLinkComplete *muLinkComplete;
    //tmuLinkDestroy *muLinkDestroy;
    tmuModuleLoadData *muModuleLoadData;
    tmuModuleUnload *muModuleUnload;
    tmuModuleGetFunction *muModuleGetFunction;
    tmuModuleGetGlobal *muModuleGetGlobal;
    tmuTexObjectCreate *muTexObjectCreate;
    tmuTexObjectDestroy *muTexObjectDestroy;

    //tmuGLGetDevices_v2 *muGLGetDevices;
    tmuGraphicsGLRegisterImage *muGraphicsGLRegisterImage;
    tmuGraphicsUnregisterResource *muGraphicsUnregisterResource;
    tmuGraphicsMapResources *muGraphicsMapResources;
    tmuGraphicsUnmapResources *muGraphicsUnmapResources;
    tmuGraphicsSubResourceGetMappedArray *muGraphicsSubResourceGetMappedArray;
    tmuGraphicsResourceGetMappedPointer *muGraphicsResourceGetMappedPointer;

    tmuImportExternalMemory *muImportExternalMemory;
    tmuDestroyExternalMemory *muDestroyExternalMemory;
    tmuExternalMemoryGetMappedBuffer *muExternalMemoryGetMappedBuffer;
    tmuExternalMemoryGetMappedMipmappedArray *muExternalMemoryGetMappedMipmappedArray;
    tmuMipmappedArrayDestroy *muMipmappedArrayDestroy;

    tmuMipmappedArrayGetLevel *muMipmappedArrayGetLevel;

    tmuImportExternalSemaphore *muImportExternalSemaphore;
    tmuDestroyExternalSemaphore *muDestroyExternalSemaphore;
    tmuSignalExternalSemaphoresAsync *muSignalExternalSemaphoresAsync;
    tmuWaitExternalSemaphoresAsync *muWaitExternalSemaphoresAsync;

    tmuArrayCreate *muArrayCreate;
    tmuArray3DCreate *muArray3DCreate;
    tmuArrayDestroy *muArrayDestroy;

    tmuEGLStreamProducerConnect *muEGLStreamProducerConnect;
    tmuEGLStreamProducerDisconnect *muEGLStreamProducerDisconnect;
    tmuEGLStreamConsumerDisconnect *muEGLStreamConsumerDisconnect;
    tmuEGLStreamProducerPresentFrame *muEGLStreamProducerPresentFrame;
    tmuEGLStreamProducerReturnFrame *muEGLStreamProducerReturnFrame;

#if defined(_WIN32) || defined(__CYGWIN__)
    tmuD3D11GetDevice *muD3D11GetDevice;
    tmuD3D11GetDevices *muD3D11GetDevices;
    tmuGraphicsD3D11RegisterResource *muGraphicsD3D11RegisterResource;
#endif

    FFMT_LIB_HANDLE lib;
} MusaFunctions;

static inline void musa_free_functions(MusaFunctions **functions)
{
    FFMT_GENERIC_FREE_FUNC();
}
static inline int musa_load_functions(MusaFunctions **functions, void *logctx)
{
    FFMT_GENERIC_LOAD_FUNC_PREAMBLE(MusaFunctions, musa, MUSA_LIBNAME);

    FFMT_LOAD_SYMBOL(muInit, tmuInit, "muInit");
    FFMT_LOAD_SYMBOL(muDriverGetVersion, tmuDriverGetVersion, "muDriverGetVersion");
    FFMT_LOAD_SYMBOL(muDeviceGetCount, tmuDeviceGetCount, "muDeviceGetCount");
    FFMT_LOAD_SYMBOL(muDeviceGet, tmuDeviceGet, "muDeviceGet");
    FFMT_LOAD_SYMBOL(muDeviceGetAttribute, tmuDeviceGetAttribute, "muDeviceGetAttribute");
    FFMT_LOAD_SYMBOL(muDeviceGetName, tmuDeviceGetName, "muDeviceGetName");
    FFMT_LOAD_SYMBOL(muDeviceComputeCapability, tmuDeviceComputeCapability, "muDeviceComputeCapability");
    FFMT_LOAD_SYMBOL(muCtxCreate, tmuCtxCreate_v2, "muCtxCreate_v2");
    FFMT_LOAD_SYMBOL(muCtxGetCurrent, tmuCtxGetCurrent, "muCtxGetCurrent");
    FFMT_LOAD_SYMBOL(muCtxSetLimit, tmuCtxSetLimit, "muCtxSetLimit");
    FFMT_LOAD_SYMBOL(muCtxPushCurrent, tmuCtxPushCurrent_v2, "muCtxPushCurrent_v2");
    FFMT_LOAD_SYMBOL(muCtxPopCurrent, tmuCtxPopCurrent_v2, "muCtxPopCurrent_v2");
    FFMT_LOAD_SYMBOL(muCtxDestroy, tmuCtxDestroy_v2, "muCtxDestroy_v2");
    FFMT_LOAD_SYMBOL(muMemAlloc, tmuMemAlloc_v2, "muMemAlloc_v2");
    FFMT_LOAD_SYMBOL(muMemAllocPitch, tmuMemAllocPitch_v2, "muMemAllocPitch_v2");
    FFMT_LOAD_SYMBOL(muMemAllocManaged, tmuMemAllocManaged, "muMemAllocManaged");
    FFMT_LOAD_SYMBOL(muMemsetD8Async, tmuMemsetD8Async, "muMemsetD8Async");
    FFMT_LOAD_SYMBOL(muMemFree, tmuMemFree_v2, "muMemFree_v2");
    FFMT_LOAD_SYMBOL(muMemcpy, tmuMemcpy, "muMemcpy");
    FFMT_LOAD_SYMBOL(muMemcpyAsync, tmuMemcpyAsync, "muMemcpyAsync");
    FFMT_LOAD_SYMBOL(muMemcpy2D, tmuMemcpy2D_v2, "muMemcpy2D_v2");
    FFMT_LOAD_SYMBOL(muMemcpy2DAsync, tmuMemcpy2DAsync_v2, "muMemcpy2DAsync_v2");
    FFMT_LOAD_SYMBOL(muMemcpyHtoD, tmuMemcpyHtoD_v2, "muMemcpyHtoD_v2");
    FFMT_LOAD_SYMBOL(muMemcpyHtoDAsync, tmuMemcpyHtoDAsync_v2, "muMemcpyHtoDAsync_v2");
    FFMT_LOAD_SYMBOL(muMemcpyDtoH, tmuMemcpyDtoH_v2, "muMemcpyDtoH_v2");
    FFMT_LOAD_SYMBOL(muMemcpyDtoHAsync, tmuMemcpyDtoHAsync_v2, "muMemcpyDtoHAsync_v2");
    FFMT_LOAD_SYMBOL(muMemcpyDtoD, tmuMemcpyDtoD_v2, "muMemcpyDtoD_v2");
    FFMT_LOAD_SYMBOL(muMemcpyDtoDAsync, tmuMemcpyDtoDAsync_v2, "muMemcpyDtoDAsync_v2");
    FFMT_LOAD_SYMBOL(muGetErrorName, tmuGetErrorName, "muGetErrorName");
    FFMT_LOAD_SYMBOL(muGetErrorString, tmuGetErrorString, "muGetErrorString");
    FFMT_LOAD_SYMBOL(muCtxGetDevice, tmuCtxGetDevice, "muCtxGetDevice");

    FFMT_LOAD_SYMBOL(muDevicePrimaryCtxRetain, tmuDevicePrimaryCtxRetain, "muDevicePrimaryCtxRetain");
    FFMT_LOAD_SYMBOL(muDevicePrimaryCtxRelease, tmuDevicePrimaryCtxRelease, "muDevicePrimaryCtxRelease");
    FFMT_LOAD_SYMBOL(muDevicePrimaryCtxSetFlags, tmuDevicePrimaryCtxSetFlags, "muDevicePrimaryCtxSetFlags");
    FFMT_LOAD_SYMBOL(muDevicePrimaryCtxGetState, tmuDevicePrimaryCtxGetState, "muDevicePrimaryCtxGetState");
    FFMT_LOAD_SYMBOL(muDevicePrimaryCtxReset, tmuDevicePrimaryCtxReset, "muDevicePrimaryCtxReset");

    FFMT_LOAD_SYMBOL(muStreamCreate, tmuStreamCreate, "muStreamCreate");
    FFMT_LOAD_SYMBOL(muStreamQuery, tmuStreamQuery, "muStreamQuery");
    FFMT_LOAD_SYMBOL(muStreamSynchronize, tmuStreamSynchronize, "muStreamSynchronize");
    FFMT_LOAD_SYMBOL(muStreamDestroy, tmuStreamDestroy_v2, "muStreamDestroy_v2");
    FFMT_LOAD_SYMBOL(muStreamAddCallback, tmuStreamAddCallback, "muStreamAddCallback");
    FFMT_LOAD_SYMBOL(muStreamWaitEvent, tmuStreamWaitEvent, "muStreamWaitEvent");
    FFMT_LOAD_SYMBOL(muEventCreate, tmuEventCreate, "muEventCreate");
    FFMT_LOAD_SYMBOL(muEventDestroy, tmuEventDestroy_v2, "muEventDestroy_v2");
    FFMT_LOAD_SYMBOL(muEventSynchronize, tmuEventSynchronize, "muEventSynchronize");
    FFMT_LOAD_SYMBOL(muEventQuery, tmuEventQuery, "muEventQuery");
    FFMT_LOAD_SYMBOL(muEventRecord, tmuEventRecord, "muEventRecord");

    FFMT_LOAD_SYMBOL(muLaunchKernel, tmuLaunchKernel, "muLaunchKernel");
    //FFMT_LOAD_SYMBOL(muLinkCreate, tmuLinkCreate, "muLinkCreate");
    //FFMT_LOAD_SYMBOL(muLinkAddData, tmuLinkAddData, "muLinkAddData");
    //FFMT_LOAD_SYMBOL(muLinkComplete, tmuLinkComplete, "muLinkComplete");
    //FFMT_LOAD_SYMBOL(muLinkDestroy, tmuLinkDestroy, "muLinkDestroy");
    FFMT_LOAD_SYMBOL(muModuleLoadData, tmuModuleLoadData, "muModuleLoadData");
    FFMT_LOAD_SYMBOL(muModuleUnload, tmuModuleUnload, "muModuleUnload");
    FFMT_LOAD_SYMBOL(muModuleGetFunction, tmuModuleGetFunction, "muModuleGetFunction");
    FFMT_LOAD_SYMBOL(muModuleGetGlobal, tmuModuleGetGlobal, "muModuleGetGlobal");
    FFMT_LOAD_SYMBOL(muTexObjectCreate, tmuTexObjectCreate, "muTexObjectCreate");
    FFMT_LOAD_SYMBOL(muTexObjectDestroy, tmuTexObjectDestroy, "muTexObjectDestroy");

    //FFMT_LOAD_SYMBOL(muGLGetDevices, tmuGLGetDevices_v2, "muGLGetDevices_v2");
    FFMT_LOAD_SYMBOL(muGraphicsGLRegisterImage, tmuGraphicsGLRegisterImage, "muGraphicsGLRegisterImage");
    FFMT_LOAD_SYMBOL(muGraphicsUnregisterResource, tmuGraphicsUnregisterResource, "muGraphicsUnregisterResource");
    FFMT_LOAD_SYMBOL(muGraphicsMapResources, tmuGraphicsMapResources, "muGraphicsMapResources");
    FFMT_LOAD_SYMBOL(muGraphicsUnmapResources, tmuGraphicsUnmapResources, "muGraphicsUnmapResources");
    FFMT_LOAD_SYMBOL(muGraphicsSubResourceGetMappedArray, tmuGraphicsSubResourceGetMappedArray, "muGraphicsSubResourceGetMappedArray");
    FFMT_LOAD_SYMBOL(muGraphicsResourceGetMappedPointer, tmuGraphicsResourceGetMappedPointer, "muGraphicsResourceGetMappedPointer_v2");

    FFMT_LOAD_SYMBOL_OPT(muDeviceGetUuid, tmuDeviceGetUuid, "muDeviceGetUuid");
    FFMT_LOAD_SYMBOL_OPT(muDeviceGetUuid_v2, tmuDeviceGetUuid_v2, "muDeviceGetUuid_v2");
    FFMT_LOAD_SYMBOL_OPT(muDeviceGetLuid, tmuDeviceGetLuid, "muDeviceGetLuid");
    FFMT_LOAD_SYMBOL_OPT(muDeviceGetByPCIBusId, tmuDeviceGetByPCIBusId, "muDeviceGetByPCIBusId");
    FFMT_LOAD_SYMBOL_OPT(muDeviceGetPCIBusId, tmuDeviceGetPCIBusId, "muDeviceGetPCIBusId");
    FFMT_LOAD_SYMBOL_OPT(muImportExternalMemory, tmuImportExternalMemory, "muImportExternalMemory");
    FFMT_LOAD_SYMBOL_OPT(muDestroyExternalMemory, tmuDestroyExternalMemory, "muDestroyExternalMemory");
    FFMT_LOAD_SYMBOL_OPT(muExternalMemoryGetMappedBuffer, tmuExternalMemoryGetMappedBuffer, "muExternalMemoryGetMappedBuffer");
    FFMT_LOAD_SYMBOL_OPT(muExternalMemoryGetMappedMipmappedArray, tmuExternalMemoryGetMappedMipmappedArray, "muExternalMemoryGetMappedMipmappedArray");
    FFMT_LOAD_SYMBOL_OPT(muMipmappedArrayGetLevel, tmuMipmappedArrayGetLevel, "muMipmappedArrayGetLevel");
    FFMT_LOAD_SYMBOL_OPT(muMipmappedArrayDestroy, tmuMipmappedArrayDestroy, "muMipmappedArrayDestroy");

    FFMT_LOAD_SYMBOL_OPT(muImportExternalSemaphore, tmuImportExternalSemaphore, "muImportExternalSemaphore");
    FFMT_LOAD_SYMBOL_OPT(muDestroyExternalSemaphore, tmuDestroyExternalSemaphore, "muDestroyExternalSemaphore");
    FFMT_LOAD_SYMBOL_OPT(muSignalExternalSemaphoresAsync, tmuSignalExternalSemaphoresAsync, "muSignalExternalSemaphoresAsync");
    FFMT_LOAD_SYMBOL_OPT(muWaitExternalSemaphoresAsync, tmuWaitExternalSemaphoresAsync, "muWaitExternalSemaphoresAsync");

    FFMT_LOAD_SYMBOL(muArrayCreate, tmuArrayCreate, "muArrayCreate_v2");
    FFMT_LOAD_SYMBOL(muArray3DCreate, tmuArray3DCreate, "muArray3DCreate_v2");
    FFMT_LOAD_SYMBOL(muArrayDestroy, tmuArrayDestroy, "muArrayDestroy");

    FFMT_LOAD_SYMBOL_OPT(muEGLStreamProducerConnect, tmuEGLStreamProducerConnect, "muEGLStreamProducerConnect");
    FFMT_LOAD_SYMBOL_OPT(muEGLStreamProducerDisconnect, tmuEGLStreamProducerDisconnect, "muEGLStreamProducerDisconnect");
    FFMT_LOAD_SYMBOL_OPT(muEGLStreamConsumerDisconnect, tmuEGLStreamConsumerDisconnect, "muEGLStreamConsumerDisconnect");
    FFMT_LOAD_SYMBOL_OPT(muEGLStreamProducerPresentFrame, tmuEGLStreamProducerPresentFrame, "muEGLStreamProducerPresentFrame");
    FFMT_LOAD_SYMBOL_OPT(muEGLStreamProducerReturnFrame, tmuEGLStreamProducerReturnFrame, "muEGLStreamProducerReturnFrame");

#if defined(_WIN32) || defined(__CYGWIN__)
    FFMT_LOAD_SYMBOL(muD3D11GetDevice, tmuD3D11GetDevice, "muD3D11GetDevice");
    FFMT_LOAD_SYMBOL(muD3D11GetDevices, tmuD3D11GetDevices, "muD3D11GetDevices");
    FFMT_LOAD_SYMBOL(muGraphicsD3D11RegisterResource, tmuGraphicsD3D11RegisterResource, "muGraphicsD3D11RegisterResource");
#endif

    FFMT_GENERIC_LOAD_FUNC_FINALE(musa);
}


#endif
