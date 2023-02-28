#include <stdio.h>
#include <stdlib.h>

/*temos a presença de duas estruturas: uma Celula que guarda o valor e o endereço para a próxima celula
e uma LDE (lista) que guarda um ponteiro para o primeiro elemento e a quantidade de células presentes
na fila*/
typedef struct Celula{
	int valor;
	struct Celula *proximo; //não existe o tipo ponteiro, o ponteiro é do tipo do dado que ele aponta
}Celula;

typedef struct {
	Celula *primeiro;
	int qtde;
}LDE;

/*inicializando a lista: Criando um ponteiro que apontará para o primeiro da LDE e setará como nulo 
(ainda não é um elemento de fato) e esse mesmo ponteiro settará a quantidade para 0*/

LDE *inicializa_lista(){ //como retorna um ponteiro, deve apresentar o asterisco na assinatura da função
	LDE *lista = malloc(sizeof(LDE)); //alocando espaço de memória para um ponteiro tipo lista
	lista->primeiro = NULL; //o ponteiro aponta inicialmente para nulo, já que não há elementos na lista ainda
	lista->qtde = 0; //quantidade definida para zero
	return lista; //retorna o ponteiro
}

/*inserir recebe como parâmetro a lista na qual fará a inserção e o elemento*/
void inserir(LDE *lista, int valor){
	//nas próximas 3 linhas vamos criar um ponteiro tipo Celula que será adicionado ao final da lista
	Celula *novo = malloc(sizeof(Celula)); //alocando um novo ponteiro tipo Celula
	novo->proximo = NULL; //adicionando ao final da fila, então o próximo sempre apontará para null
	novo->valor = valor; //adicionando valor na celula que será inserida
	
	if(lista->primeiro == NULL){//verificando se estamos realizando a primeira inserção
		lista->primeiro = novo;//fazendo a inserção do primeiro elemento através da struct lista, chegamos 
		//no primeiro elemento da Struct célula que ela aponta e atribuimos o valor
	}else{ //se não for o primeiro elemento
		Celula *atual = lista->primeiro; //criando um ponteiro tipo Celula que irá apontar para o primeiro da lista
		Celula *anterior = NULL; //criando um ponteiro tipo Celula que irá apontar para null
		
		/*movendo o ponteiro para adicionar o elemento no final da lista: enquanto o atual for diferente de nulo 
		e o valor do atual for menor ou igual o valor que queremos inserir (apenas para inserir na posição 
		desejada e ter uma fila ordenada do menor para o maior)
		*/
		while(atual != NULL && atual->valor <= valor){
			//o ponteiro anterior vira o atual e o atual virá aquele que ele estava apontando
			anterior = atual;
			atual = atual->proximo;
		}
		//Aqui já achamos a posição que vamos inserir no meio da lista mas precisamos verificar se o anterior não está
		//apontando para nulo
		if(anterior == NULL){
			novo->proximo = lista->primeiro; //o próximo do novo é o primeiro da lista
			lista->primeiro = novo; 
		}else{ //inserindo no final da lista
			if(atual == NULL){
				anterior->proximo = novo; //fazemos o próximo do anterior ser o atual (novo último elemento da lista)
			}else{
				novo->proximo = atual;
				anterior->proximo = novo;
			}
		}
	}
	lista->qtde++;
}
void remover(LDE *l, int valor){
/*criamos dois ponteiros: uma para ser o atual e o outro para ser o anterior e apontamos o atual para o primeiro da lista*/
  Celula *ptr;
  Celula *anterior=NULL;
  ptr = l->primeiro;

/*enquanto o valor não for encontrado, o anterior vira o atul e o atual o atual->prox*/
  while(ptr->valor != valor){
    anterior = ptr;
    ptr = ptr->proximo;
  }
/*removendo na primeira posição*/
  if(anterior==NULL){
    l->primeiro = ptr->proximo;
  }else{
    anterior->proximo = ptr->proximo;
    ptr=NULL;
  }

  l->qtde--;
}
void imprimir(LDE *lista){
	/*para imprimir alocamos um ponteiro tipo célula que apontará para todas as células da lista e verificará se é 
	diferente de nulo*/
	Celula *atual = lista->primeiro; //apontando para o primeiro elemento
	while(atual != NULL){
		printf("%d ", atual->valor);
		atual = atual->proximo; //enquanto não for nulo, o atual vira o próximo
	}
	printf("\n");
}

int main(void) {
  LDE *lista = inicializa_lista();
	inserir(lista, 80);
	imprimir(lista);
	inserir(lista, 70);
	imprimir(lista);
	inserir(lista, 90);
	imprimir(lista);
	inserir(lista, 50);
	imprimir(lista);
	
  return 0;
}

/*
1)Inicializando a fila: Criamos um novo ponteiro tipo Lista que fara o primeiro apontar para NULL e a quantidade
será zero e retornamos esse ponteiro

2)Inserção na fila:
2.1 - Alocação de um ponteiro tipo Celula
2.2 - Se o primeiro for null, fazer o primeiro apontar para a nova celula
2.3 - Se não for o primeiro:
	  a)Criamos um ponteiro atual que aponta para o primeiro da lista e um ponteiro anterior que aponta para null
	  b)Fazemos a condiciona se o atual é diferente de nulo e o valor do atual é menor que o valor da inserção, enquanto 
	  for, o anterior vira o atual e o atual vira o próximo que o atual aponta
	  ### pode ser que ele tenha achado o ponto de inserção comparando os valores e esse ponto seja o primeiro da lista
	  c)se no momento da inserção, ele deve inserir no inicio da fila (anterior = NULL), o proximo vira o primeiro da fila
	  e o novo é o novo primeiro da fila
	  d)se vamos inserir no final da fila (atual == NULL) o próximo do anterior é o novo
	  e)se temos uma inserção realmente no meio (não é a primeira inserção, não vamos inserir no inicio e não vamos inserir
	  no final), o próximo da nova célula vira o atual e o anterior o novo
	  f)incremento na quantidade

3)Para imprimir: 
Criamos um ponteiro tipo célula que aponta para o primeiro da lista e fazemos a condicional, enquanto ele não for null,
o atual recebe atual->proximo
*/

