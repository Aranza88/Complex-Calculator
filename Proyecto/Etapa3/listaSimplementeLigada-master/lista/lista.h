#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

typedef struct {
       TNodo *h;
       TNodo *t;
    } TLista;

TLista *nuevaLista();
void itera(TLista lis,void (*funcion)(TInfo info) );
void agregarNodo(TLista *lis, TInfo d);

#endif // LISTA_H_INCLUDED
