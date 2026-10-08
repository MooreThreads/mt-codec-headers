/*
 * Copyright (c) 2026 MOORE THREADS & AFFILIATES.
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef FFMT_DYNLINK_MUSA_H
#define FFMT_DYNLINK_MUSA_H
#include <stdlib.h>
#ifdef _MSC_VER
typedef unsigned __int32 muuint32_t;
typedef unsigned __int64 muuint64_t;
#else
#include <stdint.h>
typedef uint32_t muuint32_t;
typedef uint64_t muuint64_t;
#endif
#if defined(__MUSA_API_VERSION_INTERNAL) || defined(__DOXYGEN_ONLY__) || defined(MUSA_ENABLE_DEPRECATED)
#define __MUSA_DEPRECATED
#elif defined(_MSC_VER)
#define __MUSA_DEPRECATED __declspec(deprecated)
#elif defined(__GNUC__)
#define __MUSA_DEPRECATED __attribute__((deprecated))
#else
#define __MUSA_DEPRECATED
#endif
#if defined(MUSA_FORCE_API_VERSION)
#error "MUSA_FORCE_API_VERSION is no longer supported."
#endif
#if defined(__MUSA_API_VERSION_INTERNAL) || defined(MUSA_API_PER_THREAD_DEFAULT_STREAM)
    #define __MUSA_API_PER_THREAD_DEFAULT_STREAM
    #define __MUSA_API_PTDS(api) api ## _ptds
    #define __MUSA_API_PTSZ(api) api ## _ptsz
#else
    #define __MUSA_API_PTDS(api) api
    #define __MUSA_API_PTSZ(api) api
#endif
#define muDeviceTotalMem                    muDeviceTotalMem_v2
#define muCtxCreate                         muCtxCreate_v2
#define muCtxCreate_v3                      muCtxCreate_v3
#define muCtxCreate_v4                      muCtxCreate_v4
#define muModuleGetGlobal                   muModuleGetGlobal_v2
#define muMemGetInfo                        muMemGetInfo_v2
#define muMemAlloc                          muMemAlloc_v2
#define muMemAllocPitch                     muMemAllocPitch_v2
#define muMemFree                           muMemFree_v2
#define muMemGetAddressRange                muMemGetAddressRange_v2
#define muMemAllocHost                      muMemAllocHost_v2
#define muMemHostGetDevicePointer           muMemHostGetDevicePointer_v2
#define muMemcpyHtoD                        __MUSA_API_PTDS(muMemcpyHtoD_v2)
#define muMemcpyDtoH                        __MUSA_API_PTDS(muMemcpyDtoH_v2)
#define muMemcpyDtoD                        __MUSA_API_PTDS(muMemcpyDtoD_v2)
#define muMemcpyDtoA                        __MUSA_API_PTDS(muMemcpyDtoA_v2)
#define muMemcpyAtoD                        __MUSA_API_PTDS(muMemcpyAtoD_v2)
#define muMemcpyHtoA                        __MUSA_API_PTDS(muMemcpyHtoA_v2)
#define muMemcpyAtoH                        __MUSA_API_PTDS(muMemcpyAtoH_v2)
#define muMemcpyAtoA                        __MUSA_API_PTDS(muMemcpyAtoA_v2)
#define muMemcpyHtoAAsync                   __MUSA_API_PTSZ(muMemcpyHtoAAsync_v2)
#define muMemcpyAtoHAsync                   __MUSA_API_PTSZ(muMemcpyAtoHAsync_v2)
#define muMemcpy2D                          __MUSA_API_PTDS(muMemcpy2D_v2)
#define muMemcpy2DUnaligned                 __MUSA_API_PTDS(muMemcpy2DUnaligned_v2)
#define muMemcpy3D                          __MUSA_API_PTDS(muMemcpy3D_v2)
#define muMemcpyHtoDAsync                   __MUSA_API_PTSZ(muMemcpyHtoDAsync_v2)
#define muMemcpyDtoHAsync                   __MUSA_API_PTSZ(muMemcpyDtoHAsync_v2)
#define muMemcpyDtoDAsync                   __MUSA_API_PTSZ(muMemcpyDtoDAsync_v2)
#define muMemcpy2DAsync                     __MUSA_API_PTSZ(muMemcpy2DAsync_v2)
#define muMemcpy3DAsync                     __MUSA_API_PTSZ(muMemcpy3DAsync_v2)
#define muMemcpyBatchAsync                  __MUSA_API_PTSZ(muMemcpyBatchAsync)
#define muMemcpy3DBatchAsync                __MUSA_API_PTSZ(muMemcpy3DBatchAsync)
#define muMemsetD8                          __MUSA_API_PTDS(muMemsetD8_v2)
#define muMemsetD16                         __MUSA_API_PTDS(muMemsetD16_v2)
#define muMemsetD32                         __MUSA_API_PTDS(muMemsetD32_v2)
#define muMemsetD2D8                        __MUSA_API_PTDS(muMemsetD2D8_v2)
#define muMemsetD2D16                       __MUSA_API_PTDS(muMemsetD2D16_v2)
#define muMemsetD2D32                       __MUSA_API_PTDS(muMemsetD2D32_v2)
#define muArrayCreate                       muArrayCreate_v2
#define muArrayGetDescriptor                muArrayGetDescriptor_v2
#define muArray3DCreate                     muArray3DCreate_v2
#define muArray3DGetDescriptor              muArray3DGetDescriptor_v2
#define muTexRefSetAddress                  muTexRefSetAddress_v2
#define muTexRefGetAddress                  muTexRefGetAddress_v2
#define muGraphicsResourceGetMappedPointer  muGraphicsResourceGetMappedPointer_v2
#define muCtxDestroy                        muCtxDestroy_v2
#define muCtxPopCurrent                     muCtxPopCurrent_v2
#define muCtxPushCurrent                    muCtxPushCurrent_v2
#define muStreamDestroy                     muStreamDestroy_v2
#define muEventDestroy                      muEventDestroy_v2
#define muTexRefSetAddress2D                muTexRefSetAddress2D_v3
#define muLinkCreate                        muLinkCreate_v2
#define muLinkAddData                       muLinkAddData_v2
#define muLinkAddFile                       muLinkAddFile_v2
#define muMemHostRegister                   muMemHostRegister_v2
#define muGraphicsResourceSetMapFlags       muGraphicsResourceSetMapFlags_v2
#define muStreamBeginCapture                __MUSA_API_PTSZ(muStreamBeginCapture_v2)
#define muDevicePrimaryCtxRelease           muDevicePrimaryCtxRelease_v2
#define muDevicePrimaryCtxReset             muDevicePrimaryCtxReset_v2
#define muDevicePrimaryCtxSetFlags          muDevicePrimaryCtxSetFlags_v2
#define muDeviceGetUuid_v2                  muDeviceGetUuid_v2
#define muIpcOpenMemHandle                  muIpcOpenMemHandle_v2
#define muGraphInstantiate                  muGraphInstantiateWithFlags
#define muGraphExecUpdate                   muGraphExecUpdate_v2
#define muGetProcAddress                    muGetProcAddress_v2
#define muGraphAddKernelNode                muGraphAddKernelNode_v2
#define muGraphKernelNodeGetParams          muGraphKernelNodeGetParams_v2
#define muGraphKernelNodeSetParams          muGraphKernelNodeSetParams_v2
#define muGraphExecKernelNodeSetParams      muGraphExecKernelNodeSetParams_v2
#define muStreamWriteValue32                __MUSA_API_PTSZ(muStreamWriteValue32_v2)
#define muStreamWaitValue32                 __MUSA_API_PTSZ(muStreamWaitValue32_v2)
#define muStreamWriteValue64                __MUSA_API_PTSZ(muStreamWriteValue64_v2)
#define muStreamWaitValue64                 __MUSA_API_PTSZ(muStreamWaitValue64_v2)
#define muStreamBatchMemOp                  __MUSA_API_PTSZ(muStreamBatchMemOp_v2)
#define muStreamGetCaptureInfo              __MUSA_API_PTSZ(muStreamGetCaptureInfo_v2)
#define muStreamGetCaptureInfo_v2           __MUSA_API_PTSZ(muStreamGetCaptureInfo_v2)
#if defined(__MUSA_API_PER_THREAD_DEFAULT_STREAM)
    #define muMemcpy                            __MUSA_API_PTDS(muMemcpy)
    #define muMemcpyAsync                       __MUSA_API_PTSZ(muMemcpyAsync)
    #define muMemcpyPeer                        __MUSA_API_PTDS(muMemcpyPeer)
    #define muMemcpyPeerAsync                   __MUSA_API_PTSZ(muMemcpyPeerAsync)
    #define muMemcpy3DPeer                      __MUSA_API_PTDS(muMemcpy3DPeer)
    #define muMemcpy3DPeerAsync                 __MUSA_API_PTSZ(muMemcpy3DPeerAsync)
    #define muMemPrefetchAsync                  __MUSA_API_PTSZ(muMemPrefetchAsync)
    #define muMemPrefetchAsync_v2               __MUSA_API_PTSZ(muMemPrefetchAsync_v2)
    #define muMemsetD8Async                     __MUSA_API_PTSZ(muMemsetD8Async)
    #define muMemsetD16Async                    __MUSA_API_PTSZ(muMemsetD16Async)
    #define muMemsetD32Async                    __MUSA_API_PTSZ(muMemsetD32Async)
    #define muMemsetD2D8Async                   __MUSA_API_PTSZ(muMemsetD2D8Async)
    #define muMemsetD2D16Async                  __MUSA_API_PTSZ(muMemsetD2D16Async)
    #define muMemsetD2D32Async                  __MUSA_API_PTSZ(muMemsetD2D32Async)
    #define muStreamGetPriority                 __MUSA_API_PTSZ(muStreamGetPriority)
    #define muStreamGetId                       __MUSA_API_PTSZ(muStreamGetId)
    #define muStreamGetFlags                    __MUSA_API_PTSZ(muStreamGetFlags)
    #define muStreamGetDevice                   __MUSA_API_PTSZ(muStreamGetDevice)
    #define muStreamGetCtx                      __MUSA_API_PTSZ(muStreamGetCtx)
    #define muStreamGetCtx_v2                   __MUSA_API_PTSZ(muStreamGetCtx_v2)
    #define muStreamWaitEvent                   __MUSA_API_PTSZ(muStreamWaitEvent)
    #define muStreamEndCapture                  __MUSA_API_PTSZ(muStreamEndCapture)
    #define muStreamIsCapturing                 __MUSA_API_PTSZ(muStreamIsCapturing)
    #define muStreamGetCaptureInfo_v3           __MUSA_API_PTSZ(muStreamGetCaptureInfo_v3)
    #define muStreamUpdateCaptureDependencies   __MUSA_API_PTSZ(muStreamUpdateCaptureDependencies)
    #define muStreamUpdateCaptureDependencies_v2 __MUSA_API_PTSZ(muStreamUpdateCaptureDependencies_v2)
    #define muStreamAddCallback                 __MUSA_API_PTSZ(muStreamAddCallback)
    #define muStreamAttachMemAsync              __MUSA_API_PTSZ(muStreamAttachMemAsync)
    #define muStreamQuery                       __MUSA_API_PTSZ(muStreamQuery)
    #define muStreamSynchronize                 __MUSA_API_PTSZ(muStreamSynchronize)
    #define muEventRecord                       __MUSA_API_PTSZ(muEventRecord)
    #define muEventRecordWithFlags              __MUSA_API_PTSZ(muEventRecordWithFlags)
    #define muLaunchKernel                      __MUSA_API_PTSZ(muLaunchKernel)
    #define muLaunchKernelEx                    __MUSA_API_PTSZ(muLaunchKernelEx)
    #define muLaunchHostFunc                    __MUSA_API_PTSZ(muLaunchHostFunc)
    #define muGraphicsMapResources              __MUSA_API_PTSZ(muGraphicsMapResources)
    #define muGraphicsUnmapResources            __MUSA_API_PTSZ(muGraphicsUnmapResources)
    #define muLaunchCooperativeKernel           __MUSA_API_PTSZ(muLaunchCooperativeKernel)
    #define muSignalExternalSemaphoresAsync     __MUSA_API_PTSZ(muSignalExternalSemaphoresAsync)
    #define muWaitExternalSemaphoresAsync       __MUSA_API_PTSZ(muWaitExternalSemaphoresAsync)
    #define muGraphInstantiateWithParams        __MUSA_API_PTSZ(muGraphInstantiateWithParams)
    #define muGraphUpload                       __MUSA_API_PTSZ(muGraphUpload)
    #define muGraphLaunch                       __MUSA_API_PTSZ(muGraphLaunch)
    #define muStreamCopyAttributes              __MUSA_API_PTSZ(muStreamCopyAttributes)
    #define muStreamGetAttribute                __MUSA_API_PTSZ(muStreamGetAttribute)
    #define muStreamSetAttribute                __MUSA_API_PTSZ(muStreamSetAttribute)
    #define muMemMapArrayAsync                  __MUSA_API_PTSZ(muMemMapArrayAsync)
    #define muMemFreeAsync                      __MUSA_API_PTSZ(muMemFreeAsync)
    #define muMemAllocAsync                     __MUSA_API_PTSZ(muMemAllocAsync)
    #define muMemAllocFromPoolAsync             __MUSA_API_PTSZ(muMemAllocFromPoolAsync)
    #define muStreamBeginCaptureToGraph         __MUSA_API_PTSZ(muStreamBeginCaptureToGraph)
    #define muMemoryTransfer                    __MUSA_API_PTDS(muMemoryTransfer)
    #define muMemoryTransferAsync               __MUSA_API_PTSZ(muMemoryTransferAsync)
#endif
#define muMemBatchDecompressAsync               __MUSA_API_PTSZ(muMemBatchDecompressAsync)
#define MUSA_VERSION 50300
#ifdef __cplusplus
extern "C" {
#endif
#if defined(_WIN64) || defined(__LP64__)
typedef unsigned long long MUdeviceptr_v2;
#else
typedef unsigned int MUdeviceptr_v2;
#endif
typedef MUdeviceptr_v2 MUdeviceptr;
typedef int MUdevice_v1;
typedef MUdevice_v1 MUdevice;
typedef struct MUctx_st *MUcontext;
typedef struct MUmod_st *MUmodule;
typedef struct MUfunc_st *MUfunction;
typedef struct MUlib_st *MUlibrary;
typedef struct MUkern_st *MUkernel;
typedef struct MUarray_st *MUarray;
typedef struct MUmipmappedArray_st *MUmipmappedArray;
typedef struct MUtexref_st *MUtexref;
typedef struct MUsurfref_st *MUsurfref;
typedef struct MUevent_st *MUevent;
typedef struct MUstream_st *MUstream;
typedef struct MUgraphicsResource_st *MUgraphicsResource;
typedef unsigned long long MUtexObject_v1;
typedef MUtexObject_v1 MUtexObject;
typedef unsigned long long MUsurfObject_v1;
typedef MUsurfObject_v1 MUsurfObject;
typedef struct MUextMemory_st *MUexternalMemory;
typedef struct MUextSemaphore_st *MUexternalSemaphore;
typedef struct MUgraph_st *MUgraph;
typedef struct MUgraphNode_st *MUgraphNode;
typedef struct MUgraphExec_st *MUgraphExec;
typedef struct MUmemPoolHandle_st *MUmemoryPool;
typedef struct MUuserObject_st *MUuserObject;
typedef muuint64_t MUgraphConditionalHandle;
typedef struct MUgraphDeviceUpdatableNode_st *MUgraphDeviceNode;
typedef struct MUasyncCallbackEntry_st *MUasyncCallbackHandle;
typedef struct MUgreenCtx_st *MUgreenCtx;
#ifndef MU_UUID_HAS_BEEN_DEFINED
#define MU_UUID_HAS_BEEN_DEFINED
typedef struct MUuuid_st {
    char bytes[16];
} MUuuid;
#endif
#define MU_IPC_HANDLE_SIZE 64
typedef struct MUmemFabricHandle_st {
    unsigned char data[MU_IPC_HANDLE_SIZE];
} MUmemFabricHandle_v1;
typedef MUmemFabricHandle_v1 MUmemFabricHandle;
typedef struct MUipcEventHandle_st {
    char reserved[MU_IPC_HANDLE_SIZE];
} MUipcEventHandle_v1;
typedef MUipcEventHandle_v1 MUipcEventHandle;
typedef struct MUipcMemHandle_st {
    char reserved[MU_IPC_HANDLE_SIZE];
} MUipcMemHandle_v1;
typedef MUipcMemHandle_v1 MUipcMemHandle;
typedef enum MUipcMem_flags_enum {
    MU_IPC_MEM_LAZY_ENABLE_PEER_ACCESS = 0x1,
    MU_IPC_MEM_LAZY_UNIDIR_INTERLEAVE_PEER_ACCESS       = 0x2,
    MU_IPC_MEM_LAZY_BIDIR_INTERLEAVE_PEER_ACCESS        = 0x3,
    MU_IPC_MEM_LAZY_HETERO_INTERLEAVE_PEER_ACCESS       = 0x4,
    MU_IPC_MEM_LAZY_HETERO_BIDIR_INTERLEAVE_PEER_ACCESS = 0x5,
    MU_IPC_MEM_LAZY_HALF_BIDIR_INTERLEAVE_PEER_ACCESS   = 0x6,
    MU_IPC_MEM_LAZY_PCIE_PEER_ACCESS                    = 0x7,
    MU_IPC_MEM_LAZY_POLICY_MAX                          = 0x7
} MUipcMem_flags;
typedef enum MUmemAttach_flags_enum {
    MU_MEM_ATTACH_GLOBAL = 0x1,
    MU_MEM_ATTACH_HOST   = 0x2,
    MU_MEM_ATTACH_SINGLE = 0x4
} MUmemAttach_flags;
typedef enum MUctx_flags_enum {
    MU_CTX_SCHED_AUTO          = 0x00,
    MU_CTX_SCHED_SPIN          = 0x01,
    MU_CTX_SCHED_YIELD         = 0x02,
    MU_CTX_SCHED_BLOCKING_SYNC = 0x04,
    MU_CTX_BLOCKING_SYNC       = 0x04,
    MU_CTX_SCHED_MASK          = 0x07,
    MU_CTX_MAP_HOST            = 0x08,
    MU_CTX_LMEM_RESIZE_TO_MAX  = 0x10,
    MU_CTX_COREDUMP_ENABLE     = 0x20,
    MU_CTX_USER_COREDUMP_ENABLE= 0x40,
    MU_CTX_SYNC_MEMOPS         = 0x80,
    MU_CTX_FLAGS_MASK          = 0xFF
} MUctx_flags;
typedef enum MUevent_sched_flags_enum {
    MU_EVENT_SCHED_AUTO = 0x00,
    MU_EVENT_SCHED_SPIN = 0x01,
    MU_EVENT_SCHED_YIELD = 0x02,
    MU_EVENT_SCHED_BLOCKING_SYNC = 0x04,
} MUevent_sched_flags;
typedef enum cl_event_flags_enum {
    NVCL_EVENT_SCHED_AUTO = 0x00,
    NVCL_EVENT_SCHED_SPIN = 0x01,
    NVCL_EVENT_SCHED_YIELD = 0x02,
    NVCL_EVENT_SCHED_BLOCKING_SYNC = 0x04,
} cl_event_flags;
typedef enum cl_context_flags_enum {
    NVCL_CTX_SCHED_AUTO = 0x00,
    NVCL_CTX_SCHED_SPIN = 0x01,
    NVCL_CTX_SCHED_YIELD = 0x02,
    NVCL_CTX_SCHED_BLOCKING_SYNC = 0x04,
} cl_context_flags;
typedef enum MUhostTaskSyncMode_enum {
    MU_HOST_TASK_BLOCKING = 0x0,
    MU_HOST_TASK_SPINWAIT = 0x1,
} MUhostTaskSyncMode;
typedef enum MUstream_flags_enum {
    MU_STREAM_DEFAULT             = 0x0,
    MU_STREAM_NON_BLOCKING        = 0x1
} MUstream_flags;
#define MU_STREAM_LEGACY     ((MUstream)0x1)
#define MU_STREAM_PER_THREAD ((MUstream)0x2)
typedef enum MUevent_flags_enum {
    MU_EVENT_DEFAULT        = 0x0,
    MU_EVENT_BLOCKING_SYNC  = 0x1,
    MU_EVENT_DISABLE_TIMING = 0x2,
    MU_EVENT_INTERPROCESS   = 0x4
} MUevent_flags;
typedef enum MUevent_record_flags_enum {
    MU_EVENT_RECORD_DEFAULT  = 0x0,
    MU_EVENT_RECORD_EXTERNAL = 0x1
} MUevent_record_flags;
typedef enum MUevent_wait_flags_enum {
    MU_EVENT_WAIT_DEFAULT  = 0x0,
    MU_EVENT_WAIT_EXTERNAL = 0x1
} MUevent_wait_flags;
typedef enum MUatomicOperation_enum {
    MU_ATOMIC_OPERATION_INTEGER_ADD         = 0,
    MU_ATOMIC_OPERATION_INTEGER_MIN         = 1,
    MU_ATOMIC_OPERATION_INTEGER_MAX         = 2,
    MU_ATOMIC_OPERATION_INTEGER_INCREMENT   = 3,
    MU_ATOMIC_OPERATION_INTEGER_DECREMENT   = 4,
    MU_ATOMIC_OPERATION_AND                 = 5,
    MU_ATOMIC_OPERATION_OR                  = 6,
    MU_ATOMIC_OPERATION_XOR                 = 7,
    MU_ATOMIC_OPERATION_EXCHANGE            = 8,
    MU_ATOMIC_OPERATION_CAS                 = 9,
    MU_ATOMIC_OPERATION_FLOAT_ADD           = 10,
    MU_ATOMIC_OPERATION_FLOAT_MIN           = 11,
    MU_ATOMIC_OPERATION_FLOAT_MAX           = 12,
    MU_ATOMIC_OPERATION_MAX
} MUatomicOperation;
typedef enum MUatomicOperationCapability_enum {
    MU_ATOMIC_CAPABILITY_SIGNED         = 1u<<0,
    MU_ATOMIC_CAPABILITY_UNSIGNED       = 1u<<1,
    MU_ATOMIC_CAPABILITY_REDUCTION      = 1u<<2,
    MU_ATOMIC_CAPABILITY_SCALAR_32      = 1u<<3,
    MU_ATOMIC_CAPABILITY_SCALAR_64      = 1u<<4,
    MU_ATOMIC_CAPABILITY_SCALAR_128     = 1u<<5,
    MU_ATOMIC_CAPABILITY_VECTOR_32x4    = 1u<<6
} MUatomicOperationCapability;
typedef enum MUstreamWaitValue_flags_enum {
    MU_STREAM_WAIT_VALUE_GEQ   = 0x0,
    MU_STREAM_WAIT_VALUE_EQ    = 0x1,
    MU_STREAM_WAIT_VALUE_AND   = 0x2,
    MU_STREAM_WAIT_VALUE_NOR   = 0x3,
    MU_STREAM_WAIT_VALUE_LT    = 0x4,
    MU_STREAM_WAIT_VALUE_LEQ   = 0x5,
    MU_STREAM_WAIT_VALUE_GT    = 0x6,
    MU_STREAM_WAIT_VALUE_NEQ   = 0x7,
    MU_STREAM_WAIT_VALUE_FLUSH = 1<<30
} MUstreamWaitValue_flags;
typedef enum MUstreamWriteValue_flags_enum {
    MU_STREAM_WRITE_VALUE_DEFAULT           = 0x0,
    MU_STREAM_WRITE_VALUE_NO_MEMORY_BARRIER = 0x1
} MUstreamWriteValue_flags;
typedef enum MUstreamBatchMemOpType_enum {
    MU_STREAM_MEM_OP_WAIT_VALUE_32  = 1,
    MU_STREAM_MEM_OP_WRITE_VALUE_32 = 2,
    MU_STREAM_MEM_OP_WAIT_VALUE_64  = 4,
    MU_STREAM_MEM_OP_WRITE_VALUE_64 = 5,
    MU_STREAM_MEM_OP_BARRIER = 6,
    MU_STREAM_MEM_OP_FLUSH_REMOTE_WRITES = 3
} MUstreamBatchMemOpType;
typedef enum MUstreamMemoryBarrier_flags_enum {
    MU_STREAM_MEMORY_BARRIER_TYPE_SYS = 0x0,
    MU_STREAM_MEMORY_BARRIER_TYPE_GPU = 0x1
} MUstreamMemoryBarrier_flags;
typedef enum MUstreamAtomicReductionOpType_enum {
    MU_STREAM_ATOMIC_REDUCTION_OP_OR =  MU_ATOMIC_OPERATION_OR,
    MU_STREAM_ATOMIC_REDUCTION_OP_AND = MU_ATOMIC_OPERATION_AND,
    MU_STREAM_ATOMIC_REDUCTION_OP_ADD = MU_ATOMIC_OPERATION_INTEGER_ADD,
} MUstreamAtomicReductionOpType;
typedef enum MUstreamAtomicReductionDataType_enum {
    MU_STREAM_ATOMIC_REDUCTION_UNSIGNED_32 = MU_ATOMIC_CAPABILITY_UNSIGNED | MU_ATOMIC_CAPABILITY_SCALAR_32 | MU_ATOMIC_CAPABILITY_REDUCTION,
    MU_STREAM_ATOMIC_REDUCTION_UNSIGNED_64 = MU_ATOMIC_CAPABILITY_UNSIGNED | MU_ATOMIC_CAPABILITY_SCALAR_64 | MU_ATOMIC_CAPABILITY_REDUCTION,
} MUstreamAtomicReductionDataType;
typedef union MUstreamBatchMemOpParams_union {
    MUstreamBatchMemOpType operation;
    struct MUstreamMemOpWaitValueParams_st {
        MUstreamBatchMemOpType operation;
        MUdeviceptr address;
        union {
            muuint32_t value;
            muuint64_t value64;
        };
        unsigned int flags;
        MUdeviceptr alias;
    } waitValue;
    struct MUstreamMemOpWriteValueParams_st {
        MUstreamBatchMemOpType operation;
        MUdeviceptr address;
        union {
            muuint32_t value;
            muuint64_t value64;
        };
        unsigned int flags;
        MUdeviceptr alias;
    } writeValue;
    struct MUstreamMemOpFlushRemoteWritesParams_st {
        MUstreamBatchMemOpType operation;
        unsigned int flags;
    } flushRemoteWrites;
    struct MUstreamMemOpMemoryBarrierParams_st {
        MUstreamBatchMemOpType operation;
        unsigned int flags;
    } memoryBarrier;
    struct MUstreamMemOpAtomicReductionParams_st {
        MUstreamBatchMemOpType operation;
        unsigned int flags;
        MUstreamAtomicReductionOpType reductionOp;
        MUstreamAtomicReductionDataType dataType;
        MUdeviceptr address;
        muuint64_t value;
        MUdeviceptr alias;
    } atomicReduction;
    muuint64_t pad[6];
} MUstreamBatchMemOpParams_v1;
typedef MUstreamBatchMemOpParams_v1 MUstreamBatchMemOpParams;
typedef struct MUSA_BATCH_MEM_OP_NODE_PARAMS_v1_st {
    MUcontext ctx;
    unsigned int count;
    MUstreamBatchMemOpParams *paramArray;
    unsigned int flags;
} MUSA_BATCH_MEM_OP_NODE_PARAMS_v1;
typedef MUSA_BATCH_MEM_OP_NODE_PARAMS_v1 MUSA_BATCH_MEM_OP_NODE_PARAMS;
typedef struct MUSA_BATCH_MEM_OP_NODE_PARAMS_v2_st {
    MUcontext ctx;
    unsigned int count;
    MUstreamBatchMemOpParams *paramArray;
    unsigned int flags;
} MUSA_BATCH_MEM_OP_NODE_PARAMS_v2;
typedef enum MUoccupancy_flags_enum {
    MU_OCCUPANCY_DEFAULT                  = 0x0,
    MU_OCCUPANCY_DISABLE_CACHING_OVERRIDE = 0x1
} MUoccupancy_flags;
typedef enum MUstreamUpdateCaptureDependencies_flags_enum {
    MU_STREAM_ADD_CAPTURE_DEPENDENCIES = 0x0,
    MU_STREAM_SET_CAPTURE_DEPENDENCIES = 0x1
} MUstreamUpdateCaptureDependencies_flags;
typedef enum MUasyncNotificationType_enum {
    MU_ASYNC_NOTIFICATION_TYPE_DEFAULT,
    MU_ASYNC_NOTIFICATION_TYPE_OVER_BUDGET = 0x1
} MUasyncNotificationType;
typedef struct MUasyncNotificationInfo_st {
    MUasyncNotificationType type;
    union {
        struct {
            unsigned long long bytesOverBudget;
        } overBudget;
    } info;
} MUasyncNotificationInfo;
typedef void (*MUasyncCallback)(MUasyncNotificationInfo *info, void *userData, MUasyncCallbackHandle callback);
typedef enum MUarray_format_enum {
    MU_AD_FORMAT_UNSIGNED_INT8            = 0x01,
    MU_AD_FORMAT_UNSIGNED_INT16           = 0x02,
    MU_AD_FORMAT_UNSIGNED_INT32           = 0x03,
    MU_AD_FORMAT_SIGNED_INT8              = 0x08,
    MU_AD_FORMAT_SIGNED_INT16             = 0x09,
    MU_AD_FORMAT_SIGNED_INT32             = 0x0a,
    MU_AD_FORMAT_HALF                     = 0x10,
    MU_AD_FORMAT_FLOAT                    = 0x20,
    MU_AD_FORMAT_NV12                     = 0xb0,
    MU_AD_FORMAT_UNORM_INT8X1             = 0xc0,
    MU_AD_FORMAT_UNORM_INT8X2             = 0xc1,
    MU_AD_FORMAT_UNORM_INT8X4             = 0xc2,
    MU_AD_FORMAT_UNORM_INT16X1            = 0xc3,
    MU_AD_FORMAT_UNORM_INT16X2            = 0xc4,
    MU_AD_FORMAT_UNORM_INT16X4            = 0xc5,
    MU_AD_FORMAT_SNORM_INT8X1             = 0xc6,
    MU_AD_FORMAT_SNORM_INT8X2             = 0xc7,
    MU_AD_FORMAT_SNORM_INT8X4             = 0xc8,
    MU_AD_FORMAT_SNORM_INT16X1            = 0xc9,
    MU_AD_FORMAT_SNORM_INT16X2            = 0xca,
    MU_AD_FORMAT_SNORM_INT16X4            = 0xcb,
    MU_AD_FORMAT_BC1_UNORM                = 0x91,
    MU_AD_FORMAT_BC1_UNORM_SRGB           = 0x92,
    MU_AD_FORMAT_BC2_UNORM                = 0x93,
    MU_AD_FORMAT_BC2_UNORM_SRGB           = 0x94,
    MU_AD_FORMAT_BC3_UNORM                = 0x95,
    MU_AD_FORMAT_BC3_UNORM_SRGB           = 0x96,
    MU_AD_FORMAT_BC4_UNORM                = 0x97,
    MU_AD_FORMAT_BC4_SNORM                = 0x98,
    MU_AD_FORMAT_BC5_UNORM                = 0x99,
    MU_AD_FORMAT_BC5_SNORM                = 0x9a,
    MU_AD_FORMAT_BC6H_UF16                = 0x9b,
    MU_AD_FORMAT_BC6H_SF16                = 0x9c,
    MU_AD_FORMAT_BC7_UNORM                = 0x9d,
    MU_AD_FORMAT_BC7_UNORM_SRGB           = 0x9e,
    MU_AD_FORMAT_P010                     = 0x9f,
    MU_AD_FORMAT_P016                     = 0xa1,
    MU_AD_FORMAT_NV16                     = 0xa2,
    MU_AD_FORMAT_P210                     = 0xa3,
    MU_AD_FORMAT_P216                     = 0xa4,
    MU_AD_FORMAT_YUY2                     = 0xa5,
    MU_AD_FORMAT_Y210                     = 0xa6,
    MU_AD_FORMAT_Y216                     = 0xa7,
    MU_AD_FORMAT_AYUV                     = 0xa8,
    MU_AD_FORMAT_Y410                     = 0xa9,
    MU_AD_FORMAT_Y416                     = 0xb1,
    MU_AD_FORMAT_Y444_PLANAR8             = 0xb2,
    MU_AD_FORMAT_Y444_PLANAR10            = 0xb3,
    MU_AD_FORMAT_YUV444_8bit_SemiPlanar   = 0xb4,
    MU_AD_FORMAT_YUV444_16bit_SemiPlanar  = 0xb5,
    MU_AD_FORMAT_UNORM_INT_101010_2       = 0x50,
    MU_AD_FORMAT_UINT8_PACKED_422         = 0x51,
    MU_AD_FORMAT_UINT8_PACKED_444         = 0x52,
    MU_AD_FORMAT_UINT8_SEMIPLANAR_420     = 0x53,
    MU_AD_FORMAT_UINT16_SEMIPLANAR_420    = 0x54,
    MU_AD_FORMAT_UINT8_SEMIPLANAR_422     = 0x55,
    MU_AD_FORMAT_UINT16_SEMIPLANAR_422    = 0x56,
    MU_AD_FORMAT_UINT8_SEMIPLANAR_444     = 0x57,
    MU_AD_FORMAT_UINT16_SEMIPLANAR_444    = 0x58,
    MU_AD_FORMAT_UINT8_PLANAR_420         = 0x59,
    MU_AD_FORMAT_UINT16_PLANAR_420        = 0x5a,
    MU_AD_FORMAT_UINT8_PLANAR_422         = 0x5b,
    MU_AD_FORMAT_UINT16_PLANAR_422        = 0x5c,
    MU_AD_FORMAT_UINT8_PLANAR_444         = 0x5d,
    MU_AD_FORMAT_UINT16_PLANAR_444        = 0x5e,
    MU_AD_FORMAT_MAX                      = 0x7FFFFFFF
} MUarray_format;
typedef enum MUaddress_mode_enum {
    MU_TR_ADDRESS_MODE_WRAP   = 0,
    MU_TR_ADDRESS_MODE_CLAMP  = 1,
    MU_TR_ADDRESS_MODE_MIRROR = 2,
    MU_TR_ADDRESS_MODE_BORDER = 3
} MUaddress_mode;
typedef enum MUfilter_mode_enum {
    MU_TR_FILTER_MODE_POINT  = 0,
    MU_TR_FILTER_MODE_LINEAR = 1
} MUfilter_mode;

#define MU_TRSA_OVERRIDE_FORMAT             0x01
#define MU_TRSF_READ_AS_INTEGER             0x01
#define MU_TRSF_NORMALIZED_COORDINATES      0x02
#define MU_TRSF_SRGB                        0x10
#define MU_TRSF_DISABLE_TRILINEAR_OPTIMIZATION 0x20
#define MU_TRSF_SEAMLESS_CUBEMAP            0x40

typedef enum MUdevice_attribute_enum {
    MU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
    MU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X = 2,
    MU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y = 3,
    MU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z = 4,
    MU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X = 5,
    MU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y = 6,
    MU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z = 7,
    MU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK = 8,
    MU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
    MU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY = 9,
    MU_DEVICE_ATTRIBUTE_WARP_SIZE = 10,
    MU_DEVICE_ATTRIBUTE_MAX_PITCH = 11,
    MU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK = 12,
    MU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
    MU_DEVICE_ATTRIBUTE_CLOCK_RATE = 13,
    MU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT = 14,
    MU_DEVICE_ATTRIBUTE_GPU_OVERLAP = 15,
    MU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT = 16,
    MU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT = 17,
    MU_DEVICE_ATTRIBUTE_INTEGRATED = 18,
    MU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY = 19,
    MU_DEVICE_ATTRIBUTE_COMPUTE_MODE = 20,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH = 21,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH = 22,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT = 23,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH = 24,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT = 25,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH = 26,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH = 27,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT = 28,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS = 29,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH = 27,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT = 28,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES = 29,
    MU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT = 30,
    MU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS = 31,
    MU_DEVICE_ATTRIBUTE_ECC_ENABLED = 32,
    MU_DEVICE_ATTRIBUTE_PCI_BUS_ID = 33,
    MU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID = 34,
    MU_DEVICE_ATTRIBUTE_TCC_DRIVER = 35,
    MU_DEVICE_ATTRIBUTE_MEMORY_CLOCK_RATE = 36,
    MU_DEVICE_ATTRIBUTE_GLOBAL_MEMORY_BUS_WIDTH = 37,
    MU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE = 38,
    MU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_MULTIPROCESSOR = 39,
    MU_DEVICE_ATTRIBUTE_ASYNC_ENGINE_COUNT = 40,
    MU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING = 41,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_WIDTH = 42,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_LAYERS = 43,
    MU_DEVICE_ATTRIBUTE_CAN_TEX2D_GATHER = 44,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_WIDTH = 45,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_HEIGHT = 46,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH_ALTERNATE = 47,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT_ALTERNATE = 48,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH_ALTERNATE = 49,
    MU_DEVICE_ATTRIBUTE_PCI_DOMAIN_ID = 50,
    MU_DEVICE_ATTRIBUTE_TEXTURE_PITCH_ALIGNMENT = 51,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_WIDTH = 52,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_WIDTH = 53,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_LAYERS = 54,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_WIDTH = 55,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_WIDTH = 56,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_HEIGHT = 57,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_WIDTH = 58,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_HEIGHT = 59,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_DEPTH = 60,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_WIDTH = 61,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_LAYERS = 62,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_WIDTH = 63,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_HEIGHT = 64,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_LAYERS = 65,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_WIDTH = 66,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_WIDTH = 67,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_LAYERS = 68,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LINEAR_WIDTH = 69,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_WIDTH = 70,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_HEIGHT = 71,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_PITCH = 72,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_WIDTH = 73,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_HEIGHT = 74,
    MU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MAJOR = 75,
    MU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MINOR = 76,
    MU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_MIPMAPPED_WIDTH = 77,
    MU_DEVICE_ATTRIBUTE_STREAM_PRIORITIES_SUPPORTED = 78,
    MU_DEVICE_ATTRIBUTE_GLOBAL_L1_CACHE_SUPPORTED = 79,
    MU_DEVICE_ATTRIBUTE_LOCAL_L1_CACHE_SUPPORTED = 80,
    MU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_MULTIPROCESSOR = 81,
    MU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_MULTIPROCESSOR = 82,
    MU_DEVICE_ATTRIBUTE_MANAGED_MEMORY = 83,
    MU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD = 84,
    MU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD_GROUP_ID = 85,
    MU_DEVICE_ATTRIBUTE_HOST_NATIVE_ATOMIC_SUPPORTED = 86,
    MU_DEVICE_ATTRIBUTE_SINGLE_TO_DOUBLE_PRECISION_PERF_RATIO = 87,
    MU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS = 88,
    MU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS = 89,
    MU_DEVICE_ATTRIBUTE_COMPUTE_PREEMPTION_SUPPORTED = 90,
    MU_DEVICE_ATTRIBUTE_CAN_USE_HOST_POINTER_FOR_REGISTERED_MEM = 91,
    MU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_MEM_OPS_V1 = 92,
    MU_DEVICE_ATTRIBUTE_CAN_USE_64_BIT_STREAM_MEM_OPS_V1 = 93,
    MU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_WAIT_VALUE_NOR_V1 = 94,
    MU_DEVICE_ATTRIBUTE_COOPERATIVE_LAUNCH = 95,
    MU_DEVICE_ATTRIBUTE_COOPERATIVE_MULTI_DEVICE_LAUNCH = 96,
    MU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK_OPTIN = 97,
    MU_DEVICE_ATTRIBUTE_CAN_FLUSH_REMOTE_WRITES = 98,
    MU_DEVICE_ATTRIBUTE_HOST_REGISTER_SUPPORTED = 99,
    MU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS_USES_HOST_PAGE_TABLES = 100,
    MU_DEVICE_ATTRIBUTE_DIRECT_MANAGED_MEM_ACCESS_FROM_HOST = 101,
    MU_DEVICE_ATTRIBUTE_VIRTUAL_ADDRESS_MANAGEMENT_SUPPORTED = 102,
    MU_DEVICE_ATTRIBUTE_VIRTUAL_MEMORY_MANAGEMENT_SUPPORTED = 102,
    MU_DEVICE_ATTRIBUTE_HANDLE_TYPE_POSIX_FILE_DESCRIPTOR_SUPPORTED = 103,
    MU_DEVICE_ATTRIBUTE_HANDLE_TYPE_WIN32_HANDLE_SUPPORTED = 104,
    MU_DEVICE_ATTRIBUTE_HANDLE_TYPE_WIN32_KMT_HANDLE_SUPPORTED = 105,
    MU_DEVICE_ATTRIBUTE_MAX_BLOCKS_PER_MULTIPROCESSOR = 106,
    MU_DEVICE_ATTRIBUTE_GENERIC_COMPRESSION_SUPPORTED = 107,
    MU_DEVICE_ATTRIBUTE_MAX_PERSISTING_L2_CACHE_SIZE = 108,
    MU_DEVICE_ATTRIBUTE_MAX_ACCESS_POLICY_WINDOW_SIZE = 109,
    MU_DEVICE_ATTRIBUTE_GPU_DIRECT_RDMA_WITH_MUSA_VMM_SUPPORTED = 110,
    MU_DEVICE_ATTRIBUTE_RESERVED_SHARED_MEMORY_PER_BLOCK = 111,
    MU_DEVICE_ATTRIBUTE_SPARSE_MUSA_ARRAY_SUPPORTED = 112,
    MU_DEVICE_ATTRIBUTE_READ_ONLY_HOST_REGISTER_SUPPORTED = 113,
    MU_DEVICE_ATTRIBUTE_TIMELINE_SEMAPHORE_INTEROP_SUPPORTED = 114,
    MU_DEVICE_ATTRIBUTE_MEMORY_POOLS_SUPPORTED = 115,
    MU_DEVICE_ATTRIBUTE_GPU_DIRECT_RDMA_SUPPORTED = 116,
    MU_DEVICE_ATTRIBUTE_GPU_DIRECT_RDMA_FLUSH_WRITES_OPTIONS = 117,
    MU_DEVICE_ATTRIBUTE_GPU_DIRECT_RDMA_WRITES_ORDERING = 118,
    MU_DEVICE_ATTRIBUTE_MEMPOOL_SUPPORTED_HANDLE_TYPES = 119,
    MU_DEVICE_ATTRIBUTE_CLUSTER_LAUNCH = 120,
    MU_DEVICE_ATTRIBUTE_DEFERRED_MAPPING_MUSA_ARRAY_SUPPORTED = 121,
    MU_DEVICE_ATTRIBUTE_CAN_USE_64_BIT_STREAM_MEM_OPS = 122,
    MU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_WAIT_VALUE_NOR = 123,
    MU_DEVICE_ATTRIBUTE_DMA_BUF_SUPPORTED = 124,
    MU_DEVICE_ATTRIBUTE_IPC_EVENT_SUPPORTED = 125,
    MU_DEVICE_ATTRIBUTE_MEM_SYNC_DOMAIN_COUNT = 126,
    MU_DEVICE_ATTRIBUTE_TENSOR_MAP_ACCESS_SUPPORTED = 127,
    MU_DEVICE_ATTRIBUTE_HANDLE_TYPE_FABRIC_SUPPORTED = 128,
    MU_DEVICE_ATTRIBUTE_UNIFIED_FUNCTION_POINTERS = 129,
    MU_DEVICE_ATTRIBUTE_NUMA_CONFIG = 130,
    MU_DEVICE_ATTRIBUTE_NUMA_ID = 131,
    MU_DEVICE_ATTRIBUTE_MULTICAST_SUPPORTED = 132,
    MU_DEVICE_ATTRIBUTE_MPS_ENABLED = 133,
    MU_DEVICE_ATTRIBUTE_HOST_NUMA_ID = 134,
    MU_DEVICE_ATTRIBUTE_D3D12_CIG_SUPPORTED = 135,
    MU_DEVICE_ATTRIBUTE_MEM_DECOMPRESS_ALGORITHM_MASK = 136,
    MU_DEVICE_ATTRIBUTE_MEM_DECOMPRESS_MAXIMUM_LENGTH = 137,
    MU_DEVICE_ATTRIBUTE_VULKAN_CIG_SUPPORTED = 138,
    MU_DEVICE_ATTRIBUTE_GPU_PCI_DEVICE_ID    = 139,
    MU_DEVICE_ATTRIBUTE_GPU_PCI_SUBSYSTEM_ID = 140,
    MU_DEVICE_ATTRIBUTE_HOST_NUMA_VIRTUAL_MEMORY_MANAGEMENT_SUPPORTED = 141,
    MU_DEVICE_ATTRIBUTE_HOST_NUMA_MEMORY_POOLS_SUPPORTED = 142,
    MU_DEVICE_ATTRIBUTE_HOST_NUMA_MULTINODE_IPC_SUPPORTED = 143,
    MU_DEVICE_ATTRIBUTE_HOST_MEMORY_POOLS_SUPPORTED = 144,
    MU_DEVICE_ATTRIBUTE_HOST_VIRTUAL_MEMORY_MANAGEMENT_SUPPORTED = 145,
    MU_DEVICE_ATTRIBUTE_HOST_ALLOC_DMA_BUF_SUPPORTED = 146,
    MU_DEVICE_ATTRIBUTE_ONLY_PARTIAL_HOST_NATIVE_ATOMIC_SUPPORTED = 147,
    MU_DEVICE_ATTRIBUTE_ATOMIC_REDUCTION_SUPPORTED = 148,
    MU_DEVICE_ATTRIBUTE_MAX
} MUdevice_attribute;
typedef struct MUdevprop_st {
    int maxThreadsPerBlock;
    int maxThreadsDim[3];
    int maxGridSize[3];
    int sharedMemPerBlock;
    int totalConstantMemory;
    int SIMDWidth;
    int memPitch;
    int regsPerBlock;
    int clockRate;
    int textureAlign;
} MUdevprop_v1;
typedef MUdevprop_v1 MUdevprop;
typedef enum MUpointer_attribute_enum {
    MU_POINTER_ATTRIBUTE_CONTEXT = 1,
    MU_POINTER_ATTRIBUTE_MEMORY_TYPE = 2,
    MU_POINTER_ATTRIBUTE_DEVICE_POINTER = 3,
    MU_POINTER_ATTRIBUTE_HOST_POINTER = 4,
    MU_POINTER_ATTRIBUTE_P2P_TOKENS = 5,
    MU_POINTER_ATTRIBUTE_SYNC_MEMOPS = 6,
    MU_POINTER_ATTRIBUTE_BUFFER_ID = 7,
    MU_POINTER_ATTRIBUTE_IS_MANAGED = 8,
    MU_POINTER_ATTRIBUTE_DEVICE_ORDINAL = 9,
    MU_POINTER_ATTRIBUTE_IS_LEGACY_MUSA_IPC_CAPABLE = 10,
    MU_POINTER_ATTRIBUTE_RANGE_START_ADDR = 11,
    MU_POINTER_ATTRIBUTE_RANGE_SIZE = 12,
    MU_POINTER_ATTRIBUTE_MAPPED = 13,
    MU_POINTER_ATTRIBUTE_ALLOWED_HANDLE_TYPES = 14,
    MU_POINTER_ATTRIBUTE_IS_GPU_DIRECT_RDMA_CAPABLE = 15,
    MU_POINTER_ATTRIBUTE_ACCESS_FLAGS = 16,
    MU_POINTER_ATTRIBUTE_MEMPOOL_HANDLE = 17,
    MU_POINTER_ATTRIBUTE_MAPPING_SIZE = 18,
    MU_POINTER_ATTRIBUTE_MAPPING_BASE_ADDR = 19,
    MU_POINTER_ATTRIBUTE_MEMORY_BLOCK_ID = 20
  , MU_POINTER_ATTRIBUTE_IS_HW_DECOMPRESS_CAPABLE = 21
} MUpointer_attribute;
typedef enum MUfunction_attribute_enum {
    MU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 0,
    MU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES = 1,
    MU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES = 2,
    MU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES = 3,
    MU_FUNC_ATTRIBUTE_NUM_REGS = 4,
    MU_FUNC_ATTRIBUTE_PTX_VERSION = 5,
    MU_FUNC_ATTRIBUTE_BINARY_VERSION = 6,
    MU_FUNC_ATTRIBUTE_CACHE_MODE_CA = 7,
    MU_FUNC_ATTRIBUTE_MAX_DYNAMIC_SHARED_SIZE_BYTES = 8,
    MU_FUNC_ATTRIBUTE_PREFERRED_SHARED_MEMORY_CARVEOUT = 9,
    MU_FUNC_ATTRIBUTE_CLUSTER_SIZE_MUST_BE_SET = 10,
    MU_FUNC_ATTRIBUTE_REQUIRED_CLUSTER_WIDTH = 11,
    MU_FUNC_ATTRIBUTE_REQUIRED_CLUSTER_HEIGHT = 12,
    MU_FUNC_ATTRIBUTE_REQUIRED_CLUSTER_DEPTH = 13,
    MU_FUNC_ATTRIBUTE_NON_PORTABLE_CLUSTER_SIZE_ALLOWED = 14,
    MU_FUNC_ATTRIBUTE_CLUSTER_SCHEDULING_POLICY_PREFERENCE = 15,
    MU_FUNC_ATTRIBUTE_MAX
} MUfunction_attribute;
typedef enum MUfunc_cache_enum {
    MU_FUNC_CACHE_PREFER_NONE    = 0x00,
    MU_FUNC_CACHE_PREFER_SHARED  = 0x01,
    MU_FUNC_CACHE_PREFER_L1      = 0x02,
    MU_FUNC_CACHE_PREFER_EQUAL   = 0x03
} MUfunc_cache;
typedef enum MUsharedconfig_enum {
    MU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE    = 0x00,
    MU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE  = 0x01,
    MU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE = 0x02
} MUsharedconfig;
typedef enum MUshared_carveout_enum {
    MU_SHAREDMEM_CARVEOUT_DEFAULT       = -1,
    MU_SHAREDMEM_CARVEOUT_MAX_SHARED    = 100,
    MU_SHAREDMEM_CARVEOUT_MAX_L1        = 0
} MUshared_carveout;
typedef enum MUmemorytype_enum {
    MU_MEMORYTYPE_HOST    = 0x01,
    MU_MEMORYTYPE_DEVICE  = 0x02,
    MU_MEMORYTYPE_ARRAY   = 0x03,
    MU_MEMORYTYPE_UNIFIED = 0x04
} MUmemorytype;
typedef enum MUcomputemode_enum {
    MU_COMPUTEMODE_DEFAULT           = 0,
    MU_COMPUTEMODE_PROHIBITED        = 2,
    MU_COMPUTEMODE_EXCLUSIVE_PROCESS = 3
} MUcomputemode;
typedef enum MUmem_advise_enum {
    MU_MEM_ADVISE_SET_READ_MOSTLY          = 1,
    MU_MEM_ADVISE_UNSET_READ_MOSTLY        = 2,
    MU_MEM_ADVISE_SET_PREFERRED_LOCATION   = 3,
    MU_MEM_ADVISE_UNSET_PREFERRED_LOCATION = 4,
    MU_MEM_ADVISE_SET_ACCESSED_BY          = 5,
    MU_MEM_ADVISE_UNSET_ACCESSED_BY        = 6
} MUmem_advise;
typedef enum MUmem_range_attribute_enum {
    MU_MEM_RANGE_ATTRIBUTE_READ_MOSTLY                 = 1,
    MU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION          = 2,
    MU_MEM_RANGE_ATTRIBUTE_ACCESSED_BY                 = 3,
    MU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION      = 4
    , MU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION_TYPE     = 5
    , MU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION_ID       = 6
    , MU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION_TYPE = 7
    , MU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION_ID   = 8
} MUmem_range_attribute;
typedef enum MUjit_option_enum
{
    MU_JIT_MAX_REGISTERS = 0,
    MU_JIT_THREADS_PER_BLOCK = 1,
    MU_JIT_WALL_TIME = 2,
    MU_JIT_INFO_LOG_BUFFER = 3,
    MU_JIT_INFO_LOG_BUFFER_SIZE_BYTES = 4,
    MU_JIT_ERROR_LOG_BUFFER = 5,
    MU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES = 6,
    MU_JIT_OPTIMIZATION_LEVEL = 7,
    MU_JIT_TARGET_FROM_MUCONTEXT = 8,
    MU_JIT_TARGET = 9,
    MU_JIT_FALLBACK_STRATEGY = 10,
    MU_JIT_GENERATE_DEBUG_INFO = 11,
    MU_JIT_LOG_VERBOSE = 12,
    MU_JIT_GENERATE_LINE_INFO = 13,
    MU_JIT_CACHE_MODE = 14,
    MU_JIT_NEW_SM3X_OPT = 15,
    MU_JIT_FAST_COMPILE = 16,
    MU_JIT_GLOBAL_SYMBOL_NAMES = 17,
    MU_JIT_GLOBAL_SYMBOL_ADDRESSES = 18,
    MU_JIT_GLOBAL_SYMBOL_COUNT = 19,
    MU_JIT_LTO = 20,
    MU_JIT_FTZ = 21,
    MU_JIT_PREC_DIV = 22,
    MU_JIT_PREC_SQRT = 23,
    MU_JIT_FMA = 24,
    MU_JIT_REFERENCED_KERNEL_NAMES = 25,
    MU_JIT_REFERENCED_KERNEL_COUNT = 26,
    MU_JIT_REFERENCED_VARIABLE_NAMES = 27,
    MU_JIT_REFERENCED_VARIABLE_COUNT = 28,
    MU_JIT_OPTIMIZE_UNUSED_DEVICE_VARIABLES = 29,
    MU_JIT_POSITION_INDEPENDENT_CODE = 30,
    MU_JIT_MIN_CTA_PER_SM = 31,
    MU_JIT_MAX_THREADS_PER_BLOCK = 32,
    MU_JIT_OVERRIDE_DIRECTIVE_VALUES = 33,
    MU_JIT_SPLIT_COMPILE = 34,
    MU_JIT_BINARY_LOADER_THREAD_COUNT = 35,
    MU_JIT_NUM_OPTIONS
} MUjit_option;
#define MU_COMPUTE_ACCELERATED_TARGET_BASE   0x10000
#define MU_COMPUTE_FAMILY_TARGET_BASE 0x20000
typedef enum MUjit_target_enum
{
    MU_TARGET_COMPUTE_30 = 30,
    MU_TARGET_COMPUTE_32 = 32,
    MU_TARGET_COMPUTE_35 = 35,
    MU_TARGET_COMPUTE_37 = 37,
    MU_TARGET_COMPUTE_50 = 50,
    MU_TARGET_COMPUTE_52 = 52,
    MU_TARGET_COMPUTE_53 = 53,
    MU_TARGET_COMPUTE_60 = 60,
    MU_TARGET_COMPUTE_61 = 61,
    MU_TARGET_COMPUTE_62 = 62,
    MU_TARGET_COMPUTE_70 = 70,
    MU_TARGET_COMPUTE_72 = 72,
    MU_TARGET_COMPUTE_75 = 75,
    MU_TARGET_COMPUTE_80 = 80,
    MU_TARGET_COMPUTE_86 = 86,
    MU_TARGET_COMPUTE_87 = 87,
    MU_TARGET_COMPUTE_89 = 89,
    MU_TARGET_COMPUTE_90 = 90,
    MU_TARGET_COMPUTE_100 = 100,
    MU_TARGET_COMPUTE_101 = 101,
    MU_TARGET_COMPUTE_110 = 110,
    MU_TARGET_COMPUTE_103 = 103,
    MU_TARGET_COMPUTE_120 = 120,
    MU_TARGET_COMPUTE_121 = 121,
    MU_TARGET_COMPUTE_90A = MU_COMPUTE_ACCELERATED_TARGET_BASE + MU_TARGET_COMPUTE_90,
    MU_TARGET_COMPUTE_100A = MU_COMPUTE_ACCELERATED_TARGET_BASE + MU_TARGET_COMPUTE_100,
    MU_TARGET_COMPUTE_110A = MU_COMPUTE_ACCELERATED_TARGET_BASE + MU_TARGET_COMPUTE_110,
    MU_TARGET_COMPUTE_103A = MU_COMPUTE_ACCELERATED_TARGET_BASE + MU_TARGET_COMPUTE_103,
    MU_TARGET_COMPUTE_120A = MU_COMPUTE_ACCELERATED_TARGET_BASE + MU_TARGET_COMPUTE_120,
    MU_TARGET_COMPUTE_121A = MU_COMPUTE_ACCELERATED_TARGET_BASE + MU_TARGET_COMPUTE_121,
    MU_TARGET_COMPUTE_100F = MU_COMPUTE_FAMILY_TARGET_BASE + MU_TARGET_COMPUTE_100,
    MU_TARGET_COMPUTE_110F = MU_COMPUTE_FAMILY_TARGET_BASE + MU_TARGET_COMPUTE_110,
    MU_TARGET_COMPUTE_103F = MU_COMPUTE_FAMILY_TARGET_BASE + MU_TARGET_COMPUTE_103,
    MU_TARGET_COMPUTE_120F = MU_COMPUTE_FAMILY_TARGET_BASE + MU_TARGET_COMPUTE_120,
    MU_TARGET_COMPUTE_121F = MU_COMPUTE_FAMILY_TARGET_BASE + MU_TARGET_COMPUTE_121,
} MUjit_target;
typedef enum MUjit_fallback_enum
{
    MU_PREFER_PTX = 0,
    MU_PREFER_BINARY
} MUjit_fallback;
typedef enum MUjit_cacheMode_enum
{
    MU_JIT_CACHE_OPTION_NONE = 0,
    MU_JIT_CACHE_OPTION_CG,
    MU_JIT_CACHE_OPTION_CA
} MUjit_cacheMode;
typedef enum MUjitInputType_enum
{
    MU_JIT_INPUT_MUBIN = 0,
    MU_JIT_INPUT_PTX = 1,
    MU_JIT_INPUT_FATBINARY = 2,
    MU_JIT_INPUT_OBJECT = 3,
    MU_JIT_INPUT_LIBRARY = 4,
    MU_JIT_INPUT_NVVM = 5,
    MU_JIT_NUM_INPUT_TYPES = 6
} MUjitInputType;
typedef struct MUlinkState_st *MUlinkState;
typedef enum MUgraphicsRegisterFlags_enum {
    MU_GRAPHICS_REGISTER_FLAGS_NONE           = 0x00,
    MU_GRAPHICS_REGISTER_FLAGS_READ_ONLY      = 0x01,
    MU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD  = 0x02,
    MU_GRAPHICS_REGISTER_FLAGS_SURFACE_LDST   = 0x04,
    MU_GRAPHICS_REGISTER_FLAGS_TEXTURE_GATHER = 0x08
} MUgraphicsRegisterFlags;
typedef enum MUgraphicsMapResourceFlags_enum {
    MU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE          = 0x00,
    MU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY     = 0x01,
    MU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD = 0x02
} MUgraphicsMapResourceFlags;
typedef enum MUarray_cubemap_face_enum {
    MU_CUBEMAP_FACE_POSITIVE_X  = 0x00,
    MU_CUBEMAP_FACE_NEGATIVE_X  = 0x01,
    MU_CUBEMAP_FACE_POSITIVE_Y  = 0x02,
    MU_CUBEMAP_FACE_NEGATIVE_Y  = 0x03,
    MU_CUBEMAP_FACE_POSITIVE_Z  = 0x04,
    MU_CUBEMAP_FACE_NEGATIVE_Z  = 0x05
} MUarray_cubemap_face;
typedef enum MUlimit_enum {
    MU_LIMIT_STACK_SIZE                       = 0x00,
    MU_LIMIT_PRINTF_FIFO_SIZE                 = 0x01,
    MU_LIMIT_MALLOC_HEAP_SIZE                 = 0x02,
    MU_LIMIT_DEV_RUNTIME_SYNC_DEPTH           = 0x03,
    MU_LIMIT_DEV_RUNTIME_PENDING_LAUNCH_COUNT = 0x04,
    MU_LIMIT_MAX_L2_FETCH_GRANULARITY         = 0x05,
    MU_LIMIT_PERSISTING_L2_CACHE_SIZE         = 0x06,
    MU_LIMIT_SHMEM_SIZE                       = 0x07,
    MU_LIMIT_CIG_ENABLED                      = 0x08,
    MU_LIMIT_CIG_SHMEM_FALLBACK_ENABLED       = 0x09,
    MU_LIMIT_MAX
} MUlimit;
typedef enum MUresourcetype_enum {
    MU_RESOURCE_TYPE_ARRAY           = 0x00,
    MU_RESOURCE_TYPE_MIPMAPPED_ARRAY = 0x01,
    MU_RESOURCE_TYPE_LINEAR          = 0x02,
    MU_RESOURCE_TYPE_PITCH2D         = 0x03
} MUresourcetype;
#ifdef _WIN32
#define MUSA_CB __stdcall
#else
#define MUSA_CB
#endif
typedef void (MUSA_CB *MUhostFn)(void *userData);
typedef enum MUaccessProperty_enum {
    MU_ACCESS_PROPERTY_NORMAL           = 0,
    MU_ACCESS_PROPERTY_STREAMING        = 1,
    MU_ACCESS_PROPERTY_PERSISTING       = 2
} MUaccessProperty;
typedef struct MUaccessPolicyWindow_st {
    void *base_ptr;
    size_t num_bytes;
    float hitRatio;
    MUaccessProperty hitProp;
    MUaccessProperty missProp;
} MUaccessPolicyWindow_v1;
typedef MUaccessPolicyWindow_v1 MUaccessPolicyWindow;
typedef enum musaError_enum {
    MUSA_SUCCESS                              = 0,
    MUSA_ERROR_INVALID_VALUE                  = 1,
    MUSA_ERROR_OUT_OF_MEMORY                  = 2,
    MUSA_ERROR_NOT_INITIALIZED                = 3,
    MUSA_ERROR_DEINITIALIZED                  = 4,
    MUSA_ERROR_PROFILER_DISABLED              = 5,
    MUSA_ERROR_PROFILER_NOT_INITIALIZED       = 6,
    MUSA_ERROR_PROFILER_ALREADY_STARTED       = 7,
    MUSA_ERROR_PROFILER_ALREADY_STOPPED       = 8,
    MUSA_ERROR_STUB_LIBRARY                   = 34,
    MUSA_ERROR_CALL_REQUIRES_NEWER_DRIVER          = 36,
    MUSA_ERROR_DEVICE_UNAVAILABLE            = 46,
    MUSA_ERROR_NO_DEVICE                      = 100,
    MUSA_ERROR_INVALID_DEVICE                 = 101,
    MUSA_ERROR_DEVICE_NOT_LICENSED            = 102,
    MUSA_ERROR_INVALID_IMAGE                  = 200,
    MUSA_ERROR_INVALID_CONTEXT                = 201,
    MUSA_ERROR_CONTEXT_ALREADY_CURRENT        = 202,
    MUSA_ERROR_MAP_FAILED                     = 205,
    MUSA_ERROR_UNMAP_FAILED                   = 206,
    MUSA_ERROR_ARRAY_IS_MAPPED                = 207,
    MUSA_ERROR_ALREADY_MAPPED                 = 208,
    MUSA_ERROR_NO_BINARY_FOR_GPU              = 209,
    MUSA_ERROR_ALREADY_ACQUIRED               = 210,
    MUSA_ERROR_NOT_MAPPED                     = 211,
    MUSA_ERROR_NOT_MAPPED_AS_ARRAY            = 212,
    MUSA_ERROR_NOT_MAPPED_AS_POINTER          = 213,
    MUSA_ERROR_ECC_UNCORRECTABLE              = 214,
    MUSA_ERROR_UNSUPPORTED_LIMIT              = 215,
    MUSA_ERROR_CONTEXT_ALREADY_IN_USE         = 216,
    MUSA_ERROR_PEER_ACCESS_UNSUPPORTED        = 217,
    MUSA_ERROR_INVALID_PTX                    = 218,
    MUSA_ERROR_INVALID_GRAPHICS_CONTEXT       = 219,
    MUSA_ERROR_MTLINK_UNCORRECTABLE           = 220,
    MUSA_ERROR_JIT_COMPILER_NOT_FOUND         = 221,
    MUSA_ERROR_UNSUPPORTED_PTX_VERSION        = 222,
    MUSA_ERROR_JIT_COMPILATION_DISABLED       = 223,
    MUSA_ERROR_UNSUPPORTED_EXEC_AFFINITY      = 224,
    MUSA_ERROR_UNSUPPORTED_DEVSIDE_SYNC       = 225,
    MUSA_ERROR_CONTAINED                      = 226,
    MUSA_ERROR_INVALID_SOURCE                 = 300,
    MUSA_ERROR_FILE_NOT_FOUND                 = 301,
    MUSA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND = 302,
    MUSA_ERROR_SHARED_OBJECT_INIT_FAILED      = 303,
    MUSA_ERROR_OPERATING_SYSTEM               = 304,
    MUSA_ERROR_INVALID_HANDLE                 = 400,
    MUSA_ERROR_ILLEGAL_STATE                  = 401,
    MUSA_ERROR_LOSSY_QUERY                    = 402,
    MUSA_ERROR_NOT_FOUND                      = 500,
    MUSA_ERROR_NOT_READY                      = 600,
    MUSA_ERROR_ILLEGAL_ADDRESS                = 700,
    MUSA_ERROR_LAUNCH_OUT_OF_RESOURCES        = 701,
    MUSA_ERROR_LAUNCH_TIMEOUT                 = 702,
    MUSA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING  = 703,
    MUSA_ERROR_PEER_ACCESS_ALREADY_ENABLED    = 704,
    MUSA_ERROR_PEER_ACCESS_NOT_ENABLED        = 705,
    MUSA_ERROR_PRIMARY_CONTEXT_ACTIVE         = 708,
    MUSA_ERROR_CONTEXT_IS_DESTROYED           = 709,
    MUSA_ERROR_ASSERT                         = 710,
    MUSA_ERROR_TOO_MANY_PEERS                 = 711,
    MUSA_ERROR_HOST_MEMORY_ALREADY_REGISTERED = 712,
    MUSA_ERROR_HOST_MEMORY_NOT_REGISTERED     = 713,
    MUSA_ERROR_HARDWARE_STACK_ERROR           = 714,
    MUSA_ERROR_ILLEGAL_INSTRUCTION            = 715,
    MUSA_ERROR_MISALIGNED_ADDRESS             = 716,
    MUSA_ERROR_INVALID_ADDRESS_SPACE          = 717,
    MUSA_ERROR_INVALID_PC                     = 718,
    MUSA_ERROR_LAUNCH_FAILED                  = 719,
    MUSA_ERROR_COOPERATIVE_LAUNCH_TOO_LARGE   = 720,
    MUSA_ERROR_TENSOR_MEMORY_LEAK             = 721,
    MUSA_ERROR_INSTRUCTION_BAR_ID_OOB         = 769,
    MUSA_ERROR_ILLEGAL_CLC_IDS                = 770,
    MUSA_ERROR_INVALID_MEMORY_SPACE           = 771,
    MUSA_ERROR_SRAM_PARITY_ERR_SL             = 772,
    MUSA_ERROR_SRAM_PARITY_ERR_LMS            = 773,
    MUSA_ERROR_SRAM_PARITY_ERR_VR             = 774,
    MUSA_ERROR_WGC_COUNTER_UNCLEARED          = 775,
    MUSA_ERROR_UNCOMPLETED_BARRIER_PHASE      = 776,
    MUSA_ERROR_ILLEGAL_CLC_INSTRUCTION        = 777,
    MUSA_ERROR_TCE_PAIR_NOT_SUPPORT           = 778,
    MUSA_ERROR_VECT_REG_RECONFIG              = 779,
    MUSA_ERROR_INVALID_SOFT_BKT               = 780,
    MUSA_ERROR_ATM_BPP_ERR                    = 781,
    MUSA_ERROR_FIRMWARE_HANG                  = 782,
    MUSA_ERROR_ABORTED                        = 783,
    MUSA_ERROR_OUT_OF_BOUND                   = 784,
    MUSA_ERROR_FP_INVALID_VECTOR              = 785,
    MUSA_ERROR_FP_INVALID_TENSOR              = 786,
    MUSA_ERROR_FP_OVERFLOW_VECTOR             = 787,
    MUSA_ERROR_FP_OVERFLOW_TENSOR             = 788,
    MUSA_ERROR_READ_WRITE_CONFLICT            = 789,
    MUSA_ERROR_READ_WRITER_NO_BARRIER         = 790,
    MUSA_ERROR_CLUSTER_WRITE_FAIL             = 791,
    MUSA_ERROR_CLUSTER_READ_FAIL              = 792,
    MUSA_ERROR_TME_ILLEGAL_PARAMETERS         = 793,
    MUSA_ERROR_TCE_ILLEGAL_ACTIVE_MASK        = 794,
    MUSA_ERROR_KILL_TIMEOUT                   = 795,
    MUSA_ERROR_AXI_BUS_TIMEOUT                = 796,
    MUSA_ERROR_AXI_BUS_DECODE_ERROR           = 797,
    MUSA_ERROR_AXI_BUS_SLAVE_ERROR            = 798,
    MUSA_ERROR_CSW_TIMEOUT                    = 799,
    MUSA_ERROR_NOT_PERMITTED                  = 800,
    MUSA_ERROR_NOT_SUPPORTED                  = 801,
    MUSA_ERROR_SYSTEM_NOT_READY               = 802,
    MUSA_ERROR_SYSTEM_DRIVER_MISMATCH         = 803,
    MUSA_ERROR_COMPAT_NOT_SUPPORTED_ON_DEVICE = 804,
    MUSA_ERROR_MPS_CONNECTION_FAILED          = 805,
    MUSA_ERROR_MPS_RPC_FAILURE                = 806,
    MUSA_ERROR_MPS_SERVER_NOT_READY           = 807,
    MUSA_ERROR_MPS_MAX_CLIENTS_REACHED        = 808,
    MUSA_ERROR_MPS_MAX_CONNECTIONS_REACHED    = 809,
    MUSA_ERROR_MPS_CLIENT_TERMINATED          = 810,
    MUSA_ERROR_CDP_NOT_SUPPORTED              = 811,
    MUSA_ERROR_CDP_VERSION_MISMATCH           = 812,
    MUSA_ERROR_STREAM_CAPTURE_UNSUPPORTED     = 900,
    MUSA_ERROR_STREAM_CAPTURE_INVALIDATED     = 901,
    MUSA_ERROR_STREAM_CAPTURE_MERGE           = 902,
    MUSA_ERROR_STREAM_CAPTURE_UNMATCHED       = 903,
    MUSA_ERROR_STREAM_CAPTURE_UNJOINED        = 904,
    MUSA_ERROR_STREAM_CAPTURE_ISOLATION       = 905,
    MUSA_ERROR_STREAM_CAPTURE_IMPLICIT        = 906,
    MUSA_ERROR_CAPTURED_EVENT                 = 907,
    MUSA_ERROR_STREAM_CAPTURE_WRONG_THREAD    = 908,
    MUSA_ERROR_TIMEOUT                        = 909,
    MUSA_ERROR_GRAPH_EXEC_UPDATE_FAILURE      = 910,
    MUSA_ERROR_EXTERNAL_DEVICE               = 911,
    MUSA_ERROR_INVALID_CLUSTER_SIZE           = 912,
    MUSA_ERROR_FUNCTION_NOT_LOADED            = 913,
    MUSA_ERROR_INVALID_RESOURCE_TYPE          = 914,
    MUSA_ERROR_INVALID_RESOURCE_CONFIGURATION = 915,
    MUSA_ERROR_KEY_ROTATION                   = 916,
    MUSA_ERROR_STREAM_DETACHED                = 917,
    MUSA_ERROR_UNKNOWN                        = 999
} MUresult;
typedef enum MUdevice_P2PAttribute_enum {
    MU_DEVICE_P2P_ATTRIBUTE_PERFORMANCE_RANK                     = 0x01,
    MU_DEVICE_P2P_ATTRIBUTE_ACCESS_SUPPORTED                     = 0x02,
    MU_DEVICE_P2P_ATTRIBUTE_NATIVE_ATOMIC_SUPPORTED              = 0x03,
    MU_DEVICE_P2P_ATTRIBUTE_ACCESS_ACCESS_SUPPORTED              = 0x04,
    MU_DEVICE_P2P_ATTRIBUTE_MUSA_ARRAY_ACCESS_SUPPORTED          = 0x04,
    MU_DEVICE_P2P_ATTRIBUTE_MTLINK_PORT_COUNT
} MUdevice_P2PAttribute;
typedef void (MUSA_CB *MUstreamCallback)(MUstream hStream, MUresult status, void *userData);
typedef size_t (MUSA_CB *MUoccupancyB2DSize)(int blockSize);
#define MU_MEMHOSTALLOC_PORTABLE               0x01
#define MU_MEMHOSTALLOC_DEVICEMAP              0x02
#define MU_MEMHOSTALLOC_WRITECOMBINED          0x04
#define MU_MEMHOSTREGISTER_PORTABLE            0x01
#define MU_MEMHOSTREGISTER_DEVICEMAP           0x02
#define MU_MEMHOSTREGISTER_IOMEMORY            0x04
#define MU_MEMHOSTREGISTER_READ_ONLY           0x08
#define MU_PEERACCESS_DEFAULT                  0x00
#define MU_PEERACCESS_UNIDIR_INTERLEAVED       0x01
#define MU_PEERACCESS_BIDIR_INTERLEAVED        0x02
#define MU_PEERACCESS_HETERO_INTERLEAVED       0x03
#define MU_PEERACCESS_HETERO_BIDIR_INTERLEAVED 0x04
#define MU_PEERACCESS_HALF_BIDIR_INTERLEAVED   0x05
#define MU_PEERACCESS_PCIE_ONLY                0x06
#define MU_PEERACCESS_POLICY_MAX               0x06
typedef struct MUSA_MEMCPY2D_st {
    size_t srcXInBytes;
    size_t srcY;
    MUmemorytype srcMemoryType;
    const void *srcHost;
    MUdeviceptr srcDevice;
    MUarray srcArray;
    size_t srcPitch;
    size_t dstXInBytes;
    size_t dstY;
    MUmemorytype dstMemoryType;
    void *dstHost;
    MUdeviceptr dstDevice;
    MUarray dstArray;
    size_t dstPitch;
    size_t WidthInBytes;
    size_t Height;
} MUSA_MEMCPY2D_v2;
typedef MUSA_MEMCPY2D_v2 MUSA_MEMCPY2D;
typedef struct MUSA_MEMCPY3D_st {
    size_t srcXInBytes;
    size_t srcY;
    size_t srcZ;
    size_t srcLOD;
    MUmemorytype srcMemoryType;
    const void *srcHost;
    MUdeviceptr srcDevice;
    MUarray srcArray;
    void *reserved0;
    size_t srcPitch;
    size_t srcHeight;
    size_t dstXInBytes;
    size_t dstY;
    size_t dstZ;
    size_t dstLOD;
    MUmemorytype dstMemoryType;
    void *dstHost;
    MUdeviceptr dstDevice;
    MUarray dstArray;
    void *reserved1;
    size_t dstPitch;
    size_t dstHeight;
    size_t WidthInBytes;
    size_t Height;
    size_t Depth;
} MUSA_MEMCPY3D_v2;
typedef MUSA_MEMCPY3D_v2 MUSA_MEMCPY3D;
typedef struct MUSA_MEMCPY3D_PEER_st {
    size_t srcXInBytes;
    size_t srcY;
    size_t srcZ;
    size_t srcLOD;
    MUmemorytype srcMemoryType;
    const void *srcHost;
    MUdeviceptr srcDevice;
    MUarray srcArray;
    MUcontext srcContext;
    size_t srcPitch;
    size_t srcHeight;
    size_t dstXInBytes;
    size_t dstY;
    size_t dstZ;
    size_t dstLOD;
    MUmemorytype dstMemoryType;
    void *dstHost;
    MUdeviceptr dstDevice;
    MUarray dstArray;
    MUcontext dstContext;
    size_t dstPitch;
    size_t dstHeight;
    size_t WidthInBytes;
    size_t Height;
    size_t Depth;
} MUSA_MEMCPY3D_PEER_v1;
typedef MUSA_MEMCPY3D_PEER_v1 MUSA_MEMCPY3D_PEER;
typedef struct MUSA_MEMCPY_NODE_PARAMS_st {
    int flags;
    int reserved;
    MUcontext copyCtx;
    MUSA_MEMCPY3D copyParams;
} MUSA_MEMCPY_NODE_PARAMS;
typedef struct MUSA_ARRAY_DESCRIPTOR_st
{
    size_t Width;
    size_t Height;
    MUarray_format Format;
    unsigned int NumChannels;
} MUSA_ARRAY_DESCRIPTOR_v2;
typedef MUSA_ARRAY_DESCRIPTOR_v2 MUSA_ARRAY_DESCRIPTOR;
typedef struct MUSA_ARRAY3D_DESCRIPTOR_st
{
    size_t Width;
    size_t Height;
    size_t Depth;
    MUarray_format Format;
    unsigned int NumChannels;
    unsigned int Flags;
} MUSA_ARRAY3D_DESCRIPTOR_v2;
typedef MUSA_ARRAY3D_DESCRIPTOR_v2 MUSA_ARRAY3D_DESCRIPTOR;
#define MU_ARRAY_SPARSE_PROPERTIES_SINGLE_MIPTAIL 0x1
typedef struct MUSA_ARRAY_SPARSE_PROPERTIES_st {
    struct {
        unsigned int width;
        unsigned int height;
        unsigned int depth;
    } tileExtent;
    unsigned int miptailFirstLevel;
    unsigned long long miptailSize;
    unsigned int flags;
    unsigned int reserved[4];
} MUSA_ARRAY_SPARSE_PROPERTIES_v1;
typedef MUSA_ARRAY_SPARSE_PROPERTIES_v1 MUSA_ARRAY_SPARSE_PROPERTIES;
typedef struct MUSA_ARRAY_MEMORY_REQUIREMENTS_st {
    size_t size;
    size_t alignment;
    unsigned int reserved[4];
} MUSA_ARRAY_MEMORY_REQUIREMENTS_v1;
typedef MUSA_ARRAY_MEMORY_REQUIREMENTS_v1 MUSA_ARRAY_MEMORY_REQUIREMENTS;
typedef struct MUSA_RESOURCE_DESC_st
{
    MUresourcetype resType;
    union {
        struct {
            MUarray hArray;
        } array;
        struct {
            MUmipmappedArray hMipmappedArray;
        } mipmap;
        struct {
            MUdeviceptr devPtr;
            MUarray_format format;
            unsigned int numChannels;
            size_t sizeInBytes;
        } linear;
        struct {
            MUdeviceptr devPtr;
            MUarray_format format;
            unsigned int numChannels;
            size_t width;
            size_t height;
            size_t pitchInBytes;
        } pitch2D;
        struct {
            int reserved[32];
        } reserved;
    } res;
    unsigned int flags;
} MUSA_RESOURCE_DESC_v1;
typedef MUSA_RESOURCE_DESC_v1 MUSA_RESOURCE_DESC;
typedef struct MUSA_TEXTURE_DESC_st {
    MUaddress_mode addressMode[3];
    MUfilter_mode filterMode;
    unsigned int flags;
    unsigned int maxAnisotropy;
    MUfilter_mode mipmapFilterMode;
    float mipmapLevelBias;
    float minMipmapLevelClamp;
    float maxMipmapLevelClamp;
    float borderColor[4];
    int reserved[12];
} MUSA_TEXTURE_DESC_v1;
typedef MUSA_TEXTURE_DESC_v1 MUSA_TEXTURE_DESC;
typedef enum MUresourceViewFormat_enum
{
    MU_RES_VIEW_FORMAT_NONE          = 0x00,
    MU_RES_VIEW_FORMAT_UINT_1X8      = 0x01,
    MU_RES_VIEW_FORMAT_UINT_2X8      = 0x02,
    MU_RES_VIEW_FORMAT_UINT_4X8      = 0x03,
    MU_RES_VIEW_FORMAT_SINT_1X8      = 0x04,
    MU_RES_VIEW_FORMAT_SINT_2X8      = 0x05,
    MU_RES_VIEW_FORMAT_SINT_4X8      = 0x06,
    MU_RES_VIEW_FORMAT_UINT_1X16     = 0x07,
    MU_RES_VIEW_FORMAT_UINT_2X16     = 0x08,
    MU_RES_VIEW_FORMAT_UINT_4X16     = 0x09,
    MU_RES_VIEW_FORMAT_SINT_1X16     = 0x0a,
    MU_RES_VIEW_FORMAT_SINT_2X16     = 0x0b,
    MU_RES_VIEW_FORMAT_SINT_4X16     = 0x0c,
    MU_RES_VIEW_FORMAT_UINT_1X32     = 0x0d,
    MU_RES_VIEW_FORMAT_UINT_2X32     = 0x0e,
    MU_RES_VIEW_FORMAT_UINT_4X32     = 0x0f,
    MU_RES_VIEW_FORMAT_SINT_1X32     = 0x10,
    MU_RES_VIEW_FORMAT_SINT_2X32     = 0x11,
    MU_RES_VIEW_FORMAT_SINT_4X32     = 0x12,
    MU_RES_VIEW_FORMAT_FLOAT_1X16    = 0x13,
    MU_RES_VIEW_FORMAT_FLOAT_2X16    = 0x14,
    MU_RES_VIEW_FORMAT_FLOAT_4X16    = 0x15,
    MU_RES_VIEW_FORMAT_FLOAT_1X32    = 0x16,
    MU_RES_VIEW_FORMAT_FLOAT_2X32    = 0x17,
    MU_RES_VIEW_FORMAT_FLOAT_4X32    = 0x18,
    MU_RES_VIEW_FORMAT_UNSIGNED_BC1  = 0x19,
    MU_RES_VIEW_FORMAT_UNSIGNED_BC2  = 0x1a,
    MU_RES_VIEW_FORMAT_UNSIGNED_BC3  = 0x1b,
    MU_RES_VIEW_FORMAT_UNSIGNED_BC4  = 0x1c,
    MU_RES_VIEW_FORMAT_SIGNED_BC4    = 0x1d,
    MU_RES_VIEW_FORMAT_UNSIGNED_BC5  = 0x1e,
    MU_RES_VIEW_FORMAT_SIGNED_BC5    = 0x1f,
    MU_RES_VIEW_FORMAT_UNSIGNED_BC6H = 0x20,
    MU_RES_VIEW_FORMAT_SIGNED_BC6H   = 0x21,
    MU_RES_VIEW_FORMAT_UNSIGNED_BC7  = 0x22
} MUresourceViewFormat;
typedef struct MUSA_RESOURCE_VIEW_DESC_st
{
    MUresourceViewFormat format;
    size_t width;
    size_t height;
    size_t depth;
    unsigned int firstMipmapLevel;
    unsigned int lastMipmapLevel;
    unsigned int firstLayer;
    unsigned int lastLayer;
    unsigned int reserved[16];
} MUSA_RESOURCE_VIEW_DESC_v1;
typedef MUSA_RESOURCE_VIEW_DESC_v1 MUSA_RESOURCE_VIEW_DESC;
typedef struct MUSA_LAUNCH_PARAMS_st {
    MUfunction function;
    unsigned int gridDimX;
    unsigned int gridDimY;
    unsigned int gridDimZ;
    unsigned int blockDimX;
    unsigned int blockDimY;
    unsigned int blockDimZ;
    unsigned int sharedMemBytes;
    MUstream hStream;
    void **kernelParams;
} MUSA_LAUNCH_PARAMS_v1;
typedef MUSA_LAUNCH_PARAMS_v1 MUSA_LAUNCH_PARAMS;
typedef enum MUexternalMemoryHandleType_enum {
    MU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD          = 1,
    MU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32       = 2,
    MU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT   = 3,
    MU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP         = 4,
    MU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE     = 5,
    MU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_RESOURCE     = 6,
    MU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_RESOURCE_KMT = 7,
    MU_EXTERNAL_MEMORY_HANDLE_TYPE_MTSCIBUF = 8,
    MU_EXTERNAL_MEMORY_HANDLE_TYPE_DMABUF_FD = 9
} MUexternalMemoryHandleType;
#define MUSA_EXTERNAL_MEMORY_DEDICATED   0x1
#define MUSA_EXTERNAL_SEMAPHORE_SIGNAL_SKIP_MTSCIBUF_MEMSYNC 0x01
#define MUSA_EXTERNAL_SEMAPHORE_WAIT_SKIP_MTSCIBUF_MEMSYNC 0x02
#define MUSA_MTSCISYNC_ATTR_SIGNAL 0x1
#define MUSA_MTSCISYNC_ATTR_WAIT 0x2
typedef struct MUSA_EXTERNAL_MEMORY_HANDLE_DESC_st {
    MUexternalMemoryHandleType type;
    union {
        int fd;
        struct {
            void *handle;
            const void *name;
        } win32;
        const void *mtSciBufObject;
    } handle;
    unsigned long long size;
    unsigned int flags;
    unsigned int reserved[16];
} MUSA_EXTERNAL_MEMORY_HANDLE_DESC_v1;
typedef MUSA_EXTERNAL_MEMORY_HANDLE_DESC_v1 MUSA_EXTERNAL_MEMORY_HANDLE_DESC;
typedef struct MUSA_EXTERNAL_MEMORY_BUFFER_DESC_st {
    unsigned long long offset;
    unsigned long long size;
    unsigned int flags;
    unsigned int reserved[16];
} MUSA_EXTERNAL_MEMORY_BUFFER_DESC_v1;
typedef MUSA_EXTERNAL_MEMORY_BUFFER_DESC_v1 MUSA_EXTERNAL_MEMORY_BUFFER_DESC;
typedef struct MUSA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC_st {
    unsigned long long offset;
    MUSA_ARRAY3D_DESCRIPTOR arrayDesc;
    unsigned int numLevels;
    unsigned int reserved[16];
} MUSA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC_v1;
typedef MUSA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC_v1 MUSA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC;
typedef enum MUexternalSemaphoreHandleType_enum {
    MU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD             = 1,
    MU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32          = 2,
    MU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT      = 3,
    MU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE           = 4,
    MU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_FENCE           = 5,
	MU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_MTSCISYNC             = 6,
    MU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_KEYED_MUTEX     = 7,
    MU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_KEYED_MUTEX_KMT = 8,
    MU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_TIMELINE_SEMAPHORE_FD = 9,
    MU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_TIMELINE_SEMAPHORE_WIN32 = 10
} MUexternalSemaphoreHandleType;
typedef struct MUSA_EXTERNAL_SEMAPHORE_HANDLE_DESC_st {
    MUexternalSemaphoreHandleType type;
    union {
        int fd;
        struct {
            void *handle;
            const void *name;
        } win32;
        const void* mtSciSyncObj;
    } handle;
    unsigned int flags;
    unsigned int reserved[16];
} MUSA_EXTERNAL_SEMAPHORE_HANDLE_DESC_v1;
typedef MUSA_EXTERNAL_SEMAPHORE_HANDLE_DESC_v1 MUSA_EXTERNAL_SEMAPHORE_HANDLE_DESC;
typedef struct MUSA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS_st {
    struct {
        struct {
            unsigned long long value;
        } fence;
        union {
            void *fence;
            unsigned long long reserved;
        } mtSciSync;
        struct {
            unsigned long long key;
        } keyedMutex;
        unsigned int reserved[12];
    } params;
    unsigned int flags;
    unsigned int reserved[16];
} MUSA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS_v1;
typedef MUSA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS_v1 MUSA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS;
typedef struct MUSA_EXTERNAL_SEMAPHORE_WAIT_PARAMS_st {
    struct {
        struct {
            unsigned long long value;
        } fence;
        union {
            void *fence;
            unsigned long long reserved;
        } mtSciSync;
        struct {
            unsigned long long key;
            unsigned int timeoutMs;
        } keyedMutex;
        unsigned int reserved[10];
    } params;
    unsigned int flags;
    unsigned int reserved[16];
} MUSA_EXTERNAL_SEMAPHORE_WAIT_PARAMS_v1;
typedef MUSA_EXTERNAL_SEMAPHORE_WAIT_PARAMS_v1 MUSA_EXTERNAL_SEMAPHORE_WAIT_PARAMS;
typedef struct MUSA_EXT_SEM_SIGNAL_NODE_PARAMS_st {
    MUexternalSemaphore* extSemArray;
    const MUSA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS* paramsArray;
    unsigned int numExtSems;
} MUSA_EXT_SEM_SIGNAL_NODE_PARAMS_v1;
typedef MUSA_EXT_SEM_SIGNAL_NODE_PARAMS_v1 MUSA_EXT_SEM_SIGNAL_NODE_PARAMS;
typedef struct MUSA_EXT_SEM_SIGNAL_NODE_PARAMS_v2_st {
    MUexternalSemaphore* extSemArray;
    const MUSA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS* paramsArray;
    unsigned int numExtSems;
} MUSA_EXT_SEM_SIGNAL_NODE_PARAMS_v2;
typedef struct MUSA_EXT_SEM_WAIT_NODE_PARAMS_st {
    MUexternalSemaphore* extSemArray;
    const MUSA_EXTERNAL_SEMAPHORE_WAIT_PARAMS* paramsArray;
    unsigned int numExtSems;
} MUSA_EXT_SEM_WAIT_NODE_PARAMS_v1;
typedef MUSA_EXT_SEM_WAIT_NODE_PARAMS_v1 MUSA_EXT_SEM_WAIT_NODE_PARAMS;
typedef struct MUSA_EXT_SEM_WAIT_NODE_PARAMS_v2_st {
    MUexternalSemaphore* extSemArray;
    const MUSA_EXTERNAL_SEMAPHORE_WAIT_PARAMS* paramsArray;
    unsigned int numExtSems;
} MUSA_EXT_SEM_WAIT_NODE_PARAMS_v2;
#ifdef _WIN32
#define MUSAAPI __stdcall
#else
#define MUSAAPI
#endif
#ifdef __cplusplus
}
#endif
#undef __MUSA_DEPRECATED
#endif
