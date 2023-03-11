#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "info.h"

struct Nodo{
    TInfo datos;
    struct Nodo *s;
};
typedef struct Nodo TNodo;

TNodo *creaNodo(TInfo d);

#endif // NODO_H_INCLUDED
