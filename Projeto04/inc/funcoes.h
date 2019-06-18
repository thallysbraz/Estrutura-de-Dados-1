//Integrantes
//Gabriela Moraes - 16/0006872
//Guilherme Siqueira - 16/0007763
//Kamilla Costa - 16/0010969

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#ifdef WIN32
    #include <windows.h>
    #define LIMPA_TELA system("cls")
    #define LIMPA_BUFFER fflush(stdin)
#else
    #include <stdio_ext.h>
    #include <unistd.h>
    #define LIMPA_TELA system("clear")
    #define LIMPA_BUFFER __fpurge(stdin)
#endif

//Constantes
#define NUMMAXVOOS 64
#define NUMMINVOOS 20
#define NUMMAXAPROXDECOLAGEM 32
#define NUMMINAPROXDECOLAGEM 10
#define NUMMAXACOMBUSTIVEL 12
#define NUMMINACOMBUSTIVEL 0
#define UnTempo 5
#define HORAINICIAL 6

//Structs
typedef struct info{
  char codigoVoo[7];
  char status; //A ou D
  int qtdCombustivel;
  int nPista;
}Info;

typedef struct TNo {
  Info info;
  struct Tno* prox;
} No;

typedef struct fila {
  No* inicio;
  No* fim;
} Fila;

//Prototipos
int sorteiaNumero(int *, int *);
void selecionaCodigosVoos(int *, char*[], char *[], char *[]);
void imprimeResultados(int *, Fila *, Fila *, Fila *);
Fila* criaFilaAproximacao();
Fila* criaFilaDecolagem();
void insereFila(Fila *, char *[], char, int, int *);
No* insereFinalFila(No*, char *[], char, int, int *);
void imprimeFila(Fila *, Fila *, Fila *, Fila *);
Fila* criaFilaPista1();
Fila* criaFilaPista2();
Fila* criaFilaPista3();
void insereFilaPista(Fila *, No *);
No* insereFinalFilaPista(No *, Fila *);





No* auxDesenfileiraFila(No *);
Info desenfileiraFila(Fila *);
int filaVazia (Fila*);


//Fila* criaListaAproximacao(Fila*, int *, char*[], char *[], char *[], int *);
//No* insereFila(Fila*, Info);


/*
Tempo de aproximação -> 1*UnTempo
Tempo de pouso -> 3*UnTempo
Tempo de decolagem -> 2*UnTempo
*/


/*
//Codigos de erro

*/
