typedef struct Fn8040C244Args {
    char padding[8];
    int count;
} Fn8040C244Args;

void fn_8040C244(Fn8040C244Args *object) {
    if (object->count > 0) {
        object->count--;
    }
}
