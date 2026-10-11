#ifndef GAME_FN_803C81_QUERY_TYPES_H
#define GAME_FN_803C81_QUERY_TYPES_H

/* Chosen accessed-field view; original C type and allocation extent unknown. */
typedef struct Fn803C81QueryView {
    unsigned char unknown_0;
    signed char byte_1;
    unsigned char unknown_2[0x22];
    unsigned int word_24;
} Fn803C81QueryView;

#ifdef __cplusplus
extern "C" {
#endif

/* Chosen consumed-pointer and result projections; original full interfaces unknown. */
unsigned int fn_803C81A4(const Fn803C81QueryView *object);
int fn_803C81E4(const Fn803C81QueryView *object);
int fn_804030A8(const Fn803C81QueryView *object);
/* Chosen side-effect projection; original full arity/types/return unknown. */
void fn_804030D4(void);

#ifdef __cplusplus
}
#endif

#endif
