//Integrantes
//Gabriela Moraes - 16/0006872
//Guilherme Siqueira - 16/0007763
//Kamilla Costa - 16/0010969

#include "funcoes.h"

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Portuguese");

  //Declaracoes
  int option, size, valueSearched, deleteValue;
  char userFileName[100], *fileName;
  Node *raiz = NULL;

  //Instrucoes
  do{
    option = menu();
    switch(option){
      case 1:
        LIMPA_TELA;
        printf("=============== LOAD TREE =================\n\n");
        printf("Enter the name of the file: ");
        LIMPA_BUFFER;
        fgets(userFileName, 100, stdin);
        size = strlen(userFileName);
        fileName = calloc((size-1), sizeof(char));
        if(fileName == NULL){
          printf("Allocation Failed!");
          exit(1);
        }
        strncpy(fileName, userFileName, (size-1));
        raiz = loadTreeFromFile(fileName);
        free(fileName);

      break;

      case 2:
        LIMPA_TELA;
        printf("=============== SHOW TREE =================\n\n");
        if(isEmpty(raiz) == 1){
          printf("Empty tree");
        }
        else{
          showTree(raiz);
        }
        printf("\n\nPress ENTER to return to menu ");
        LIMPA_BUFFER;
        getchar();
      break;

      case 3:
        LIMPA_TELA;
        printf("=============== IS FULL  =================\n\n");
        isFull(raiz);
        printf("\n\nPress ENTER to return to menu ");
        LIMPA_BUFFER;
        getchar();
      break;

      case 4:
        LIMPA_TELA;
        printf("=============== SEARCH =================\n\n");
        if(isEmpty(raiz) == 1){
          printf("Empty tree");
        }
        else{
          printf("Enter the value you would like to search: ");
          scanf("%d", &valueSearched);
          nodeLevel = 1;
          searchValue(raiz, valueSearched);
        }
        printf("\n\nPress ENTER to return to menu ");
        LIMPA_BUFFER;
        getchar();
      break;

      case 5:
        LIMPA_TELA;
        printf("=============== TREE HEIGHT ==================\n\n");
        getHeight(raiz);
        printf("\n\nPress ENTER to return to menu ");
        LIMPA_BUFFER;
        getchar();
      break;

      case 6:
        LIMPA_TELA;
        printf("=============== DELETE =================\n\n");
        if(isEmpty(raiz) == 1){
          printf("Empty tree");
        }
        else{

          printf("Enter the value you would like to delete: ");
          scanf("%d", &deleteValue);
          if(searchValue(raiz, deleteValue) != -1){
            LIMPA_TELA;
            raiz = removeValue(raiz, deleteValue);
            printf("Wait... Deleting Node\n");
            for(int i = 0; i < 3; i++){
              sleep(1);
              printf("*\n");
            }
            printf("\nSuccessfully Deleted node...");
          }
        }
        printf("\n\nPress ENTER to return to menu ");
        LIMPA_BUFFER;
        getchar();
      break;

      case 7:
        LIMPA_TELA;
        printf("=============== IN ORDER ==================\n\n");
        if(isEmpty(raiz) == 1){
          printf("Empty tree");
        }
        else{
          printInOrder(raiz);
        }
        printf("\n\nPress ENTER to return to menu ");
        LIMPA_BUFFER;
        getchar();
      break;

      case 8:
        LIMPA_TELA;
        printf("=============== PRE ORDER ==================\n\n");
        if(isEmpty(raiz) == 1){
          printf("Empty tree");
        }
        else{
          printPreOrder(raiz);
        }
        printf("\n\nPress ENTER to return to menu ");
        LIMPA_BUFFER;
        getchar();
      break;

      case 9:
        LIMPA_TELA;
        printf("=============== POST ORDER ==================\n\n");
        if(isEmpty(raiz) == 1){
          printf("Empty tree");
        }
        else{
          printPostOrder(raiz);
        }
        printf("\n\nPress ENTER to return to menu ");
        LIMPA_BUFFER;
        getchar();
      break;

      case 10:
        LIMPA_TELA;
        printf("=============== BALANCE ==================\n\n");
        raiz = balanceTree(raiz);
        printf("\n\nPress ENTER to return to menu ");
        LIMPA_BUFFER;
        getchar();
      break;
    }
  }while(option != 0);

  LIMPA_TELA;
  printf("===========================================================");
  printf("\nProgram finished");
  printf("\n===========================================================\n");
  return 0;
}
