extern float lbl_805FAD78;
extern float lbl_805F1358[2];

void fn_8040CD60(void) {
    float initial_value = lbl_805FAD78;
    float *vector = lbl_805F1358;

    vector[0] = initial_value;
    vector[1] = initial_value;
}

// Keep this entry in the regular constructor-order band.
#pragma force_active on
#pragma section ".ctors$50"
__declspec(section ".ctors$50") extern void (*const fn_8040CD60_reference)(void) = fn_8040CD60;
#pragma force_active reset
