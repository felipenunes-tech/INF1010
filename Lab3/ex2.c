#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int obter_altura(Nodo* n) {
    if (n == NULL) return -1;
    int esq = obter_altura(n->esq);
    int dir = obter_altura(n->dir);
    return (esq > dir ? esq : dir) + 1;
}

int calcular_fb(Nodo* n) {
    if (n == NULL) return 0;
    return obter_altura(n->esq) - obter_altura(n->dir);
}

Nodo* rotacionar_direita(Nodo* r) {
    printf("Rotação à direita (RD) no nó %d\n", r->chave);
    Nodo* nova_raiz = r->esq;
    r->esq = nova_raiz->dir;
    nova_raiz->dir = r;
    return nova_raiz;
}

Nodo* rotacionar_esquerda(Nodo* r) {
    printf("Rotação à esquerda (RE) no nó %d\n", r->chave);
    Nodo* nova_raiz = r->dir;
    r->dir = nova_raiz->esq;
    nova_raiz->esq = r;
    return nova_raiz;
}

Nodo* avl_insere(Nodo* r, int chave) {
    if (r == NULL) {
        r = (Nodo*) malloc(sizeof(Nodo));
        r->chave = chave;
        r->esq = r->dir = NULL;
        r->fb = 0;
        return r;
    }

    if (chave < r->chave) r->esq = avl_insere(r->esq, chave);
    else if (chave > r->chave) r->dir = avl_insere(r->dir, chave);
    else return r;

    int fb = calcular_fb(r);

    if (fb > 1 && chave < r->esq->chave)
        return rotacionar_direita(r);

    if (fb < -1 && chave > r->dir->chave)
        return rotacionar_esquerda(r);

    if (fb > 1 && chave > r->esq->chave) {
        r->esq = rotacionar_esquerda(r->esq);
        return rotacionar_direita(r);
    }

    if (fb < -1 && chave < r->dir->chave) {
        r->dir = rotacionar_direita(r->dir);
        return rotacionar_esquerda(r);
    }

    return r;
}

void imprimir_em_ordem(Nodo* r) {
    if (r != NULL) {
        imprimir_em_ordem(r->esq);
        printf("%d ", r->chave);
        imprimir_em_ordem(r->dir);
    }
}

int main() {
    Nodo* raiz = (Nodo*) malloc(sizeof(Nodo));
    raiz->chave = 50;
    raiz->esq = raiz->dir = NULL;
    raiz->fb = 0;

    int elementos[] = {1, 64, 12, 18, 66, 38, 95, 58, 59, 70, 43, 16, 67, 39};
    int n = sizeof(elementos) / sizeof(elementos[0]);

    for(int i = 0; i < n; i++) {
        printf("Inserindo %d: ", elementos[i]);
        raiz = avl_insere(raiz, elementos[i]);
        printf("Foi\n");
    }

    printf("\nÁrvore Final (Em Ordem): ");
    imprimir_em_ordem(raiz);
    printf("\n");

    return 0;
}