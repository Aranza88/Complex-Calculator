#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tokens.h"
#include "pila.h"
#include "lista.h"
#include "posfija.h"
#include "operacion.h"

void imprimir(void *a);
void imprimirVariables(void *a);

int main() {
    TLista *var = nuevaLista(sizeof(TVariable));
    TLista *listaPosfija;
    TLista *listaInfija = nuevaLista(sizeof(TToken));
    TToken p;
    char cadena[30];
    int r=1,k=0;
    printf("\t\t\t----- EVALUADOR DE EXPRESIONES ARITMETICAS -----");
    printf("\nEstructuras de Datos y Algoritmos I\nUniversidad Nacional Autonoma de Mexico");
    printf("\nEquipo de Azul Alfaro, Aranza Nuniez, Karla Vazquez, Carlos Recinas");
    printf("\nEjemplo de expresiones aceptadas: x =+20^(2/23+2)\nOperadores validos: + - * / ^ =\nAcepta expresiones parentizadas () y variables");
    printf("\nEscriba Vars para ver las variables actuales");
    printf("\nEscriba Exit para salir del programa");
    while(r==1){
        printf("\n\nInserte una operacion, con parentesis bien colocados\n");
        scanf("%s",cadena);
        if((strcmp(cadena,"Vars")==0||strcmp(cadena,"vars")==0||strcmp(cadena,"VARS")==0) && k==0){
            printf("\nLas variables son:\n");
            itera(var,imprimirVariables);
            k=1;
        }else if(strcmp(cadena,"Exit")==0||strcmp(cadena,"exit")==0||strcmp(cadena,"EXIT")==0)
            exit(0);
        p = token(cadena);
        while ((strcmp(p.token, "Termine")) != 0) { //se modifico la condición de ruptura del ciclo comparando con la cadena del campo token
            agregarNodo(listaInfija,&p);
            p = token(NULL);
        }
        listaPosfija=posfija(listaInfija);
        if (k!=1)
            answer(listaPosfija,var);
        k=0;
    }
    return 0;
}

void imprimir(void *a)  {
  printf("token: %s [%s]\n",strToken[((TToken *)a)->tipo],((TToken *)a)->token);
}
void imprimirVariables(void *a)  {
  printf("Variable: %s \tValor: [%f]\n",((TVariable *)a)->Nombre,((TVariable *)a)->Cantidad);
}
