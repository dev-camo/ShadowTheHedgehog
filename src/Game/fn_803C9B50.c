#include "Game/fn_803C9_record_types.h"

/* Body-inferred raw-word result; original full types/arity are unknown. */
unsigned int fn_803C9B50(const Fn803C9RecordView *record) {
    const char *diagnostics = lbl_80517288;
    unsigned int result;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0xAC);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
        result = 0;
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0xB8);
        fn_803ACA90(message, diagnostics + 0x74);
        fn_803CAF48(message);
        result = 0;
    } else {
        result = record->word_24;
    }
    fn_803C8D94();
    return result;
}
