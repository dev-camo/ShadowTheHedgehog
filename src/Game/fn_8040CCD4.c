typedef struct Fn8040CCD4Args {
    float x;
    float y;
} Fn8040CCD4Args;

#pragma fp_contract off
float fn_8040CCD4(Fn8040CCD4Args *vector) {
    return vector->x * vector->x + vector->y * vector->y;
}
