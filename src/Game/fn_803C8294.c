#include "Game/fn_803C82_record_types.h"

extern const char lbl_80516F50[];
extern const char lbl_80516F7C[];
extern void fn_803C7F90(const char *format, ...);
/* Chosen consumed-pointer/side-effect projection; original full interface unknown. */
extern void fn_803C0018(void *object);

/* Inferred inline behavior; original helper identity/interface unknown. */
static inline void clear_idle_fields(Fn803C82RecordView *object) {
    if (object == 0) {
        fn_803C7F90(lbl_80516F7C);
    } else if (object->byte_1 == 0) {
        object->word_1C = 0;
        object->word_20 = 0;
        object->word_24 = 0;
    }
}
/* Chosen consumed-pointer/side-effect projection; original full interface unknown. */
void fn_803C8294(Fn803C82RecordView *object) {
    if (object == 0) {
        fn_803C7F90(lbl_80516F50);
    } else if (object->byte_1 != 0) {
        object->byte_1 = 0;
        if (object->pointer_28 != 0 && (int)object->byte_2 == 1) {
            fn_803C0018(object->pointer_28);
            object->byte_2 = 0;
        }
        object->word_2C = 0;
        clear_idle_fields(object);
        object->word_34 = 0;
    }
}
