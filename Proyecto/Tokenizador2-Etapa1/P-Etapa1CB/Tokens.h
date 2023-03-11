#ifndef TOKENS_H_INCLUDED
#define TOKENS_H_INCLUDED

extern char strToken[][11];

typedef enum {operador, numero, variable, parentesis} tipoToken;

typedef struct {
    tipoToken tipo;
    char token[20];
} TToken;

TToken *token(char *s);

int esOperador(char c);
int esParentesis(char c);

#endif // TOKENS_H_INCLUDED
