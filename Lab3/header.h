#ifndef HEAD_H
#define HEAD_H

typedef struct nodo {
    int chave;
    int fb; /* fator de balanceamento */
    struct nodo *esq;
    struct nodo *dir;
} Nodo;

typedef struct avl {
    Nodo *raiz;
} Avl;

Nodo* avl_insere(Nodo* r, int chave);

#endif