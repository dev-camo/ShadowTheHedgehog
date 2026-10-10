#if defined(VERSION_GUPJ8P)
#define CALLOC_FUNCTION fn_803A3280
#define CALLOC_ZERO_FILL_HELPER fn_803A3480
#define ALLOCATOR_STATE lbl_805A5860
#define ALLOCATOR_INITIALIZED lbl_805F18F8
#elif defined(VERSION_GUPP8P)
#define CALLOC_FUNCTION fn_803A3C90
#define CALLOC_ZERO_FILL_HELPER fn_803A3E90
#define ALLOCATOR_STATE lbl_805A6300
#define ALLOCATOR_INITIALIZED lbl_805F2390
#else
#define CALLOC_FUNCTION fn_803A2C40
#define CALLOC_ZERO_FILL_HELPER fn_803A2E40
#define ALLOCATOR_STATE lbl_805A5240
#define ALLOCATOR_INITIALIZED lbl_805F12E8
#endif

extern unsigned int ALLOCATOR_STATE[14];
extern unsigned char ALLOCATOR_INITIALIZED;

extern void __begin_critical_region(int region);
extern void __end_critical_region(int region);
extern void *memset(void *destination, int value, unsigned int size);
extern void *CALLOC_ZERO_FILL_HELPER(void *heap, unsigned int size);

void *CALLOC_FUNCTION(unsigned int count, unsigned int size) {
    void *ptr;

    __begin_critical_region(1);
    if (ALLOCATOR_INITIALIZED == 0) {
        memset(ALLOCATOR_STATE, 0, 0x34);
        ALLOCATOR_INITIALIZED = 1;
    }

    ptr = CALLOC_ZERO_FILL_HELPER(ALLOCATOR_STATE, size * count);
    __end_critical_region(1);
    return ptr;
}
