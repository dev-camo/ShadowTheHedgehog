#include "Game/fn_803C8_record_types.h"

/* Inferred accessed-word interface; original full types/arity/return identities unknown. */
void fn_803C950C(Fn803C8RecordView *record) {
    const char *diagnostics = lbl_80517120;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0xF8);
        fn_803ACA90(message, diagnostics + 0x1C);
        fn_803CAF48(message);
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x104);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
    } else {
        record->word_C = record->word_18;
        record->word_10 = 0;
    }
    fn_803C8D94();
}
