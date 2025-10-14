#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int *X = (int*)malloc(N * sizeof(int));
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }
    
    int menor = X[0];
    int posicao = 0;
    
    for(int i = 1; i < N; i++) {
        if(X[i] < menor) {
            menor = X[i];
            posicao = i;
        }
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
    
    free(X);
    
    return 0;
}