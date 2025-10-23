#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    
    scanf("%d", &N);
    
    int *fila = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }
    
    scanf("%d", &M);
    
    int *saidas = (int*)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        scanf("%d", &saidas[i]);
    }
    
    int *saiu = (int*)calloc(100001, sizeof(int));
    
    for (int i = 0; i < M; i++) {
        saiu[saidas[i]] = 1;
    }
    
    int *fila_final = (int*)malloc((N - M) * sizeof(int));
    int pos = 0;
    
    for (int i = 0; i < N; i++) {
        if (!saiu[fila[i]]) {
            fila_final[pos++] = fila[i];
        }
    }
    
    for (int i = 0; i < N - M; i++) {
        printf("%d", fila_final[i]);
        if (i < N - M - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    free(fila);
    free(saidas);
    free(saiu);
    free(fila_final);
    
    return 0;
}