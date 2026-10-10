typedef struct Fn80411548Vector {
    float x;
    float y;
    float z;
} Fn80411548Vector;

void fn_80411548(Fn80411548Vector *destination, Fn80411548Vector *left, Fn80411548Vector *right) {
    float x = left->x + right->x;
    float y = left->y + right->y;
    float z = left->z + right->z;
    destination->x = x;
    destination->y = y;
    destination->z = z;
}
