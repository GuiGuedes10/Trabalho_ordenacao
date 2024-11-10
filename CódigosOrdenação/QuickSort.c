#include <stdio.h>

typedef struct {
    int Chave;
} Item;

int passos = 0;  // Contador de passos global

// Função de particionamento do Quick Sort
void Particao(int Esq, int Dir, int *i, int *j, Item *A) {
    Item x, aux;
    *i = Esq;
    *j = Dir;
    x = A[(*i + *j) / 2]; // Pivo

    do {
        while (x.Chave > A[*i].Chave) (*i)++;  // Move o índice da esquerda até encontrar um valor maior ou igual ao pivô
        while (x.Chave < A[*j].Chave) (*j)--;  // Move o índice da direita até encontrar um valor menor ou igual ao pivô

        if (*i <= *j) {
            // Troca os elementos A[*i] e A[*j] 
            aux = A[*i];
            A[*i] = A[*j];
            A[*j] = aux;

            // Incrementa o contador de passos por cada troca realizada
            passos++;
            (*i)++;
            (*j)--;

            // Imprime o vetor após a troca (opcional, para visualizar os passos)
            printf("Passo %d: ", passos);
            for (int k = 0; k < Dir + 1; k++) {
                printf("%d ", A[k].Chave);
            }
            printf("\n");
        }
    } while (*i <= *j);  // Continua enquanto os índices não se cruzarem
}

// Função recursiva para ordenar as duas metades
void Ordena(int Esq, int Dir, Item *A) {
    int i, j;

    if (Esq < Dir) {
        // Chama a função de particionamento
        Particao(Esq, Dir, &i, &j, A);

        // Chama recursivamente para as duas metades
        Ordena(Esq, j, A);
        Ordena(i, Dir, A);
    }
}

// Função principal do QuickSort
void QuickSort(Item *A, int n) {
    Ordena(0, n - 1, A);  // Ordena o vetor inteiro
}

int main() {
    Item A[] = {{25}, {57}, {48}, {37}, {12}, {92}, {86}, {33}}; // Vetor de exemplo
    int n = sizeof(A) / sizeof(A[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i].Chave);
    }
    printf("\n");

    // Chama o QuickSort e conta os passos
    QuickSort(A, n);

    // Exibe o vetor ordenado
    printf("\nVetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i].Chave);
    }
    printf("\n");

    // Exibe o total de passos
    printf("\nTotal de passos: %d\n", passos);

    return 0;
}
