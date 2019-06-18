#include "funcoes.h"

int sorteiaNumero(int *treinamento){
  int numSorteado, vetor[NUMMAX] = {51}, situacao;
  srand((unsigned) time(NULL));
  printf("\n\nConjunto de Treinamento: \n");
  for(int i = 0; i < NUMMAX; i++){
    do{
      numSorteado = ((rand() % FILEMAX) + 1);
      situacao = NREPETIDO;
      for(int aux = 0; aux < NUMMAX; aux++){
        if(numSorteado == vetor[aux]){
            situacao = REPETIDO;
        }
      }
    }while(situacao == REPETIDO);
    vetor[i] = numSorteado;
    treinamento[i] = vetor[i];
    printf("%d ", treinamento[i]);
  }
  printf("\n\n");
}

int comparaVetor(int *treinamento, int *teste){
  int vetorCompara[FILEMAX] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
                              26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
  int j=0;
  int comparador = 0;
  int vet[NUMMAX];
  int soma = 0;

  for(int i = 0; i < FILEMAX; i++){
      soma=0;
      comparador = vetorCompara[i];
    for(int aux = 0; aux < NUMMAX; aux++){
      if(comparador != *(treinamento + aux)){
        soma++;
      }else{
        vet[aux] = comparador;
        break;
      }
    }
      if(soma == 25 ){

        teste[j] = comparador;
        j++;
          if(j==25)
            break;
      }
  }
  printf("\nConjunto de Teste: \n");
  for (int j=0; j<NUMMAX; j++) {
    printf("%d ", teste[j]);
  }
  puts("");
}

void converterIntChar(int i, char *indice){
  sprintf(indice,"%02d", i);
}

void concantenaNomeArquivo(char *nomeArquivo, char *define, char *indice){

  strcat(nomeArquivo, define);
  strcat(nomeArquivo, indice);
  strcat(nomeArquivo, EXTENSION);
  printf("\nFunção\t%s\n", nomeArquivo);
}

FILE* abreArquivo(char *nomeArquivo, char *tipo){
  FILE* arq;

  arq = fopen(nomeArquivo, tipo);
  if(arq == NULL){
		printf("Erro ao abrir o arquivo!");
    exit(1);
	}

  return arq;
}

void calculaDimensao(FILE *arq, int *dimMatriz){
  char detectorPonto;
  int contLinha = 0, contColuna = 0;
  fseek(arq, 0, SEEK_SET);

  while(fread(&detectorPonto,sizeof(char),1,arq)==1){
    if(detectorPonto == '\n'){
      contLinha++;
      contColuna++;
    }
    if(detectorPonto == ';'){
      contColuna++;
    }
  }
  contColuna/=contLinha; //divisão
  *(dimMatriz + 0) = contLinha;
  *(dimMatriz + 1) = contColuna;
  printf("%d ", contLinha);
  printf("%d\n", contColuna);
}

int** alocaMatriz(int *dimMatriz){
  int **matriz, nLin, nCol;
  nLin = *(dimMatriz + 0);
  nCol= *(dimMatriz + 1);
  matriz = (int**)calloc(nLin,sizeof(int*));
  for(int i=0;i < nLin;i++){
    *(matriz+i) = (int*)calloc(nCol,sizeof(int));
  }
  return matriz;
}

void salvaMatrizMemoria(FILE *arq, int **matriz, int *dimMatriz, int *valorMaior){
  int nLin = 0, nCol = 0;
  nLin = *(dimMatriz +0);
  nCol = *(dimMatriz + 1);
  char guarda[nLin][nCol];
  int tempValorMaior = 0;

  printf("\nnLin:%d\tnCol:%d",nLin, nCol);

  rewind(arq);
  for(int i = 0; i < nLin; i++){
    for(int j = 0; j < nCol; j++){
      fscanf(arq, "%d%c", (*(matriz+i)+j), &guarda[i][j]);
      printf("\nLinha:%d\tColuna:%d\tConteudo:%d\t",i,j, *(*(matriz+i)+j));

      if(*(*(matriz+i)+j) > tempValorMaior){
          tempValorMaior = (*(*(matriz+i)+j));
      }
    }
  }
  *valorMaior = tempValorMaior;
  printf("\n\nValorMaior:%d", *valorMaior);
}

float media(int **matriz, int *ilbp, int *dimMatriz){
  int pixelCentral = 0, somatorio = 0, linhas = 3, colunas = 3;
  float mediaPixelCentral = 0.0;
  //calcula filtro de média dos 9 elementos de cada submatriz
  pixelCentral = **(matriz + 4);
  //printf("Pixel Central = %d \n", pixelCentral);

    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        printf("\nElementos da matriz %d\n", *(*((matriz+i)+j)));
        somatorio = somatorio + (*((matriz+i)+j));
      }
    }
    mediaPixelCentral = somatorio / (9.0);
    **(matriz+4) = mediaPixelCentral;
}

