TLista *posfija(TLista *listaInfija){
    TLista*listaPosfija=nuevaLista(sizeof(TToken));
    TPila *p=nuevaPila(sizeof(Token),100);
    TToken +aux;
    while (!listaVacia(listaInfija)){
        retirarNodo(listaInfija,(void **)&aux);
        printf("token: %s [%s]\n",strToken[aux->tipo],aux->token);
    }
    return listaPosfija;
}
