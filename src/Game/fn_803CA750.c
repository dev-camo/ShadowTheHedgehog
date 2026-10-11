#include "Game/fn_803C9_record_types.h"

/* Inferred accessed-word interface; original full types/arity/return identities unknown. */
void fn_803CA750(Fn803C9RecordView *record, Fn803C8RecordCallback callback, unsigned int context) {
    const char *diagnostics = lbl_80517288;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x1B4);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x1C0);
        fn_803ACA90(message, diagnostics + 0x74);
        fn_803CAF48(message);
    } else {
        record->callback_38 = callback;
        record->argument_3C = context;
    }
    fn_803C8D94();
}
