//PONTEIROS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    
    scanf("%d", &N);
    
    int *X = (int*)malloc(N * sizeof(int));
    
    int *ptr = X;
    for(int i = 0; i < N; i++) {
        scanf("%d", ptr);
        ptr++;
    }
    
    int *menor_ptr = X, *atual = X + 1;
    
    for(int i = 1; i < N; i++) {
        if(*atual < *menor_ptr) {
            menor_ptr = atual;
        }
        atual++;
    }
    
    int posicao = menor_ptr - X;
    
    printf("Menor valor: %d\n", *menor_ptr);
    printf("Posicao: %d\n", posicao);
    
    free(X);
    
    return 0;
}