#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int *v, int tam) {
    int i, j, aux;
    for (i = 1; i < tam; i++) {
        aux = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

void gerar_dados(int *v, int tam) {
    for (int i = 0; i < tam; i++) {
        v[i] = rand() % 100000;
    }
}

int main() {
    srand(time(NULL));
    int tamanhos[] = {100, 1000, 10000, 50000, 100000};
    int n_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < n_tamanhos; i++) {
        int tam = tamanhos[i];
        int *v = malloc(tam * sizeof(int));
        
        gerar_dados(v, tam);
        clock_t inicio = clock();
        insertionsort(v, tam);
        clock_t fim = clock();

        double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("    Tempo de execução para %d elementos: %.4f segundos\n", tam, tempo_execucao);

        free(v);
    } return 0;
}
