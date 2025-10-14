#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    int NC;
    scanf("%d", &NC);
    
    int **todosAlturas = (int**)malloc(NC * sizeof(int*));
    int *tamanhos = (int*)malloc(NC * sizeof(int));
    
    for (int caso = 0; caso < NC; caso++) {
        scanf("%d", &tamanhos[caso]);
        int N = tamanhos[caso];
        
        todosAlturas[caso] = (int*)malloc(N * sizeof(int));
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &todosAlturas[caso][i]);
        }
        
        insertionSort(todosAlturas[caso], N);
    }
    
    for (int caso = 0; caso < NC; caso++) {
        int N = tamanhos[caso];
        for (int i = 0; i < N; i++) {
            printf("%d", todosAlturas[caso][i]);
            if (i < N - 1) printf(" ");
        }
        printf("\n");
        
        free(todosAlturas[caso]);
    }
    
    free(todosAlturas);
    free(tamanhos);
    
    return 0;
}