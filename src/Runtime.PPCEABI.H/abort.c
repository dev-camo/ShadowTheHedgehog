typedef void (*ExitCallback)(void);

#if defined(VERSION_GUPJ8P)
#define RAISE_ABORT fn_803ACC40
#define ABORT_FUNCTION fn_803A31E4
#elif defined(VERSION_GUPP8P)
#define RAISE_ABORT fn_803AD650
#define ABORT_FUNCTION fn_803A3BF4
#else
#define RAISE_ABORT fn_803AC600
#define ABORT_FUNCTION fn_803A2BA4
#endif

extern int __aborting;
extern int __atexit_curr_func;
extern ExitCallback __atexit_funcs[];
extern ExitCallback __console_exit;

extern int RAISE_ABORT(int signal);
extern void __begin_critical_region(int region);
extern void __end_critical_region(int region);
extern void __kill_critical_regions(void);
extern void _ExitProcess(void);

void ABORT_FUNCTION(void) {
    RAISE_ABORT(1);
    __aborting = 1;
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
