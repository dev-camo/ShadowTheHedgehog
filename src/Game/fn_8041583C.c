typedef struct Fn8041583CArgs {
    char padding[32];
    void *value;
} Fn8041583CArgs;

void *fn_8041583C(Fn8041583CArgs *object) {
    if (object != 0) {
        return object->value;
    }
    return 0;
}
