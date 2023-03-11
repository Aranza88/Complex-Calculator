#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int esOperador(char c);
char *token(char *s);

int main() {
    int n=0,k;
    char cadena[] = " ( aabdfs36.5 ( 23.4- 2)^2/56)/3\n ";
    char *p;
    char *tokens[100];
    p = token(cadena);
    while (p!=NULL) {
        tokens[n] = p;
        n++;
        p = token(NULL);
    }
    for (k=0; k<n; k++)
        printf("Token: %s\n",tokens[k]);
    printf("Termine\n");
    return 0;
}

int esOperador(char c) {
    char operadores[] = "+-*/^()";
    int k;
    for (k=0; k<strlen(operadores); k++)
        if (c==operadores[k])
            return 1;
    return 0;
}

char *token(char *s) {
    static char cadena[1000];
    static char *actual;
    char *res;
    res=malloc(50*sizeof(char));
    int j;
    if (s!=NULL) {
        strcpy(cadena,s);
        actual=cadena;
    }
    while ((*actual==' ') || (*actual=='\n') || (*actual=='\t'))
        actual++;
    if (*actual=='\0')
        return NULL;
    if (esOperador(*actual)==1) {
        res[0]=*actual;
        res[1]='\0';
        actual=actual + 1;
        return res;
    } else if (isdigit(*actual)){
        j=0;
        while ((*actual!='\0'&&isdigit(*actual))||*actual=='.'){
            if (isdigit(*actual)||*actual!='\0') {
                res[j]=*actual;
                actual=actual + 1;
                j++;
            }
        }res[j]='\0';
        return res;
    } else if (isalpha(*actual)) {
        j=0;
        while (*actual!='\0'&&(isalpha(*actual)/*||isdigit(*actual)*/)){
            if (isalpha(*actual)||*actual!='\0') {
                res[j]=*actual;
                actual=actual + 1;
                j++;
            }
        }res[j]='\0';
        return res;
    }
    printf("Hay algo raro! expresion incorrecta");
    exit(0);
}
