#include "Game/fn_803CB_state_types.h"
#include "Game/fn_803CB_text_types.h"

/* Chosen message side-effect projection; original full types/arity/return unknown. */
void fn_803CBADC(const char *text) {
    Fn803CBTextCallback callback;
    fn_803ACABC((char *)lbl_805BFDA0, text, 0x7F);
    callback = (Fn803CBTextCallback)lbl_805BFE20.word_0;
    if (callback != 0) {
        callback(lbl_805BFE20.word_4, (const char *)lbl_805BFDA0);
    }
}
