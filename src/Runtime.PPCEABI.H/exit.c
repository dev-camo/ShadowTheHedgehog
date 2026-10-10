typedef void (*ExitCallback)(void);

extern int __aborting;
extern int __atexit_curr_func;
extern ExitCallback __atexit_funcs[];
extern ExitCallback __console_exit;
extern ExitCallback __stdio_exit;
extern ExitCallback _dtors[];

extern void __begin_critical_region(int region);
extern void __destroy_global_chain(void);
extern void __end_critical_region(int region);
extern void __kill_critical_regions(void);
extern void _ExitProcess(void);

void exit(int status) {
    ExitCallback *dtor;

    if (__aborting == 0) {
        __begin_critical_region(0);
        __end_critical_region(0);
        __destroy_global_chain();

        for (dtor = _dtors; *dtor != 0; dtor++) {
            (*dtor)();
        }

        if (__stdio_exit != 0) {
            __stdio_exit();
            __stdio_exit = 0;
        }
    }

    __begin_critical_region(0);
    while (__atexit_curr_func > 0) {
        __atexit_funcs[--__atexit_curr_func]();
    }
    __end_critical_region(0);
    __kill_critical_regions();

    if (__console_exit != 0) {
        __console_exit();
        __console_exit = 0;
    }

    _ExitProcess();
}
