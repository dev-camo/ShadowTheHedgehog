typedef struct Fn8040CD20Vector {
    float x;
    float y;
} Fn8040CD20Vector;

float fn_8040CD20(Fn8040CD20Vector *left, Fn8040CD20Vector *right) {
    return left->x * right->x + left->y * right->y;
}

void fn_8040CD3C(volatile Fn8040CD20Vector *left, const volatile Fn8040CD20Vector *right) {
    float left_x;
    float right_x;
    float right_y;
    float left_y;
    left_x = left->x;
    right_x = right->x;
    right_y = right->y;
    left->x = left_x + right_x;
    left_y = left->y;
    left->y = left_y + right_y;
}
