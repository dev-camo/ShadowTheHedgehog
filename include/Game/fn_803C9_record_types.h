#ifndef FN_803C9_RECORD_TYPES_H
#define FN_803C9_RECORD_TYPES_H

#include "Game/fn_803C8_record_types.h"

/* Inferred accessed-field view; original full type and extent are unknown.
 * The indexed reader's shifts establish byte strides, not an original C array type.
 */
typedef struct Fn803C9RecordView {
    unsigned char unknown_0[4];
    unsigned int word_4;
    unsigned char unknown_8[4];
    unsigned int word_C;
    unsigned int word_10;
    unsigned int word_14;
    unsigned int word_18;
    unsigned int word_1C;
    unsigned int word_20;
    unsigned int word_24;
    unsigned char unknown_28[16];
    Fn803C8RecordCallback callback_38;
    unsigned int argument_3C;
} Fn803C9RecordView;

#ifdef __cplusplus
extern "C" {
#endif
extern const char lbl_80517288[];
/* Body-inferred raw-word/shift interfaces; original full types/arity unknown. */
unsigned int fn_803C9A7C(const Fn803C9RecordView *record, unsigned int row, unsigned int column);
unsigned int fn_803C9B50(const Fn803C9RecordView *record);
unsigned int fn_803C9BFC(const Fn803C9RecordView *record);
unsigned int fn_803C9CA8(const Fn803C9RecordView *record);
/* Inferred signed comparison/output interface; original full types/arity unknown. */
int fn_803C9D54(const Fn803C9RecordView *record, int mode, int requested, int *actual);
#ifdef __cplusplus
}
#endif
#endif
