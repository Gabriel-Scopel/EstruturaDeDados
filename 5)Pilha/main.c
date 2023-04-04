#include <stdio.h>
#include <stdlib.h> //permite usar malloc
/*
-lifo: last in, first out (primeiro que entra é o último que sai)
-comum em chamadas recursivas(que chama a si mesmo)
-ponto único de acesso: topo (posição sem conteúdo, onde haverá inserção)
-
*/
#define ARRAY_SIZE 7
#define TRUE 1
#define FALSE 0
typedef struct{
  int values[ARRAY_SIZE];
  int top;
}Pilha;

/*inicialização da struct -> retorna o endereço de uma struct Pilha */
Pilha *start_stack(){
  Pilha* pilha = malloc(sizeof(Pilha));
  pilha->top = 0;
  return pilha;
}

/*inserção: o valor é inserido e a posição do top é incrementada. A pilha não deve aceitar mais inserção quando está cheia, ou seja, top é igual ao array_size. A função que faz essa verificação é isFull
*/
int is_full(Pilha *pilha){
  return pilha->top == ARRAY_SIZE;
  /*o código acima faz a mesma verificação que:
  if(pilha->top == ARRAY_SIZE){
    return TRUE;
  }else{
    return FALSE;
  }*/
}
//inserção
int push(Pilha* pilha, int value){
  if(!is_full(pilha)){
    pilha->values[pilha->top] = value;
    pilha->top++;
    /*as duas linhas seriam simplificadas em:pilha->values[pilha->top++] = value; */
    return TRUE;
  }else{
    return FALSE;
  }
}

//remoção
/*o topo deve ser decrementado, para apontar para o último elemento que foi inserido. Quando top aponta para a posição 0, ele está na base da pilha(pilha vazia). Remoção só pode existir se is_empty foi false (não está vazia)*/
int is_empty(Pilha *pilha){
  if(pilha->top == 0){
    return TRUE;
  }else{
    return FALSE;
  }
  /*o if e else poderia ser substituido por:
  return pilha->top == 0;*/
}
int pop(Pilha *pilha){
  if(!is_empty(pilha)){
    int result = pilha->values[--pilha->top]; //é necessário primeiro decrementar e depois acessar o valor, já que o topo é uma posição vazia onde seria a próxima inserção
    return result;
  }else{
    return -1; //impossível retirar pq a pilha está vazia
  }
}
void show_stack(Pilha *pilha){
  printf("Topo\n");
  //a impressão é do topo a base
  for(int i=pilha->top; i>=0; i--){
    printf("%d\n", pilha->values[i]);
  }
}
int main(void) {
  Pilha* pilha = start_stack();
  for(int i=0; i<ARRAY_SIZE; i++){
    push(pilha, i);
    show_stack(pilha);
  }
  for(int i=0; i<ARRAY_SIZE; i++){
    printf("valor removido = %d\n", pop(pilha));
    show_stack(pilha);
  }
  return 0;
}

/*PILHA DINÂMICA
-não se faz necessário definir o tamanho do ARRAY_SIZE
-struct possui apenas o topo ou topo e quantidade
-celula com um membro valor e um membro próximo
-inicilizando struct pilha: topo: null e qtde =0
-  ''            ''  celula: value=0 e proximo =null

*/