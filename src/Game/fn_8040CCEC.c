#include "Game/fn_8040_vector_types.h"

extern float fn_8000FEE4(float value);

float fn_8040CCEC(const Fn8040Vector2 *vector) {
    float magnitude_squared = vector->x * vector->x + vector->y * vector->y;

    return fn_8000FEE4(magnitude_squared);
}
