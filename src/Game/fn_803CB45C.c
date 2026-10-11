#include "Game/fn_803CB_state_types.h"

/* Chosen consumed-context projection; original full interface unknown. */
typedef void (*Fn803CBIndexedCallback)(unsigned int argument);

/* Chosen index/side-effect interface; original full types/arity/return unknown. */
void fn_803CB45C(unsigned int index) {
    Fn803CBPairView *entries = (Fn803CBPairView *)lbl_805BFE38;
    Fn803CBIndexedCallback callback = (Fn803CBIndexedCallback)entries[index].word_0;
    if (callback != 0) {
        callback(entries[index].word_4);
    }
}
