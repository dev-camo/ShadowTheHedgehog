#include "Game/fn_803CB_state_types.h"
#include "Game/fn_803CB_text_types.h"
#include "mwcc_varargs.h"

extern void *memset(void *destination, int value, unsigned int size);

/* Chosen variadic side-effect projection; original return/full interface unknown. */
void fn_803CBB34(const char *format, ...) {
    MwccVaList args;
    Fn803CBTextCallback callback;
    Fn803CBPairView *pair;

    memset(lbl_805BFDA0, 0, 0x80);
    /* Keep cursor initialization after clearing the output buffer. */
    __builtin_va_info(args);
    fn_803A92D8((char *)lbl_805BFDA0, format, args);
    pair = &lbl_805BFE20;
    callback = (Fn803CBTextCallback)pair->word_0;
    if (callback != 0) {
        callback(pair->word_4, (const char *)lbl_805BFDA0);
    }
}