void calculaMatrizBinaria(int **matriz, int **ilbp, int *dimMatriz, int **matrizBinaria){
  int tamanhoMatriz = 0, linhas = 3, colunas = 3;
  tamanhoMatriz = dimMatriz[0] * dimMatriz[1];

  /*Limiarização Simples */
    tamanhoMatriz = linhas * colunas;
    //matrizBinaria = alocaMatriz(tamanhoMatriz);
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) { //(*((matriz+i)+j))
        if((*(*(matriz+i)+j)) > **(matriz+4)){
          *(*(matrizBinaria+i)+j) = 1;
        }else{
          *(*(matrizBinaria+i)+j) = 0;
        }
        printf("Matriz Binária: %d\n", *(*(matriz+i)+j)); //OKAY
    }
  }
}

int calculaILBP(int **matriz, int **ilbp, int *dimMatriz, int **matrizBinaria){
  int pixel = 0, precisaoCalcT = 0, tamanhoMatriz = 0, linhas = 3, colunas = 3, numVizinhos = 0, proxMatriz = 0;
  float mediaSomatorio = 0.0;

  mediaSomatorio = media(matriz, ilbp, dimMatriz);
  printf("Media somatorio = %f", mediaSomatorio);

  calculaMatrizBinaria(matriz, ilbp, dimMatriz, matrizBinaria);
 /* for(int i=0; i<linhas; i++){
    for(int j=0; j<colunas; j++){
      printf("Matriz Binária: %d\n", (*(matrizBinaria+(i*colunas)+j)));
    }
  }
*/ // OK

  tamanhoMatriz = dimMatriz[0] * dimMatriz[1];

    //Calcular Menor Binário para invariância de rotação e cálculo do ILBP
    numVizinhos = 8;
    int num = 0; //valor decimal
    int binario[9], aux[9], decimal = 0;
    int numMin = 511; //1024 / (2 -1)
    int res = 0;
    int contador = 0;

    for(int i = 0; i < linhas; i++){
      for(int j = 0; j < colunas; j++, contador++){
        *(binario+contador) = (*(matrizBinaria+i)+j);
      // printf("BinarioPrimeiro[%d] = %d\n",j,binario[contador] ); //OK
      }
    }

    for(int i = 0; i < 9; i++, contador++){
    // printf("Binario[%d] = %d\n", i, binario[contador]);
    }

    for (int i = 0; i < 9; i++) { //conversor bin -> dec
      for (int j = 0; j < 7; j++){
        if (binario[j] == 1)
        {
          num += pow(2,8-j);
          printf("j = %d\n",j);
        }
        //num += binario[j] * pow(2, j);
        //printf("Bin - Dec = %d\n",num);
      }
        for (int k = 0; k < numVizinhos; k++){
          aux[k] = *(binario+(k + 1));
        }

        for (int l = 0; l < 9; l++){
          *(binario + l) = aux[l];
        // printf("AAA%d\n",*(matrizBinaria + l) );
        }
          printf("Debug num = %d\n", num);

        if (numMin > num ){
          numMin = num;
          printf("Numero Min = %d\n", numMin );
        }
    }
    printf("min Final = %d \n", numMin);
    *(ilbp + numMin) = *(ilbp + numMin) + 1;
    //printf("frequencia ilbp = %d", *(ilbp+numMin));

  free(matrizBinaria);
}



// Criando matrizes de direções para calculo de VetorGLCM
void direita(int **matrizDireita, int **matriz, float *vetorResultado){
    int i, j, nLin = 0, nCol = 0;
    nLin = 256;
    nCol = 256;
    matrizDireita = (int**) calloc(nLin, sizeof(int*));
    for(i=0;i < 256;i++){
      *(matrizDireita+i) = (int*)calloc(nCol,sizeof(int));
    }

    for(i=0;i < nLin ;i++){
       for(j=1;j < nCol;j++){
           matrizDireita[matriz[i][j-1]][matriz[i][j]]++;
       }
    }

  float contraste=0,energia=0,homogenidade=0;

     for(i=0;i<nLin;i++){
         for(j=0;j<nCol;j++){

             energia += pow(matrizDireita[i][j],2);
             contraste += pow(i-j,2) * matrizDireita[i][j];
             homogenidade += matrizDireita[i][j]/(1+sqrt(pow(i-j,2)));

        }
    }
    printf("\n\nDireita:%.3f,\t%.3f,\t%.3f\t", energia,contraste,homogenidade);
    *(vetorResultado + 512) = energia;
    *(vetorResultado + 513) = contraste;
    *(vetorResultado + 514) = homogenidade;
  free(matrizDireita);
}

