#include <stdio.h>
#include <stdlib.h>
#include "Tokens.h"

// instrucciones:
// implemente la funcion esParentesis() en tokens.c
// modifique la funcion TToken *token(char *s) para que regrese una estructura del tipo token
// modifique el arreglo strToken de tokens.c por {"variable", "parentesis","operador", "numero"}
// ¿que sucede? corrija el programa para que con ese nuevo arreglo el programa funcione correctamente

int main()
{
	char cadena[] = "          ( 36.5*Coma *[   23.4- 2]^2/56)/3\n       ";
	//"Coma" agregado
    TToken *p,*toks[1000];
    //edición del tamaño en toks
    int n=0,k;
    printf("Hola!\n");
    printf("Lo operacion separada en tokens es:\n");
    //printf agregado
    p=token(cadena);
    while(p!=NULL){
        toks[n]=p;
        n++;
        //Cambio en el ciclo, original toks[n++]=p
        p=token(NULL);
    }
    printf("\n");
    //printf agregado
    for (k=0;k<n;k++) {
        p=toks[k];
        printf("token: %s [%s]\n",strToken[p->tipo],p->token);
    }
    for (k=0;k<n;k++) {
        free(toks[k]);
    }
    printf("\nFin!");
    return 0;
}

