#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *prox;
} celula;

typedef struct {
    celula *inicio;
    celula *fim;
} fila;

void inicializarFila(fila *f) {
    f->inicio = f->fim = NULL;
}

int filaVazia(fila *f) {
    return f->inicio == NULL;
}

void enfileirar(fila *f, int valor) {
    celula *nova = (celula *) malloc(sizeof(celula)); 
    
    if (nova == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(1);
    }

    nova->valor = valor;
    nova->prox = NULL;

    if (filaVazia(f)) {
        f->inicio = f->fim = nova;
    } else {
        f->fim->prox = nova;
        f->fim = nova;
    }
}

int desenfileirar(fila *f) {
    if (filaVazia(f)) {
        fprintf(stderr, "Fila vazia. Erro fatal.\n");
        exit(1); 
    }

    celula *temp = f->inicio;
    int valor = temp->valor;

    f->inicio = temp->prox;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);

    return valor;
}


int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        fila f;
        inicializarFila(&f);

        for (int i = 1; i <= n; i++) {
            enfileirar(&f, i);
        }

        printf("Discarded cards: ");

        int first_discard = 1;
        
        while (!filaVazia(&f)) {
            int discarded = desenfileirar(&f);

            if (!filaVazia(&f)) {
                
                if (!first_discard) {
                    printf(", ");
                }
                printf("%d", discarded);
                first_discard = 0;

                int move_to_bottom = desenfileirar(&f);
                enfileirar(&f, move_to_bottom);
            } else {
                printf("\nRemaining card: %d\n", discarded);
            }
        }

    }

    return 0;
}