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
#include <string.h>


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

//Variáveis Globais
int nodeLevel;


//Structs
typedef struct Node{
  int info;
  struct Node *direita;
  struct Node *esquerda;
}Node;

//Prototipos
int menu();
int validateNumbers(int, int, int);
Node* loadTreeFromFile(char *);
int calculateQuantityOfNumbers(FILE *);
void readNumbersFromArchive(FILE *, int, int *);
Node* createNewNode(int);
Node* insert(Node *, Node *);
int isEmpty(Node *);
void print2DUtil(Node *, int);
void showTree(Node *);
int checkIsFull(Node *);
void isFull(Node *);
int searchValue(Node *, int);
int calculateHeight(Node *);
void getHeight(Node *);
Node* findSuccessor(Node *);
Node* removeValue(Node *, int);
void printInOrder(Node *);
void printPreOrder(Node *);
void printPostOrder(Node *);
Node* balanceTree(Node *);
int checkIfTreeIsBalanced(Node *);
int calculateBalanceFactor(Node *);
Node* balanceNode(Node *);
Node* rotateLeftLeft(Node *);
Node* rotateLeftRight(Node *);
Node* rotateRightLeft(Node *);
Node* rotateRightRight(Node *);
