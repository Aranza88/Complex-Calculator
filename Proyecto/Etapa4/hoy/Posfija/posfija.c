#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "pila.h"
#include "Tokens.h"
#include "posfija.h"

int precedencia(char op);
int mayorPrecedencia(TToken op1,TToken op2);

int precedencia(char op){
    if( op=='^')
        return 3;
    if( op=='/' || op=='*')
        return 2;
    if( op=='+' || op=='-')
        return 1;
    return 0;
}

int mayorPrecedencia(TToken op1,TToken op2){
    if (precedencia(*(op1.token))>precedencia(*(op2.token)))
        return 1;
    return 0;
}

TLista *posfija(TLista *listaInfija){
    TLista *listaPosfija=nuevaLista(sizeof(TToken));
    TPila *p=nuevaPila(sizeof(TToken),100);
    TToken *tokenActual,tope;
    while (!listaVacia(listaInfija)) {
        retirarNodo(listaInfija,(void **)&tokenActual);
        if (tokenActual->tipo==numero || tokenActual->tipo==variable)
            agregarNodo(listaPosfija,tokenActual);
        else if (tokenActual->tipo==igual){
            push(p,tokenActual);
        }else if(tokenActual->tipo==parentesis){
            if(*(tokenActual->token)=='('){
                push(p,tokenActual);
            }else if(*(tokenActual->token)==')'){
                while(!vacia(p)){
                    pop(p,tokenActual);
                    if(*(tokenActual->token)=='(')
                        break;
                    agregarNodo(listaPosfija,tokenActual);
                }
            }
        }else if(tokenActual->tipo==operador){
            while(!vacia(p)){
                top(p,&tope);
                if(!mayorPrecedencia(tope,*tokenActual) || *(tokenActual->token)=='(')
                    break;
                pop(p,&tope);
                agregarNodo(listaPosfija,&tope);
            }
            push(p,tokenActual);
        }
    }
    while(!vacia(p)){
        pop(p,tokenActual);
        agregarNodo(listaPosfija,tokenActual);
    }
    return listaPosfija;
}










