#include<stdio.h>
#include<stdlib.h>
#include "Lista.h"
#include "Nodo.h"

TLista * nuevaLista ( int tamInfo){
	TLista *Nueva_Lista;
	Nueva_Lista=(TLista *)malloc(sizeof(TLista));
	Nueva_Lista->tamInfo=tamInfo;
	Nueva_Lista->h=NULL;
	Nueva_Lista->t=NULL;
	return Nueva_Lista;
}

void agregarNodo(TLista * lis, void * info){
	TNodo *Auxiliar;
	Auxiliar=creaNodo(info,lis->tamInfo);
	if(lis->h==NULL){
		lis->h=Auxiliar;
		printf("Nodo agregado\n");
	} else{
		if(lis->h->s==NULL){
			lis->h->s=Auxiliar;
			lis->t=Auxiliar;
			printf("Nodo agregado\n");
		} else{
			if(lis->t->s==NULL){
				lis->t->s=Auxiliar;
				lis->t=Auxiliar;
				printf("Nodo agregado\n");
			} else{
				printf("No se agrego");
			}
		}
	}
}

int  listaVacia (TLista * lis){
	return lis->h==NULL;
}

void retirarNodo(TLista * lis, void * info){
	if(listaVacia(lis)){
        info=NULL;
        return;
    }else{
        TNodo *Aux;
        if(lis->h->s==NULL){
            memcpy(info,lis->h->dato,lis->tamInfo);
            Aux=lis->h;
            lis->h=NULL;
            lis->t=NULL;
            liberaNodo(Aux);
            return;
        }else{
            memcpy(info,lis->h,lis->tamInfo);
            Aux=lis->h;
            lis->h=lis->h->s;
            liberaNodo(Aux);
            return;
        }
    }
}

void  itera(TLista * lis, void (* funcion) ( void *Info)){
    TNodo *Auxiliar;
    Auxiliar = lis->h;
    while (Auxiliar!=NULL){
        funcion(Auxiliar->dato);
        Auxiliar=Auxiliar->s;
	}
}

void *buscarNodo (TLista * lis, void * info, int (* compara) ( void * a, void * b)){
	TNodo *Auxiliar;
	Auxiliar=lis->h;
	while(Auxiliar!=NULL){
		if(compara(info,Auxiliar->dato)==0){
			printf("Nodo encontrado\n");
			return Auxiliar->dato;
		}
		Auxiliar=Auxiliar->s;
	}
	printf("Nodo no encotrado\n");
	return NULL;
}


