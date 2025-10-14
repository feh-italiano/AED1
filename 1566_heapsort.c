#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
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
        
        heapSort(todosAlturas[caso], N);
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