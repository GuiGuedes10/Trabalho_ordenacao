#include <stdio.h>

void bubblesort(int *v, int tam) {  // Vetor e tamanho passados como parâmetro
    int i, j; //criação das variáveis de interação 
    int aux; // criação da variável auxiliar que serve para receber os elementos 
    int cont = 1; // só um contador para ver em quantos passos foi feito
    for (i = 0; i < tam - 1; i++) {           // Loop externo limita o tamanho de cada interação, já que em cada uma ele acha o maior e trava a última casa
        for (j = 1; j < tam - i; j++) {       // Loop interno 
            if (v[j] < v[j - 1]) {          // Compara o atual e o anterior. Se a j(atual) for menor
                aux = v[j];                 // variavel auxiliar vai receber o elemento do j atual 
                v[j] = v[j - 1];            // e o j atual receberá o j anterior 
                v[j - 1] = aux;             // e o j anterior recebe o aux assim colocando os números na ordem
                for (int i = 0; i < tam; i++) { // percorre todo o vetor mostrando cada passo dado
                  printf("%d ",v[i]);
                }
                 printf(" Passo %d \n", cont);
                 cont ++;
            }
        }
    }
}

int main() {
    int v[] = {25 , 57 , 48 , 37 , 12 , 92 , 86 , 33};  // Vetor para ordenar
    int tam = sizeof(v) / sizeof(v[0]); // Calcula o tamanho do vetor

    bubblesort(v, tam);  // Chama a função de ordenação 

    // Exibe o vetor ordenado
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("  Vetor ordenado\n");

    return 0;
}
