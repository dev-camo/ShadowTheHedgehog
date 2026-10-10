typedef struct Fn803C8140Object {
    unsigned char padding[0x14];
    int field_14;
    int field_18;
} Fn803C8140Object;

extern const char lbl_80516D18[];
extern const char lbl_80516D44[];
extern void fn_803C7F90(const char *format, ...);

void fn_803C8140(Fn803C8140Object *object, int value) {
    if (object == 0) {
        fn_803C7F90(lbl_80516D18);
    } else if (value < 0 || value > object->field_18) {
        fn_803C7F90(lbl_80516D44, value);
    } else {
        object->field_14 = value;
    }
}
