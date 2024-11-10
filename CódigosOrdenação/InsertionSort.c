#include <stdio.h>

// Função do Insertion Sort com contagem de passos
void insertionsort(int *v, int tam) {
    int i, j, aux;
    int cont = 1; // Contador de passos

    // Laço externo percorre os elementos de 1 até n-1
    for (i = 1; i < tam; i++) {
        aux = v[i];   // Guarda o valor atual para inserção
        j = i - 1;     // Começa comparando com o elemento anterior

        // Laço interno compara o elemento atual com os anteriores e desloca os maiores
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];  // Move o elemento para a direita
            j--;               // Move para o próximo elemento da parte ordenada
        }
        v[j + 1] = aux;  // Insere o valor atual na posição correta

        // Imprime o vetor após cada passo (após cada inserção)
        printf("Passo %d: ", cont);
        for (int k = 0; k < tam; k++) {
            printf("%d ", v[k]);
        }
        printf("\n");
        cont++; // Incrementa o contador de passos
    }
}

int main() {
    int v[] = {25, 57, 48, 37, 12, 92, 86, 33};  // Vetor para ordenar
    int tam = sizeof(v) / sizeof(v[0]);          // Calcula o tamanho do vetor

    printf("Vetor original:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n\n");

    insertionsort(v, tam);  // Chama a função de ordenação por inserção

    // Mostra o vetor ordenado
    printf("\nVetor ordenado: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
