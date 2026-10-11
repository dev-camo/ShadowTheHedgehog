#ifndef GAME_FN_803CB_STATE_TYPES_H
#define GAME_FN_803CB_STATE_TYPES_H

/* Chosen word/backing views. Original C types and qualifiers are unknown. */
typedef struct Fn803CBStateView {
    unsigned int word_0;
    unsigned int word_4;
    unsigned int word_8;
    unsigned char unknown_C[0x20];
    unsigned char unknown_2C[8];
    unsigned char unknown_34[8];
    unsigned int word_3C;
} Fn803CBStateView;

typedef struct Fn803CBPairView {
    unsigned int word_0;
    unsigned int word_4;
} Fn803CBPairView;

extern Fn803CBStateView lbl_805BFD60;
extern unsigned char lbl_805BFDA0[0x80];
/* Raw backing extent; original aggregate/type identity unknown. */
extern unsigned char lbl_805BFE38[0x2C0];
extern Fn803CBPairView lbl_805BFE20;
extern Fn803CBPairView lbl_805BFE28;
extern Fn803CBPairView lbl_805BFE30;

#ifdef __cplusplus
extern "C" {
#endif

/* Chosen index/side-effect interface; original full types/arity/return unknown. */
void fn_803CB45C(unsigned int index);

#ifdef __cplusplus
}
#endif

#endif
