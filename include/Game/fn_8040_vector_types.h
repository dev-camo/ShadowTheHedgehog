#ifndef FN_8040_VECTOR_TYPES_H
#define FN_8040_VECTOR_TYPES_H

typedef struct Fn8040Vector2 {
    float x;
    float y;
} Fn8040Vector2;

typedef struct Fn8040Vector3 {
    float x;
    float y;
    float z;
} Fn8040Vector3;

#ifdef __cplusplus
extern "C" {
#endif

float fn_8040CCEC(const Fn8040Vector2 *vector);
float fn_8040CF50(const Fn8040Vector3 *vector);
void fn_800091D0(Fn8040Vector3 *destination, const Fn8040Vector3 *source);

#ifdef __cplusplus
}
#endif

#endif
