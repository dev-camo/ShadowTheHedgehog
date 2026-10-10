extern float lbl_805EE2D4;
extern float lbl_805F2228;

void fn_80068A3C(void) {
    lbl_805EE2D4 = lbl_805F2228;
}

#pragma force_active on
#pragma section ".ctors$30"
__declspec(section ".ctors$30") extern void (*const fn_80068A3C_reference)(void) = fn_80068A3C;
#pragma force_active reset
