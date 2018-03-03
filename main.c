#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char *vet;
int tamArray = 100;
int valor;

void construtor(){
    vet = (char *)malloc(tamArray * sizeof(char)); // tamanho inicial do vetor
    memset(vet,0,sizeof(char) * tamArray); // inicializo todos valores com '0'
}

void dobraBuffer(){

    int i;
    char *t = vet;

    char u[tamArray];

    for(i=0;i<tamArray;i++){ // faco a cópia dos valores do antigo vetor pra esse
        u[i] = t[i];
    }

    char *p = vet;
    p = (char *)realloc(p,(tamArray*2) * sizeof(char)); // aloco o novo vetor

    if(p==NULL){
        printf("nao consegui alocar mais falta de memoria disponivel!\n");
        exit(1);
    }

    memset(p,0,sizeof (char) * (tamArray*2)); // inicializo todos os valores pra 0

    for(i=0;i<tamArray;i++){ // copio da nossa cópia pro novo vetor
        p[i] = u[i];
    }

    tamArray = tamArray * 2; // dobro a variavel que assegura a necessidade de dobrar

    vet = p; // nosso vetor antigo agora aponta para o novo
}

void mostraBuffer(){

    int k;
    printf("valores alocados\n");
    for(k=0;k<strlen(vet);k++){

        printf("%c",vet[k]);
    }
}

void necessarioDobrar(){

    if(vet[tamArray-1]!=0){ // sabe que precisa alocar mais memoria
        printf("\n*** Tamanho atual do vetor = %d***\n",tamArray);
        printf("\n*** Tamanho apos realocar memoria = %d***\n",tamArray*2);
        dobraBuffer();
    }
}

int main()
{
    construtor(); /// vetor normal
    char opcao;

    printf("\nDigite e tecle enter\n<< diferente de zero - inserir valores >>\n<< 0 - sair >>\n");
    scanf(" %c",&opcao);

    getchar();

    char *frase = "Game of Thrones "; // 16 chars, letras mais espaços

    while(opcao!='0'){

        int i=0;
        while(frase[i]!='\0'){
            vet[valor] = frase[i];
            valor++;
            i++;

            necessarioDobrar();
        }

        mostraBuffer();
        printf("\nDigite e tecle enter\n<< diferente de zero - inserir valores >>\n<< 0 - sair >>\n");
        scanf(" %c",&opcao);
        getchar();
    }
        free(vet);
        return 0;
    }
