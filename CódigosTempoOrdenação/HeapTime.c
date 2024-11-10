#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void AjustarHeap(int n, int V[], int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && V[esq] > V[maior]) {
        maior = esq;
    }

    if (dir < n && V[dir] > V[maior]) {
        maior = dir;
    }

    if (maior != i) {
        int temp = V[i];
        V[i] = V[maior];
        V[maior] = temp;

        AjustarHeap(n, V, maior);
    }
}

void FormarFilaPrioridades(int n, int V[]) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        AjustarHeap(n, V, i);
    }
}

void HeapSort(int n, int V[]) {
    FormarFilaPrioridades(n, V);

    for (int i = n - 1; i > 0; i--) {
        int temp = V[0];
        V[0] = V[i];
        V[i] = temp;

        AjustarHeap(i, V, 0);
    }
}

void GerarVetorAleatorio(int V[], int n) {
    for (int i = 0; i < n; i++) {
        V[i] = rand() % 1000000;
    }
}

void ImprimirVetor(int V[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

int main() {
    int tamanhos[] = {100, 1000, 10000, 50000, 100000};
    int num_testes = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int t = 0; t < num_testes; t++) {
        int n = tamanhos[t];
        int *V = (int *)malloc(n * sizeof(int));

        GerarVetorAleatorio(V, n);

        clock_t inicio = clock();

        HeapSort(n, V);

        clock_t fim = clock();
        double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        printf("    Tempo de execução para %d elementos: %.6f segundos\n", n, tempo_execucao);

        free(V);
    }

    return 0;
}
