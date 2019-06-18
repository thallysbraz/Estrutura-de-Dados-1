#include "funcoes.h"

int main(int argc, char *argv[]){
  // Variaveis
  char indice[2], nomeArquivo[100] = "./", setaIArquivo[100] = "./", *r = "r", *w= "w", *string;
  FILE *arq, *resultadoArq;
  int tamanhoMatriz, dimMatriz[2], valorMaior, contador = 0, treinamento[NUMMAX], teste[NUMMAX];
  int **matriz = NULL, **matrizDireita = NULL, **matrizEsquerda = NULL, **matrizAbaixo = NULL, **matrizAcima = NULL,
      **matrizDireitaInferior = NULL, **ilbp = NULL, **matrizBinaria = NULL, **matrizDireitaSuperior = NULL, **matrizEsquerdaSuperior = NULL, **matrizEsquerdaInferior = NULL;
  char *setaArquivo = setaIArquivo;
  float vetorResultado[536];

  setlocale(LC_ALL, "Portuguese");
  for(int i = 0; i < 2; i++){
    for(int i = 1; i <= FILEMAX; i++){
      converterIntChar(i, indice);
      for(int j = 0; j < FILEMAX; j++){
        nomeArquivo[j] = setaArquivo[j];
      }
      printf("nomeArquivo: %s\t setaArquivo: %s", nomeArquivo, setaArquivo);
      if(contador == 1){
        concantenaNomeArquivo(nomeArquivo, ASPHAULTFILE, indice);
        string = "Resultado_Asfalto ";
      }
      else{
        concantenaNomeArquivo(nomeArquivo, GRASSFILE, indice);
        string = "Resultado_Grama ";
      }
      arq = abreArquivo(nomeArquivo, r);
      calculaDimensao(arq, dimMatriz);
      tamanhoMatriz = ((*(dimMatriz + 0)) * (*(dimMatriz + 1)));
      printf("Tamanho da matriz: %d\n",tamanhoMatriz );
      matriz = alocaMatriz(dimMatriz);
      salvaMatrizMemoria(arq, matriz, dimMatriz, &valorMaior);
      printf("\n\nILBP");
    //  calculaILBP(matriz, ilbp, dimMatriz, matrizBinaria);
      printf("\n\nGLCM");
      direita(matrizDireita, matriz, vetorResultado);
      esquerda(matrizEsquerda, matriz, vetorResultado);
      acima(matrizAcima, matriz, vetorResultado);
      abaixo(matrizAbaixo, matriz, vetorResultado);
      diagonalEsquerdaSuperior(matrizEsquerdaSuperior, matriz, vetorResultado);
      diagonalDireitaSuperior(matrizDireitaSuperior, matriz, vetorResultado);
      diagonalEsquerdaInferior(matrizEsquerdaInferior, matriz, vetorResultado);
      diagonalDireitaInferior(matrizDireitaInferior, matriz, vetorResultado);
      printf("\n\n\n\nVetor Resultado");
      for(int i = 512; i < 536; i++){
        printf("\nConteudo:%.3f\tIndice: %d", *(vetorResultado+i), i);
      }
      resultadoArq = abreArquivo("Resultados.txt", "a+");
      salvaArquivo(resultadoArq, vetorResultado, string);
      fechaArquivo(arq);
      fechaArquivo(resultadoArq);
      free(matriz);
    }
    contador++;
  }
  sorteiaNumero(treinamento);
  comparaVetor(treinamento, teste);
  return 0;
}
