#if defined(VERSION_GUPJ8P)
#define DEFAULT_HEAP lbl_805EE140
#define INITIALIZE_ALLOC fn_80371924
#define CREATE_HEAP fn_80371994
#define FINISH_ALLOC fn_80371914
#define ALLOCATE_ONE fn_80371898
#define ALLOCATE_TWO fn_8037179C
#define ALLOCATE_FUNCTION_ONE fn_803A2F84
#define ALLOCATE_FUNCTION_TWO fn_803A303C
#define INIT_ERROR_MESSAGE lbl_80514350
#define INIT_HEAP_MESSAGE lbl_80514388

extern int lbl_805EE140;
extern void *fn_80371924(void *arena_lo, void *arena_hi, int grow);
extern void fn_80371994(void *arena_lo, void *arena_hi);
extern void fn_80371914(void);
extern void *fn_80371898(int heap, unsigned int size);
extern void *fn_8037179C(int heap, unsigned int size);
void *fn_803A2F84(unsigned int size);
void *fn_803A303C(unsigned int size);
const char lbl_80514350[] = "GCN_Mem_Alloc.c : InitDefaultHeap. No Heap Available\n";
const char lbl_80514388[] = "Metrowerks CW runtime library initializing default heap\n";
#elif defined(VERSION_GUPP8P)
#define DEFAULT_HEAP lbl_805EEBE0
#define INITIALIZE_ALLOC fn_80372138
#define CREATE_HEAP fn_803721A8
#define FINISH_ALLOC fn_80372128
#define ALLOCATE_ONE fn_803720AC
#define ALLOCATE_TWO fn_80371FB0
#define ALLOCATE_FUNCTION_ONE fn_803A3994
#define ALLOCATE_FUNCTION_TWO fn_803A3A4C
#define INIT_ERROR_MESSAGE lbl_80514DC8
#define INIT_HEAP_MESSAGE lbl_80514E00

extern int lbl_805EEBE0;
extern void *fn_80372138(void *arena_lo, void *arena_hi, int grow);
extern void fn_803721A8(void *arena_lo, void *arena_hi);
extern void fn_80372128(void);
extern void *fn_803720AC(int heap, unsigned int size);
extern void *fn_80371FB0(int heap, unsigned int size);
void *fn_803A3994(unsigned int size);
void *fn_803A3A4C(unsigned int size);
const char lbl_80514DC8[] = "GCN_Mem_Alloc.c : InitDefaultHeap. No Heap Available\n";
const char lbl_80514E00[] = "Metrowerks CW runtime library initializing default heap\n";
#else
#define DEFAULT_HEAP lbl_805EDB30
#define INITIALIZE_ALLOC fn_803712F0
#define CREATE_HEAP fn_80371360
#define FINISH_ALLOC fn_803712E0
#define ALLOCATE_ONE fn_80371264
#define ALLOCATE_TWO fn_80371168
#define ALLOCATE_FUNCTION_ONE fn_803A2944
#define ALLOCATE_FUNCTION_TWO fn_803A29FC
#define INIT_ERROR_MESSAGE lbl_80513CB0
#define INIT_HEAP_MESSAGE lbl_80513CE8

extern int lbl_805EDB30;
extern void *fn_803712F0(void *arena_lo, void *arena_hi, int grow);
extern void fn_80371360(void *arena_lo, void *arena_hi);
extern void fn_803712E0(void);
extern void *fn_80371264(int heap, unsigned int size);
extern void *fn_80371168(int heap, unsigned int size);
void *fn_803A2944(unsigned int size);
void *fn_803A29FC(unsigned int size);
const char lbl_80513CB0[] = "GCN_Mem_Alloc.c : InitDefaultHeap. No Heap Available\n";
const char lbl_80513CE8[] = "Metrowerks CW runtime library initializing default heap\n";
#endif

extern void OSReport(const char *message, ...);
extern void *OSGetArenaLo(void);
extern void *OSGetArenaHi(void);
extern void OSSetArenaLo(void *arena_lo);

#define ALLOCATE_FROM_DEFAULT_HEAP(allocate, size)                                                 \
    do {                                                                                           \
        if (DEFAULT_HEAP == -1) {                                                                  \
            unsigned int arena_lo;                                                                 \
            unsigned int arena_hi;                                                                 \
            unsigned int new_arena_lo;                                                             \
            OSReport(INIT_ERROR_MESSAGE);                                                          \
            OSReport(INIT_HEAP_MESSAGE);                                                           \
            arena_lo = (unsigned int)OSGetArenaLo();                                               \
            arena_hi = (unsigned int)OSGetArenaHi();                                               \
            new_arena_lo = (unsigned int)INITIALIZE_ALLOC((void *)arena_lo, (void *)arena_hi, 1);  \
            OSSetArenaLo((void *)new_arena_lo);                                                    \
            new_arena_lo = (new_arena_lo + 0x1F) & ~0x1F;                                          \
            arena_hi &= ~0x1F;                                                                     \
            CREATE_HEAP((void *)new_arena_lo, (void *)arena_hi);                                   \
            FINISH_ALLOC();                                                                        \
            OSSetArenaLo((void *)arena_hi);                                                        \
        }                                                                                          \
        return allocate(DEFAULT_HEAP, size);                                                       \
    } while (0)

void *ALLOCATE_FUNCTION_ONE(unsigned int size) {
    ALLOCATE_FROM_DEFAULT_HEAP(ALLOCATE_ONE, size);
}

void *ALLOCATE_FUNCTION_TWO(unsigned int size) {
    ALLOCATE_FROM_DEFAULT_HEAP(ALLOCATE_TWO, size);
}

#undef ALLOCATE_FROM_DEFAULT_HEAP
