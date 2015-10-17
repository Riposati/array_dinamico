#include <stdio.h>
#include <stdlib.h>

int tamanhoBufferDesejado(){
    int tamArrayInicial = 10;
    return tamArrayInicial;
}

int *alocaMemoria(){
    int tamArray = tamanhoBufferDesejado();
    int *p;
    int i;

    p = (int *)malloc(tamArray * sizeof(int));

    for(i=0;i<tamArray;i++){

        p[i] = 0;
    }

    if(p==NULL){ /// se acabar a memória
        printf("memoria ram insuficiente\n");
        exit(1);
    }
    return p;
}

int *dobraBuffer(int *p,int tamArrayInicial){

    int i;
    p = (int *)realloc(p,(tamArrayInicial*2) * sizeof(int));

    if(p==NULL){

        printf("Memoria RAM insuficiente\n");
        exit(1);
    }

    for(i=tamArrayInicial;i<tamArrayInicial*2;i++){

        p[i] = 0;
    }

    tamArrayInicial *=2;
    return p;
}

void mostraBuffer(int *vet,int tamArrayInicial){

    int k;

    printf("valores alocados\n");
    for(k=0;k<tamArrayInicial;k++){
        if(vet[k]!=0)
        printf("%d ",vet[k]);
    }
}

int necessarioDobrar(int *vet,int valor,int tamArrayInicial){

    if(valor==tamArrayInicial){ /// sabe que precisa alocar mais memoria
        printf("\n\n*** dobrei o tamanho do vetor *** valor do valor neste momento = %d\n\n",valor);
        vet = dobraBuffer(vet,tamArrayInicial);
        tamArrayInicial*=2;
    }

    return tamArrayInicial;
}
