#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortWrapper(int arr[], int n) {
    quickSort(arr, 0, n - 1);
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
        
        quickSortWrapper(todosAlturas[caso], N);
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