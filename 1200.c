#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No *esq, *dir;
} No;

No* inserir(No* raiz, char valor) {
    if (raiz == NULL) {
        No* novo = (No*) malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

void infixa(No* raiz, int *primeiro) {
    if (raiz == NULL) return;

    infixa(raiz->esq, primeiro);

    if (*primeiro) {
        printf("%c", raiz->valor);
        *primeiro = 0;
    } else {
        printf(" %c", raiz->valor);
    }

    infixa(raiz->dir, primeiro);
}

void prefixa(No* raiz, int *primeiro) {
    if (raiz == NULL) return;

    if (*primeiro) {
        printf("%c", raiz->valor);
        *primeiro = 0;
    } else {
        printf(" %c", raiz->valor);
    }

    prefixa(raiz->esq, primeiro);
    prefixa(raiz->dir, primeiro);
}

void posfixa(No* raiz, int *primeiro) {
    if (raiz == NULL) return;

    posfixa(raiz->esq, primeiro);
    posfixa(raiz->dir, primeiro);

    if (*primeiro) {
        printf("%c", raiz->valor);
        *primeiro = 0;
    } else {
        printf(" %c", raiz->valor);
    }
}

int buscar(No* raiz, char valor) {
    if (raiz == NULL) return 0;

    if (valor == raiz->valor) return 1;

    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);
    else
        return buscar(raiz->dir, valor);
}

int main() {
    No* raiz = NULL;
    char comando[20];
    char letra;

    // Lê até EOF
    while (scanf("%s", comando) != EOF) {

        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &letra);
            raiz = inserir(raiz, letra);
        }
        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &letra);
            if (buscar(raiz, letra))
                printf("%c existe\n", letra);
            else
                printf("%c nao existe\n", letra);
        }
        else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            infixa(raiz, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixa(raiz, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixa(raiz, &primeiro);
            printf("\n");
        }
    }

    return 0;
}
