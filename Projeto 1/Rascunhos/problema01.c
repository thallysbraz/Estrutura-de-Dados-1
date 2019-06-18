//Integrantes
//Gabriela Chaves de Moraes - 16/0006872
//Guilherme Siqueira - 16/0007763
//Kamilla Costa - 16/0010969

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

#ifdef WIN32
    #define LIMPA_TELA system("cls")
#else
    #define LIMPA_TELA system("clear")
#endif

#define TAMANHO 10
#define INIBIDO 0
#define ATIVADO 1

//Prototipos
void leVetores(int*, int, char*);
void fneuronio(int*, int*, int, int, int*);

int main(int argc, char *argv[]){
  setlocale(LC_ALL, "Portuguese");

  //Declarações
  int entradas[TAMANHO], pesos[TAMANHO], estado;
  int T;
  char *str1 = "ENTRADA", *str2 = "PESOS";

  printf("Bem-vindo!\n");
  sleep(1);
  leVetores(entradas, TAMANHO, str1);
  leVetores(pesos, TAMANHO, str2);
  LIMPA_TELA;
  printf("Insira o valor do limiar (T): ");
  scanf("%d", &T);
  fneuronio(entradas, pesos, T, TAMANHO, &estado);
  if(estado == ATIVADO){
    printf("\nNeurônio ativado!\n");
  }
  else{
    printf("\nNeurônio inibido!\n");
  }
  return 0;
}

//=========== SUBPROGRAMAS =========================
void leVetores (int *vetor, int tamanho, char *string){
  for(int i = 0; i < tamanho; i++){
    LIMPA_TELA;
    printf("Digite a %d entrada do vetor %s: ", (i+1), string);
    scanf("%d", (vetor+i));
  }
}

int maior(int a, int b){
  if(a > b || a == b){
    return a;
  }
  return b;
}

void fneuronio(int *entradas, int *pesos, int limiar, int tamanho, int *resultado){
  int somap = 0;
  for(int i = 0; i < tamanho; i++){
    somap += (*(entradas + i)) * (*(pesos+i));
  }
  if(maior(somap, limiar) == somap){
    *resultado = ATIVADO;
  }
  else{
    *resultado = INIBIDO;
  }
}
