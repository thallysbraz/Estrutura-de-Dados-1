//Integrantes
//Gabriela Moraes - 16/0006872
//Guilherme Siqueira - 16/0007763
//Kamilla Costa - 16/0010969

#include "funcoes.h"

int menu(){
  //Declarações
  int option;

  //Instruções
  LIMPA_TELA;
  printf("==================== TREE PROGRAM =========================");
  printf("\n1 - Load Tree From File");
  printf("\n2 - Show Tree");
  printf("\n3 - Is Full");
  printf("\n4 - Search Value");
  printf("\n5 - Get Height");
  printf("\n6 - Remove Value");
  printf("\n7 - Print In Order");
  printf("\n8 - Print Pre Order");
  printf("\n9 - Print Post Order");
  printf("\n10 - Balance Tree");
  printf("\n0 - Exit");
  do{
    printf("\n\nEnter the number of the function you would like to do: ");
    scanf("%d", &option);
  }while(validateNumbers(option, 0, 10) == 1);

  return option;
}

int validateNumbers(int numberEntered, int min, int max){
  //Declarações

  //Instruções
  while(numberEntered < min || numberEntered > max){
    printf("\nInvalid Number! Try again\n");
    return 1;
  }
  return 0;
}

Node* loadTreeFromFile(char *fileName){
  //Declarações
  FILE *arq;
  Node *raiz = NULL, *novoNo = NULL;
  int totalOfNumbersInFile, *fileNumbers = NULL;

  //Instruções
  arq = fopen(fileName, "r");
  if(arq == NULL){
    printf("Cannot open file!");
    printf("\nPress ENTER to return to menu ");
    LIMPA_BUFFER;
    getchar();
  }else{
    totalOfNumbersInFile = (calculateQuantityOfNumbers(arq) + 1);
    fileNumbers = calloc(totalOfNumbersInFile, sizeof(int));
    if(fileNumbers == NULL){
      printf("Allocation Failed!");
      exit(1);
    }
    readNumbersFromArchive(arq, totalOfNumbersInFile, fileNumbers);
    fclose(arq);
    for(int i = 0; i < totalOfNumbersInFile; i++){
      novoNo = createNewNode(fileNumbers[i]);
      raiz = insert(raiz, novoNo);
    }
    printf("\n\nWait... Creating Tree\n");
    for(int i = 0; i < 3; i++){
      sleep(1);
      printf("*\n");
    }
    printf("\nSuccessfully created tree... Press ENTER ");
    LIMPA_BUFFER;
    getchar();
    free(fileNumbers);
  }

  return raiz;
}

int calculateQuantityOfNumbers(FILE *arq){
  int qtdRegistros = 0;
  char detectaRegistro;

  fseek(arq, 0, SEEK_SET);

  while(fread(&detectaRegistro,sizeof(char),1,arq)==1){
    if(detectaRegistro == ' '){
      qtdRegistros++;
    }
  }

  return qtdRegistros;
}


void readNumbersFromArchive(FILE *arq, int totalOfNumbersInFile, int *fileNumbers){
  //Declarações

  //Instruções
  rewind(arq);
  for(int i = 0; i < totalOfNumbersInFile; i++){
    fscanf(arq, "%d ", &fileNumbers[i]);
  }

}

Node* createNewNode(int fileNumber){
  //Declarações

  //Instruções
  Node *novoNo = (Node*) malloc(sizeof(Node));
  novoNo->info = fileNumber;
  novoNo->esquerda = NULL;
  novoNo->direita = NULL;

  return novoNo;
}

Node* insert(Node *raiz, Node *novoNo){
  //Declarações

  //Instruções
  if(raiz == NULL){
    return novoNo;
  }

  if(raiz->info > novoNo->info){
    raiz->esquerda = insert(raiz->esquerda, novoNo);
  }
  else{
    raiz->direita = insert(raiz->direita, novoNo);
  }

  return raiz;

}

int isEmpty(Node *raiz){
  //Declarações

  //Instruções
  if(raiz == NULL){
    return 1;
  }
  return 0;
}

