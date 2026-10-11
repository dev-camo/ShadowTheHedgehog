#include "Game/fn_803C8_record_types.h"

/* Inferred raw counter and external byte-span views; original types are unknown. */
extern unsigned int lbl_805BF158;
extern unsigned char lbl_805BF15C[];
extern void *memset(void *destination, int value, unsigned int size);
/* Chosen side-effect projections; original full arity/returns unknown. */
void fn_803C8E2C(void);
void fn_803C8E5C(void);

/* Inferred side-effect interfaces; original full arity/returns unknown. */
void fn_803CAC1C(void) {
    fn_803C8DE0();
    if (--lbl_805BF158 == 0) {
        memset(&lbl_805BF15C, 0, 0xC00);
    }
    fn_803C8D94();
    fn_803C8E2C();
}

void fn_803CAC70(void) {
    fn_803C8E5C();
    fn_803C8DE0();
    if ((int)lbl_805BF158 == 0) {
        memset(&lbl_805BF15C, 0, 0xC00);
    }
    lbl_805BF158++;
    fn_803C8D94();
}
