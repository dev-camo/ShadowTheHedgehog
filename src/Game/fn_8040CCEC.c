typedef struct Fn8040CCECVector {
    float x;
    float y;
} Fn8040CCECVector;

extern float fn_8000FEE4(float value);

float fn_8040CCEC(Fn8040CCECVector *vector) {
    float magnitude_squared = vector->x * vector->x + vector->y * vector->y;

    return fn_8000FEE4(magnitude_squared);
}
