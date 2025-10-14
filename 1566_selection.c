#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
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
        
        selectionSort(todosAlturas[caso], N);
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