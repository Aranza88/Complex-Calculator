#include <stdlib.h>
#include "lista.h"

TLista *nuevaLista() {
    TLista *lista = malloc(sizeof(TLista));
    lista->h = lista->t = NULL;
    return lista;
}

void agregarNodo(TLista *lis, TInfo d) {
    TNodo *p = creaNodo(d);
    if (lis->h == NULL) {
        lis->h = p;
        lis->t = p;
        return;
    }
    lis->t->s = p;
    lis->t = p;
}

void itera(TLista lis,void (*funcion)(TInfo info) ) {
    TNodo *p;

    p = lis.h;
    while (p!=NULL) {
        funcion(p->datos);
        p = p->s;
    }
}
