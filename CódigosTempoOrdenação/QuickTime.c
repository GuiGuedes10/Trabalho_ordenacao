#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int Chave;
} Item;

void Particao(int Esq, int Dir, int *i, int *j, Item *A) {
    Item x, aux;
    *i = Esq;
    *j = Dir;
    x = A[(*i + *j) / 2]; 
    do {
        while (x.Chave > A[*i].Chave) (*i)++;  
        while (x.Chave < A[*j].Chave) (*j)--;  

        if (*i <= *j) {
  
            aux = A[*i];
            A[*i] = A[*j];
            A[*j] = aux;

            (*i)++;
            (*j)--;

        }
    } while (*i <= *j); 
}

void Ordena(int Esq, int Dir, Item *A) {
    int i, j;

    if (Esq < Dir) {
        Particao(Esq, Dir, &i, &j, A);  
        Ordena(Esq, j, A);
        Ordena(i, Dir, A);
    }
}
void QuickSort(Item *A, int n) {
    Ordena(0, n - 1, A);  
}
void GerarVetorAleatorio(Item *A, int n) {
    for (int i = 0; i < n; i++) {
        A[i].Chave = rand() % 1000000; 
    }
}

int main() {
    int tamanhos[] = {100, 1000, 10000, 50000, 100000}; 
    int num_testes = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int t = 0; t < num_testes; t++) {
        int n = tamanhos[t];
        Item *A = (Item *)malloc(n * sizeof(Item));  

        GerarVetorAleatorio(A, n);

        clock_t inicio = clock();

        QuickSort(A, n);

        clock_t fim = clock();
        double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        printf("    Tempo de execução para %d elementos: %.6f segundos\n", n, tempo_execucao);

        free(A);
    }

    return 0;}
