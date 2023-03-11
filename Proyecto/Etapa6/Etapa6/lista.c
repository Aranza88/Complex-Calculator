#include<stdio.h>
#include<stdlib.h>
#include <mem.h>
#include "lista.h"
#include "nodo.h"

TLista * nuevaLista (int tamInfo) {
    TLista *Nueva_Lista;
    Nueva_Lista=(TLista *)malloc(sizeof(TLista));
    Nueva_Lista->tamInfo=tamInfo;
    Nueva_Lista->h=NULL;
    Nueva_Lista->t=NULL;
    return Nueva_Lista;
}

void agregarNodo(TLista * lis, void * info) {
    TNodo *Auxiliar;
    Auxiliar=creaNodo(info,lis->tamInfo);
    if(lis->h==NULL) {
        lis->h=Auxiliar;
    } else {
        if(lis->h->s==NULL) {
            lis->h->s=Auxiliar;
            lis->t=Auxiliar;
        } else {
            if(lis->t->s==NULL) {
                lis->t->s=Auxiliar;
                lis->t=Auxiliar;
            } else {
                printf("No se agrego");
            }
        }
    }
}

int  listaVacia (TLista * lis) {
    return lis->h==NULL;
}

void retirarNodo(TLista * lis, void ** info) {
    TNodo *Aux;

    if(listaVacia(lis)) {
        *info=NULL;
        return;
    } else {
        *info = malloc(lis->tamInfo);
        Aux=lis->h;
        if(lis->h->s==NULL) {
            memcpy(*info,lis->h->dato,lis->tamInfo);
            lis->h=NULL;
            lis->t=NULL;
        } else {
            memcpy(*info,lis->h->dato,lis->tamInfo);
            lis->h=lis->h->s;
        }
        liberaNodo(Aux);
        return;
    }
}

void  itera(TLista * lis, void (* funcion) ( void *Info)) {
    TNodo *Auxiliar;
    Auxiliar = lis->h;
    while (Auxiliar!=NULL) {
        funcion(Auxiliar->dato);
        Auxiliar=Auxiliar->s;
    }
}

void *buscarNodo (TLista * lis, void * info, int (* compara) ( void * a, void * b)) {
    TNodo *Auxiliar;
    Auxiliar=lis->h;
    while(Auxiliar!=NULL) {
        if(compara(info,Auxiliar->dato)==0) {
            //printf("Variable encontrada\n");
            return Auxiliar->dato;
        }
        Auxiliar=Auxiliar->s;
    }
    //printf("Variable no encontrada\n");
    return NULL;
}
