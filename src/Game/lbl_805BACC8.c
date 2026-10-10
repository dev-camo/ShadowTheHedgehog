/* Inferred raw counter view; the original C type is unknown.
 * An explicit zero definition preserves MWCC's BSS symbol order.
 */
unsigned int lbl_805BACC8 = 0;

/* Observed accesses cover 32 slots of 0x24 bytes. Preserve the four remaining
 * allocation bytes without asserting the original pool or slot types.
 */
unsigned char lbl_805BACCC[0x480 + 4];
