extern const char lbl_80516CC0[];
extern void fn_803C7F90(const char *format, ...);

/* Inferred signature: the caller supplies a pointer and a 32-bit argument.
 * Only the low byte of the second argument is observed; no result is consumed.
 */
void fn_803C80C4(unsigned char *object, unsigned int value) {
    if (object == 0) {
        fn_803C7F90(lbl_80516CC0);
    } else {
        object[3] = value;
    }
}
