/*Todas las funciones de nodo funcionan correctamente*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Nodo.h"

TNodo *creaNodo( void * dato, int tam){
	TNodo *Nuevo_nodo;
	Nuevo_nodo=malloc(sizeof(TNodo));
	Nuevo_nodo->dato=(void *)malloc(tam);
	memcpy(Nuevo_nodo->dato,dato,tam);
	Nuevo_nodo->s=NULL;
	return Nuevo_nodo;
}//El nodo que regresa, en su campo siguiente no apunta a nada, hacerlo apuntar dependera de la lista.h

void  liberaNodo (TNodo * nodo){
	if(nodo==NULL)
		printf("Nodo vacio\n");
	else{
		free(nodo);
		printf("Nodo liberado\n");
	}
}

