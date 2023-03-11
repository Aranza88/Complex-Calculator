#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "lista.h"

typedef struct {
    char Nombre[20];
    int edad;
} TPersona;

int diferenteNombre(void *x, void *y) {
    if (strcmp(((TPersona *)x)->Nombre,((TPersona *)y)->Nombre)==0)
        return 0;
    return 1;
}

void imprimePersona(void *p) {
    printf("Nombre: %-20s edad: %2d\n",((TPersona *)p)->Nombre,((TPersona *)p)->edad);
}

void imprimeNumero(void *x) {
    printf("Numero %0.2f\n",*(double *)x);
}

int main()
{
    TLista *listaNumeros, *listaPersona;
    double x;
    TPersona p, *q;
    char r;

    listaNumeros = nuevaLista(sizeof(double));
    listaPersona = nuevaLista(sizeof(TPersona));


    do {
        printf("Dame un numero real: ");
        scanf("%lf",&x);
        if (x>=0) {
            agregarNodo(listaNumeros,&x);
        }
    } while (x>=0);

    do {
        printf("Nombre de la persona? ");
        scanf("%s",p.Nombre);
        printf("Edad? ");
        scanf("%d",&(p.edad));
        if (p.edad>0)
            agregarNodo(listaPersona,&p);

    } while (p.edad>0);

    printf("----- Lista numeros ----\n");
    itera(listaNumeros,imprimeNumero);
    printf("---- Lista Personas ----\n");
    itera(listaPersona,imprimePersona);

    do {
        printf("Nombre de la persona? ");
        scanf("%s",p.Nombre);
        q = buscarNodo(listaPersona,&p,diferenteNombre);

        if (q!=NULL) {
            imprimePersona(q);
            q->edad += 1;
        } else {
            printf("No existe\n");
        }
        itera(listaPersona,imprimePersona);

        printf("Desea buscar otra persona (s/n)? ");
        fflush(stdin);
        scanf("%c",&r);
        fflush(stdin);

    } while (r == 's');

    return 0;
}
