#include "Game/fn_803C82_pool_types.h"

/* Chosen consumed-register interfaces; original full types/arity/returns unknown. */
extern void fn_803C80A4(void *context);
extern void fn_803C8084(void *context);
extern void fn_803C86F4(void *entry);
extern void fn_803C8050(unsigned int first_word, unsigned int second_word);
extern void *memset(void *destination, int value, unsigned int size);

void fn_803C8958(void) {
    /* Chosen opaque stack word; original context type/extent unknown. */
    unsigned int context;
    fn_803C80A4(&context);
    if (--lbl_805B65B0 == 0) {
        int index = 0;
        for (; index < 32; index++) {
            unsigned char *entry = &lbl_805B65B4[index * 0x238];
            if ((int)entry[0] == 1) {
                fn_803C86F4(entry);
            }
        }
        memset(lbl_805B65B4, 0, 0x4700);
        fn_803C8050(0, 0);
    }
    fn_803C8084(&context);
}
