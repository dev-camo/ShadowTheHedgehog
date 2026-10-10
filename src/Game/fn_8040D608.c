typedef struct Fn8040D608Args {
    unsigned char state;
    unsigned char padding1;
    unsigned short flags;
    unsigned short limit;
    unsigned short padding6;
    unsigned int field8;
    unsigned int field12;
    unsigned int field16;
    unsigned int field20;
    unsigned int field24;
} Fn8040D608Args;

void fn_8040D608(Fn8040D608Args *object) {
    object->state = 0;
    object->flags = 0;
    object->limit = 0xFFFF;
    object->field8 = 0;
    object->field12 = 4;
    object->field16 = 30;
    object->field20 = 0;
    object->field24 = 0;
}
