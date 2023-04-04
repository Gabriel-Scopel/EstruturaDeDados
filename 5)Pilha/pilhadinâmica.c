#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
  
typedef struct Celula{
	//implementar a estrutura de uma célula
  int valor;
  struct Celula *proximo;
}Celula;

typedef struct Pilha{
	//implementar e estrutura de uma pilha
  Celula *topo;
  int qtde;
}Pilha;

Pilha* start_stack(){
	//implementar função que retorne uma pilha inicializada
  Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
  pilha->topo = NULL;
  pilha->qtde =0;
	return pilha;
}

Celula* start_cell(){
	//implementar função que retorne uma célula inicializada
  Celula *celula = (Celula*)malloc(sizeof(Celula));
  celula->proximo = NULL;
  celula->valor = 0;
	return celula;
}

int isEmpty(Pilha* pilha){
	//implementar função que verifique se pilha é vazia
  if(pilha->topo == NULL){
    return TRUE;
  }else{
    return FALSE;
  }
}

void show_stack(Pilha* pilha){
	//implementar procedimento que mostre o estado atual de pilha
	//dica: analise a saída produzida e construa o procedimento de acordo
  Celula *aux;
  aux = pilha->topo;
  printf("Topo da pilha -> " );
  while(aux != NULL){
    printf("%d ",aux->valor);
    aux = aux->proximo;
  }
  printf("<- Fim da pilha\n");
}

void push(Pilha* pilha, int value){
	//contrua um procedimento para emplilhar values em pilha
  Celula *aux = start_cell();
  aux->valor = value;
  aux->proximo = pilha->topo;
  pilha->topo = aux;
  pilha->qtde++;
  
}

int pop(Pilha* pilha){
	//construa um procedimento para desempilhar um valor de pilha
  if(!isEmpty(pilha)){
    Celula *apagar = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    int value = apagar->valor;
    return value;
  }
	
	else{
    return -1;
  }
	
}

int main(void) {
	Pilha* pilha = start_stack();
  for(int i = 0; i < 10; i++){
		printf("Empilhando: %d\n", i);
		push(pilha, i);
	}
	show_stack(pilha);
	for(int i = 0; i <= 10; i++){
		printf("Desempilhando: %d\n", pop(pilha));
		show_stack(pilha);
	}
	
  return 0;
}