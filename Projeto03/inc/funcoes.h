

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

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
#define NOMEARQUIVO "contatos.txt"
#define MAXNOMEENDERECO 101 // contar o terminador
#define MAXTELEFONEDATA 100 //contar o terminador
#define SAIR 0
#define INSERIR 1
#define REMOVER 2
#define VISUALIZARNOME 3
#define VISUALIZARORDEMALFABETICA 4

//Structs
typedef struct Contato{
  char nomeCompleto[MAXNOMEENDERECO];
  char telefone[MAXTELEFONEDATA];
  char endereco[MAXNOMEENDERECO];
  unsigned int cep; //8 numeros
  char dataNascimento[MAXTELEFONEDATA];
  char cifrao[2];
}contato;

typedef struct No{
  struct No *anterior;
  contato conteudo;
  struct No *proximo;
}No;


//Prototipos
FILE* abreArquivo(char *);
void darBoasVindas();
int menu();
int calculaQtdRegistros(FILE *);
void entradaString(char *, int);
void leLinha(char *, int, FILE *);
No* leArquivo(FILE *, int,  No* );
contato insereDadosContato();
void validaNome(char *);
void validaTelefone(char *);
void validaDataNascimento(char *);
char validaOpcao(char);
No* insereLista(No *, contato);
No* excluiElemento(No*);
void imprimeLista(No *);
void pesquisaElemento(No *);
void escreveArquivo(No *lista, FILE *);
void liberarLista(No *);
/*
//Codigos de erro
1-> Falha ao abrir o arquivo
2-> Falha na alocação
*/
