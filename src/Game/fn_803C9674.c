#include "Game/fn_803C8_record_types.h"

/* Inferred accessed-word interface; original full types/arity/return identities unknown. */
unsigned int fn_803C9674(const Fn803C8RecordView *record) {
    const char *diagnostics = lbl_80517120;
    unsigned int result;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x128);
        fn_803ACA90(message, diagnostics + 0x1C);
        fn_803CAF48(message);
        result = 0;
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x134);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
        result = 0;
    } else {
        result = record->word_8;
    }
    fn_803C8D94();
    return result;
}
