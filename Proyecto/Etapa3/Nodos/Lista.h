# ifndef LISTA_H_INCLUDED
# define  LISTA_H_INCLUDED
#include "Nodo.h"

struct TLista
{
    TNodo *h;//Direccion de memoria del primer Nodo
    TNodo *t;//Direccion en memoria del ultimo Nodo
	int tamInfo;
};
typedef struct TLista TLista;

TLista * nuevaLista ( int tamInfo);
void  agregarNodo (TLista * lis, void * info);
void  retirarNodo (TLista * lis, void * info);
int  listaVacia (TLista * lis);
void  itera (TLista * lis, void (* funcion) ( void * Info));
//la función compara debe devolver un valor igual a cero si los elementos apuntados por ayb son iguales
void *buscarNodo (TLista * lis, void * info, int (* compara) ( void * a, void * b));


# endif  // LISTA_H_INCLUDED
