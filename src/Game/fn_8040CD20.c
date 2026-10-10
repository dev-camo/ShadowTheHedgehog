typedef struct Fn8040CD20Vector {
    float x;
    float y;
} Fn8040CD20Vector;

float fn_8040CD20(Fn8040CD20Vector *left, Fn8040CD20Vector *right) {
    return left->x * right->x + left->y * right->y;
}

void fn_8040CD3C(Fn8040CD20Vector *left, Fn8040CD20Vector *right) {
    float left_x = left->x;
    float right_x = right->x;
    float right_y = right->y;
    left->x = left_x + right_x;
    left->y = left->y + right_y;
}
