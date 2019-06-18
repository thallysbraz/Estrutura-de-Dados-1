//Integrantes
//Gabriela Moraes - 16/0006872
//Guilherme Siqueira - 16/0007763
//Kamilla Costa - 16/0010969

#include "funcoes.h"

int sorteiaNumero(int *combA, int *vetInformacoes){
  int numSorteadoCombA;
  int nVoos, nAproximacoes, nDecolagens;
  nVoos = NUMMINVOOS;
  nAproximacoes = NUMMINAPROXDECOLAGEM;
  nDecolagens = NUMMINAPROXDECOLAGEM;
  numSorteadoCombA = NUMMINACOMBUSTIVEL;
  srand((unsigned) time(NULL));
  nAproximacoes = NUMMINAPROXDECOLAGEM + (rand() % NUMMAXAPROXDECOLAGEM);
  if(nAproximacoes > NUMMAXAPROXDECOLAGEM){
    nAproximacoes = nAproximacoes - NUMMINAPROXDECOLAGEM;
  }
  nDecolagens = NUMMINAPROXDECOLAGEM +(rand() % NUMMAXAPROXDECOLAGEM);
  if(nDecolagens > NUMMAXAPROXDECOLAGEM){
    nDecolagens = nDecolagens - NUMMINAPROXDECOLAGEM;
  }

  nVoos = nAproximacoes + nDecolagens;

   printf("\nnVoos: ");
   printf("%d\n", nVoos);
   printf("\nnAproximacoes: %d\n", nAproximacoes);
   printf("\nnDecolagens: %d\n", nDecolagens);
   printf("\n\nVetor de pousos e combustiveis: \n");
   for(int i = 0; i < nAproximacoes; i++){
    numSorteadoCombA = ((rand() % NUMMAXACOMBUSTIVEL) + 1);
    *(combA+i) = numSorteadoCombA;
  }
  for(int i = 0; i < nAproximacoes; i++){
    printf("Aviao %d = %d \n",i+1, combA[i]);
  }
  *(vetInformacoes + 0) = nVoos;
  *(vetInformacoes + 1) = nAproximacoes;
  *(vetInformacoes + 2) = nDecolagens;
  ordenaPrioridade(combA, nAproximacoes);
  return 0;
}
void selecionaCodigosVoos(int *vetInformacoes, char *codVoos[], char *codAproximacoes[],  char *codDecolagens[]){
  int nAproximacoes, nDecolagens;
  nAproximacoes = *(vetInformacoes + 1);
  nDecolagens = *(vetInformacoes + 2);
  printf("\nCodigos dos voos de aproximação");
  for(int i=0; i < nAproximacoes; i++){
    codAproximacoes[i] = codVoos[i];
    printf("\t %s", codAproximacoes[i]);
  }
  printf("\nCodigos dos voos de decolagens");
  for(int i = 0;i < nDecolagens; i++){
    codDecolagens[i] = codVoos[i+(nAproximacoes)];
    printf("\t %s", codDecolagens[i]);
  }
}

void ordenaPrioridade( int *vetor, int TAM){
  int x,y;
  int aux;
  for( x = 0; x < TAM; x++ ){
    for( y = x + 1; y < TAM; y++ ){
      if ( vetor[x] > vetor[y] ){
           aux = vetor[x];
           vetor[x] = vetor[y];
           vetor[y] = aux;
        }
      }
    }
  printf("\n\nVetor ordenado\n");
  for(int i = 0; i < TAM; i++){
    printf("%d\t", vetor[i]);
  }
}

Fila* criaFilaAproximacao(){
  Fila *fAprox = (Fila*)malloc(sizeof(Fila));
  fAprox->inicio = NULL;
  fAprox->fim = NULL;

  return fAprox;
}

Fila* criaFilaDecolagem(){

  Fila *fDec = (Fila*)malloc(sizeof(Fila));
  fDec->inicio = NULL;
  fDec->fim = NULL;

  return fDec;
}

void insereFila(Fila *f, char *cod[], char status, int i, int *combA){
  f->fim = insereFinalFila(f->fim, cod, status, i, combA);
  if(f->inicio == NULL){
    f->inicio = f->fim;
  }
}

No* insereFinalFila(No* fim, char *cod[], char status, int i, int *combA){
  No* novoElemento = NULL;
  novoElemento = (No*) malloc(sizeof(No));
  novoElemento->info.status = status;
  strcpy(novoElemento->info.codigoVoo, cod[i]);
  if(status == 'D'){
    novoElemento->info.qtdCombustivel = 12;
  }
  else{
    novoElemento->info.qtdCombustivel = combA[i];
  }
  novoElemento->prox = NULL;
  if(fim != NULL){
    fim->prox = novoElemento;
  }
  return novoElemento;
}

