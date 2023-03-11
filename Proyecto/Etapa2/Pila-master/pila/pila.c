#include <stdlib.h>
#include <stdio.h>
#include "pila.h"

TPila *nuevaPila(){
    TPila *p = malloc(sizeof(TPila));
    p->tos = -1;
    return p;
}

/* regresa un valor diferente de 0 si
 la pila esta vacia
 */
int vacia(TPila *pila) {
    if (pila->tos == -1)
        return 1;
    return 0;
}

/* regresa un valor diferente de 0
   si la pila esta llena
*/
int llena(TPila *pila) {
    return pila->tos >= MAX_PILA-1;
}

int push(TPila *pila, TDato valor){
    if (!llena(pila)) { /* si NO esta llena la pila...*/
        pila->tos = pila->tos+1;
        pila->p[ pila->tos ] = valor;
        return 1;
    }
    return 0; /* sucedio un overflow */
}

TDato pop(TPila *pila) {
    if (!vacia(pila)) {
        pila->tos = pila->tos -1;
        return pila->p[pila->tos+1];
    }
    printf("Error: Stack underflow\n");
    exit(0);
}
