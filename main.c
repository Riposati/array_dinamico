#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char *vet;
int tamArrayInicial = 10;
int valor;

void alocaMemoria(){

    vet = (char *)malloc(tamArrayInicial * sizeof(char));
    memset(vet,0,sizeof(char) * tamArrayInicial);
}

void dobraBuffer(){

    int i;
    char *t = vet;

    char u[tamArrayInicial];

    for(i=0;i<tamArrayInicial;i++){
        u[i] = t[i];
    }

    char *p = vet;
    p = (char *)realloc(p,(tamArrayInicial*2) * sizeof(char));

    memset(p,0,sizeof (char) * (tamArrayInicial*2));

    for(i=0;i<tamArrayInicial;i++){
        p[i] = u[i];
    }
    tamArrayInicial = tamArrayInicial * 2;
    vet = p;
}

void mostraBuffer(){

    int k;
    printf("valores alocados\n");
    for(k=0;k<strlen(vet);k++){

        printf("%c",vet[k]);
    }
}

void necessarioDobrar(){

    if(vet[tamArrayInicial-1]!=0){ /// sabe que precisa alocar mais memoria
        printf("\n\n*** dobrei o tamanho do vetor *** valor nesse momento = %d\n\n",valor);
        dobraBuffer();
    }
}

int main()
{
    alocaMemoria(); /// vetor normal
    char opcao;

    printf("\nDigite e tecle enter\n<< diferente de zero - inserir valores >>\n<< 0 - sair >>\n");
    scanf(" %c",&opcao);

    getchar();

    char *frase = "Teste String em C Gustavo Riposati estou aqui testando essa minha implementacao ";

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
