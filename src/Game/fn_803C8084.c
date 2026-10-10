/* Inferred callee interfaces: neither body consumes incoming argument registers.
 * Original argument lists and return types are not established.
 */
extern void fn_803C8D94(void);
extern void fn_803C8DE0(void);

/* Inferred wrapper interfaces: several callers pass an opaque stack address.
 * It is unused here; the original type, full arity and return types are unknown.
 */
void fn_803C8084(void *unused_context) {
    fn_803C8D94();
}

void fn_803C80A4(void *unused_context) {
    fn_803C8DE0();
}
