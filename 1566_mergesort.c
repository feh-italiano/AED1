#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        
        merge(arr, temp, left, mid, right);
    }
}

void mergeSortWrapper(int arr[], int n) {
    int *temp = (int*)malloc(n * sizeof(int));
    mergeSort(arr, temp, 0, n - 1);
    free(temp);
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
        
        mergeSortWrapper(todosAlturas[caso], N);
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