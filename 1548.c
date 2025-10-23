#include <stdio.h>
#include <string.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int resultados[1000];
    int idx = 0;

    while (N--) {
        int M;
        scanf("%d", &M);

        int original[1000];
        int ordenado[1000];

        for (int i = 0; i < M; i++) {
            scanf("%d", &original[i]);
            ordenado[i] = original[i];
        }

        bubbleSort(ordenado, M);

        int contador = 0;
        for (int i = 0; i < M; i++) {
            if (original[i] == ordenado[i])
                contador++;
        }

        resultados[idx++] = contador;
    }

    for (int i = 0; i < idx; i++) {
        printf("%d\n", resultados[i]);
    }

    return 0;
}
