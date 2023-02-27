#include <stdio.h>
#include <stdlib.h>

int descobrirValores(int *v, int *me, int *ma, int tam){
    int i;
    *me = v[0];
    *ma = v[0];

    for(i=1; i<tam; i++){
        if(v[i]<*me){
            *me = v[i];
        }
        if(v[i] > *ma){
            *ma = v[i];
        }
    }
    printf("Na funcao: menor %d maior: %d\n", *me, *ma);
    printf("endereco de me: %p endereco de ma: %p\n", &me, &ma);
    printf("conteudo de me: %p conteudo de ma: %p\n ", me, ma);
}
/* Passando o endereço de memória ao invés do valor no parâmetro da função, ele não pega lixo, dessa forma,
passando o endereço de memória, ele irá alterar o conteúdo de menor e maior (presentes na main)
na função descobrirValores, através do endereço passado */
int main()
{
    int valor = 10, menor, maior, vet[] = {50,10,250,500,25};
    int *p;
    p = &valor; //p aponta para valor
    descobrirValores(vet, &menor, &maior, 5);
    printf("Na main: menor: %d maior %d\n", menor, maior);
    printf("endereco de menor: %p endereco de maior %p\n", &menor, &maior);
}
/*
Como me e ma são variáveis diferentes de menor e maior, por isso terão endereços diferentes, mas como me
aponta para o endereço de menor e ma aponta para o endereço de maior ao printar o endereço de menor, o 
endereço de maior, o conteúdo de me e o conteúdo de ma eles serão iguais
*/