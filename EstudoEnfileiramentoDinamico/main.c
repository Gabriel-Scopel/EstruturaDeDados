#include <stdio.h>

//criando um struct que possui um inteiro dado e um ponteiro que aponta para outro struct NO
typedef struct NO{
int dado;
struct NO *prox;
}NO;


typedef struct FILA{
NO *ini;
NO *fim;
}FILA;

//inicialmente o ponteiros da fila apontam para nulo já que não há elemento enfileirado
void inicializaFILA(FILA *f){
  f->ini = NULL;
  f->fim = NULL;
}

void enfileira(int dado, FILA *f) {
  NO *ptr = (NO*) malloc(sizeof(NO));
  if(ptr == NULL){
    printf("Erro de alocação no nó\n");
    return;
  }else{
    //inserindo o dado novo no novo elemento e apontando seu ponteiro para nulo (será o novo último elemento da lista)
    ptr->dado = dado;
    ptr->prox = NULL;
    if(f->ini == NULL){ //se a insersão for a primeira o ponteiro de inicio da fila apontará para o primeiro elemento da insersão
      f->ini = ptr;
    }else{
      f->fim->prox = ptr; 
    }
    f->fim = ptr;
    return;
  }
  
}

void imprimeFila(FILA *f){
  NO *ptr = f->ini;
  if(ptr != NULL){
    while(ptr != NULL){
      printf("%d ", ptr->dado);
      ptr = ptr->prox;
    }
  }else{
    printf("erro, fila vazia");
    return;
  }
}

int main(){
  FILA *f1 = (FILA*) malloc(sizeof(FILA));
  if(f1 == NULL){
    printf("erro de alocação na fila\n");
    exit(-1);
  }else{
    inicializaFILA(f1);
    enfileira(10, f1);
    enfileira(20, f1);
    enfileira(30, f1);
    imprimeFila(f1);
  }
}