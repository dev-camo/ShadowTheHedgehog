#include "Game/fn_803C81_query_types.h"
extern const char lbl_80516ECC[];
extern const char lbl_80516EF8[];
extern void fn_803C7F90(const char *format, ...);

unsigned int fn_803C81A4(const Fn803C81QueryView *object) {
    if (object == 0) {
        fn_803C7F90(lbl_80516ECC);
        return (unsigned int)-1;
    } else {
        return object->word_24;
    }
}
int fn_803C81E4(const Fn803C81QueryView *object) {
    if (object == 0) {
        fn_803C7F90(lbl_80516EF8);
        return -1;
    } else {
        return object->byte_1;
    }
}
