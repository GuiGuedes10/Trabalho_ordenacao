#include <stdio.h>

// Função para mesclar dois subvetores de forma ordenada
void merge(int vetor[], int inicio, int meio, int fim, int* cont) {
    int tamanho = fim - inicio + 1; // Tamanho total do vetor a ser mesclado
    int temp[tamanho]; // Vetor temporário para armazenar a mesclagem
    int i = inicio, j = meio + 1, k = 0;

    // Copiar os elementos dos subvetores para o vetor temporário
    while (i <= meio && j <= fim) {
        if (vetor[i] < vetor[j]) {
            temp[k++] = vetor[i++];
        } else {
            temp[k++] = vetor[j++];
        }
    }

    // Se ainda houver elementos no subvetor esquerdo
    while (i <= meio) {
        temp[k++] = vetor[i++];
    }

    // Se ainda houver elementos no subvetor direito
    while (j <= fim) {
        temp[k++] = vetor[j++];
    }

    // Copiar os elementos de volta para o vetor original
    for (k = 0, i = inicio; i <= fim; i++, k++) {
        vetor[i] = temp[k];
    }

    // Imprimir o vetor a cada passo
    printf("Passo %d: ", (*cont)++);
    for (int i = 0; i <= fim; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função recursiva para dividir o vetor e chamar a mesclagem
void mergeSort(int vetor[], int inicio, int fim, int* cont) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        // Chamada recursiva para o subvetor esquerdo
        mergeSort(vetor, inicio, meio, cont);

        // Chamada recursiva para o subvetor direito
        mergeSort(vetor, meio + 1, fim, cont);

        // Mesclar os subvetores ordenados
        merge(vetor, inicio, meio, fim, cont);
    }
}

int main() {
    int vetor[] = {25, 57, 48, 37, 12, 92, 86, 33};  // Exemplo de vetor
    int tam = sizeof(vetor) / sizeof(vetor[0]);
    int cont = 1;  // Contador para marcar os passos

    printf("Vetor original:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Chama o mergeSort para ordenar o vetor
    mergeSort(vetor, 0, tam - 1, &cont);

    // Exibe o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
