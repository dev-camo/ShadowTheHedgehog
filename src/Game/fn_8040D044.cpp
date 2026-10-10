extern "C" {
struct Fn8040D044Vector {
    float x;
    float y;
    float z;
};

void fn_80031568(float *sine, float *cosine, float angle);

void fn_8040D044(Fn8040D044Vector *result, const Fn8040D044Vector *vector, float angle) {
    float sine;
    float cosine;
    fn_80031568(&sine, &cosine, angle);

    float sine_value = sine;
    float y = vector->y;
    float cosine_value = cosine;
    float x = vector->x;
    float z = vector->z;

    result->x = x * cosine_value - y * sine_value;
    result->y = x * sine_value + y * cosine_value;
    result->z = z;
}
}
