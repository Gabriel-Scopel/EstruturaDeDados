#include <stdio.h>
#include <stdlib.h>

#define tam_hash 7

typedef struct Celula{
    int valor;
    struct Celula* proximo;
}Celula;

typedef struct {
    Celula* inicio;
}Lista;

typedef struct {
    Lista* table[tam_hash];
}Hash;

Hash* start_hash(){
    Hash* hash = malloc(sizeof(Hash));
    for(int i = 0; i < tam_hash; i++){
        Lista* lista = malloc(sizeof(Lista));
        lista->inicio = NULL;
        hash->table[i] = lista;
    }
    return hash;
}

void inserir_hash(Hash* hash, int valor){
    int posicao = valor % tam_hash;
    Celula* celula = malloc(sizeof(Celula));
    celula->valor = valor;
    celula->proximo = hash->table[posicao]->inicio;
    hash->table[posicao]->inicio = celula;
}

void remover_hash(Hash* hash, int valor){
    int posicao = valor % tam_hash;
    Celula* celula = hash->table[posicao]->inicio;
    Celula* anterior = NULL;
    while(celula != NULL){
        if(celula->valor == valor){
            if(anterior == NULL){
                hash->table[posicao]->inicio = celula->proximo;
            }
            else{
                anterior->proximo = celula->proximo;
            }
            free(celula);
            return;
        }
        anterior = celula;
        celula = celula->proximo;
    }
}

void imprimir(Hash* hash){
    printf("---------------------\n");
    for(int i = 0; i < tam_hash; i++){
        printf("%d -> ", i);
        Celula* celula = hash->table[i]->inicio;
        while(celula != NULL){
            printf("%d ", celula->valor);
            celula = celula->proximo;
        }
        printf("\n");
    }
    printf("---------------------\n");
}

int main(void) {
    int valores[] = {190, 322, 172, 89, 13, 4, 769, 61, 15, 76, 97, 28, 80, 76, 88};
    int tam = sizeof(valores) / sizeof(int);
    Hash* hash = start_hash();
    for(int i = 0; i < tam; i++){
        inserir_hash(hash, valores[i]);
    }
    imprimir(hash);
    for(int i = 5; i < 10; i++){
        remover_hash(hash, valores[i]);
    }
    imprimir(hash);
    for(int i = 3; i < 7; i++){
        inserir_hash(hash, valores[i]);
    }
    imprimir(hash);
    for(int i = 10; i < 15; i++){
        remover_hash(hash, valores[i]);
    }
    imprimir(hash);
    return 0;
} 