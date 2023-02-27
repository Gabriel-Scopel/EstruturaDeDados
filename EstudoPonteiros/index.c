#include <stdio.h>
#include <stdlib.h>

//struct da lista (possui valor e o endereço para onde ele aponta)
typedef struct no
{
    int valor;
    struct no *proximo;
}No ;


No* inserir(No *inicio, int x){ //recebe o ponteiro inicial e o valor para inserir
    No *novo = malloc(sizeof(No)); //alocando a memórica para o ponteiro tipo No
    if(novo){
        novo->valor = x; //inserindo x 
        novo->proximo = inicio; //o novo nó é o inicio da lista
    }
    return novo;
}

No* inserir2(No **inicio, int x){ //recebe o ponteiro inicial e o valor para inserir
    No *novo = malloc(sizeof(No)); //alocando a memórica para o ponteiro tipo No
    if(novo){
        novo->valor = x; //inserindo x 
        novo->proximo = *inicio; //o novo nó é o inicio da lista
        *inicio = novo;
    }
    
}

void imprimir(No *inicio){
    if(inicio) {
        printf("%d ", inicio->valor);
        imprimir(inicio->proximo);
    }
}

int main(){
    No *lista = NULL;

    lista = inserir(lista, 10); //lista recebe o retorno após cada inserção
    lista = inserir(lista, 50);
    lista = inserir(lista, 100);

    inserir2(&lista, 101); //não há retorno
    inserir2(&lista, 51); 
    inserir2(&lista, 11);
    
    imprimir(lista);
    return 0;
}