void imprimeFilaAlternada(Fila *f1, Fila *f2){
   if (f1->inicio == NULL && f2->inicio == NULL){
       printf("Listas Vazias");
   }else {
      No* aux1 = f1->inicio;
      No* aux2 = f2->inicio;
       while (aux1 || aux2){
         if(aux1){
           printf("\n\n\nCódigo do Voo: %s", aux1->info.codigoVoo);
           printf("\nStatus: %c", aux1->info.status);
           printf("\nQuantidade de combustível: %d", aux1->info.qtdCombustivel);
           printf("\nHorário do início do procedimento:");
           printf("\nNúmero da pista: 1");
           aux1 = aux1->prox;
         }
         if(aux2) {
           printf("\n\n\nCódigo do Voo: %s", aux2->info.codigoVoo);
           printf("\nStatus: %c", aux2->info.status);
           printf("\nQuantidade de combustível: %d", aux2->info.qtdCombustivel);
           printf("\nHorário do início do procedimento:");
           printf("\nNúmero da pista: 2");
           aux2 = aux2->prox;
         }
       }
   }
}

void imprimeFila(Fila *f, Fila *fPista1, Fila *fPista2, Fila *fPista3){
  No* aux;
  for(aux = f->inicio; aux != NULL; aux = aux->prox){
    if(f == fPista1){
      aux->info.nPista = 1;
    }
    if(f == fPista2){
      aux->info.nPista = 2;
    }
    if(f == fPista3){
      aux->info.nPista = 3;
    }
    printf("\n\n\nCódigo do Voo: %s", aux->info.codigoVoo);
    printf("\nStatus: %c", aux->info.status);
    printf("\nQuantidade de combustível: %d", aux->info.qtdCombustivel);
    printf("\nHorário do início do procedimento:");
    printf("\nNúmero da pista: %d", aux->info.nPista);
  }
}

Fila* criaFilaPista1(){
  Fila *fPista1 = (Fila*)malloc(sizeof(Fila));
  fPista1->inicio = NULL;
  fPista1->fim = NULL;

  return fPista1;
}

Fila* criaFilaPista2(){
  Fila *fPista2 = (Fila*)malloc(sizeof(Fila));
  fPista2->inicio = NULL;
  fPista2->fim = NULL;

  return fPista2;
}

Fila* criaFilaPista3(){
  Fila *fPista3 = (Fila*)malloc(sizeof(Fila));
  fPista3->inicio = NULL;
  fPista3->fim = NULL;

  return fPista3;
}

No* auxDesenfileiraFila(No* inicio){
  No *p = inicio->prox;
  free(inicio);
  //printf("DESENFILEIROU p = %s\n", p);
  return p;
}

Info desenfileiraFila(Fila *f){
  Info aux;

  if(filaVazia(f)){
    printf("Fila vazia\n");
    exit(2);
  }
  aux = f->inicio->info;
  f->inicio = auxDesenfileiraFila(f->inicio);
  if(f->inicio == NULL){
    f->fim = NULL;
  }
  return aux;
}

int filaVazia (Fila* f)
{
   return (f->inicio==NULL);
}


void insereFilaPista(Fila *pista, No *final){
  No* aux;
    pista->fim = insereFinalFilaPista(pista->fim, final);
    if(pista->inicio == NULL){
      pista->inicio = pista->fim;
    }
}

No* insereFinalFilaPista(No* final, Fila *f){
  No* novoElemento = NULL;
  No* aux = NULL;
  for (aux = f->inicio; aux != NULL; aux = aux->prox) {
    novoElemento = (No*) malloc(sizeof(No));
    novoElemento->info = aux->info;
    novoElemento->prox = NULL;
    if(final != NULL){
      final->prox = novoElemento;
    }
  }
  return novoElemento;
}

void libera (Fila* f){
  No* q = f->inicio;
  while (q!=NULL) {
    No* t = q->prox;
    free(q);
    q = t;
  }
  free(f);
}

void imprimeResultados(int *vetInformacoes, Fila *fPista1, Fila *fPista2, Fila *fPista3){
  LIMPA_TELA;
  printf("\n---------------------------------------------------------");
  printf("\nAeroporto Internacional de Brasília");
  printf("\nHora inicial: %s", __TIME__);
  printf("\nFila de Pedidos:");
  printf("\nNVoos: %d", *(vetInformacoes + 0));
  printf("\nNAproximações: %d", *(vetInformacoes + 1));
  printf("\nNDecolagens: %d", *(vetInformacoes + 2));
  printf("\n---------------------------------------------------------");
  printf("\nListagem dos eventos");
  printf("\n\n\n=============FILA DA PISTA 1 =======================");
  imprimeFila(fPista1, fPista1, fPista2, fPista3);

  printf("\n\n\n=============LISTA DA PISTA 2 =======================");
  imprimeFila(fPista2, fPista1, fPista2, fPista3);

  printf("\n\n\n=============LISTA DA PISTA 3 =======================");
  imprimeFila(fPista3, fPista1, fPista2, fPista3);
}
