#include "Game/fn_803C8_record_types.h"

/* Inferred side-effect interface; original full argument lists/returns are unknown. */
void fn_803C91E0(const Fn803C8RecordView *record, int mode, Fn803C8DescriptorView *descriptor) {
    const char *diagnostics = lbl_80517120;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0xB0);
        fn_803ACA90(message, diagnostics + 0x1C);
        fn_803CAF48(message);
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0xBC);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
    } else if (descriptor->word_4 > 0 && descriptor->word_0 != 0 && mode != 0 && mode != 1) {
        descriptor->word_4 = 0;
        descriptor->word_0 = 0;
        if (record->callback_1C != 0) {
            record->callback_1C(record->argument_20, -3);
        }
    }
    fn_803C8D94();
}
