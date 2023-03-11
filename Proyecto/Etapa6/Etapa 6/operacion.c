#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "pila.h"
#include "lista.h"
#include "Tokens.h"
#include "operacion.h"
#include "variables.h"


void answer(TLista *listaPosfija){
    TPila *operacion=nuevaPila(sizeof(TToken),100);
    TToken *tokenActual;
    float op3,op4;
    float resultado;
    TToken *resultado2=malloc(sizeof(TToken));
    TToken *op1=malloc(sizeof(TToken));
    TToken *op2=malloc(sizeof(TToken));
    TLista *vars=nuevaLista(sizeof(TVariable));
    while(!listaVacia(listaPosfija)){
        retirarNodo(listaPosfija,(void **)&tokenActual);
        if(tokenActual->tipo==numero||tokenActual->tipo==variable)
        {push(operacion,tokenActual);}
        else if(tokenActual->tipo==operador){
            pop(operacion,op2);
            pop(operacion,op1);
            void *var=malloc(sizeof(TVariable));
            if(op1->tipo==variable){
                var=buscarNodo(vars,op1->token,strcmp);
                if (var!=NULL)
                    op3=((TVariable *)var)->cantidad;
                else{
                    printf("Error en la expresion\n");
                    return;
                }
            }else if(op2->tipo==variable){
                var=buscarNodo(vars,op2->token,strcmp);
                if (var!=NULL)
                    op4=((TVariable *)var)->cantidad;
                else{
                    printf("Error en la expresion\n");
                    return;
                }
            }else{
                op3= atof(op1->token);
                op4= atof(op2->token);
            }
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
        }else if(tokenActual->tipo==igual){
            pop(operacion,op2);
            pop(operacion,op1);
            if (op2!=NULL && op1!=NULL && op2->tipo==numero && op1->tipo==variable){
                op3=atof(op2->token);
                nuevaVariable(vars,op1->token,op3);
                push(operacion,op2);
            }else{
                printf("Error en la expresion\n");
                return;
            }
        }
    }
    if(operacion->tos==0)
        printf("\n\n\tResultado final: %s\n\n",resultado2->token);
    else
        printf("\n\n\t--- ERROR EN LAS OPERACIONES ---\n");
}



