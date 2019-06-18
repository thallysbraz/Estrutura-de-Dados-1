#include<stdio.h>
#include<stdlib.h>

#define TAM 10

int fneuronio(int *, int *, int, int);

int main(){
	int entradas[TAM], pesos[TAM], i,j, T, *neuronios;

	//Pegando dados digitados pelo usuário	
	for(i=0; i<TAM; i++){
		printf("Digite a %d entrada: ", i+1);
		scanf("%d", &entradas[i]);
	}
	
	for(j=0;j<TAM;j++){
		printf("Digite o %d peso: ", j+1);
		scanf("%d", &pesos[j]);
	}
	
	printf("Digite o valor do limiar T: ");
	scanf("%d", &T);
	
	//chamando a função fneuronio
	neuronios = fneuronio(entradas, pesos, TAM, T);
	
	//imprimindo os vetores
	printf("Entradas = ");
	for (i=0;i<10;i++) {
	printf("%d\t", entradas[i]);
	}

	printf("Pesos = ");
	for (i=0;i<10;i++) {
	printf("%d\t", pesos[i]);
	}
	printf("\n \n");
	
	//conferindo se o neurônio está ativado ou inibido
	if(neuronios == 1)
		printf("NEURONIO ATIVADO!");
	else
		printf("NEURONIO INIBIDO!");
	
	return 0;
}

int fneuronio(int *vetE, int *vetP, int N, int limiar){
	int i,somatorio = 0;
	for(i=0; i<TAM;i++){
		somatorio = somatorio + (*(vetE+i) * *(vetP+i));
	}
	if(somatorio > limiar)
		return 1;
	else
		return 0;
}
