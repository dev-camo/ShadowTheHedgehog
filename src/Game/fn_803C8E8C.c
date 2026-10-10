/* Inferred string-copy/append interfaces; return values are unused here. */
extern char *fn_803ACB00(char *destination, const char *source);
extern char *fn_803ACA90(char *destination, const char *source);

/* Inferred side-effect interfaces; original full argument lists/returns unknown. */
extern void fn_803CAF48(const char *text);
extern void fn_803C8DE0(void);
extern void fn_803C8D94(void);
extern const char lbl_80517120[];

/* Inferred read-only storage view; other bytes and original type are unknown. */
typedef struct {
    unsigned char unknown_0[4];
    unsigned int word_4;
    unsigned char unknown_8[16];
    unsigned int word_18;
} RecordView;

/* Inferred raw 32-bit result; only the two indicated fields are observed. */
unsigned int fn_803C8E8C(const RecordView *record) {
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
