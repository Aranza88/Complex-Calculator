#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tokens.h"
#include "pila.h"
#include "lista.h"
#include "posfija.h"

void imprimir(void *a);

int main() {
//    char cadena[] = "( 36.5 *(   23.4- 2))^2\n       ";
    char cadena[] = "total = (( prueba+23)^3 -(33+23*44))^(x/3)";
    //char cadena[]="1*(2+3)";
    TToken p;
    TLista *listaPosfija;
    TLista *listaInfija = nuevaLista(sizeof(TToken));

    p = token(cadena);
    while ((strcmp(p.token, "Termine")) != 0) { //se modifico la condición de ruptura del ciclo comparando con la cadena del campo token
        agregarNodo(listaInfija,&p);
        p = token(NULL);
    }
    printf("***** tokens antes de funcion posfija*******\n");
    itera(listaInfija,imprimir);
    printf("***** tokens después de funcion posfija*******\n");

    /*Esto es lo que debe llevar la función*/
    listaPosfija =posfija(listaInfija);
    itera(listaPosfija,imprimir);
    return 0;
}

void imprimir(void *a)  {
  printf("token: %s [%s]\n",strToken[((TToken *)a)->tipo],((TToken *)a)->token);
}
