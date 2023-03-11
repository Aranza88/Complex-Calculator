#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "pila.h"
#include "lista.h"
#include "Tokens.h"
#include "operacion.h"


void answer(TLista *listaPosfija,TLista *var){
    TPila *operacion=nuevaPila(sizeof(TToken),100);
    TVariable k;
    TToken *tokenActual;
    float op3,op4, resultado;
    int contador=0;
    TToken *resultado2=malloc(sizeof(TToken));
    TToken *aux=malloc(sizeof(TToken));
    TToken *op1=malloc(sizeof(TToken));
    TToken *op2=malloc(sizeof(TToken));
    TVariable *p=malloc(sizeof(TVariable));
    TVariable *q;
    while(!listaVacia(listaPosfija)){
        retirarNodo(listaPosfija,(void **)&tokenActual);
        if(tokenActual->tipo==igual){
            if(!listaVacia(var)){
                q=buscarNodo(var,k.Nombre,strcmp);
                if(q==NULL){
                    p->Cantidad=atof(resultado2->token);
                    memcpy (p->Nombre, k.Nombre, strlen(k.Nombre)+1 );
                    agregarNodo(var,p);
                }else
                    q->Cantidad=atof(resultado2->token);
            }else{
                p->Cantidad=atof(resultado2->token);
                memcpy (p->Nombre, k.Nombre, strlen(k.Nombre)+1 );
                agregarNodo(var,p);
            }
        }else if(tokenActual->tipo==variable){
            if(vacia(operacion)!=0 && contador!=1){
                memcpy (k.Nombre, tokenActual->token, strlen(tokenActual->token)+1 );
                contador=1;
            }else if(vacia(operacion)==0 || contador==1 || !listaVacia(var)){
                q=buscarNodo(var,tokenActual->token,compara);
                if (q==NULL){
                    printf("\nERROR-> No existe aun la variable: %s\n",tokenActual->token);
                    return;
                }else{
                    gcvt(q->Cantidad,4,aux->token);
                    push(operacion,aux);
                    memcpy (resultado2->token, aux->token, strlen(aux->token)+1);
                }
            }
        }else if(tokenActual->tipo==numero){
                push(operacion,tokenActual);
                memcpy (resultado2->token, tokenActual->token, strlen(tokenActual->token)+1 );
        }else if(tokenActual->tipo==operador){
            pop(operacion,op2);
            pop(operacion,op1);
            op3=atof(op1->token);
            op4= atof(op2->token);
            if(strcmp((tokenActual->token),"+")==0)
                resultado=op3+op4;
            else if(strcmp((tokenActual->token),"-")==0)
                resultado=op3-op4;
            else if(strcmp((tokenActual->token),"*")==0)
                resultado=op3*op4;
            else if(strcmp((tokenActual->token),"/")==0)
                resultado=op3/op4;
            else if(strcmp((tokenActual->token),"^")==0)
                resultado=pow(op3,op4);
            gcvt(resultado,4,resultado2->token);
            push(operacion,resultado2);
        }
     }
    if (contador==0)
        strcpy(k.Nombre,"\0");
    if(operacion->tos==0){
        if(strcmp(k.Nombre,"\0"))
            printf("\tNuevo valor de variable: %s=%s\n",k.Nombre,resultado2->token);
        else
            printf("\tResultado final: %s\n",resultado2->token);
    }else
        printf("\n\t--- ERROR EN LAS OPERACIONES ---\n");
}

int compara(void *x, void *y) {
    if (strcmp(((char *)x),((TVariable *)y)->Nombre)==0)
        return 0;
    return 1;
}
