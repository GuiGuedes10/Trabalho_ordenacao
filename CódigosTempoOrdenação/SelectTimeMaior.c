#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de ordenação por seleção (Selection Sort)
void selectsort(int *v, int tam) {
    int i, j, aux;
    int cont = 1;

    // Ordena o vetor pela técnica de Selection Sort
    for (i = tam - 1; i > 0; i--) {
        int maior = 0;  // Inicializa o índice do maior elemento como o primeiro da parte não ordenada
        for (j = 1; j <= i; j++) { // Percorre todo o vetor
            if (v[j] > v[maior]) { // Verifica se o valor atual é maior que o valor do maior
                maior = j;  // Se for, atualiza o maior índice
            }
        }

        // Troca o maior elemento encontrado com o último elemento da parte não ordenada
        aux = v[maior];
        v[maior] = v[i];
        v[i] = aux;

        // Exibe o vetor após cada passo (opcional para visualizar a ordenação)
        // printf("Passo %d: ", cont); // Imprime a interação
        // for (int k = 0; k < tam; k++) { // Corrigido para não usar a mesma variável i
        //     printf("%d ", v[k]);
        // }
        // printf("\n");
        cont++;
    }
}

// Função para imprimir o vetor
void print_array(int *v, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    // Diferentes tamanhos de array
    int sizes[] = {100, 1000, 10000, 50000, 100000};
    int n_tests = sizeof(sizes) / sizeof(sizes[0]);

    // Realiza o teste para cada tamanho de array
    for (int t = 0; t < n_tests; t++) {
        int tam = sizes[t];
        int *v = (int *)malloc(tam * sizeof(int));  // Aloca memória para o array de tamanho `tam`

        // Preenche o array com números aleatórios
        srand(time(NULL));
        for (int i = 0; i < tam; i++) {
            v[i] = rand() % 100000;  // Preenche com números aleatórios de 0 a 99999
        }

        // Exibe o tamanho do vetor
        printf("\nTestando com %d elementos:\n", tam);

        // Mede o tempo de execução do Selection Sort
        clock_t start_time = clock();
        selectsort(v, tam);  // Chama a função de ordenação
        clock_t end_time = clock();

        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Tempo de execução para ordenar %d elementos: %f segundos\n", tam, time_taken);

        // Descomente para visualizar o vetor ordenado
        // printf("Vetor ordenado:\n");
        // print_array(v, tam);

        // Libera a memória alocada
        free(v);
    }

    return 0;
}
