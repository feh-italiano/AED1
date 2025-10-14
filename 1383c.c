#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 9
#define SUBGRID 3

bool confere_valido(int **sudoku){
    for (int i = 0; i < TAMANHO; i++) {
        bool numeros[10] = {false};
        for (int j = 0; j < TAMANHO; j++) {
            int num = sudoku[i][j];
            if (numeros[num]) return false;
            numeros[num] = true;
        }
    }
    
    for (int j = 0; j < TAMANHO; j++) {
        bool numeros[10] = {false};
        for (int i = 0; i < TAMANHO; i++) {
            int num = sudoku[i][j];
            if (numeros[num]) return false;
            numeros[num] = true;
        }
    }
    
    for (int bloco = 0; bloco < TAMANHO; bloco++) {
        bool numeros[10] = {false};
        int inicio_linha = (bloco / SUBGRID) * SUBGRID;
        int inicio_coluna = (bloco % SUBGRID) * SUBGRID;
        
        for (int i = 0; i < SUBGRID; i++) {
            for (int j = 0; j < SUBGRID; j++) {
                int num = sudoku[inicio_linha + i][inicio_coluna + j];
                if (numeros[num]) return false;
                numeros[num] = true;
            }
        }
    }
    
    return true;
}

int main() {
    int jogos;
    scanf("%d", &jogos);

    // Alocação dinâmica da matriz
    int **sudoku = (int **)malloc(TAMANHO * sizeof(int *));
    for (int i = 0; i < TAMANHO; i++) {
        sudoku[i] = (int *)malloc(TAMANHO * sizeof(int));
    }

    for(int x = 0; x < jogos; x++){
        for(int i = 0; i < TAMANHO; i++){
            for(int j = 0; j < TAMANHO; j++){
                scanf("%d", &sudoku[i][j]);
            }
        }
        
        printf("Instancia %d\n", x + 1);
        if (confere_valido(sudoku)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    // Liberar memória
    for (int i = 0; i < TAMANHO; i++) {
        free(sudoku[i]);
    }
    free(sudoku);

    return 0;
}
