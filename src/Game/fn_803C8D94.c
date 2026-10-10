/* Inferred raw 32-bit SDK call interfaces; the restore result is unused. */
extern unsigned int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(unsigned int state);

/* Inferred raw storage views; volatile preserves the observed count reload.
 * The signed zero-test view selects MWCC cmpwi without asserting original signedness.
 */
volatile unsigned int lbl_805BACB8;
unsigned int lbl_805BACBC;

/* Inferred side-effect interfaces; original argument lists/return types unknown. */
void fn_803C8D94(void) {
    lbl_805BACB8--;
    if ((int)lbl_805BACB8 == 0) {
        OSRestoreInterrupts(lbl_805BACBC);
    }
}

void fn_803C8DE0(void) {
    if ((int)lbl_805BACB8 == 0) {
        lbl_805BACBC = OSDisableInterrupts();
    }
    lbl_805BACB8++;
}
