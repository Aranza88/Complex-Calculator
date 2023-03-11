#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tokens.h"
#include "pila.h"
#include "lista.h"
#include "posfija.h"
#include "operacion.h"

void imprimir(void *a);

int main() {
   // char cadena[] = "( 36.5 *(   23.4- 2))^2\n       ";
    //char cadena[] = "total = (( prueba+23)^3 -(33+23*44))^(x/3)";
    //char cadena[]="((3+6)/(1+1))+(7/9)*(1*6/8)";
    char cadena[30];
    int r;
    TToken p;
    TLista *listaPosfija;
    TLista *listaInfija = nuevaLista(sizeof(TToken));
    do{
        printf("\n\n\tInserte una operacion, con parentesis bien colocados\n\n");
        scanf("%s",cadena);
        p = token(cadena);
        while ((strcmp(p.token, "Termine")) != 0) { //se modifico la condici�n de ruptura del ciclo comparando con la cadena del campo token
            agregarNodo(listaInfija,&p);
            p = token(NULL);
        }
        printf("***** tokens antes de funcion posfija*******\n");
        itera(listaInfija,imprimir);
        printf("***** tokens despu�s de funcion posfija*******\n");

        /*Esto es lo que debe llevar la funci�n*/
        listaPosfija =posfija(listaInfija);
        itera(listaPosfija,imprimir);

        answer(listaPosfija);
        printf("Desea realizar otra operaci�n?\n1)Si\t2)No\n");
        scanf("%d",&r);
    }while(r==1);
    return 0;
}

void imprimir(void *a)  {
  printf("token: %s [%s]\n",strToken[((TToken *)a)->tipo],((TToken *)a)->token);
}
