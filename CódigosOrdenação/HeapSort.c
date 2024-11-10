#include <stdio.h>

#define MAX 100

int passos = 0;  // Variável global para contar os passos

// Função para ajustar o heap
void AjustarHeap(int n, int V[], int i) {
    int maior = i;  // Inicializa o maior como a raiz
    int esq = 2 * i + 1;  // Filho à esquerda
    int dir = 2 * i + 2;  // Filho à direita

    // Verifica se o filho à esquerda existe e é maior que a raiz
    if (esq < n && V[esq] > V[maior]) {
        maior = esq;
    }

    // Verifica se o filho à direita existe e é maior que a raiz (ou filho à esquerda)
    if (dir < n && V[dir] > V[maior]) {
        maior = dir;
    }

    // Se o maior não for a raiz, troca e ajusta o heap
    if (maior != i) {
        int temp = V[i];
        V[i] = V[maior];
        V[maior] = temp;

        passos++;  // Contabiliza o passo (troca de elementos)

        printf("Passo %d: ", passos);
        for (int k = 0; k < n; k++) {
            printf("%d ", V[k]);
        }
        printf("\n");

        // Chama recursivamente para ajustar o heap
        AjustarHeap(n, V, maior);
    }
}

// Função para construir o heap a partir de um vetor
void FormarFilaPrioridades(int n, int V[]) {
    // Começa do último nó não folha e ajusta o heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        AjustarHeap(n, V, i);
    }
}

// Função para ordenar usando o HeapSort
void HeapSort(int n, int V[]) {
    // Constrói o heap
    FormarFilaPrioridades(n, V);

    // Um por um, extrai os elementos do heap
    for (int i = n - 1; i > 0; i--) {
        // Troca o topo (maior elemento) com o último elemento
        int temp = V[0];
        V[0] = V[i];
        V[i] = temp;

        passos++;  // Contabiliza o passo (troca de elementos)

        printf("Passo %d: ", passos);
        for (int k = 0; k < n; k++) {
            printf("%d ", V[k]);
        }
        printf("\n");

        // Ajusta o heap para o vetor restante
        AjustarHeap(i, V, 0);
    }
}

// Função para imprimir o vetor
void ImprimirVetor(int V[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

int main() {
    int V[] = {25, 57, 48, 37, 12, 92, 86, 33};
    int n = sizeof(V) / sizeof(V[0]);

    printf("Vetor original:\n");
    ImprimirVetor(V, n);

    // Chama o HeapSort
    HeapSort(n, V);

    printf("\nVetor ordenado:\n");
    ImprimirVetor(V, n);

    printf("\nTotal de passos: %d\n", passos);

    return 0;
}
