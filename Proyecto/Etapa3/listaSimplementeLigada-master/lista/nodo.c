#include <stdlib.h>
#include "nodo.h"


TNodo *creaNodo(TInfo d) {
    TNodo *q;
    q = malloc(sizeof(TNodo));
    q->datos = d;
    q->s = NULL;
    return q;
}

