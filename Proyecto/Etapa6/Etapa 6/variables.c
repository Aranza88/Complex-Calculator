#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"
#include "Tokens.h"
#include "variables.h"

void nuevaVariable(TLista *vars,char *op1,float op2){
    TVariable nueva;
    strcpy(nueva.nombre,op1);
    nueva.cantidad=op2;
    agregarNodo(vars,&nueva);
    return;
}
