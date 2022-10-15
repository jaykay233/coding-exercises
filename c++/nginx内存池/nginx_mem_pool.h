#pragma once
#include <stdlib.h>
#include <memory.h>

using u_char = unsigned char;
using ngx_uint_t = unsigned int;
using size_t = __SIZE_TYPE__;
struct ngx_pool_s;

//清理函数的类型（回调的操作）
typedef void (*ngx_pool_cleanup_t)(void *data);
struct ngx_pool_cleanup_s
{
    ngx_pool_cleanup_t handler;
    void *data;
    ngx_pool_cleanup_s *next;
};

/*
大块内存的头部信息
*/
struct ngx_pool_large_s
{
    ngx_pool_large_s *next;
    void *alloc;
};

/*
内存分配小块内存的内存池的头部数据信息
*/
struct ngx_pool_data_t
{
    u_char *last;
    u_char *end;
    ngx_pool_s *next;
    ngx_uint_t failed;
};

/*
ngx内存池的头部信息和管理成员信息
*/
struct ngx_pool_s
{
    ngx_pool_data_t d;
    size_t max;
    ngx_pool_s *current;
    ngx_pool_large_s *large;
    ngx_pool_cleanup_s *cleanup;
};

#define ngx_align(d,a) (((d) + (a-1)) & ~(a-1) )
// 小块内存分配考虑字节对齐时的单位
#define NGX_ALIGNMENT sizeof(unsigned long)
// 把p指针调整到临近的倍数
#define ngx_align_ptr(p,a) (u_char*)(((uintptr_t)(p) + ((uintptr_t)a-1)) & ~((uintptr_t)a - 1) )

#define ngx_memzero(buf, n) (void)memset(buf, 0, n)

const int ngx_pagesize = 4096;
const int NGX_MAX_ALLOC_FROM_POOL = ngx_pagesize - 1;
const int NGX_DEFAULT_POOL_SIZE = 16 * 1024;
const int NGX_POOL_ALIGNMENT = 16;
//ngx最小块size调整成pool alignment临近的倍数
const int NGX_MIN_POOL_SIZE = ngx_align((sizeof(ngx_pool_s) + 2 * sizeof(ngx_pool_large_s)), NGX_POOL_ALIGNMENT);

class ngx_mem_pool
{
public:
    void* ngx_create_pool(size_t size);
    //考虑内存字节对齐
    void* ngx_palloc(size_t size);
    //不考虑内存字节对齐
    void* ngx_pnalloc(size_t size);
    //调用的是ngx_palloc实现内存分配，但是会初始化0
    void* ngx_pcalloc(size_t size);
    // 释放大块内存
    void ngx_pfree(void *p);
    // 内存池重置
    void ngx_reset_pool();
    //内存池销毁
    void ngx_destroy_pool();
    ngx_pool_cleanup_s *ngx_pool_cleanup_add(size_t size);
private:
    ngx_pool_s *pool_; //ngx内存的入口指针
    void *ngx_palloc_small(size_t size, ngx_uint_t align);
    void *ngx_palloc_large(size_t size);
    void *ngx_palloc_block(size_t size);
};