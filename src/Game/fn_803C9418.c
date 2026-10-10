#include "Game/fn_803C8_record_types.h"

/* Inferred raw-word result and two consumed arguments; original full types/arity unknown. */
unsigned int fn_803C9418(const Fn803C8RecordView *record, int mode) {
    const char *diagnostics = lbl_80517120;
    unsigned int result;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0xE0);
        fn_803ACA90(message, diagnostics + 0x1C);
        fn_803CAF48(message);
        result = 0;
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0xEC);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
        result = 0;
    } else if (mode == 1) {
        result = record->word_C;
    } else if (mode == 0) {
        result = 0;
    } else {
        if (record->callback_1C != 0) {
            record->callback_1C(record->argument_20, -3);
        }
        result = 0;
    }
    fn_803C8D94();
    return result;
}
