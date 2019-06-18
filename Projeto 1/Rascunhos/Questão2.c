#include<stdio.h>
#include<stdlib.h>

#define TAM_MAX 10

void recebe_notas(int *NOTAS, int nElementos, int *APR) {
  int i;
  for(i=0; i<nElementos; i++) {
    printf("Digite a nota(%d):\n",i+1);
    scanf("%d",&NOTAS[i]);
  }
    printf("---------------------\n");
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

void conta_notas(int *APR,int nElementos, int *APROVADOS, int *REPROVADOS) {
 int i, num;
 num = 0;
 for(i=0; i< TAM_MAX; i++){
     if (APR[i] == 1){
         num++;
     }
 }
 *APROVADOS = num;
 *REPROVADOS = TAM_MAX - num;
   printf("---------------------\n");
   printf("QUANTIDADE APROVADOS: %d\n", *APROVADOS);
   printf("QUANTIDADE REPROVADOS: %d\n", *REPROVADOS);
 }

 int percent_aprov (int APROVADOS, int REPROVADOS, int *PorcentRepro, int *PorcentApro) {
   *PorcentApro = 100 * APROVADOS/TAM_MAX;
   *PorcentRepro = 100 * REPROVADOS/TAM_MAX;
    printf("-------------------------------------\n");
    printf("PORCENTAGEM APROVADOS: %d%%\n", *PorcentApro);
    printf("PORCENTAGEM REPROVADOS: %d%%\n", *PorcentRepro);
    if(*PorcentApro >= 50){
      return 1;
    } else return 0;
  }

   int main(){
     int NOTAS[TAM_MAX];
     int nElementos = 10;
     int APR[TAM_MAX];
     int APROVADOS=0, REPROVADOS=0;
     int PorcentApro, PorcentRepro;
     recebe_notas(NOTAS, nElementos,APR);
     conta_notas(APR,nElementos,&APROVADOS,&REPROVADOS);
     int a = percent_aprov (APROVADOS,REPROVADOS,&PorcentRepro,&PorcentApro);
     return 0;
   }
