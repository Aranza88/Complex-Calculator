#ifndef OPERACION_H_INCLUDED
#define OPERACION_H_INCLUDED
typedef struct{
    char Nombre[20];
    float Cantidad;
}TVariable;

int compara(void *dato1, void *dato2);
void answer(TLista *listaPosfija,TLista *var);

#endif // OPERACION_H_INCLUDED
