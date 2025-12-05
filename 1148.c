#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 501
#define INF 1000000000

typedef struct {
    int destino;
    int custo;
    int prox;
} Aresta;

Aresta arestas[250000 * 2];
int primeiro[MAXN], aresta_atual;

/* ---------- TARJAN ---------- */
int indice, pilha_topo;
int indice_no[MAXN], menor_indice[MAXN], na_pilha[MAXN];
int pilha[MAXN];
int scc_id[MAXN], scc_total;

void adicionar_aresta(int a, int b, int custo) {
    arestas[aresta_atual].destino = b;
    arestas[aresta_atual].custo = custo;
    arestas[aresta_atual].prox = primeiro[a];
    primeiro[a] = aresta_atual++;
}

void tarjan(int no) {
    indice_no[no] = menor_indice[no] = ++indice;
    pilha[pilha_topo++] = no;
    na_pilha[no] = 1;

    for (int i = primeiro[no]; i != -1; i = arestas[i].prox) {
        int v = arestas[i].destino;

        if (!indice_no[v]) {
            tarjan(v);
            if (menor_indice[v] < menor_indice[no])
                menor_indice[no] = menor_indice[v];
        } else if (na_pilha[v]) {
            if (indice_no[v] < menor_indice[no])
                menor_indice[no] = indice_no[v];
        }
    }

    if (menor_indice[no] == indice_no[no]) {
        scc_total++;
        int v;
        do {
            v = pilha[--pilha_topo];
            na_pilha[v] = 0;
            scc_id[v] = scc_total;
        } while (v != no);
    }
}

/* ---------- DIJKSTRA ---------- */
int distancia[MAXN];
int visitado[MAXN];

int heap[300000][2], heap_tam;

void heap_push(int dist, int no) {
    int i = heap_tam++;
    heap[i][0] = dist;
    heap[i][1] = no;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p][0] <= heap[i][0]) break;
        int td = heap[p][0], tn = heap[p][1];
        heap[p][0] = heap[i][0], heap[p][1] = heap[i][1];
        heap[i][0] = td, heap[i][1] = tn;
        i = p;
    }
}

int heap_pop(int *ndist, int *nno) {
    if (heap_tam == 0) return 0;

    *ndist = heap[0][0];
    *nno = heap[0][1];

    heap_tam--;
    heap[0][0] = heap[heap_tam][0];
    heap[0][1] = heap[heap_tam][1];

    int i = 0;
    while (1) {
        int f = i * 2 + 1;
        if (f >= heap_tam) break;
        if (f + 1 < heap_tam && heap[f + 1][0] < heap[f][0])
            f++;

        if (heap[i][0] <= heap[f][0]) break;

        int td = heap[i][0], tn = heap[i][1];
        heap[i][0] = heap[f][0], heap[i][1] = heap[f][1];
        heap[f][0] = td, heap[f][1] = tn;

        i = f;
    }

    return 1;
}

int dijkstra(int origem, int destino, int total_nos) {
    for (int i = 1; i <= total_nos; i++) {
        distancia[i] = INF;
        visitado[i] = 0;
    }

    distancia[origem] = 0;
    heap_tam = 0;
    heap_push(0, origem);

    while (heap_tam > 0) {
        int dist, atual;
        heap_pop(&dist, &atual);

        if (visitado[atual]) continue;
        visitado[atual] = 1;

        if (atual == destino) return dist;

        for (int i = primeiro[atual]; i != -1; i = arestas[i].prox) {
            int v = arestas[i].destino;
            int custo = arestas[i].custo;

            if (distancia[v] > dist + custo) {
                distancia[v] = dist + custo;
                heap_push(distancia[v], v);
            }
        }
    }

    return INF;
}

/* ---------- MAIN ---------- */
int main() {
    int cidades, acordos;

    while (1) {
        scanf("%d %d", &cidades, &acordos);
        if (cidades == 0 && acordos == 0) break;

        memset(primeiro, -1, sizeof(primeiro));
        aresta_atual = 0;

        for (int i = 0; i < acordos; i++) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);
            adicionar_aresta(x, y, h);
        }

        /* ---- TARJAN para achar SCC ---- */
        memset(indice_no, 0, sizeof(indice_no));
        memset(na_pilha, 0, sizeof(na_pilha));
        indice = pilha_topo = 0;
        scc_total = 0;

        for (int i = 1; i <= cidades; i++)
            if (!indice_no[i])
                tarjan(i);

        /* ---- Construir grafo condensado ---- */
        int novo_primeiro[MAXN];
        Aresta arestas_backup[250000 * 2];  // Backup das arestas originais
        
        // Fazer backup da estrutura atual
        memcpy(novo_primeiro, primeiro, sizeof(primeiro));
        memcpy(arestas_backup, arestas, aresta_atual * sizeof(Aresta));
        int backup_aresta_atual = aresta_atual;

        // Limpar para novo grafo condensado
        memset(primeiro, -1, sizeof(primeiro));
        aresta_atual = 0;

        // Adicionar arestas entre SCCs diferentes
        for (int u = 1; u <= cidades; u++) {
            for (int i = novo_primeiro[u]; i != -1; i = arestas_backup[i].prox) {
                int v = arestas_backup[i].destino;
                int custo = arestas_backup[i].custo;

                if (scc_id[u] != scc_id[v]) {
                    adicionar_aresta(scc_id[u], scc_id[v], custo);
                }
            }
        }

        int consultas;
        scanf("%d", &consultas);

        for (int i = 0; i < consultas; i++) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);

            if (scc_id[origem] == scc_id[destino]) {
                printf("0\n");
                continue;
            }

            int resposta = dijkstra(scc_id[origem], scc_id[destino], scc_total);

            if (resposta >= INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", resposta);
        }

        printf("\n");
    }

    return 0;
}
