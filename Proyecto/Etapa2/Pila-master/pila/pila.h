#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define MAX_PILA 10

typedef char TDato;

typedef struct {
    TDato p[MAX_PILA];
    int tos;
} TPila;


TPila *nuevaPila();
int vacia(TPila *pila);
int llena(TPila *pila);
TDato pop(TPila *pila);
int push(TPila *pila, TDato valor);

#endif // PILA_H_INCLUDED
