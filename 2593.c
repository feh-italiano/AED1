#include <stdio.h>
#include <string.h>

#define MAX_TEXT_SIZE 10050
#define MAX_WORD_SIZE 200
#define MAX_WORDS 200

typedef struct {
    char s1[MAX_WORD_SIZE];
} string;

int main() {
    char tmp[MAX_TEXT_SIZE];
    string texto[MAX_TEXT_SIZE];
    string palavras[MAX_WORDS];

    // Leitura do texto
    scanf(" %[^\n]", tmp);
    
    // Leitura do número de palavras
    unsigned n;
    scanf("%u", &n);

    // Leitura das palavras
    for (unsigned i = 0; i < n; ++i)
        scanf("%s", palavras[i].s1);

    unsigned i = 0;
    char *aux = strtok(tmp, " ");
    strcpy(texto[i++].s1, aux);

    // Divisão do texto em palavras
    do {
        aux = strtok(NULL, " ");
        if (aux)
            strcpy(texto[i++].s1, aux);
    } while (aux);

    // Verificação das posições das palavras no texto
    for (unsigned k = 0; k < n; ++k) {
        unsigned tam = 0;
        int found = 0;

        for (unsigned j = 0; j < i; ++j) {
            if (strcmp(texto[j].s1, palavras[k].s1) == 0) {
                if (found)
                    printf(" %u", tam);
                else
                    printf("%u", tam), found = 1;
            }
            tam += strlen(texto[j].s1) + 1;
        }

        if (!found)
            printf("-1");
        printf("\n");
    }

    return 0;
}