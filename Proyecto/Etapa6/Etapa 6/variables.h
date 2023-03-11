#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

typedef struct{
    char nombre[20];
    float cantidad;
}TVariable;

void nuevaVariable(TLista *vars,char *op1,float op2);

#endif // VARIABLES_H_INCLUDED
