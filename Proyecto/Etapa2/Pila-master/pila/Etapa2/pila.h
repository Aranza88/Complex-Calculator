#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED


typedef struct {
    void **pila;
    int maxDatos;
    int tamDato;
    int tos;
} TPila;



TPila *nuevaPila(int tamDato,int maxDatos);
int vacia(TPila *pila);
int llena(TPila *pila);
void pop(TPila *pila, void *dato);
void push(TPila *pila, void *valor);
void top(TPila *pila, void *tope);
void liberaPila(TPila *pila);
void imprimePila(TPila *pila,void (*funcion)(void *info) );

#endif // PILA_H_INCLUDED
