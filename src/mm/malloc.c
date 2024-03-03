#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
    void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    
    if (p == MAP_FAILED) {
        return NULL;
    }
    
    return p;
}

void *calloc(size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;
  
    void *p = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    
    if (p == MAP_FAILED) {
        return NULL;
    }
    
    memset(p, 0, total_size);
    
    return p;
}

void free(void *p)
{
    if (p != NULL) {
        munmap(p, 0);
    }
}

void *realloc(void *p, size_t size)
{
    if (p == NULL) {
        return malloc(size);
    }
    
    void *new_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    
    if (new_ptr == MAP_FAILED) {
        return NULL;
    }

    free(p);
    
    return new_ptr;
}

void *reallocarray(void *p, size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;
    
    return realloc(p, total_size);
}
