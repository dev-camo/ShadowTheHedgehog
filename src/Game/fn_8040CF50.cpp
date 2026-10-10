extern "C" {
struct Fn8040CF50Vector {
    float x;
    float y;
    float z;
};

float fn_8000FEE4(float value);

float fn_8040CF50(const Fn8040CF50Vector *vector) {
    return fn_8000FEE4(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z);
}
}
