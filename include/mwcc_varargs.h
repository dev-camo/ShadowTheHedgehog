#ifndef MWCC_VARARGS_H
#define MWCC_VARARGS_H

/* Compiler EABI cursor view used by __builtin_va_info.
 * The original source typedef identity is unknown.
 */
typedef struct {
    unsigned char gpr;
    unsigned char fpr;
    unsigned char reserved[2];
    void *input_arg_area;
    void *reg_save_area;
} MwccVaList[1];

#ifdef __cplusplus
extern "C" {
#endif

/* Chosen consumed-buffer/format/cursor and returned-count projection.
 * Original full types and argument list are unknown.
 */
extern int fn_803A92D8(char *buffer, const char *format, MwccVaList args);

#ifdef __cplusplus
}
#endif

#endif
