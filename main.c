#include <stdio.h>
#include <stdlib.h>
#include "headers/cabecalho_funcoes_vector_meu.h"

int main()
{
    int tamArrayInicial = tamanhoBufferDesejado(); /// mesmo tamanho que o buffer tá alocando
    int *vet = alocaMemoria(); /// vetor normal
    int valor=0; /// essa variavel analisa se precisa alocar mais RAM
    int k;
    char opcao;

    printf("\nDigite e tecle enter\n<< diferente de zero - inserir valores >>\n<< 0 - sair >>\n");
    scanf(" %c",&opcao);

    while(opcao!='0'){

        printf("digite um valor e tecle enter pra alocar\n");
        scanf("%d",&vet[valor]);
        valor++;

        tamArrayInicial = necessarioDobrar(vet,valor,tamArrayInicial);

        mostraBuffer(vet,tamArrayInicial);
        printf("\nDigite e tecle enter\n<< diferente de zero - inserir valores >>\n<< 0 - sair >>\n");
        scanf(" %c",&opcao);
    }
        free(vet);
        return 0;
    }