void esquerda(int **matrizEsquerda, int **matriz, float *vetorResultado){
    int i, j, nLin = 0, nCol = 0;
    nLin = 256;
    nCol = 256;
    matrizEsquerda = (int**)calloc(256,sizeof(int*));
    for(i=0;i<256;i++){
      *(matrizEsquerda+i) = (int*)calloc(256,sizeof(int));
    }
    for(i=0;i<nLin;i++){
       for(j=0;j<(nCol-1);j++){
          matrizEsquerda[matriz[i][j+1]][matriz[i][j]]++;
       }
    }
  float contraste=0,energia=0,homogenidade=0;

     for(i=0;i<nLin;i++){
         for(j=0;j<nCol;j++){

             energia += pow(matrizEsquerda[i][j],2);
             contraste += pow(i-j,2) * matrizEsquerda[i][j];
             homogenidade += matrizEsquerda[i][j]/(1+sqrt(pow(i-j,2)));

        }
    }
    printf("\n\nEsquerda:%.3f,\t%.3f,\t%.3f\t", energia,contraste,homogenidade);
    *(vetorResultado + 515) = energia;
    *(vetorResultado + 516) = contraste;
    *(vetorResultado + 517) = homogenidade;
  free(matrizEsquerda);
}

void acima(int **matrizAcima, int **matriz, float *vetorResultado){
    int i, j, nLin = 0, nCol = 0;
    nLin = 256;
    nCol = 256;
    matrizAcima = (int**)calloc(256,sizeof(int*));
    for(i=0;i<256;i++){
      *(matrizAcima+i) = (int*)calloc(256,sizeof(int));
    }
    for(i=0;i<(nLin-1);i++){
       for(j=0;j<nCol;j++){
          matrizAcima[matriz[i+1][j]][matriz[i][j]]++;
       }
    }
  float contraste=0,energia=0,homogenidade=0;

     for(i=0;i<nLin;i++){
         for(j=0;j<nCol;j++){

             energia += pow(matrizAcima[i][j],2);
             contraste += pow(i-j,2) * matrizAcima[i][j];
             homogenidade += matrizAcima[i][j]/(1+sqrt(pow(i-j,2)));
        }
    }
  printf("\n\nAcima:%.3f,\t%.3f,\t%.3f\t", energia,contraste,homogenidade);
  *(vetorResultado + 518) = energia;
  *(vetorResultado + 519) = contraste;
  *(vetorResultado + 520) = homogenidade;
  free(matrizAcima);
}

void abaixo(int **matrizAbaixo,int **matriz, float *vetorResultado){
    int i, j, nLin = 0, nCol = 0;
    nLin = 256;
    nCol = 256;
    matrizAbaixo = (int**)calloc(256,sizeof(int*));
    for(i=0;i<256;i++){
      *(matrizAbaixo+i) = (int*)calloc(256,sizeof(int));
    }
    for(i=1;i<nLin;i++){
       for(j=0;j<nCol;j++){
          matrizAbaixo[matriz[i-1][j]][matriz[i][j]]++;
       }
    }
  float contraste=0,energia=0,homogenidade=0;

     for(i=0;i<nLin;i++){
         for(j=0;j<nCol;j++){

             energia += pow(matrizAbaixo[i][j],2);
             contraste += pow(i-j,2) * matrizAbaixo[i][j];
             homogenidade += matrizAbaixo[i][j]/(1+sqrt(pow(i-j,2)));
        }
    }
  printf("\n\nAbaixo:%.3f,\t%.3f,\t%.3f\t", energia,contraste,homogenidade);
  *(vetorResultado + 521) = energia;
  *(vetorResultado + 522) = contraste;
  *(vetorResultado + 523) = homogenidade;
  free(matrizAbaixo);
}

void diagonalEsquerdaSuperior(int **matrizEsquerdaSuperior, int **matriz, float *vetorResultado){
    int i, j, nLin = 0, nCol = 0;
    nLin = 256;
    nCol = 256;
    matrizEsquerdaSuperior = (int**)calloc(256,sizeof(int*));
    for(i=0;i<256;i++){
      *(matrizEsquerdaSuperior+i) = (int*)calloc(256,sizeof(int));
    }
    for(i=0;i<(nLin-1);i++){
       for(j=0;j<(nCol-1);j++){
          matrizEsquerdaSuperior[matriz[i+1][j+1]][matriz[i][j]]++;
       }
    }
  float contraste=0,energia=0,homogenidade=0;

     for(i=0;i<nLin;i++){
         for(j=0;j<nCol;j++){

             energia += pow(matrizEsquerdaSuperior[i][j],2);
             contraste += pow(i-j,2) * matrizEsquerdaSuperior[i][j];
             homogenidade += matrizEsquerdaSuperior[i][j]/(1+sqrt(pow(i-j,2)));
        }
    }
  printf("\n\nEsquerdaSuperior:%.3f,\t%.3f,\t%.3f\t", energia,contraste,homogenidade);
  *(vetorResultado + 524) = energia;
  *(vetorResultado + 525) = contraste;
  *(vetorResultado + 526) = homogenidade;
  free(matrizEsquerdaSuperior);
}

