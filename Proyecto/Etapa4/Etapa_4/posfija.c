#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "pila.h"
#include "Tokens.h"
#include "posfija.h"

int pCerrado(void *a){
    char aux[2];
    char p[] = ")";
    strcpy(aux,((TToken *)a)->token); //token
    if(!strcmp(aux,p))
        return 1;
   return 0;
}

int pAbierto(void *a){
    char aux[2];
    char p[] ="(";
    strcpy(aux,((TToken *)a)->token); //token
    if(!strcmp(aux,p))
        return 1;
   return 0;
}

int precedencia(char op){
/*    if(op=='(' || op==')')
 *       return 5;
 */   if(op=='=')
        return 4;
    if(op=='^')
        return 3;
    if(op=='/' || op=='*')
        return 2;
    if(op=='+' || op=='-')
        return 1;
    return 0;
}

int mayorPrecedencia(char op1,char op2){
    if (precedencia(op1)>precedencia(op2))
        return 1;
    return 0;
}

TLista *posfija(TLista *listaInfija){
    //crear pila;
    TNodo *q;
    TLista *listaPosfija=nuevaLista(sizeof(TToken));
    TPila *p=nuevaPila(sizeof(TToken),100);
    TToken aux;
    q=listaInfija->h;
    while(q!=NULL){
        //variable o numero
        if (((TToken *)(q->dato))->tipo==numero || ((TToken *)(q->dato))->tipo==variable)
            agregarNodo(listaPosfija,q->dato);
        //igual
        if(((TToken *)(q->dato))->tipo==igual)
            push(p,q->dato);
            //agregar pila
        else if(((TToken *)(q->dato))->tipo==parentesis){
            if(*(((TToken *)(q->dato))->token)=='('){
                //push a la pila
                push(p,q->dato);
            }else if(*(((TToken *)(q->dato))->token)==')'){
                while(!vacia(p) && !pAbierto(p->pila[p->tos])){
                    //hacer pop a la pila
                    pop(p,&aux);
                    //agregar a lista posfija el tope de la pila
                    agregarNodo(listaPosfija,&aux);
                }
                //hacer pop a la pila
                pop(p,&aux);
            }
        }else if (((TToken *)(q->dato))->tipo==operador){
            /*pila no vacía, no sea ( y el operador en el stack tiene mayor precedencia que el que queremos agregar*/
            while(!mayorPrecedencia(*((TToken *)(p->pila[p->tos])->token),*((TToken *)(q->dato))->token) && !vacia(p) && !pAbierto(p->pila[p->tos])){
                //hacer pop a la pila
                pop(p,&aux);
                //agregar a lista posfija el tope de la pila
                agregarNodo(listaPosfija,&aux);
            }
            push(p,q->dato);
        }
        q=q->s;
    }
    while(!vacia(p)/*pila no vacia*/){
        //hacer pop a la pila
        pop(p,&aux);
        //agregar a lista posfija el tope de la pila
        agregarNodo(listaPosfija,&aux);
    }
    return listaPosfija;
}

