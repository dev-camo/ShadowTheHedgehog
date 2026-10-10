#include "Game/fn_803C8_record_types.h"

/* Inferred raw counter and external byte-span views; original types are unknown. */
unsigned int lbl_805BACC8;
extern unsigned char lbl_805BACCC[];
extern const char lbl_80517278[];
extern void *memset(void *destination, int value, unsigned int size);
/* Chosen side-effect projections; original full arity/returns unknown. */
void fn_803C8E2C(void);
void fn_803C8E5C(void);

/* Inferred side-effect interfaces; original full arity/returns unknown. */
void fn_803C99A0(void) {
    fn_803C8DE0();
    if (--lbl_805BACC8 == 0) {
        memset(&lbl_805BACCC, 0, 0x480);
    }
    fn_803C8D94();
    fn_803C8E2C();
}

void fn_803C99F4(void) {
    fn_803C8E5C();
    fn_803C8DE0();
    if ((int)lbl_805BACC8 == 0) {
        memset(&lbl_805BACCC, 0, 0x480);
    }
    lbl_805BACC8++;
    fn_803C8D94();
}

/* Callback-compatible projection; ignored registers do not establish original types/arity. */
void fn_803C9A54(unsigned int context, int argument) {
    (void)context;
    (void)argument;
    fn_803CAF48(lbl_80517278);
}
