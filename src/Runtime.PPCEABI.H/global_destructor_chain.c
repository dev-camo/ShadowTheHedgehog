typedef struct GlobalDestructorChain {
    struct GlobalDestructorChain *next;
    void (*destructor)(void *, int);
    void *object;
} GlobalDestructorChain;

GlobalDestructorChain *__global_destructor_chain;

void __destroy_global_chain(void) {
    GlobalDestructorChain *entry;

    while ((entry = __global_destructor_chain) != 0) {
        __global_destructor_chain = entry->next;
        entry->destructor(entry->object, -1);
    }
}

void __register_global_object(void *object, void (*destructor)(void *, int),
                              GlobalDestructorChain *entry) {
    entry->next = __global_destructor_chain;
    entry->destructor = destructor;
    entry->object = object;
    __global_destructor_chain = entry;
}
