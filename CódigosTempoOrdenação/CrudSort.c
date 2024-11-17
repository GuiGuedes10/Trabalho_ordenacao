#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void insertionsort(int *v, int tam) {
    int i, j, aux;
    for (i = 1; i < tam; i++) {
        aux = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

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


void GerarVetorAleatorioQuick(Item *A, int n) {
    for (int i = 0; i < n; i++) {
        A[i].Chave = rand() % 1000000; 
    }
}

void select_sort(int *v, int tam) {
    int i, j, min; 
    int aux;
    int cont = 1;
    
    
    for (i = 0; i < tam - 1; i++) { 
        min = i; 
        for (j = i + 1; j < tam; j++) { 
            if (v[j] < v[min]) { 
                min = j;
            }
        }

        aux = v[min]; 
        v[min] = v[i];
        v[i] = aux;

        cont++;
    }
}

int main() {
    int opcao;
    int tamanhos[] = {100, 1000, 10000, 50000, 100000};
    int num_testes = sizeof(tamanhos) / sizeof(tamanhos[0]);
    
    
    printf("\nSeja Bem Vindo!\nNeste programa iremos cronometrar o tempo de execução de diferentes métodos de ordenação de array\nPara isso, usaremos veteroes de tamanhos variaveis(100, 1000, 10000, 50000, 100000) e geraremos numeros aleatororios para inseriosmos nestas arrays");
    do {
        printf("\n\nMENU\n1.Sair\n2.Bubble Sort\n3.Heap Sort\n4.Insertion Sort\n5.Merge Sort\n6.Quick Sort\n7.Select Sort");
        printf("\n\nDigite o método de ordenação que deseja medir o tempo: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n\nObrigado por usar este programa!");
                break;

            case 2: {
                printf("\n--- Teste com Bubble Sort ---\n");
                for (int t = 0; t < num_testes; t++) {
                    int n = tamanhos[t];
                    int *V = (int *)malloc(n * sizeof(int));
                    if (V == NULL) {
                        printf("Erro ao alocar memória para %d elementos.\n", n);
                        continue;
                    }

                    GerarVetorAleatorio(V, n);

                    clock_t inicio = clock();
                    bubblesort(V, n);
                    clock_t fim = clock();

                    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    printf("Tempo de execução para %d elementos: %.6f segundos\n", n, tempo_execucao);

                    free(V);
                }
                break;
            }

            case 3: {
                printf("\n--- Teste com Heap Sort ---\n");
                for (int t = 0; t < num_testes; t++) {
                    int n = tamanhos[t];
                    int *V = (int *)malloc(n * sizeof(int));
                    if (V == NULL) {
                        printf("Erro ao alocar memória para %d elementos.\n", n);
                        continue;
                    }

                    GerarVetorAleatorio(V, n);

                    clock_t inicio = clock();
                    HeapSort(n, V);
                    clock_t fim = clock();

                    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    printf("Tempo de execução para %d elementos: %.6f segundos\n", n, tempo_execucao);

                    free(V);
                }
                break;
            }

            case 4: {
                printf("\n--- Teste com Insertion Sort ---\n");
                for (int t = 0; t < num_testes; t++) {
                    int n = tamanhos[t];
                    int *V = (int *)malloc(n * sizeof(int));
                    if (V == NULL) {
                        printf("Erro ao alocar memória para %d elementos.\n", n);
                        continue;
                    }

                    GerarVetorAleatorio(V, n);

                    clock_t inicio = clock();
                    insertionsort(V, n);
                    clock_t fim = clock();

                    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    printf("Tempo de execução para %d elementos: %.6f segundos\n", n, tempo_execucao);

                    free(V);
                }
                break;
            }

            case 5:{
                 printf("\n--- Teste com Merge Sort ---\n");
                for (int t = 0; t < num_testes; t++) {
                    int n = tamanhos[t];
                    int *V = (int *)malloc(n * sizeof(int));
                    if (V == NULL) {
                        printf("Erro ao alocar memória para %d elementos.\n", n);
                        continue;
                    }

                    GerarVetorAleatorio(V, n);

                    clock_t inicio = clock();
                    mergeSort(V, 0, n - 1);
                    clock_t fim = clock();

                    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    printf("Tempo de execução para %d elementos: %.6f segundos\n", n, tempo_execucao);

                    free(V);
                }
                break;
            }
            case 6:{
                 printf("\n  --- Teste com Quick Sort ---\n");
                    for (int t = 0; t < num_testes; t++) {
                    int n = tamanhos[t];
                    Item *A = (Item *)malloc(n * sizeof(Item));
                    if (A == NULL) {
                        printf("Erro ao alocar memória para %d elementos.\n", n);
                        continue;
                    }

                    GerarVetorAleatorioQuick(A, n);

                    clock_t inicio = clock();
                    QuickSort(A, n);
                    clock_t fim = clock();

                    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    printf("Tempo de execução para %d elementos: %.6f segundos\n", n, tempo_execucao);

                    free(A);
                }
                break;
            }
            case 7:{
                printf("\n--- Teste com Select Sort ---\n");
                for (int t = 0; t < num_testes; t++) {
                    int n = tamanhos[t];
                    int *V = (int *)malloc(n * sizeof(int));
                    if (V == NULL) {
                        printf("Erro ao alocar memória para %d elementos.\n", n);
                        continue;
                    }

                    GerarVetorAleatorio(V, n);

                    clock_t inicio = clock();
                     select_sort(V, n);
                    clock_t fim = clock();

                    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    printf("Tempo de execução para %d elementos: %.6f segundos\n", n, tempo_execucao);

                    free(V);
                }
                break;
            }
            default:
                if (opcao > 7) printf("\nOpcao invalida!\n");
        }
    } while (opcao != 1);

    return 0;
}
