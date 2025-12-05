#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        No* novo = (No*) malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

void preOrdem(No* raiz, char *saida) {
    if (raiz == NULL) return;

    char buffer[20];
    sprintf(buffer, "%d ", raiz->valor);
    strcat(saida, buffer);

    preOrdem(raiz->esq, saida);
    preOrdem(raiz->dir, saida);
}

void inOrdem(No* raiz, char *saida) {
    if (raiz == NULL) return;

    inOrdem(raiz->esq, saida);

    char buffer[20];
    sprintf(buffer, "%d ", raiz->valor);
    strcat(saida, buffer);

    inOrdem(raiz->dir, saida);
}

void posOrdem(No* raiz, char *saida) {
    if (raiz == NULL) return;

    posOrdem(raiz->esq, saida);
    posOrdem(raiz->dir, saida);

    char buffer[20];
    sprintf(buffer, "%d ", raiz->valor);
    strcat(saida, buffer);
}

void liberar(No* raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int C;
    scanf("%d", &C);

    int quantidades[1000];
    int *valores[1000];

    for (int i = 0; i < C; i++) {
        scanf("%d", &quantidades[i]);

        valores[i] = (int*) malloc(sizeof(int) * quantidades[i]);

        for (int j = 0; j < quantidades[i]; j++) {
            scanf("%d", &valores[i][j]);
        }
    }

    for (int caso = 0; caso < C; caso++) {

        No *raiz = NULL;

        for (int i = 0; i < quantidades[caso]; i++) {
            raiz = inserir(raiz, valores[caso][i]);
        }

        char pre[5000] = "";
        char in[5000] = "";
        char post[5000] = "";

        preOrdem(raiz, pre);
        inOrdem(raiz, in);
        posOrdem(raiz, post);

        pre[strlen(pre) - 1] = '\0';
        in[strlen(in) - 1] = '\0';
        post[strlen(post) - 1] = '\0';

        printf("Case %d:\n", caso + 1);
        printf("Pre.: %s\n", pre);
        printf("In..: %s\n", in);
        printf("Post: %s\n\n", post);

        liberar(raiz);
        free(valores[caso]);
    }

    return 0;
}
