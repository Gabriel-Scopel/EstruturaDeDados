#include <stdio.h>
#include <stdlib.h>

/*A Celula deve conter um ponteiro que aponta para a atual e para a anterior*/
typedef struct Celula{
	struct Celula *anterior;
	struct Celula *proximo;
	int valor;
}Celula;

typedef struct LDDE{
	Celula *primeiro;
	int qtde;
}LDDE;

/*Para inicializar a lista e a Celula devemos alocar um ponteiro com seu espaço de memória e settar seus valores*/
LDDE *inicializa_lista(){
	LDDE *lista = malloc(sizeof(LDDE));
	lista->primeiro = NULL;
	lista->qtde = 0;
	return lista;
}

Celula *inicializa_celula(int valor){
	Celula *celula = malloc(sizeof(Celula));
	celula->anterior = NULL;
	celula->proximo = NULL;
	celula->valor = valor;
	return celula;
}


void inserir(LDDE *lista, int valor){
    //alocamos um ponteiro com o espaço de memória de uma célula passando como argumento o valor que a célula terá
	Celula *novo = inicializa_celula(valor); 
	if(lista->qtde == 0){ //inserindo em uma lista vazia
		lista->primeiro = novo; //o novo primeiro elemento da lista é o elemento que acabmos de criar
	}else{
        //caso não seja o primeiro
        //criando 2 ponteiros(atual e anterior) para percorrer a lista
		Celula *atual = lista->primeiro;
		Celula *anterior = NULL;
		while(atual != NULL && atual->valor <= valor){ //percorrendo com a finalidade de ordenar de forma crescente
			anterior = atual;
			atual = atual->proximo;
		}
		if(anterior == NULL && atual != NULL){ //caso seja o primeiro elemento de uma lista não vazia: vamos inserir a nova Celula criada na primeira posição
			//o proximo do novo é o atual (primeiro da lista) e o anterior do atual é o novo
            novo->proximo = atual; 
			atual->anterior = novo; 
			lista->primeiro = novo; //o primeiro da lista passa a ser o novo
		}else{
			if(atual == NULL && anterior != NULL){ //inserindo na última posição
				anterior->proximo = novo;
				novo->anterior = anterior;
			}else{ //inserindo no meio da lista
				anterior->proximo = novo;
				novo->anterior = anterior;
				novo->proximo = atual;
				atual->anterior = novo;
			}
		}
	}
	lista->qtde++;
}

void imprimir(LDDE *lista){
	Celula *atual = lista->primeiro; //criamos um ponteiro que aponta para o primeiro da lista
    //enquanto esse ponteiro não for null (chegamos ao final da lista) ele apontará para o valor de cada elemento e imprimirá esse valor
	while(atual != NULL){
		printf("%d ", atual->valor);
		atual = atual->proximo; //passando pelos elementos
	}
	printf("\n");
}

Celula *buscar(LDDE *lista, int valor){
  Celula *atual = lista->primeiro;
  //buscando o valor
  while(atual != NULL && atual->valor != valor){ //ele parará quando o valor for encontrado ou chegarmos ao final da lista (atual == NULL)
    atual = atual->proximo;
  }
  return atual;
}

void remover(LDDE *lista, int valor){
	Celula *c = buscar(lista,valor); //pegando o elemento que vamos remover
    if(c!=NULL){ //só vamos remover se o elemento existir 
        if(lista->qtde == 1){ //removendo o primeiro elemento
            lista->primeiro = NULL;
    }else if(c->proximo == NULL){ //removendo o último da lista
        c->anterior->proximo = NULL; 
        free(c);
    }else if(c->anterior == NULL){ //removendo o primeiro
        lista->primeiro = c->proximo; //o segundo elemento da lista será o novo primeiro
        c->proximo->anterior = NULL;
        free(c);
    }else{ //removendo do meio
        //ligando o anterior e o próximo do meio da lista 
        c->anterior->proximo = c->proximo; 
        c->proximo->anterior = c->anterior;
        free(c);
    }
    lista->qtde--;
    }else{
        
    }
  
  
}

int main(void) {
  LDDE *lista = inicializa_lista();
	int in[] = {2, 3, 9, 6, 7, 4, 1, 8, 0, 5};
	int out[] = {0, 9, 1, 8, 5, 5, 6, 2, 3, 4, 7};
	int len_in = sizeof(in) / sizeof(int);
	int len_out = sizeof(out) / sizeof(int);
	for(int i = 0; i < len_in; i ++){
		inserir(lista, in[i]);
		imprimir(lista);
	}
	for(int j = 0; j < len_out; j++){
		remover(lista, out[j]);
		imprimir(lista);
	}
  return 0;
}