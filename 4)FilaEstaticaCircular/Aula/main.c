#include <stdio.h>
#include <stdlib.h>

#define tamanho_fila 10

typedef struct Fila{
  int v[tamanho_fila];
  int tail;
  int head;
}Fila;

Fila *inicializa_fila(){
  Fila *fila = malloc(sizeof(Fila));
  fila->head = 0;
  fila->tail = 0;
  return fila;
}

//se a fila estiver cheia return = 1 se não result = 0
int is_full(Fila *fila){
  if(fila->tail == tamanho_fila){
    return 1;
  }else{
    return 0;
  }
}

void enqueue(Fila *fila, int valor){
  if(!is_full(fila)){
    fila->v[fila->tail] = valor;
    fila->tail++;
  }
}

int is_empty(Fila *fila){
  if(fila->head == fila->tail){
    return 1;
  }else{
    return 0;
  }
}

int dequeue(Fila *fila){
  if(!is_empty(fila)){
    int result = fila->v[fila->head];
    fila->head++;
    return result;
  }
  return 0;
}

void mostra_fila(Fila *fila){
  for(int i=fila->head; i<fila->tail; i++){
    printf("%d ", fila->v[i]);
  }
  printf("\n");  
}

int main(void) {
  Fila *fila = inicializa_fila();
  enqueue(fila, 5);
  mostra_fila(fila);
  enqueue(fila, 10);
  mostra_fila(fila);
  enqueue(fila, 15);
  mostra_fila(fila);
  dequeue(fila);
  mostra_fila(fila);
  
  return 0;
}