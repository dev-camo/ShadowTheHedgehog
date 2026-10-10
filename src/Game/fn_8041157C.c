typedef struct Fn8041157CVector {
    float x;
    float y;
    float z;
} Fn8041157CVector;

typedef struct Fn8041157COutput {
    float x;
    float y;
    float z;
} Fn8041157COutput;

typedef struct Fn8041157CMatrix {
    float values[3][4];
} Fn8041157CMatrix;

extern void *lbl_805F13A8;
extern Fn8041157CMatrix *fn_80411700(void *table);
extern void fn_8040C148(Fn8041157CMatrix *destination, const Fn8041157CMatrix *source);
extern void fn_800091D0(Fn8041157COutput *destination, const Fn8041157COutput *source);

void fn_8041157C(Fn8041157COutput *destination, const Fn8041157CMatrix *matrix,
                 const Fn8041157CVector *vector) {
    Fn8041157COutput output;
    Fn8041157CMatrix matrix_copy;

    if (matrix == 0) {
        fn_8040C148(&matrix_copy, fn_80411700(lbl_805F13A8));
        matrix = &matrix_copy;
    }

    output.x = vector->y * matrix->values[0][1] + vector->x * matrix->values[0][0] +
               vector->z * matrix->values[0][2];
    output.y = vector->y * matrix->values[1][1] + vector->x * matrix->values[1][0] +
               vector->z * matrix->values[1][2];
    output.z = vector->y * matrix->values[2][1] + vector->x * matrix->values[2][0] +
               vector->z * matrix->values[2][2];

    fn_800091D0(destination, &output);
}
