/* Inferred callback signature; only the two 32-bit argument slots are observed. */
typedef void (*Callback)(unsigned int argument_4, unsigned int argument_8);

/* Inferred storage layout; the final four bytes have no observed accesses. */
typedef struct {
    Callback callback;
    unsigned int argument_4;
    unsigned int argument_8;
    unsigned char reserved[4];
} CallbackState;

CallbackState lbl_805B65A0;

/* Inferred dispatcher signature; the observed caller prepares no arguments or result use. */
void fn_803C8100(void) {
    CallbackState *state = &lbl_805B65A0;
    Callback callback = state->callback;

    if (callback != 0) {
        callback(state->argument_4, state->argument_8);
    }
}
