#include "Game/fn_803C9_record_types.h"

/* Body-inferred raw-word result; original full types/arity are unknown. */
unsigned int fn_803C9A7C(const Fn803C9RecordView *record, unsigned int row, unsigned int column) {
    const char *diagnostics = lbl_80517288;
    unsigned int result;

    fn_803C8DE0();
    if (record == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x3C);
        fn_803ACA90(message, diagnostics + 0x48);
        fn_803CAF48(message);
        result = 0;
    } else if ((int)record->word_4 == 0) {
        char message[64];

        fn_803ACB00(message, diagnostics + 0x68);
        fn_803ACA90(message, diagnostics + 0x74);
        fn_803CAF48(message);
        result = 0;
    } else {
        const unsigned char *address = (const unsigned char *)record + (row << 3);

        address += column << 2;
        result = *(const unsigned int *)(address + 0x28);
    }
    fn_803C8D94();
    return result;
}
