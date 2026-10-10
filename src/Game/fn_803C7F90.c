/* MWCC EABI varargs layout; __builtin_va_info initializes these fields. */
typedef struct {
    unsigned char gpr;
    unsigned char fpr;
    unsigned char reserved[2];
    void *input_arg_area;
    void *reg_save_area;
} MwccVaList[1];

/* Inferred formatter signature; the return value is unused here. */
extern int fn_803A92D8(char *buffer, const char *format, MwccVaList args);

/* Inferred callback signature; its return value is unused. */
typedef void (*DiagnosticCallback)(void *context, const char *text);

/* Inferred storage view from this helper and fn_803C8050. */
typedef struct {
    DiagnosticCallback callback;
    void *context;
    char text[0x100];
} DiagnosticState;

/* Incomplete storage views preserve the target's absolute-address loads and stores. */
extern DiagnosticCallback lbl_805B6498[];
extern void *lbl_805B649C[];

/* Inferred variadic diagnostic signature; callers do not consume a result. */
void fn_803C7F90(const char *format, ...) {
    MwccVaList args;
    DiagnosticCallback callback;
    DiagnosticState *state = (DiagnosticState *)lbl_805B6498;

    /* Use the compiler intrinsic to save registers and initialize the varargs cursor. */
    __builtin_va_info(args);
    fn_803A92D8(state->text, format, args);
    callback = state->callback;
    if (callback != 0) {
        callback(state->context, state->text);
    }
}

/* Inferred setter signature; callers do not consume a result. */
void fn_803C8050(DiagnosticCallback callback, void *context) {
    if (callback == 0) {
        lbl_805B6498[0] = 0;
        lbl_805B649C[0] = 0;
    } else {
        lbl_805B6498[0] = callback;
        lbl_805B649C[0] = context;
    }
}
