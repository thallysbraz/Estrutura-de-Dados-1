#include<stdio.h>
#include<stdlib.h>

#define TAM_MAX 10

void recebe_notas(int NOTAS[], int nElementos, int APR[]) {
  int i;
  for(i=0; i<nElementos; i++) {
    printf("Digite a nota(%d):\n",i+1);
    scanf("%d",&NOTAS[i]);
  }
  for(i=0; i< TAM_MAX; i++) {
    if (NOTAS[i] >= 6) {
      APR[i] = 1;
    }else
      APR[i] = 0;
  }
  for(i=0; i< TAM_MAX; i++) {
    printf("%d\n", APR[i]);
  }
 }

void conta_notas(int APR[],int nElementos) {
   int APROVADOS = 0;
   int APROVADOS = 0;
   int i;
   for(i=0; i< TAM_MAX; i++) {
   if (APR[i] == 1){
     APROVADOS ++;
   }
   if (APR[i] == 0){
     REPROVADOS ++;
   }
 }
   printf("%d\n", APROVADOS);
   printf("%d\n", REPROVADOS);
 }

 int percent_aprov (int APROVADOS, int REPROVADOS, int *PorcentRepro, int *PorcentApro) {

 }

  int main(){
    int NOTAS[TAM_MAX];
    int nElementos = 10;
    int APR[TAM_MAX];
    recebe_notas(NOTAS, nElementos,APR);
    conta_notas(APR,nElementos);
    return 0;
  }
