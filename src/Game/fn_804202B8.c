typedef struct Fn804202B8FlagData {
    char padding[10];
    volatile unsigned short flags;
} Fn804202B8FlagData;

typedef struct Fn804202B8Vector {
    float x;
    float y;
    float z;
    unsigned int unknown[2];
    Fn804202B8FlagData *flag_data;
} Fn804202B8Vector;

void fn_804202B8(Fn804202B8Vector *vector) {
    Fn804202B8FlagData *flag_data = vector->flag_data;

    /* Keep these volatile reads at each test; the target reloads the flags every time. */
    if (flag_data->flags & 1) {
        vector->x = -vector->x;
    }
    if (flag_data->flags & 2) {
        vector->y = -vector->y;
    }
    if (flag_data->flags & 4) {
        vector->z = -vector->z;
    }
}
