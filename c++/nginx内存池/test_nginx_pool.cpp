#include "nginx_mem_pool.h"
#include "stdio.h"
#include <typeinfo>
#include "string.h"

typedef struct Data stData;
struct Data
{
    char *ptr;
    FILE* pfile;
};

void func1(void *p1)
{
    char *p=(char*)p1;
    printf("free ptr mem!");
    free(p);
}
void func2(void *pf1)
{
    FILE* pf = (FILE*)pf1;
    printf("close file!");
    fclose(pf);
}

int main()
{
    ngx_mem_pool mempool;
    if(nullptr == mempool.ngx_create_pool(512))
    {
        printf("ngx_create_pool failed...");
        return -1;
    }

    void *pl = mempool.ngx_palloc(128);
    if(pl==nullptr)
    {   
        printf("ngx alloc 128 bytes fail...");
        return -1;
    }

    stData *p2 = (stData*)mempool.ngx_palloc(512);
    if (p2 == nullptr)
    {
        printf("ngx alloc 512 bytes fail...");
        return -1;
    }
    p2->ptr = (decltype(p2->ptr))malloc(12);
    strcpy(p2->ptr, "hello world");
    p2->pfile = fopen("data.txt", "w");

    ngx_pool_cleanup_s *c1 = mempool.ngx_pool_cleanup_add(sizeof(char*));
    c1->handler = func1;
    c1->data = p2->ptr;

    ngx_pool_cleanup_s *c2 = mempool.ngx_pool_cleanup_add(sizeof(FILE*));
    c2->handler = func2;
    c2->data = p2->pfile;

    mempool.ngx_destroy_pool();

    return 0;
}