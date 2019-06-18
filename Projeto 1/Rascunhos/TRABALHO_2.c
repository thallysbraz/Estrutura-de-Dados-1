#include<stdio.h>
#include<stdlib.h>

#define TAM 10

int recebe_notas(float *, int);
int conta_notas(int *, int *, int);
float *percent_aprov(int, int);

int main(){
	float notas[TAM], percent;
	int tamanho=0,i=0, resultado,*ptr, *ptrConta_Notas1,*ptrConta_Notas2, situacao=0;
	
	tamanho = TAM;
	
	//Pegando dados digitados pelo usuário	
	for(i=0; i<TAM; i++){
		printf("Digite a %d nota: ", i+1);
		scanf("%f", &notas[i]);
	}

	//imprimindo os vetores
	printf("Notas = ");
	for (i=0;i<10;i++) {
		printf("%.2f\t", notas[i]);
	}
	
	
	printf("\n \n");
	
	//chamando a função recebe_notas
	resultado = recebe_notas(notas, tamanho);
	for (i=0;i<10;i++) {
		printf("%.2f\t", notas[i]);
	}
	
	
	//chamando a função conta_notas
	ptrConta_Notas1 = resultado;
	ptrConta_Notas2 = resultado;
	situacao = conta_notas(&ptrConta_Notas1, &ptrConta_Notas2, tamanho);
	printf("\n\n Aprovados: \t %.1f \n Reprovados: \t %.1f  \n\n", ptrConta_Notas1, ptrConta_Notas2);


	//chamando a função percent_aprov
	
	
	
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
	
int conta_notas(int *vetAPR, int *vetAPR2, int N){
	int i, aprovados=0, reprovados=0;
		for (i=0;i<N;i++) {
		printf("aaaa %d\t", vetAPR2[i]);
	}

	for(i=0; i<N; i++){
		if(vetAPR[i] >= 1){
			aprovados++;
		}
		else if(vetAPR[i] == 0){
			reprovados++;
		}
	}
	*(vetAPR) = aprovados;
	*(vetAPR2) = reprovados;
	return 0;	
}
/*
float *percent_aprov(int, int){
	
	
}

*/

