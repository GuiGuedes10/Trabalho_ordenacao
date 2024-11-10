#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de ordenação por seleção (Selection Sort)
void select_sort(int *v, int tam) {
    int i, j, min; 
    int aux;
    int cont = 1;
    
    // Ordena o vetor pela técnica de Selection Sort
    for (i = 0; i < tam - 1; i++) { // Laço de interação externo
        min = i; // Inicializa o primeiro como o menor
        for (j = i + 1; j < tam; j++) { // Laço interno
            if (v[j] < v[min]) { // Compara o j atual com o valor do menor
                min = j; // Se o valor menor for maior que o j atual, o menor passa a ser o j
            }
        }
        // Faz a troca para o menor ficar no começo
        aux = v[min]; 
        v[min] = v[i];
        v[i] = aux;

        // Exibe o vetor após cada passo (opcional para visualizar a ordenação)
        // printf("Passo %d: ", cont); // Imprime a interação
        // for (int k = 0; k < tam; k++) {
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
        select_sort(v, tam);  // Chama a função de ordenação
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
