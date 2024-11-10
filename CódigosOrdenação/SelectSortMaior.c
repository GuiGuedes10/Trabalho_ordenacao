#include <stdio.h>
// vai procurar o maior e vai trocar a posição de onde tá o maior com a posição do último elemento, trava a última posição e repete isso
void selectsort(int *v, int tam) { // Função recebe os parâmetros
    int i, j, aux;
    int cont =1;

    // Começa do final e vai diminuindo o intervalo da parte não ordenada
    for (i = tam - 1; i > 0; i--) {
        int maior = 0;  // Inicializa o índice do maior elemento como o primeiro da parte não ordenada
        for (j = 1; j <= i; j++) { //Percorre todo o vetor
            if (v[j] > v[maior]) { //Verifica se o valor atual é maior q o valor maior
                maior = j;  // Se for atualiza o maior elemento
            }
        }

        // Troca o maior elemento encontrado com o último elemento da parte não ordenada
        aux = v[maior];
        v[maior] = v[i];
        v[i] = aux;


         printf("Passo %d: ", cont); // printa cada interação 
         for (int i = 0; i < tam; i++) {
            printf("%d ", v[i]);
        }
        cont ++;
        printf("\n");
    }
    
}
int main() {
    int v[] = {25 , 57 , 48 , 37 , 12 , 92 , 86 , 33};     // Exemplo de vetor para ordenar
    int tam = sizeof(v) / sizeof(v[0]); // Calcula o tamanho do vetor

    selectsort(v, tam);                 // Chama a função de ordenação por seleção

    // Mostra o vetor ordenado
    printf("Vetor ordenado: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
