#include <stdio.h>
#include "pila.h"


typedef struct {
    char nombre[20];
    int calif;
} TAlumno;

TAlumno leer() {
    TAlumno a;
    printf("Nombre? "); scanf("%s",a.nombre);
    printf("Calificacion? ");scanf("%d",&a.calif);
    return a;
}


// la direccion apunta a una estructura TAlumno
void imprimir(void *a)  {
    TAlumno *dato = a;
    printf("Nombre: %20s %2d\n",dato->nombre,dato->calif);
//    printf("Nombre: %20s %2d\n",((TAlumno *)a)->nombre,
//                                ((TAlumno *)a)->calif);
}

void imprimirEntero(int *a) {
    printf("%d",*a);
}

int main() {
    TPila *pAlumno;
    TAlumno alumno;
    TPila *pEnteros;
    int k;

    pAlumno = nuevaPila(sizeof(TAlumno),100);
    pEnteros = nuevaPila(sizeof(int),50);

    for (k=0;k<4;k++) {
        alumno = leer();
        if (! llena(pAlumno)) {
            push(pAlumno,&alumno);
            imprimir(&alumno);
        }
    }

    imprimePila(pAlumno,imprimir);

    while (!vacia(pAlumno)) {
        pop(pAlumno,&alumno);
        push(pEnteros,&alumno.calif);
    }

    imprimePila(pEnteros,imprimirEntero);

}
