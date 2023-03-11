#ifndef POSFIJA_H_INCLUDED
#define POSFIJA_H_INCLUDED

int pCerrado(void *a);
int pAbierto(void *a);
int precedencia(char op);
int mayorPrecedencia(char op1,char op2);
TLista *posfija(TLista *listaInfija);

#endif // POSFIJA_H_INCLUDED
