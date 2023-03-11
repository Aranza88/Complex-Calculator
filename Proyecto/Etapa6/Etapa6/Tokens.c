#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Tokens.h"

char strToken[][11] = {"operador", "numero", "variable", "parentesis","igual"};

int esOperador(char c)
{
    int k;
    static char operadores[] = "+-*/^";
    for (k=0; k<strlen(operadores); k++)
        if (c == operadores[k])
            return 1;
    return 0;
}

int esParentesis(char c)
{
    if (c=='(' || c==')'||c=='['||c==']')
        return 1;
    return 0;
}

TToken token(char *s) {
    static char cadena[1000];
    static char *actual;
    int k;
    char res[100];
    TToken *unToken;
    if (s!= NULL)//Agrega la cadena que da el usuario 2 arreglos distintos: cadena[1000] y *actual
	{
        strcpy(cadena,s);
        actual = cadena;
    }
    while ((*actual == ' ') || (*actual =='\n') || (*actual=='\t'))//Recorre todos los espacios vacios y secuencias de escape hasta que encuentra un caracter
        actual = actual + 1;
    if (*actual == '\0'){//Comprueba si la cadena esta vacia una ves recorrido
        unToken=malloc(sizeof(TToken));
        strcpy(unToken->token,"Termine");
        return *unToken;
    }
    if (esOperador(*actual) == 1) //Verifica si es un operador
	{
        res[0] = *actual;
        res[1] = '\0';
        unToken=malloc(sizeof(TToken));
        actual = actual + 1;
        strcpy(unToken->token,res);
        unToken->tipo= operador;
        return *unToken;
    } else if (*actual=='='){
        res[0] = *actual;
        res[1] = '\0';
        unToken=malloc(sizeof(TToken));
        actual = actual + 1;
        strcpy(unToken->token,res);
        unToken->tipo= igual;
        return *unToken;
    } else if (esParentesis(*actual) == 1){//Verifica si es un parentesis
        res[0] = *actual;
        res[1] = '\0';
        unToken=malloc(sizeof(TToken));
        actual = actual + 1;
        strcpy(unToken->token,res);
        unToken->tipo= parentesis;
        return *unToken;
    } else if (isdigit(*actual) || (*actual=='.')){//Convierte el caracter a numero y verifica si es un punto, si se forma un solo numoer, se agrega como un solo token
        k = 0;
        while ( (*actual != '\0') && (isdigit(*actual) || *actual == '.' ) ) {
            res[k] = (*actual);
            actual = actual + 1;
            k = k+1;
        }
        res[k]='\0';
        unToken=malloc(sizeof(TToken));
        strcpy(unToken->token,res);
        unToken->tipo= numero;
        return *unToken;
    } else if (isalpha(*actual)){//Separa las variables de la cadena ejemplo: si es 2x, lo separa de la cadena como un solo
        k = 0;
        while ( (*actual != '\0') && isalpha(*actual)){
            res[k] = *actual;
            actual = actual + 1;
            k = k+1;
        }
        res[k] = '\0';
        unToken=malloc(sizeof(TToken));
        strcpy(unToken->token,res);
        unToken->tipo= variable;
        return *unToken;
    	}
    printf("Error: expresion incorrecta");
    printf("Programa detenido");
    exit(0);
}

