#if defined(VERSION_GUPJ8P)
#define BAD_EXCEPTION_VTABLE lbl_80568480
#define EXCEPTION_VTABLE lbl_8051CB44
extern char lbl_80568480[];
extern char lbl_8051CB44[];
extern void dtor_803A0924(void *self);

void *fn_803A239C(void *self, short flags) {
#elif defined(VERSION_GUPP8P)
#define BAD_EXCEPTION_VTABLE lbl_80568EC0
#define EXCEPTION_VTABLE lbl_8051D5C4
extern char lbl_80568EC0[];
extern char lbl_8051D5C4[];
extern void dtor_803A1334(void *self);

void *fn_803A2DAC(void *self, short flags) {
#else
#define BAD_EXCEPTION_VTABLE lbl_80567E00
#define EXCEPTION_VTABLE lbl_8051C4A4
extern char lbl_80567E00[];
extern char lbl_8051C4A4[];
extern void dtor_803A02E4(void *self);

void *fn_803A1D5C(void *self, short flags) {
#endif
    if (self != 0) {
        *(char **)self = BAD_EXCEPTION_VTABLE;
        if (self != 0) {
            *(char **)self = EXCEPTION_VTABLE;
        }
        if (flags > 0) {
#if defined(VERSION_GUPJ8P)
            dtor_803A0924(self);
#elif defined(VERSION_GUPP8P)
            dtor_803A1334(self);
#else
            dtor_803A02E4(self);
#endif
        }
    }
    return self;
}
