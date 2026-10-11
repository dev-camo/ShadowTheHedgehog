#ifndef GAME_FN_803CB_TEXT_TYPES_H
#define GAME_FN_803CB_TEXT_TYPES_H

/* Chosen context-word/text callback projection; original full interface unknown. */
typedef void (*Fn803CBTextCallback)(unsigned int argument, const char *text);

#ifdef __cplusplus
extern "C" {
#endif

/* Chosen byte-buffer interfaces; original full types/arity/returns unknown. */
char *fn_803ACABC(char *destination, const char *source, unsigned int count);
void fn_803CBADC(const char *text);
void fn_803CBB34(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif
