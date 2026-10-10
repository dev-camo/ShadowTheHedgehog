typedef struct Fn803BF924Object {
    unsigned char padding[0x18];
    int field_18;
    int field_1C;
} Fn803BF924Object;

int fn_803BF924(Fn803BF924Object *object, int value_1C, int value_18) {
    object->field_1C = value_1C;
    object->field_18 = value_18;
    return 1;
}