void print2DUtil(Node *raiz, int space){
  //Declarações

  //Instruções
    if (raiz == NULL)
        return;

    space += 10;


    print2DUtil(raiz->direita, space);


    printf("\n");
    for (int i = 10; i < space; i++){
      printf(" ");
    }
    printf("%d\n", raiz->info);

    print2DUtil(raiz->esquerda, space);
}

void showTree(Node* raiz){
  //Declarações

  //Instruções
  print2DUtil(raiz, 0);

}

int checkIsFull(Node *raiz){
  //Declarações

  //Instruções
  if(raiz == NULL){
    return 2;
  }
  if(raiz->esquerda == NULL && raiz->direita == NULL){
    return 1;
  }
  if((raiz->esquerda) && (raiz->direita)){
    return (checkIsFull(raiz->esquerda) && checkIsFull(raiz->direita));
  }
  return 0;
}

void isFull(Node *raiz){
  //Declarações

  //Instruções
  if(checkIsFull(raiz) == 1){
      printf("Tree is full");
  }
  else if(checkIsFull(raiz) == 2){
    printf("Empty Tree");
  }
  else{
      printf("Tree is not full");
  }
}

int searchValue(Node *raiz, int value){
  //Declarações

  //Instruções
  if (!(raiz == NULL)){
    if(value == raiz->info){
      printf("\n\nRoot\n");
      printf("Node level: 1\n");
      return 0;
    }else if((raiz->esquerda != NULL) && value < raiz->info){
      if(raiz->esquerda->info == value){
        printf("\n\nNode level: %d", nodeLevel+1);
        printf("\nDad: %d\n",raiz->info);
        if(!(raiz->direita == NULL)){
          printf("Brother: %d\n\n", raiz->direita->info);
        }
        else{
          printf("\n\nThis node doesn't have brother\n\n");
        }
        return 0;
      }
        nodeLevel++;
        searchValue(raiz->esquerda, value);
    }else if((raiz->direita != NULL)){
      if(raiz->direita->info == value){
        printf("\n\nNode level: %d", nodeLevel+1);
        printf("\nDad: %d\n",raiz->info);
        if(!(raiz->esquerda == NULL)){
          printf("Brother: %d\n", raiz->esquerda->info);
        }
        else{
          printf("\n\nThis node doesn't have brother\n\n");
        }
        return 0;
      }
      nodeLevel++;
      searchValue(raiz->direita, value);
    }else{
      printf("\n\nNode not found in the tree\n\n");
      return -1;
    }
  }

}

int calculateHeight(Node *raiz){
  //Declarações
  int hEsq, hDir, altura;
  //Instruções
  if (raiz == NULL){
    return 0;
  }
  hEsq = calculateHeight(raiz->esquerda);
  hDir = calculateHeight(raiz->direita);
  altura = hEsq > hDir ? hEsq + 1 : hDir + 1;

  return altura;
}

void getHeight(Node *raiz){
  //Declarações
  //Instruções
  if(calculateHeight(raiz) == 0){
    printf("Empty tree");
  }
  else{
    printf("Tree Height: %d", calculateHeight(raiz));
  }
}

Node* findSuccessor(Node *no){
  //Declarações
   Node *aux = no;
  //Instruções
  while(aux-> esquerda != NULL){
    aux = aux->esquerda;
  }

  return aux;
}

Node* removeValue(Node *raiz, int deleteValue){
  //Declarações
  Node *aux = NULL;
  //Instruções
  if(raiz == NULL){
    return raiz;
  }
  if(deleteValue > raiz->info){
    raiz->direita = removeValue(raiz->direita, deleteValue);
  }else if(deleteValue < raiz->info){
    raiz->esquerda = removeValue(raiz->esquerda, deleteValue);
  }
  else{
    //Remover folha
    if(raiz->esquerda == NULL && raiz->direita == NULL){
      raiz = NULL;
      return raiz;
    }
    //Remover nó com 1 filho
    if(raiz->esquerda == NULL && raiz->direita != NULL){
      aux = raiz->direita;
      raiz = aux;
    }
    if(raiz->esquerda != NULL && raiz->direita == NULL){
      aux = raiz->esquerda;
      raiz = aux;
    }
    //Remover nó com 2 filhos
    if(raiz-> esquerda != NULL && raiz-> direita != NULL){
      aux = findSuccessor(raiz->direita);
      raiz->info = aux->info;
      raiz->direita = removeValue(raiz->direita, aux->info);
    }
  }
  return raiz;
}

