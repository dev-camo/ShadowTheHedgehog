extern "C" {
extern float lbl_805F1358[2];
extern float lbl_805FAD7C;
}

typedef struct Fn8040CC6CVector {
    float x;
    float y;
} Fn8040CC6CVector;

extern "C" float fn_8040CCEC(Fn8040CC6CVector *vector);

extern "C" void fn_8040CC6C(Fn8040CC6CVector *vector) {
    float magnitude = fn_8040CCEC(vector);

    if (magnitude < lbl_805FAD7C) {
        vector->x = lbl_805F1358[0];
        vector->y = lbl_805F1358[1];
    } else {
        vector->x /= magnitude;
        vector->y /= magnitude;
    }
}
