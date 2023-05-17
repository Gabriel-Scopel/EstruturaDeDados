

/* 5( ) 
5( 3( ) ) 
5( 3( ) 8( ) ) 
5( 3( 2( ) ) 8( ) ) 
5( 3( 2( ) 4( ) ) 8( ) ) 
5( 3( 2( ) 4( ) ) 8( 7( ) ) ) 
5( 3( 2( ) 4( ) ) 8( 7( ) 9( ) ) ) 
5( 3( 2( 1( ) ) 4( ) ) 8( 7( ) 9( ) ) ) 
5( 3( 2( 1( ) ) 4( ) ) 8( 7( 6( ) ) 9( ) ) ) 
5( 3( 2( 1( ) ) 4( ) ) 8( 7( 6( ) ) 9( 10( ) ) ) ) 
4( 3( 2( 1( ) ) ) 8( 7( 6( ) ) 9( 10( ) ) ) ) 
4( 2( 1( ) ) 8( 7( 6( ) ) 9( 10( ) ) ) ) 
4( 2( 1( ) ) 7( 6( ) 9( 10( ) ) ) ) 
4( 1( ) 7( 6( ) 9( 10( ) ) ) ) 
1( 7( 6( ) 9( 10( ) ) ) ) 
1( 6( 9( 10( ) ) ) ) 
1( 6( 10( ) ) ) 
6( 10( ) ) 
10( ) */

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
	int valor;
	struct Vertice* esq;
	struct Vertice* dir;
	struct Vertice* pai;
} Vertice;

typedef struct Arvore{
	Vertice* raiz;
	int qtde;
} Arvore;

void imprimeEstrutura(Vertice* raiz){
    if(raiz == NULL){
        return;
    }
    printf("%d( ", raiz->valor);
    imprimeEstrutura(raiz->esq);
    imprimeEstrutura(raiz->dir);
    printf(") ");
}

void inserir(Arvore* arvore, int valor){
	Vertice* novo = malloc(sizeof(Vertice));
	novo->dir = NULL;
	novo->esq = NULL;
	novo->pai = NULL;
	novo->valor = valor;

	Vertice* anterior = NULL;
	Vertice* atual = arvore->raiz;

	while(atual != NULL){
		anterior = atual;
		if(valor <= anterior->valor){
			atual = atual->esq;
		}else{
			atual = atual->dir;
		}
	}

	novo->pai = anterior;
	if(anterior != NULL){
		if(valor <= anterior->valor){
			anterior->esq = novo;
		}else{
			anterior->dir = novo;
		}
	}else{
		arvore->raiz = novo;
	}
	arvore->qtde++;
}

int remover_vertice(Arvore* arvore, Vertice* vertice){
    int aux;
    int filhos = 0;
    Vertice* filho;
    Vertice* pai = vertice->pai;

    if(vertice->esq != NULL) filhos++;
    if(vertice->dir != NULL) filhos++;

    if(filhos == 0){
        if(pai == NULL) arvore->raiz = NULL;
        else if(vertice == pai->esq) pai->esq = NULL;
        else pai->dir = NULL;
        free(vertice);
        arvore->qtde--;
        return 1;
    }

    if(filhos == 1){
        if(vertice->esq != NULL) filho = vertice->esq;
        else filho = vertice->dir;

        if(pai == NULL) arvore->raiz = filho;
        else if(vertice == pai->esq) pai->esq = filho;
        else pai->dir = filho;

        filho->pai = pai;
        free(vertice);
        arvore->qtde--;
        return 1;
    }

    if(filhos == 2){
        filho = vertice->esq;
        while(filho->dir != NULL) filho = filho->dir;

        aux = vertice->valor;
        vertice->valor = filho->valor;
        filho->valor = aux;
        return remover_vertice(arvore, filho);
    }

    return 0;
}

int buscar_valor(Arvore* arvore, int valor){
	Vertice* atual = arvore->raiz;
	while(atual != NULL){
		if(valor < atual->valor){
			atual = atual->esq;
		}else{
			if(valor > atual->valor){
				atual = atual->dir;
			}else{
				return remover_vertice(arvore, atual);
			}
		}
	}
	return 0;
}

int main(void) {
	int dados[] = {5, 3, 8, 2, 4, 7, 9, 1, 6, 10};
    Arvore* arvore = malloc(sizeof(Arvore));
	arvore->raiz = NULL;
	arvore->qtde = 0;

	for(int i = 0; i < 10; i++){
		inserir(arvore, dados[i]);
		imprimeEstrutura(arvore->raiz);
		printf("\n");
	}
	
	for(int i = 0; i < 10; i++){
		buscar_valor(arvore, dados[i]);
		imprimeEstrutura(arvore->raiz);
		printf("\n");
	}
		
  return 0;
}