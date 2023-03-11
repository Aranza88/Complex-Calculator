#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Tokens.h"

char strToken[][11] = {"operador", "numero", "variable", "parentesis"};

int esOperador(char c) {
    int k;
    static char operadores[] = "+-*/^";
    for (k=0; k<strlen(operadores); k++)
        if (c == operadores[k])
            return 1;
    return 0;
}

int esParentesis(char c) {
// si c es un caracter correspondiente a un parentesis regresa 1 si no 0
if (c=='(' || c==')')
    return 1;
return 0;
}

TToken *token(char *s) {
    static char cadena[1000];
    static char *actual;
    int k;
    char res[1000];

    TToken *unToken=NULL;


    if (s != NULL) {
        strcpy(cadena,s);
        actual = cadena;
    }

    while ((*actual == ' ') || (*actual =='\n') || (*actual=='\t'))
        actual++;

    if (*actual == '\0')
        return NULL;
    if ( (esOperador(*actual) == 1) ) {
        res[0] = *actual;
        res[1] = '\0';

        // crea de manera dinamica el token
        // y le asigna los valores correctos

        actual = actual + 1;
        return unToken;
    } else if ( (esParentesis(*actual) == 1) ) {
        res[0] = *actual;
        res[1] = '\0';

        // crea de manera dinamica el token
        // y le asigna los valores correctos

        actual = actual + 1;
        return unToken;
    } else if (isdigit(*actual) || (*actual=='.')) {
        k = 0;
        while ( (*actual != '\0') && (isdigit(*actual) || *actual == '.' ) ) {
            res[k] = *actual;
            actual = actual + 1;
            k = k+1;
        }
        res[k] = '\0';

        // crea de manera dinamica el token
        // y le asigna los valores correctos

        return unToken;
    } else if (isalpha(*actual)) {
        k = 0;
        while ( (*actual != '\0') && isalpha(*actual)) {
            res[k] = *actual;
            actual = actual + 1;
            k = k+1;
        }
        res[k] = '\0';

        // crea de manera dinamica el token
        // y le asigna los valores correctos

        return unToken;
    }

    printf("Error: expresion incorrecta");
    printf("Programa detenido");
    exit(0);
}









