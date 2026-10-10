#if defined(VERSION_GUPJ8P)
#define ALLOCATOR_RELEASE_FUNCTION fn_803A3C80
#define FREE_SMALL_BLOCK fn_803A3D2C
#define FREE_LARGE_BLOCK fn_803A4154
#elif defined(VERSION_GUPP8P)
#define ALLOCATOR_RELEASE_FUNCTION fn_803A4690
#define FREE_SMALL_BLOCK fn_803A473C
#define FREE_LARGE_BLOCK fn_803A4B64
#else
#define ALLOCATOR_RELEASE_FUNCTION fn_803A3640
#define FREE_SMALL_BLOCK fn_803A36EC
#define FREE_LARGE_BLOCK fn_803A3B14
#endif

extern void FREE_SMALL_BLOCK(void *heap, void *ptr);
extern void FREE_LARGE_BLOCK(void *heap, void *ptr);

void ALLOCATOR_RELEASE_FUNCTION(void *heap, void *ptr) {
    void *block_header;
    unsigned int block_size;

    if (ptr != 0) {
        block_header = *(void **)((unsigned char *)ptr - 4);
        if (((unsigned int)block_header & 1) == 0) {
            block_size = *(unsigned int *)((unsigned char *)block_header + 8);
        } else {
            block_size = *(unsigned int *)((unsigned char *)ptr - 8) & ~7;
            block_size = block_size - 8;
        }

        if (block_size <= 0x44) {
            FREE_SMALL_BLOCK(heap, ptr);
        } else {
            FREE_LARGE_BLOCK(heap, ptr);
        }
    }
}
