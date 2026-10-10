/* Inferred storage layout; the trailing four bytes have no established type. */
typedef struct {
    volatile unsigned int count;
    unsigned char reserved[4];
} NestingState;

NestingState lbl_805BACC0;
extern volatile unsigned int lbl_805BACB8;

/* Inferred side-effect interfaces; original argument lists/return types unknown.
 * Signed comparison views select target cmpwi without asserting original signedness.
 */
void fn_803C8E2C(void) {
    lbl_805BACC0.count--;
    if ((int)lbl_805BACC0.count == 0) {
        lbl_805BACB8 = 0;
    }
}

void fn_803C8E5C(void) {
    lbl_805BACC0.count++;
    if ((int)lbl_805BACC0.count == 1) {
        lbl_805BACB8 = 0;
    }
}
