#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 9
#define SUBGRID 3

bool confere_valido(int sudoku[9][9]){
    
    //CONFERE NA LINHA
    for (int i = 0; i < TAMANHO; i++) {
        bool numeros[10] = {false}; // índice 1-9
        for (int j = 0; j < TAMANHO; j++) {
            int num = sudoku[i][j];
            if (numeros[num]) {
                return false; // Número repetido na linha
            }
            numeros[num] = true;
        }
    }
    
    //CONFERE NA COLUNA
    for (int j = 0; j < TAMANHO; j++) {
        bool numeros[10] = {false};
        for (int i = 0; i < TAMANHO; i++) {
            int num = sudoku[i][j];
            if (numeros[num]) {
                return false; // Número repetido na coluna
            }
            numeros[num] = true;
        }
    }
    
    //CONFERE NO 3x3
    for (int bloco = 0; bloco < TAMANHO; bloco++) {
        bool numeros[10] = {false};
        int inicio_linha = (bloco / SUBGRID) * SUBGRID;
        int inicio_coluna = (bloco % SUBGRID) * SUBGRID;
        
        for (int i = 0; i < SUBGRID; i++) {
            for (int j = 0; j < SUBGRID; j++) {
                int num = sudoku[inicio_linha + i][inicio_coluna + j];
                if (numeros[num]) {
                    return false;
                }
                numeros[num] = true;
            }
        }
    }
    
    return true;
}

int main()
{
    int sudoku[9][9], jogos;
    scanf("%d",&jogos);
    
    for(int x=0;x<jogos;x++){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                scanf("%d",&sudoku[i][j]);
            }
        }
        
        if (confere_valido(sudoku)) {
                printf("Instancia %d\n", x+1);
                printf("SIM\n\n");
            } else {
                printf("Instancia %d\n", x+1);
                printf("NAO\n\n");
            }
    }
}