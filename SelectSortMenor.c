#include <stdio.h>

void select(int *v, int tam) { //recebe os parâmetros
	int i, j, min; 
	int aux;
    int cont =1;
    
	for (i = 0; i < tam - 1; i++) { // laço de interação externo
		min = i; // inicializa o primeiro como o menor
		for (j = i + 1; j < tam; j++) { // laço interno 
			if (v[j] < v[min]) {      // compara o j atual com o valor do menor
				min = j; // se o valor menor for maior q o j atual ent o menor passa a ser o j
			}
		}
	// Faz a troca para para o menor ficar no começo
		aux = v[min]; 
		v[min] = v[i];
		v[i] = aux;
		 printf("Passo %d: ", cont); //printa cada interação 
         for (int i = 0; i < tam; i++) {
            printf("%d ", v[i]);
        }
        cont ++;
        printf("\n");
	}
}

int main() {
	int v[] = {25 , 57 , 48 , 37 , 12 , 92 , 86 , 33};       // Exemplo de vetor
	int tam = sizeof(v) / sizeof(v[0]);     // Calcula o tamanho do vetor

	select(v, tam);                     //Chama a função     

	// Mostra o vetor ordenado
	printf("Vetor ordenado:");
	for (int i = 0; i < tam; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}
