#ifndef __DEF_LIBPIZIOT_OS_MEM_H__
#define __DEF_LIBPIZIOT_OS_MEM_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_platform.h"

#include "def_libpiziot_os_type.h"
#include "def_libpiziot_os_mutex.h"

#define LIBPIZIOT_ENABLE_OS_MEM

#define LIBPIZIOT_ENABLE_OS_MEM_CHECK_STRUCT_SIZE

#if defined(LIBPIZIOT_ENABLE_OS_MEM)
    #if defined(__LIBPIZIOT_OS_FREERTOS__)
        #undef os_free
        #undef os_malloc
        #undef os_calloc
        #undef os_realloc
        #undef os_zalloc
    #endif //defined(__LIBPIZIOT_OS_FREERTOS__)

    #define malloc(size) libpiziot_os_mem_malloc(size,__FILE__,__LINE__)
    #define calloc(count, size) libpiziot_os_mem_calloc(count,size,__FILE__,__LINE__)
    #define free(mem_ref) libpiziot_os_mem_free(mem_ref)
    #define kzalloc(size, mode) libpiziot_os_mem_malloc(size,__FILE__,__LINE__)
    #define kmalloc(size, flag) libpiziot_os_mem_malloc(size,__FILE__,__LINE__)
    #define kfree(mem_ref) libpiziot_os_mem_free(mem_ref)
    #define kfifoalloc(size, flag, lock) libpiziot_os_mem_malloc(size,__FILE__,__LINE__)
    #define kfifo_free(mem_ref) libpiziot_os_mem_free(mem_ref)

    #define os_malloc(size) libpiziot_os_mem_malloc(size,__FILE__,__LINE__)
    #define os_calloc(count, size) libpiziot_os_mem_calloc(count,size,__FILE__,__LINE__)
    #define os_free(mem_ref) libpiziot_os_mem_free(mem_ref)
#endif //defined(LIBPIZIOT_ENABLE_OS_MEM)

#define memset_addr(type_p,var,value,size) {type_p *lpaddrxxx = (var);memset((void*)lpaddrxxx, (value), size);}

#ifdef __cplusplus
extern "C"
{
#endif

    extern libpiziot_os_mutex_struct_plock_t libpiziot_os_file_mx_proc_sys_vm_drop_caches;
#if (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
    //extern uint64_t libpiziot_os_mem_get_system_total_free_memory(void);
#else
    extern uint64_t libpiziot_os_mem_get_system_total_free_memory(void);
#endif //(defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))

#if defined(LIBPIZIOT_ENABLE_OS_MEM)
    extern void *libpiziot_os_mem_malloc(size_t size, const char *file, unsigned int line);
    extern void *libpiziot_os_mem_calloc(size_t count, size_t size, const char *file, unsigned int line);
    //extern void* _user_malloc_calloc(unsigned int elements,unsigned int size,const char * file,unsigned int line);
    extern void libpiziot_os_mem_free(void *mem_ref);
    extern void libpiziot_os_mem_report_leaks(void);
#if defined(LIBPIZIOT_ENABLE_OS_MEM_CHECK_STRUCT_SIZE)
    extern libpiziot_os_type_func_result_e libpiziot_os_mem_check_struct_size(char *Astruct_name, size_t Asizeof, size_t Acheck);
#else
#define libpiziot_os_mem_check_struct_size(x,y,z)
#endif //defined(LIBPIZIOT_ENABLE_OS_MEM_CHECK_STRUCT_SIZE)
#endif //defined(LIBPIZIOT_ENABLE_OS_MEM)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
    //#define X_TEST_BIG_ENDIAN__
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#if defined(__LIBPIZIOT_OS_ENDIAN_BIG__) || defined(X_TEST_BIG_ENDIAN__)
    extern uint64_t libpiziot_os_mem_endian_u64(uint64_t val);
    extern int64_t libpiziot_os_mem_endian_64(int64_t val);
    extern uint32_t libpiziot_os_mem_endian_u32(uint32_t val);
    extern int32_t libpiziot_os_mem_endian_32(int32_t val);
    extern uint16_t libpiziot_os_mem_endian_u16(uint16_t val);
    extern int16_t libpiziot_os_mem_endian_16(int16_t val);
    extern void libpiziot_os_mem_endian_memcpy_u32(unsigned char* AlpDest, unsigned char* AlpSrc);
#elif defined(__LIBPIZIOT_OS_ENDIAN_LITTLE__)
#define libpiziot_os_mem_endian_u64(x) (x)
#define libpiziot_os_mem_endian_64(x) (x)
#define libpiziot_os_mem_endian_u32(x) (x)
#define libpiziot_os_mem_endian_32(x) (x)
#define libpiziot_os_mem_endian_u16(x) (x)
#define libpiziot_os_mem_endian_16(x) (x)
#define libpiziot_os_mem_endian_memcpy_u32(dest, src) memcpy(dest,src,sizeof(4))
#else
#error endian not define !!
#endif //defined(__LIBPIZIOT_OS_ENDIAN_BIG__)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#define libpiziot_os_mem_dwfile_u32(x) (x)
#define libpiziot_os_mem_dwfile_u16(x) (x)
#define libpiziot_os_mem_dwfile_32(x) (x)
#define libpiziot_os_mem_dwfile_16(x) (x)
#define libpiziot_os_mem_dwfile_memcpy_u32(dest,src) memcpy(dest,src,sizeof(4))
#else
#define libpiziot_os_mem_dwfile_u32(x) libpiziot_os_mem_endian_u32(x)
#define libpiziot_os_mem_dwfile_u16(x) libpiziot_os_mem_endian_u16(x)
#define libpiziot_os_mem_dwfile_32(x) libpiziot_os_mem_endian_32(x)
#define libpiziot_os_mem_dwfile_16(x) libpiziot_os_mem_endian_16(x)
#define libpiziot_os_mem_dwfile_memcpy_u32(dest, src) libpiziot_os_mem_endian_memcpy_u32(dest,src)
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_MEM_H__
