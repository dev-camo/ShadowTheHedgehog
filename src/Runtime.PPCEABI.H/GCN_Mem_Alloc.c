#if defined(VERSION_GUPJ8P)
#define DEFAULT_HEAP lbl_805EE140
#define INITIALIZE_ALLOC fn_80371924
#define CREATE_HEAP fn_80371994
#define SET_CURRENT_HEAP fn_80371914
#define FREE_TO_HEAP fn_80371898
#define ALLOC_FROM_HEAP fn_8037179C
#define FREE_FUNCTION fn_803A2F84
#define ALLOCATE_FUNCTION fn_803A303C
#define INIT_ERROR_MESSAGE lbl_80514350
#define INIT_HEAP_MESSAGE lbl_80514388

extern int lbl_805EE140;
extern void *fn_80371924(void *arena_lo, void *arena_hi, int grow);
extern int fn_80371994(void *arena_lo, void *arena_hi);
extern int fn_80371914(int heap);
extern void fn_80371898(int heap, void *ptr);
extern void *fn_8037179C(int heap, unsigned int size);
void fn_803A2F84(void *ptr);
void *fn_803A303C(unsigned int size);
const char lbl_80514350[] = "GCN_Mem_Alloc.c : InitDefaultHeap. No Heap Available\n";
const char lbl_80514388[] = "Metrowerks CW runtime library initializing default heap\n";
#elif defined(VERSION_GUPP8P)
#define DEFAULT_HEAP lbl_805EEBE0
#define INITIALIZE_ALLOC fn_80372138
#define CREATE_HEAP fn_803721A8
#define SET_CURRENT_HEAP fn_80372128
#define FREE_TO_HEAP fn_803720AC
#define ALLOC_FROM_HEAP fn_80371FB0
#define FREE_FUNCTION fn_803A3994
#define ALLOCATE_FUNCTION fn_803A3A4C
#define INIT_ERROR_MESSAGE lbl_80514DC8
#define INIT_HEAP_MESSAGE lbl_80514E00

extern int lbl_805EEBE0;
extern void *fn_80372138(void *arena_lo, void *arena_hi, int grow);
extern int fn_803721A8(void *arena_lo, void *arena_hi);
extern int fn_80372128(int heap);
extern void fn_803720AC(int heap, void *ptr);
extern void *fn_80371FB0(int heap, unsigned int size);
void fn_803A3994(void *ptr);
void *fn_803A3A4C(unsigned int size);
const char lbl_80514DC8[] = "GCN_Mem_Alloc.c : InitDefaultHeap. No Heap Available\n";
const char lbl_80514E00[] = "Metrowerks CW runtime library initializing default heap\n";
#else
#define DEFAULT_HEAP lbl_805EDB30
#define INITIALIZE_ALLOC fn_803712F0
#define CREATE_HEAP fn_80371360
#define SET_CURRENT_HEAP fn_803712E0
#define FREE_TO_HEAP fn_80371264
#define ALLOC_FROM_HEAP fn_80371168
#define FREE_FUNCTION fn_803A2944
#define ALLOCATE_FUNCTION fn_803A29FC
#define INIT_ERROR_MESSAGE lbl_80513CB0
#define INIT_HEAP_MESSAGE lbl_80513CE8

extern int lbl_805EDB30;
extern void *fn_803712F0(void *arena_lo, void *arena_hi, int grow);
extern int fn_80371360(void *arena_lo, void *arena_hi);
extern int fn_803712E0(int heap);
extern void fn_80371264(int heap, void *ptr);
extern void *fn_80371168(int heap, unsigned int size);
void fn_803A2944(void *ptr);
void *fn_803A29FC(unsigned int size);
const char lbl_80513CB0[] = "GCN_Mem_Alloc.c : InitDefaultHeap. No Heap Available\n";
const char lbl_80513CE8[] = "Metrowerks CW runtime library initializing default heap\n";
#endif

extern void OSReport(const char *message, ...);
extern void *OSGetArenaLo(void);
extern void *OSGetArenaHi(void);
extern void OSSetArenaLo(void *arena_lo);

static inline void InitializeDefaultHeap(void) {
    if (DEFAULT_HEAP == -1) {
        void *arena_lo;
        void *arena_hi;
        int heap;
        OSReport(INIT_ERROR_MESSAGE);
        OSReport(INIT_HEAP_MESSAGE);
        arena_lo = OSGetArenaLo();
        arena_hi = OSGetArenaHi();
        arena_lo = INITIALIZE_ALLOC(arena_lo, arena_hi, 1);
        OSSetArenaLo(arena_lo);
        arena_lo = (void *)(((unsigned int)arena_lo + 0x1F) & ~0x1F);
        arena_hi = (void *)((unsigned int)arena_hi & ~0x1F);
        heap = CREATE_HEAP(arena_lo, arena_hi);
        SET_CURRENT_HEAP(heap);
        OSSetArenaLo(arena_hi);
    }
}

void FREE_FUNCTION(void *ptr) {
    InitializeDefaultHeap();
    FREE_TO_HEAP(DEFAULT_HEAP, ptr);
}

void *ALLOCATE_FUNCTION(unsigned int size) {
    InitializeDefaultHeap();
    return ALLOC_FROM_HEAP(DEFAULT_HEAP, size);
}
