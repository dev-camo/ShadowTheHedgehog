typedef struct Fn80406F08Object {
    unsigned char padding[0x1C8];
    int field_1C8;
} Fn80406F08Object;

typedef union Fn80406F08IntegerDouble {
    double value;
    struct {
        unsigned int high;
        unsigned int low;
    } words;
} Fn80406F08IntegerDouble;

extern const unsigned char lbl_80519DB8[];
extern const unsigned char lbl_80519DC0[];
extern void fn_8040773C(Fn80406F08Object *object, int value);

void fn_80406F08(Fn80406F08Object *object) {
    int field_1C8 = object->field_1C8;
    Fn80406F08IntegerDouble converted;

    /* Form the signed integer-to-double representation used by the target. */
    converted.words.low = (unsigned int)field_1C8 ^ 0x80000000;
    converted.words.high = 0x43300000;
    fn_8040773C(object, (int)((converted.value - *(const double *)lbl_80519DC0) *
                              *(const double *)lbl_80519DB8));
}
