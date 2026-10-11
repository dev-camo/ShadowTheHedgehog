#include "Game/fn_803C8_record_types.h"

/* Inferred raw counter and external byte-span views; original types are unknown. */
extern unsigned int lbl_805BB150;
extern unsigned char lbl_805BB154[];
extern const char lbl_80517484[];
extern void *memset(void *destination, int value, unsigned int size);
/* Chosen side-effect projections; original full arity/returns unknown. */
void fn_803C8E2C(void);
void fn_803C8E5C(void);

/* Inferred side-effect interfaces; original full arity/returns unknown. */
void fn_803CAB40(void) {
    fn_803C8DE0();
    if (--lbl_805BB150 == 0) {
        memset(&lbl_805BB154, 0, 0x4000);
    }
    fn_803C8D94();
    fn_803C8E2C();
}

void fn_803CAB94(void) {
    fn_803C8E5C();
    fn_803C8DE0();
    if ((int)lbl_805BB150 == 0) {
        memset(&lbl_805BB154, 0, 0x4000);
    }
    lbl_805BB150++;
    fn_803C8D94();
}

/* Callback-compatible projection; ignored registers do not establish original types/arity. */
void fn_803CABF4(unsigned int context, int argument) {
    (void)context;
    (void)argument;
    fn_803CAF48(lbl_80517484);
}
