typedef struct Fn8040307CObject {
    unsigned char padding[0x48];
    void *field_48;
} Fn8040307CObject;

extern void fn_803C8140(void *object, int value);

void fn_8040307C(Fn8040307CObject *object, int value) {
    void *field_48 = object->field_48;

    if (field_48 != 0) {
        fn_803C8140(field_48, value);
    }
}
