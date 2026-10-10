#include "Game/fn_803C8_record_types.h"

/* Inferred raw 32-bit result; only the two indicated fields are observed. */
unsigned int fn_803C8E8C(const Fn803C8RecordView *record) {
    unsigned int result;
    const char *diagnostics = lbl_80517120;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x10);
        fn_803ACA90(message, diagnostics + 0x1C);
        fn_803CAF48(message);
        result = 0;
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x3C);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
        result = 0;
    } else {
        result = record->word_18;
    }
    fn_803C8D94();
    return result;
}
