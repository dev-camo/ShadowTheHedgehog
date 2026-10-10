struct __eti_init_info;

typedef struct FragmentInfo {
    struct __eti_init_info *init_info;
    char *toc;
    int active;
} FragmentInfo;

static FragmentInfo fragmentinfo[1];

void __unregister_fragment(int fragment_id) {
    if (fragment_id >= 0 && fragment_id < 1) {
        FragmentInfo *entry = &fragmentinfo[fragment_id];
        entry->init_info = 0;
        entry->toc = 0;
        entry->active = 0;
    }
}

int __register_fragment(struct __eti_init_info *init_info, char *toc) {
    if (fragmentinfo[0].active == 0) {
        fragmentinfo[0].init_info = init_info;
        fragmentinfo[0].toc = toc;
        fragmentinfo[0].active = 1;
        return 0;
    }

    return -1;
}
