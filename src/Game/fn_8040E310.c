typedef struct Fn8040E310Args {
    unsigned short state;
    unsigned short padding;
    unsigned int value;
    unsigned int mode;
} Fn8040E310Args;

void fn_8040E310(Fn8040E310Args *object, unsigned int value) {
    object->value = 0;
    object->state = 0;
    object->mode = 0;
    object->value = value;
    object->mode = 2;
}

void fn_8040E330(Fn8040E310Args *object, unsigned short state) {
    object->value = 0;
    object->state = 0;
    object->mode = 0;
    object->state = state;
    object->mode = 1;
}
