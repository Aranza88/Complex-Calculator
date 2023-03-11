#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{
    TLista *lista = nuevaLista();

    TInfo unDato;

    leer(&unDato);
    agregarNodo(lista,unDato);
    leer(&unDato);
    agregarNodo(lista,unDato);
    leer(&unDato);
    agregarNodo(lista,unDato);
    leer(&unDato);
    agregarNodo(lista,unDato);
    itera(*lista,imprimir);

    return 0;
}
