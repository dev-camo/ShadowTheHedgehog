#include "Game/fn_803C8_record_types.h"

/* Existing runtime memory-set interface; return unused in this unit. */
extern void *memset(void *destination, int value, unsigned int size);

/* Inferred accessed-word interface; original full types/arity/return identities unknown. */
void fn_803C9720(Fn803C8RecordView *record) {
    const char *diagnostics = lbl_80517120;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x140);
        fn_803ACA90(message, diagnostics + 0x1C);
        fn_803CAF48(message);
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x14C);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
    } else {
        memset(record, 0, 0x24);
        /* Original stores this word separately after clearing the 0x24-byte span. */
        record->word_4 = 0;
    }
    fn_803C8D94();
}
