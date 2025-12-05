#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

No* inserir(No* raiz, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = novo->dir = NULL;

    if (raiz == NULL)
        return novo;

    No* atual = raiz;
    No* pai = NULL;

    while (atual != NULL) {
        pai = atual;
        if (valor <= atual->valor)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    if (valor <= pai->valor)
        pai->esq = novo;
    else
        pai->dir = novo;

    return raiz;
}

void emOrdem(No* raiz) {
    if (!raiz) return;
  
    int capacidade = 1000;
    No** pilha = (No**)malloc(capacidade * sizeof(No*));
    int topo = -1;
    No* atual = raiz;

    while (atual != NULL || topo >= 0) {
        while (atual != NULL) {
            if (topo == capacidade - 1) {
                capacidade *= 2;
                pilha = (No**)realloc(pilha, capacidade * sizeof(No*));
            }
            pilha[++topo] = atual;
            atual = atual->esq;
        }

        atual = pilha[topo--];
        printf("%d ", atual->valor);

        atual = atual->dir;
    }
    
    free(pilha);
}

void liberarArvore(No* raiz) {
    if (!raiz) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    int numCidades;
    scanf("%d", &numCidades);

    while (numCidades--) {
        int numPessoas, altura;
        scanf("%d", &numPessoas);

        No* raiz = NULL;

        for (int i = 0; i < numPessoas; i++) {
            scanf("%d", &altura);
            raiz = inserir(raiz, altura);
        }

        emOrdem(raiz);
        printf("\n");

        liberarArvore(raiz);
    }

    return 0;
}
