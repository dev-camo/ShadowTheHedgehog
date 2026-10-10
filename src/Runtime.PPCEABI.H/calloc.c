#if defined(VERSION_GUPJ8P)
#define CALLOC_FUNCTION fn_803A3280
#define ALLOCATE_FUNCTION fn_803A3308
#define CALLOC_ZERO_FILL_HELPER fn_803A3480
#define ALLOCATE_HELPER fn_803A34CC
#define ALLOCATOR_RELEASE_FUNCTION fn_803A3394
#define ALLOCATOR_RELEASE_HELPER fn_803A3C80
#define ALLOCATOR_STATE lbl_805A5860
#define ALLOCATOR_INITIALIZED lbl_805F18F8
#elif defined(VERSION_GUPP8P)
#define CALLOC_FUNCTION fn_803A3C90
#define ALLOCATE_FUNCTION fn_803A3D18
#define CALLOC_ZERO_FILL_HELPER fn_803A3E90
#define ALLOCATE_HELPER fn_803A3EDC
#define ALLOCATOR_RELEASE_FUNCTION fn_803A3DA4
#define ALLOCATOR_RELEASE_HELPER fn_803A4690
#define ALLOCATOR_STATE lbl_805A6300
#define ALLOCATOR_INITIALIZED lbl_805F2390
#else
#define CALLOC_FUNCTION fn_803A2C40
#define ALLOCATE_FUNCTION fn_803A2CC8
#define CALLOC_ZERO_FILL_HELPER fn_803A2E40
#define ALLOCATE_HELPER fn_803A2E8C
#define ALLOCATOR_RELEASE_FUNCTION fn_803A2D54
#define ALLOCATOR_RELEASE_HELPER fn_803A3640
#define ALLOCATOR_STATE lbl_805A5240
#define ALLOCATOR_INITIALIZED lbl_805F12E8
#endif

extern unsigned int ALLOCATOR_STATE[14];
extern unsigned char ALLOCATOR_INITIALIZED;

extern void __begin_critical_region(int region);
extern void __end_critical_region(int region);
extern void *memset(void *destination, int value, unsigned int size);
extern void *CALLOC_ZERO_FILL_HELPER(void *heap, unsigned int size);
extern void *ALLOCATE_HELPER(void *heap, int arg0, int arg1);
extern void ALLOCATOR_RELEASE_HELPER(void *heap, void *ptr);

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

void *ALLOCATE_FUNCTION(int arg0, int arg1) {
    void *ptr;

    __begin_critical_region(1);
    if (ALLOCATOR_INITIALIZED == 0) {
        memset(ALLOCATOR_STATE, 0, 0x34);
        ALLOCATOR_INITIALIZED = 1;
    }

    ptr = ALLOCATE_HELPER(ALLOCATOR_STATE, arg0, arg1);
    __end_critical_region(1);
    return ptr;
}

void ALLOCATOR_RELEASE_FUNCTION(void *ptr) {
    __begin_critical_region(1);
    if (ALLOCATOR_INITIALIZED == 0) {
        memset(ALLOCATOR_STATE, 0, 0x34);
        ALLOCATOR_INITIALIZED = 1;
    }

    ALLOCATOR_RELEASE_HELPER(ALLOCATOR_STATE, ptr);
    __end_critical_region(1);
}