void diagonalDireitaSuperior(int **matrizDireitaSuperior, int **matriz, float *vetorResultado){
    int i, j, nLin = 0, nCol = 0;
    nLin = 256;
    nCol = 256;
    matrizDireitaSuperior = (int**)calloc(256,sizeof(int*));
    for(i=0;i<256;i++){
      *(matrizDireitaSuperior+i) = (int*)calloc(256,sizeof(int));
    }
    for(i=0;i<(nLin-1);i++){
       for(j=1;j<nCol;j++){
          matrizDireitaSuperior[matriz[i+1][j-1]][matriz[i][j]]++;
       }
    }
  float contraste=0,energia=0,homogenidade=0;

     for(i=0;i<nLin;i++){
         for(j=0;j<nCol;j++){

             energia += pow(matrizDireitaSuperior[i][j],2);
             contraste += pow(i-j,2) * matrizDireitaSuperior[i][j];
             homogenidade += matrizDireitaSuperior[i][j]/(1+sqrt(pow(i-j,2)));
        }
    }
  printf("\n\nDireitaSuperior:%.3f,\t%.3f,\t%.3f\t", energia,contraste,homogenidade);
  *(vetorResultado + 527) = energia;
  *(vetorResultado + 528) = contraste;
  *(vetorResultado + 529) = homogenidade;
  free(matrizDireitaSuperior);
}

void diagonalEsquerdaInferior(int **matrizEsquerdaInferior, int **matriz, float *vetorResultado){
    int i, j, nLin = 0, nCol = 0;
    nLin = 256;
    nCol = 256;
    matrizEsquerdaInferior = (int**)calloc(256,sizeof(int*));
    for(i=0;i<256;i++){
      *(matrizEsquerdaInferior+i) = (int*)calloc(256,sizeof(int));
    }
    for(i=1;i<nLin;i++){
       for(j=0;j<(nCol-1);j++){
          matrizEsquerdaInferior[matriz[i-1][j+1]][matriz[i][j]]++;
       }
    }
  float contraste=0,energia=0,homogenidade=0;

     for(i=0;i<nLin;i++){
         for(j=0;j<nCol;j++){

             energia += pow(matrizEsquerdaInferior[i][j],2);
             contraste += pow(i-j,2) * matrizEsquerdaInferior[i][j];
             homogenidade += matrizEsquerdaInferior[i][j]/(1+sqrt(pow(i-j,2)));
        }
    }
  printf("\n\nEsquerdaInferior:%.3f,\t%.3f,\t%.3f\t", energia,contraste,homogenidade);
  *(vetorResultado + 530) = energia;
  *(vetorResultado + 531) = contraste;
  *(vetorResultado + 532) = homogenidade;
  free(matrizEsquerdaInferior);
}

void diagonalDireitaInferior(int **matrizDireitaInferior,int **matriz, float *vetorResultado){
    int i, j, nLin = 0, nCol = 0;
    nLin = 256;
    nCol = 256;
    matrizDireitaInferior = (int**)calloc(256,sizeof(int*));
    for(i=0;i<256;i++){
      *(matrizDireitaInferior+i) = (int*)calloc(256,sizeof(int));
    }
    for(i=1;i<nLin;i++){
       for(j=1;j<nCol;j++){
          matrizDireitaInferior[matriz[i-1][j-1]][matriz[i][j]]++;
       }
    }
  float contraste=0,energia=0,homogenidade=0;

     for(i=0;i<nLin;i++){
         for(j=0;j<nCol;j++){

             energia += pow(matrizDireitaInferior[i][j],2);
             contraste += pow(i-j,2) * matrizDireitaInferior[i][j];
             homogenidade += matrizDireitaInferior[i][j]/(1+sqrt(pow(i-j,2)));

        }
    }
  printf("\n\nDireitaInferior:%.3f,\t%.3f,\t%.3f\t", energia,contraste,homogenidade);
  *(vetorResultado + 533) = energia;
  *(vetorResultado + 534) = contraste;
  *(vetorResultado + 535) = homogenidade;
  free(matrizDireitaInferior);
}

void salvaArquivo(FILE* resultadoArq, float* vetorResultado, char *string){
  char espaco = '\n';
  fprintf(resultadoArq, "%s", string);
  for(int i = 0; i < 536; i++){
      fprintf(resultadoArq, "%.2f ", *(vetorResultado+i));
  }
  fprintf(resultadoArq, "%c", espaco);
}

void fechaArquivo(FILE *arq){
  fclose(arq);
}
