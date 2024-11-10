#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int *v, int tam) {
    int i, j, aux;
    for (i = 0; i < tam - 1; i++) {
        for (j = 1; j < tam - i; j++) {
            if (v[j] < v[j - 1]) {
                aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;
            }
        }
    }
}

void generate_random_array(int *v, int tam) {
    for (int i = 0; i < tam; i++) {
        v[i] = rand() % 100000;
    }
}

int main() {
    srand(time(NULL));
    
    int sizes[] = {100, 1000, 10000, 50000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int s = 0; s < num_sizes; s++) {
        int tam = sizes[s];
        int *v = (int *)malloc(tam * sizeof(int));
        if (v == NULL) {
            printf("Erro ao alocar memória para o tamanho %d\n", tam);
            return 1;
        }
        
        generate_random_array(v, tam);

        clock_t start = clock();
        bubblesort(v, tam);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Tempo para ordenar %d elementos: %.4f segundos\n", tam, time_taken);

        free(v);
    }

    return 0;
}
