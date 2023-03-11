#include <stdio.h>
#include "info.h"

void leer(TInfo *cuenta) {
    static int indiceActual = 0;
    printf("Nombre? ");
    fflush(stdin); scanf("%s^[\n]",cuenta->nombre);
    printf("monto? ");
    fflush(stdin); scanf("%lf",&cuenta->monto);
    cuenta->indice = indiceActual; indiceActual++;
}

void imprimir(TInfo c) {
    printf("%2d %-20s $%10.2f\n",c.indice,c.nombre,c.monto);
}
