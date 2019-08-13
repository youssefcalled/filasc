typedef struct fila
{
    int info;
    struct fila *prox;
} Fila;

Fila *criaFila()
{
    return NULL;
}
int FilaVazia (Fila *p)
{
    return (p == NULL);
}

Fila *inserir (Fila *p, int i)
{

    Fila *novo = (Fila*) malloc(sizeof(Fila));
    novo->info = i;
    novo->prox = NULL;

    if(p != NULL)
    {
        Fila *aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;

            aux->prox = novo;
            return p;
    }


}


Fila *retirainicio (Fila *p)
{
    Fila *aux = p;
    if (FilaVazia(p))
        printf("\nFila vazia");
    else
    {
        p=p->prox;
        free(aux);
        return p;
    }
}

Fila *Busca (Fila *p, int v)
{
    Fila *aux;
    for (aux=p; aux!=NULL; aux = aux->prox)
    {
        if (aux->info == v)
            return aux; //retorna a célula se encontrou o elemento
    }
    return NULL;

}

void liberaFila (Fila *p)
{
    Fila *l = p, *t;
    while ( l != NULL)
    {
        t = l -> prox; /* guarda referência p/ próx. elemento */
        free(l); /* libera a memória apontada por p */
        l = t; /* faz p apontar para o próximo */
    }
}

Fila *Mostra (Fila *p)
{
    Fila *aux;
    for (aux=p; aux!=NULL; aux = aux->prox)
    {
        printf("%2d",aux->info);
    }

}

Fila *unir(Fila *p, Fila *q)
{

    Fila *aux = p;

    while(aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = q;
    p = NULL;

    return p;
}
Fila *passarinicio(Fila *p,int num)
{
    Fila *novo = (Fila*) malloc(sizeof(Fila));
    Fila *aux = p;
    Fila *anterior = NULL;

    while(aux != NULL && aux->info != num)
    {
        anterior = aux;
        aux = aux->prox;
    }

    if(anterior == NULL)
        return p;
    else
    {
        novo->info = num;
        anterior->prox = aux->prox;
        free(aux);
    }
	novo->prox = p;
    return novo;

}





