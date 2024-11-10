#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int vetor[], int inicio, int meio, int fim) {
    int tamanho = fim - inicio + 1;
    int temp[tamanho];
    int i = inicio, j = meio + 1, k = 0;

    while (i <= meio && j <= fim) {
        if (vetor[i] < vetor[j]) {
            temp[k++] = vetor[i++];
        } else {
            temp[k++] = vetor[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = vetor[i++];
    }

    while (j <= fim) {
        temp[k++] = vetor[j++];
    }

    for (k = 0, i = inicio; i <= fim; i++, k++) {
        vetor[i] = temp[k];
    }
}

void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
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
        mergeSort(v, 0, tam - 1);
        clock_t fim = clock();

        double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("    Tempo de execução para %d elementos: %.4f segundos\n", tam, tempo_execucao);

        free(v);
    }

    return 0;
}
