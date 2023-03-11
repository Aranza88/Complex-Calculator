#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

int main()
{
    char linea[100];
    TPila *p = nuevaPila();
    int k;

    printf("Dame la expresion? ");
    fgets(linea,99,stdin);
    for (k=0;k<strlen(linea);k++) {
        if (linea[k] == '(') {
            if (llena(p)) {
                  printf("Stack overflow!!!");
                  return 2;
                }
            push(p,linea[k]);
        }
        else if (linea[k] == ')') {
            if ( pop(p)== '\0') {
                printf("error en %d Se vacio la pila y tengo un parentesis que abre!",k+1);
                return 1;
            }
        }
    }
    if (vacia(p))
        printf("La cadena es correcta\n");
    else
        printf("Hay mas parentesis que abren que los que cierran");
    return 0;
}
