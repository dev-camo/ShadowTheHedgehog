typedef struct Fn8040AC40Node {
    struct Fn8040AC40Node *next;
    unsigned int value;
} Fn8040AC40Node;

typedef struct Fn8040AC40List {
    unsigned int unknown;
    Fn8040AC40Node *sentinel;
} Fn8040AC40List;

void fn_8040AC3C(void) {}

unsigned int fn_8040AC40(Fn8040AC40List *list) {
    unsigned int sum = 0;
    Fn8040AC40Node *node = list->sentinel->next;
    goto check;
loop:
    sum += node->value;
    node = node->next;
check:
    if (node != 0) {
        goto loop;
    }
    return sum;
}
