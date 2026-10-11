/* Inferred two-word projection; original types/extent/arity are unknown. */
typedef struct Fn803CACD0Words {
    unsigned int word_0;
    unsigned int word_4;
} Fn803CACD0Words;

/* Inferred word lookup view; original table type is unknown. */
extern unsigned int lbl_80568CE0[];
/* Observed three-register byte-comparison projection; original full interface unknown. */
extern int fn_803AC8DC(const char *left, const char *right, unsigned int count);

/* The original uses signed byte indices without a range check. */
static inline unsigned int read_length(const signed char *record) {
    unsigned int length;

    length = lbl_80568CE0[(int)record[8]];
    length = (length << 4) + lbl_80568CE0[(int)record[9]];
    length = (length << 4) + lbl_80568CE0[(int)record[10]];
    length = (length << 4) + lbl_80568CE0[(int)record[11]];
    length = (length << 4) + lbl_80568CE0[(int)record[12]];
    length = (length << 4) + lbl_80568CE0[(int)record[13]];
    length = (length << 4) + lbl_80568CE0[(int)record[14]];
    return length;
}

/* Selected raw-address/word interface; original full types/arity/return unknown. */
unsigned int fn_803CACD0(Fn803CACD0Words *span, const char *wanted, const char *stop,
                         Fn803CACD0Words *output) {
    unsigned int cursor;
    unsigned int end;

    output->word_0 = 0;
    output->word_4 = 0;
    end = span->word_0 + span->word_4;
    cursor = span->word_0;
    while (cursor < end) {
        if (fn_803AC8DC((const char *)cursor, wanted, 7) == 0) {
            output->word_0 = cursor + 0x10;
            output->word_4 = read_length((const signed char *)cursor);
            break;
        }
        if (stop != 0 && fn_803AC8DC((const char *)cursor, stop, 7) == 0) {
            return 0;
        }
        cursor += read_length((const signed char *)cursor) + 0x10;
    }
    if (cursor < end) {
        return cursor;
    }
    return 0;
}
