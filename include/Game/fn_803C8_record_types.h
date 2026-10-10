#ifndef FN_803C8_RECORD_TYPES_H
#define FN_803C8_RECORD_TYPES_H

/* Inferred callback interface: a raw context word and a signed argument.
 * Original full argument lists, return types and context type are unknown.
 */
typedef void (*Fn803C8RecordCallback)(unsigned int context, int argument);

/* Inferred accessed-field view; original full type and other bytes are unknown. */
typedef struct Fn803C8RecordView {
    unsigned char unknown_0[4];
    unsigned int word_4;
    unsigned char unknown_8[4];
    unsigned int word_C;
    unsigned int word_10;
    unsigned int word_14;
    unsigned int word_18;
    Fn803C8RecordCallback callback_1C;
    unsigned int argument_20;
} Fn803C8RecordView;

/* Inferred two-word descriptor view; original full type/extent are unknown. */
typedef struct Fn803C8DescriptorView {
    unsigned int word_0;
    int word_4;
} Fn803C8DescriptorView;

#ifdef __cplusplus
extern "C" {
#endif

/* Inferred string-copy/append interfaces; return values are unused in these units. */
char *fn_803ACB00(char *destination, const char *source);
char *fn_803ACA90(char *destination, const char *source);

/* Inferred side-effect interfaces; original full argument lists/returns unknown. */
void fn_803CAF48(const char *text);
void fn_803C8DE0(void);
void fn_803C8D94(void);
extern const char lbl_80517120[];

/* Inferred raw-word reader and four-register query interfaces. */
unsigned int fn_803C8E8C(const Fn803C8RecordView *record);
int fn_803C8F38(const Fn803C8RecordView *record, int mode, int requested, int *actual);
/* Inferred update interface from three consumed registers; original return type is unknown. */
void fn_803C904C(Fn803C8RecordView *record, int mode, Fn803C8DescriptorView *descriptor);
/* Inferred descriptor-filter interface; original full arity and return type are unknown. */
void fn_803C91E0(const Fn803C8RecordView *record, int mode, Fn803C8DescriptorView *descriptor);

#ifdef __cplusplus
}
#endif

#endif
