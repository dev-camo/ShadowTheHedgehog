#include "Game/fn_803C8_record_types.h"

/* Inferred accessed-word interface; original full types/arity/return identities unknown. */
void fn_803C95B8(Fn803C8RecordView *record, Fn803C8RecordCallback callback, unsigned int context) {
    const char *diagnostics = lbl_80517120;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x110);
        fn_803ACA90(message, diagnostics + 0x1C);
        fn_803CAF48(message);
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x11C);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
    } else {
        record->callback_1C = callback;
        record->argument_20 = context;
    }
    fn_803C8D94();
}
