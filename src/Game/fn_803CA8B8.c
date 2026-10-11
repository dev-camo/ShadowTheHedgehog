#include "Game/fn_803C9_record_types.h"

/* Existing runtime memory-set interface; return unused in this unit. */
extern void *memset(void *destination, int value, unsigned int size);

/* Inferred accessed-word interface; original full types/arity/return identities unknown. */
void fn_803CA8B8(Fn803C9RecordView *record) {
    const char *diagnostics = lbl_80517288;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x1E4);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x1F0);
        fn_803ACA90(message, diagnostics + 0x74);
        fn_803CAF48(message);
    } else {
        memset(record, 0, 0x40);
        /* Observed literal span; original full record type is unknown. */
        /* The original also stores this word separately after the clear. */
        record->word_4 = 0;
    }
    fn_803C8D94();
}
