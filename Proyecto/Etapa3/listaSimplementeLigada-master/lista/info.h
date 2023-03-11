#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED

struct Info{
    char nombre[100];
    double monto;
    int indice;
    int activo;
};
typedef struct Info TInfo;

void leer(TInfo *cuenta);
void imprimir(TInfo c);


#endif // INFO_H_INCLUDED
