#include "Game/fn_803C9_record_types.h"

/* Inferred side-effect projection; original full types/arity/return unknown. */
void fn_803CA68C(Fn803C9RecordView *record) {
    const char *diagnostics = lbl_80517288;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x19C);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x1A8);
        fn_803ACA90(message, diagnostics + 0x74);
        fn_803CAF48(message);
    } else {
        record->word_C = 0;
        record->word_10 = record->word_20;
        record->word_14 = 0;
        record->word_18 = 0;
        record->word_28 = 0;
        record->word_2C = 0;
        record->word_30 = 0;
        record->word_34 = 0;
    }
    fn_803C8D94();
}
