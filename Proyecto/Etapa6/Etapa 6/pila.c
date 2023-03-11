#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pila.h"

TPila *nuevaPila(int tamDato,int maxDatos){
    TPila *pila;
	pila=malloc(sizeof(TPila));
	pila->pila=malloc(maxDatos*sizeof(void *));
	pila->maxDatos=maxDatos;
	pila->tamDato=tamDato;
	pila->tos=-1;
	return pila;
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
    return pila->tos >= pila->maxDatos-1;
}

void pop(TPila *pila, void *dato){
    if (!vacia(pila)) {
        memcpy(dato,pila->pila[pila->tos],pila->tamDato);
        free(pila->pila[pila->tos]);
        pila->tos-=1;
        return;
    }
    free(dato);
    dato=NULL;
    printf("Error: Stack underflow\n");
    return;
}

void push(TPila *pila, void *valor){
    if (!llena(pila)) { /* si NO esta llena la pila...*/
        pila->tos=pila->tos+1;
        pila->pila[pila->tos]=malloc(pila->tamDato);
        memcpy(pila->pila[pila->tos],valor,pila->tamDato);
        return;
    }
    return;
}

void top(TPila *pila, void *tope){
    if (!vacia(pila)) {
        memcpy(tope,pila->pila[pila->tos],pila->tamDato);
        return;
    }
    tope=NULL;
    return;
}

void liberaPila(TPila *pila){
    while (pila->tos>=0){
		free(pila->pila[pila->tos]);
		pila->tos-=1;
	}
	free(pila);
	return;
}

void imprimePila(TPila *pila,void(*funcion)(void *info)){
    int k=0;
    printf("La pila es:\n");
    while (k<=pila->tos){
        printf("[%d]: ",k);
        (*funcion)(pila->pila[k]);
        k+=1;
    }
    return;
}