void printInOrder(Node* raiz){
  //Declarações

  //Instruções
  if (!(raiz == NULL)){
    printInOrder(raiz->esquerda);
    printf("%d\t", raiz->info);
    printInOrder(raiz->direita);
  }
}

void printPreOrder(Node* raiz){
  //Declarações

  //Instruções
  if (!(raiz == NULL)){
    printf("%d\t", raiz->info);
    printPreOrder(raiz->esquerda);
    printPreOrder(raiz->direita);
  }

}

void printPostOrder(Node* raiz){
  //Declarações

  //Instruções
  if (!(raiz == NULL)){
    printPostOrder(raiz->esquerda);
    printPostOrder(raiz->direita);
    printf("%d\t", raiz->info);
  }
}


Node* balanceTree(Node *raiz){
  //Declarações
  Node *newroot = NULL;

  //Instruções
  switch(checkIfTreeIsBalanced(raiz)){
    case 0:
      printf("Tree is not balanced");
      newroot = balanceNode(raiz);
      if(newroot != raiz){
        raiz = newroot;
      }
      printf("\n\nWait... Balancing Tree\n");
      for(int i = 0; i < 3; i++){
        sleep(1);
        printf("*\n");
      }
      printf("\nSuccessfully balanced tree...");
    break;
    case 1:
      printf("Balanced Tree");
    break;
    case 2:
      printf("Empty Tree");
    break;
  }
  return raiz;
}

int checkIfTreeIsBalanced(Node *raiz) {
  //Declarações
  int value;

  //Instruções
  if (raiz == NULL){
    return 2;
  }
  value = abs(calculateHeight(raiz->esquerda) - calculateHeight(raiz->direita)) <= 1;
  if(checkIfTreeIsBalanced(raiz->esquerda) == 0 && checkIfTreeIsBalanced(raiz->direita) == 0){
    value = 0;
  }
  return value;
}

int calculateBalanceFactor(Node *no){
  //Declarações
  int bf = 0;

  //Instruções
  if(no->esquerda){
    bf += calculateHeight(no->esquerda);
  }
  if(no->direita){
    bf -= calculateHeight(no->direita);
  }

  return bf;
}

Node* balanceNode(Node *no){
  //Declarações
  Node *newroot = NULL;

  //Instruções
  if(no->esquerda){
    no->esquerda  = balanceNode(no->esquerda);
  }

  if(no->direita){
    no->direita = balanceNode(no->direita);
  }

  int bf = calculateBalanceFactor(no);

  if(bf >= 2){
    if(calculateBalanceFactor(no->esquerda) <= -1){
      newroot = rotateLeftRight(no);
    }
    else{
      newroot = rotateLeftLeft(no);
    }
  }
  else if(bf <= -2){

    if(calculateBalanceFactor(no->direita) >= 1){
      newroot = rotateRightLeft(no);
    }
    else{
      newroot = rotateRightRight(no);
    }
  }
  else {
    newroot = no;
  }

  return newroot;
}

Node* rotateLeftLeft(Node *no){
  //Declarações
  Node *a = no;
  Node *b = a->esquerda;

  //Instruções
	a->esquerda = b->direita;
	b->direita = a;

	return b;
}

Node* rotateLeftRight(Node *no){
  //Declarações
  Node *a = no;
  Node *b = a->esquerda;
  Node *c = b->direita;

  //Instruções
	a->esquerda = c->direita;
	b->direita = c->esquerda;
	c->esquerda = b;
	c->direita = a;

	return c;
}

Node* rotateRightLeft(Node *no){
  //Declarações
  Node *a = no;
  Node *b = a->direita;
  Node *c = b->esquerda;

  //Instruções
	a->direita = c->esquerda;
	b->esquerda = c->direita;
	c->direita = b;
	c->esquerda = a;

	return c;
}

Node* rotateRightRight(Node *no){
  //Declarações
  Node *a = no;
  Node *b = a->direita;

  //Instruções
	a->direita = b->esquerda;
	b->esquerda = a;

	return b;
}
