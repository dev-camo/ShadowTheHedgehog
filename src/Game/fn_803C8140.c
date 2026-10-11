#include "Game/fn_803C82_record_types.h"

extern const char lbl_80516D18[];
extern const char lbl_80516D44[];
extern void fn_803C7F90(const char *format, ...);

void fn_803C8140(Fn803C82RecordView *object, int value) {
    if (object == 0) {
        fn_803C7F90(lbl_80516D18);
    } else if (value < 0 || value > (int)object->word_18) {
        fn_803C7F90(lbl_80516D44, value);
    } else {
        object->word_14 = value;
    }
}
