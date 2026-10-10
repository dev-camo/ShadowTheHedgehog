#include "Game/fn_803C8_record_types.h"

/* Inferred side-effect interface; original full argument lists/returns are unknown. */
void fn_803C904C(Fn803C8RecordView *record, int mode, Fn803C8DescriptorView *descriptor) {
    const char *diagnostics = lbl_80517120;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x98);
        fn_803ACA90(message, diagnostics + 0x1C);
        fn_803CAF48(message);
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0xA4);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
    } else if (descriptor->word_4 > 0 && descriptor->word_0 != 0) {
        if (mode == 0) {
            if (record->callback_1C != 0) {
                record->callback_1C(record->argument_20, -3);
            }
        } else if (mode == 1) {
            int remaining = (int)(record->word_10 - (unsigned int)descriptor->word_4);
            unsigned int updated;

            remaining = remaining > 0 ? remaining : 0;
            record->word_10 = (unsigned int)remaining;
            updated = record->word_C + (unsigned int)descriptor->word_4;
            if ((int)record->word_18 < (int)updated) {
                updated = record->word_18;
            }
            record->word_C = updated;
            if (remaining != (int)(descriptor->word_0 - record->word_14)) {
                if (record->callback_1C != 0) {
                    record->callback_1C(record->argument_20, -3);
                }
            }
        } else {
            descriptor->word_4 = 0;
            descriptor->word_0 = 0;
            if (record->callback_1C != 0) {
                record->callback_1C(record->argument_20, -3);
            }
        }
    }
    fn_803C8D94();
}
