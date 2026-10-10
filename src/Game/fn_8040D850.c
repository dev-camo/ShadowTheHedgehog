typedef struct Fn8040D850Args {
    char padding[36];
    float value;
} Fn8040D850Args;

void fn_8040D850(Fn8040D850Args *object, float value) {
    object->value = value;
}
