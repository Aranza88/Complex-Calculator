#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

typedef struct {
       TNodo *h;
       TNodo *t;
       int tamInfo;
    } TLista;

TLista *nuevaLista(int tamInfo);
void agregarNodo(TLista *lis, void *info);
void retirarNodo(TLista *lis, void **info);
int listaVacia(TLista *lis) ;
void itera(TLista *lis,void (*funcion)(void *info) );
// la funcion compara debe regresar un valor igual a cero si los elementos apuntados por a y b son iguales
void *buscarNodo(TLista *lis, void *info,int (*compara)(void *a, void *b) );


#endif // LISTA_H_INCLUDED
