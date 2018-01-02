#ifndef __DEF_LINUX_KERNEL_FS_H__
#define __DEF_LINUX_KERNEL_FS_H__

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

#include "../def_libpiziot_os_type.h"
#include "def_linux_kernel_type.h"

struct file {
#if defined(LIBPIZIOT_OS_ICE_TEST__)
    /*
    * fu_list becomes invalid after file_free is called and queued via
    * fu_rcuhead for RCU freeing
    */
    union
    {
        struct list_head fu_list;
        struct rcu_head fu_rcuhead;
    } f_u;
    struct path f_path;
#define f_dentry f_path.dentry
#define f_vfsmnt f_path.mnt
    const struct file_operations *f_op;
    atomic_long_t f_count;
    unsigned int f_flags;
    fmode_t f_mode;
    loff_t f_pos;
    struct fown_struct f_owner;
    unsigned int f_uid, f_gid;
    struct file_ra_state f_ra;

    u64 f_version;
#ifdef CONFIG_SECURITY
    void *f_security;
#endif
#else
#endif //defined(LIBPIZIOT_OS_ICE_TEST__)

    /* needed for tty driver, and maybe others */
    void *private_data;

#if defined(LIBPIZIOT_OS_ICE_TEST__)

#ifdef CONFIG_EPOLL
    /* Used by fs/eventpoll.c to link all the hooks to this file */
    struct list_head f_ep_links;
    spinlock_t f_ep_lock;
#endif /* #ifdef CONFIG_EPOLL */
    struct address_space *f_mapping;
#ifdef CONFIG_DEBUG_WRITECOUNT
    unsigned long f_mnt_write_state;
#endif
#else
#endif //defined(LIBPIZIOT_OS_ICE_TEST__)
};

typedef lont_int32_t loff_t;
#define IOCTL_ARG_TYPE void*

struct file_operations {
    //struct module *owner;
    //loff_t (*llseek) (struct file *, loff_t, int);
    //ssize_t (*read) (struct file *, char __user *, size_t, loff_t*);
    //ssize_t (*write) (struct file *, const char __user *, size_t, loff_t*);
    //ssize_t (*aio_read) (struct kiocb *, const struct iovec *, unsigned long, loff_t);
    //ssize_t (*aio_write) (struct kiocb *, const struct iovec *, unsigned long, loff_t);
    //int (*readdir) (struct file *, void *, filldir_t);
    unsigned int(*poll) (struct file *, struct poll_table_struct*);
    long(*unlocked_ioctl) (struct file *, unsigned int, void*);
    //long (*compat_ioctl) (struct file *, unsigned int, unsigned long);
    int(*mmap) (struct file *, struct vm_area_struct*);
    int(*open) (struct inode *, struct file*);
    //int (*flush) (struct file *, fl_owner_t id);
    int(*release) (struct inode *, struct file*);
    //int (*fsync) (struct file *, loff_t, loff_t, int datasync);
    //int (*aio_fsync) (struct kiocb *, int datasync);
    //int (*fasync) (int, struct file *, int);
    //int (*lock) (struct file *, int, struct file_lock*);
    //ssize_t (*sendpage) (struct file *, struct page *, int, size_t, loff_t *, int);
    //unsigned long (*get_unmapped_area)(struct file *, unsigned long, unsigned long, unsigned long, unsigned long);
    //int (*check_flags)(int);
    //int (*flock) (struct file *, int, struct file_lock*);
    //ssize_t (*splice_write)(struct pipe_inode_info *, struct file *, loff_t *, size_t, unsigned int);
    //ssize_t (*splice_read)(struct file *, loff_t *, struct pipe_inode_info *, size_t, unsigned int);
    //int (*setlease)(struct file *, long, struct file_lock **);
    //long (*fallocate)(struct file *file, int mode, loff_t offset,loff_t len);
};

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

#endif //__DEF_LINUX_KERNEL_FS_H__
