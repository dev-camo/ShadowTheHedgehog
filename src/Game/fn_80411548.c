typedef struct Fn80411548Vector {
    float x;
    float y;
    float z;
} Fn80411548Vector;

void fn_80411548(Fn80411548Vector *destination, const Fn80411548Vector *left,
                 const Fn80411548Vector *right) {
    destination->x = left->x + right->x;
    destination->y = left->y + right->y;
    destination->z = left->z + right->z;
}
