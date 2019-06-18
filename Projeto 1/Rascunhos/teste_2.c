#include<stdio.h>
#include<stdlib.h>

#define TAM 10

int recebe_notas(float *, int);
int conta_notas(int *, int);
float *percent_aprov(int, int);

int main(){
	float notas[TAM], percent;
	int tamanho,i, resultado, *ptrConta_Notas, situacao, aprovados, reprovados;
	
	tamanho = TAM;
	
	//Pegando dados digitados pelo usuário	
	for(i=0; i<TAM; i++){
		printf("Digite a %d nota: ", i+1);
		scanf("%f", &notas[i]);
	}
	
	//chamando a função recebe_notas
	resultado = recebe_notas(notas, tamanho);
	
	//chamando a função conta_notas
	ptrConta_Notas = resultado;
	situacao = conta_notas(ptrConta_Notas, tamanho);
	//chamando a função percent_aprov
	
	
	//imprimindo os vetores
	printf("Notas = ");
	for (i=0;i<10;i++) {
	printf("%f\t", notas[i]);
	}
	
	
	printf("\n \n");
	
	return 0;
}

int recebe_notas(float *apr, int N){
	int i,j;
	//compara os valores do vetor apr com 6
	for(i=0; i<N; i++){
		if(apr[i] >= 6){
			apr[i] = 1;
		}else{ 
			apr[i] = 0;
		}
	}
	return apr;
}

	
int conta_notas(int *vetAPR, int N){
	int i,balanco[2], aprovados=0, reprovados=0;
	for(i=0; i<N; i++){
		if(vetAPR[i] >= 1){
			aprovados++;
			balanco[0] = aprovados;
		}else if(vetAPR[i] == 0){
			reprovados++;
			balanco[1] = reprovados;
		}
	}
	printf("\n\n Aprovados: \t %d \n Reprovados: \t %d  \n\n", balanco[0], balanco[1]);
	
	return balanco;	
}
/*
float *percent_aprov(int, int){
	
	
}

*/

