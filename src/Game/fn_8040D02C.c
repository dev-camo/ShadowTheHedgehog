extern float lbl_805FAD80;
extern float lbl_805E07A0[4];

void fn_8040D02C(void) {
    float initial_value = lbl_805FAD80;
    float *vector = lbl_805E07A0;

    vector[0] = initial_value;
    vector[1] = initial_value;
    vector[2] = initial_value;
}

#pragma force_active on
#pragma section ".ctors$50"
__declspec(section ".ctors$50") extern void (*const fn_8040D02C_reference)(void) = fn_8040D02C;
#pragma force_active reset
