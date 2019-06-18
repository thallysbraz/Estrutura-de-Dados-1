#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <math.h>

#ifdef WIN32
    #define LIMPA_TELA system("cls")
#else
    #define LIMPA_TELA system("clear")
#endif

#define TAMIMAGEM 512
#define FILEMAX 50
#define NUMMAX 25
#define REPETIDO 1
#define NREPETIDO 0
#define ASPHAULTFILE "DataSet/asphalt/asphalt_"
#define GRASSFILE "DataSet/grass/grass_"
#define EXTENSION ".txt"
/*
int sorteiaNumero(int *);
//void ordenaVetor(int *);
int comparaVetor(int *, int *);
*/

void converterIntChar(int, char *);
void concantenaNomeArquivo(char *, char *, char *);
FILE* abreArquivo(char *, char *);
void calculaDimensao(FILE *, int *);
int** alocaMatriz(int *);
void salvaMatrizMemoria(FILE *, int **, int *, int *);
void salvaArquivo(FILE *, float *, char *);
void fechaArquivo(FILE *);

//ILBP
float media(int **, int *, int *);
void calculaMatrizBinaria(int **, int **, int *, int **);
int calculaILBP(int **, int **, int *, int **);

//GLCM
void direita(int **, int **, float *);
void esquerda(int **, int **, float *);
void acima(int **, int **, float *);
void abaixo(int **, int **, float *);
void diagonalEsquerdaSuperior(int **, int **, float *);
void diagonalDireitaSuperior(int **, int **, float *);
void diagonalEsquerdaInferior(int **, int **, float *);
void diagonalDireitaInferior(int **, int **, float *);