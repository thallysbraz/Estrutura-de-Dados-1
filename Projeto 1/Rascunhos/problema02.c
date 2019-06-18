//Integrantes
//Gabriela Chaves de Moraes - 16/0006872
//Guilherme Siqueira - 16/0007763
//Kamilla Costa - 16/0010969

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef WIN32
    #define LIMPA_TELA system("cls")
#else
    #define LIMPA_TELA system("clear")
#endif

#define TAMANHO 10
#define NOTAMIN 6.0
#define APROVADO 1
#define REPROVADO 0
//Prototipos
void leNotas(float *, int);
void recebe_notas(float *, int *, int);
void conta_notas(int *,  int *, int);
int percent_aprov(int *,  int *);

//Principal
int main (int argc, char *argv[]){
  setlocale(LC_ALL,"Portuguese");
  //Declarações
  float notas[TAMANHO];
  int apr[TAMANHO], situacao[2], porcentagem[2], taxaAprovacao;

  leNotas(notas, TAMANHO);
  recebe_notas(notas, apr, TAMANHO);
  conta_notas(apr, situacao, TAMANHO);
  taxaAprovacao = percent_aprov(situacao, porcentagem);
  LIMPA_TELA;
  printf("=============RESULTADOS===========");
  printf("\nAprovados: %d", *(situacao+0));
  printf("\nReprovados: %d", *(situacao+1));
  printf("\nPorcentagem de aprovados: %d", *(porcentagem+0));
  printf("\nPorcentagem de Reprovados: %d", *(porcentagem+1));
  if(taxaAprovacao == 1){
    printf("\nMais da metade da turma foi aprovada!\n");
  }
  else if(taxaAprovacao == 2){
    printf("\nMetade da turma foi aprovada!\n");
  }
  else{
    printf("\nMenos da metade da turma foi aprovada!\n");
  }
  return 0;
}

//============= SUBPROGRAMAS =============
void leNotas(float *notas, int tamanho){
  for(int i = 0; i < tamanho; i++){
    LIMPA_TELA;
    printf("Insira o valor da %d° nota: ", (i+1));
    scanf("%f", (notas+i));
  }
}

void recebe_notas(float *notas, int *apr, int tamanho){
  for(int i = 0; i < tamanho; i++){
    if(*(notas+i) < NOTAMIN){
      *(apr+i) = REPROVADO;
    }
    else{
      *(apr+i) = APROVADO;
    }
  }
}

void conta_notas(int* apr, int* situacao, int tamanho){
  int contAprovados = 0;
  for(int i = 0; i < tamanho; i++){
    if(*(apr + i) == APROVADO){
      contAprovados++;
    }
  }
  *(situacao+0) = contAprovados;
  *(situacao+1) = tamanho - contAprovados;
}

int percent_aprov(int* situacao, int* porcentagem){
  *(porcentagem+0) = ((*(situacao+0)*100)/10);
  *(porcentagem+1) = ((*(situacao+1)*100)/10);
  if(*(porcentagem+0) > 50){
    return 1;
  }
  else if(*(porcentagem+0) == 50){
    return 2;
  }
  return 0;
}
