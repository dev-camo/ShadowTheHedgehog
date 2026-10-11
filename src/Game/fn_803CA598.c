#include "Game/fn_803C9_record_types.h"

/* Inferred raw return and mode projection; original full types/arity unknown. */
unsigned int fn_803CA598(const Fn803C9RecordView *record, int mode) {
    const char *diagnostics = lbl_80517288;
    unsigned int result;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];
        fn_803ACB00(message, diagnostics + 0x184);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
        result = 0;
    } else if ((int)record->word_4 == 0) {
        char message[64];
        fn_803ACB00(message, diagnostics + 0x190);
        fn_803ACA90(message, diagnostics + 0x74);
        fn_803CAF48(message);
        result = 0;
    } else if (mode == 1) {
        result = record->word_C;
    } else if (mode == 0) {
        result = record->word_10;
    } else {
        if (record->callback_38 != 0) {
            record->callback_38(record->argument_3C, -3);
        }
        result = 0;
    }
    fn_803C8D94();
    return result;
}
