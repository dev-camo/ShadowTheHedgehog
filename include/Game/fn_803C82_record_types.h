#ifndef GAME_FN_803C82_RECORD_TYPES_H
#define GAME_FN_803C82_RECORD_TYPES_H

/* Chosen accessed-field view; original C type/allocation extent unknown. */
typedef struct Fn803C82RecordView {
    unsigned char unknown_0;
    signed char byte_1;
    unsigned char byte_2;
    unsigned char unknown_3[0x11];
    unsigned int word_14;
    unsigned int word_18;
    unsigned int word_1C;
    unsigned int word_20;
    unsigned int word_24;
    void *pointer_28;
    unsigned int word_2C;
    unsigned char unknown_30[4];
    unsigned int word_34;
} Fn803C82RecordView;

#ifdef __cplusplus
extern "C" {
#endif

/* Chosen consumed-pointer/side-effect projections; original full interfaces unknown. */
void fn_803C8140(Fn803C82RecordView *object, int value);
void fn_803C8294(Fn803C82RecordView *object);

#ifdef __cplusplus
}
#endif

#endif
