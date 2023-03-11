#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Tokens.h"

char strToken[][11] = {"operador", "numero", "variable", "parentesis"};

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
        //[ y ] agregados a la condicion
        return 1;
    return 0;
}

TToken *token(char *s) {
    static char cadena[1000];
    static char *actual;
    int k;
    char res[100];
    //tamaño de res modificado
    TToken *unToken=NULL;
    if (s!= NULL)//Agrega la cadena que da el usuario 2 arreglos distintos: cadena[1000] y *actual
	{
        strcpy(cadena,s);
        actual = cadena;
    }
    while ((*actual == ' ') || (*actual =='\n') || (*actual=='\t'))//Recorre todos los espacios vacios y secuencias de escape hasta que encuentra un caracter
        actual++;
    if (*actual == '\0')//Comprueba si la cadena esta vacia una ves recorrido
        return NULL;
    if (esOperador(*actual) == 1) //Verifica si es un operador
	{
        res[0] = *actual;
        res[1] = '\0';
        //
        unToken=malloc(sizeof(TToken));
        unToken->token[0]=res[0];
        unToken->token[1]='\0';
        unToken->tipo= 0;
        //lineas agregadas
        actual = actual + 1;
        return unToken;
    } else if (esParentesis(*actual) == 1){//Verifica si es un parentesis
        res[0] = *actual;
        res[1] = '\0';
        //
        unToken=malloc(sizeof(TToken));
        unToken->token[0]=res[0];
        unToken->token[1]='\0';
        unToken->tipo= 3;
        // lineas agregadas
        actual = actual + 1;
        return unToken;
    } else if (isdigit(*actual) || (*actual=='.')){//Convierte el caracter a numero y verifica si es un punto, si se forma un solo numoer, se agrega como un solo token
        k = 0;
        unToken=malloc(sizeof(TToken));
        //creacion de unToken agregado
        while ( (*actual != '\0') && (isdigit(*actual) || *actual == '.' ) ) {
            res[k] = (*actual);
            actual = actual + 1;
            unToken->token[k]=res[k];
            k = k+1;
        }
        res[k]='\0';
        //
        unToken->token[k]='\0';
        unToken->tipo= 1;
        //lineas agregadas
        return unToken;
    } else if (isalpha(*actual)){//Separa las variables de la cadena ejemplo: si es 2x, lo separa de la cadena como un solo
        k = 0;
        unToken=malloc(sizeof(TToken));
        //creacion de unToken agregado
        while ( (*actual != '\0') && isalpha(*actual)){
            res[k] = *actual;
            actual = actual + 1;
            unToken->token[k]=res[k];
            //linea agregada
            k = k+1;
        }
        res[k] = '\0';
        //
        unToken->token[k]='\0';
        unToken->tipo= 2;
        //lineas agregadas
        return unToken;
    	}
    printf("Error: expresion incorrecta");
    printf("Programa detenido");
    exit(0);
}
