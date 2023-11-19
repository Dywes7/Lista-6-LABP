#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

struct Model {

    int *end_vet;
    int qtd_elementos;
    float media;

};

void gerarVetor (struct Model *ve, int qtd) {

   
    if (!(ve->end_vet = (int*)malloc(qtd * sizeof(int)))) {

        puts("Memoria insuficiente.\n");
        exit(1);

    }

}

void inicializarVetor(int *end_vetor, int qtd) {

    srand(time(NULL));

    for (int i = 0; i < qtd; i++) {

        *(end_vetor + i) = rand() % (MAX + 1);

    }

}

float retornaMediaVetor(int *end_vetor, int qtd) {

    float media = 0;

    for (int i = 0; i < qtd; i++) {

        media += *(end_vetor + i);

    }

    return media / qtd;


}

void imprimeVetor(int *end_vetor, int qtd) {

    printf("\n");
    for (int i = 0; i < qtd; i++) {

        printf("Vetor[%d]: %d\n", i, *(end_vetor + i));

    }

}

int main() {

    struct Model vetor;

    int qtd_ele;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &qtd_ele);

    gerarVetor(&vetor, qtd_ele);

    inicializarVetor(vetor.end_vet, qtd_ele);
    imprimeVetor(vetor.end_vet, qtd_ele);

    printf("MEDIA DO VETOR: %.2f\n", retornaMediaVetor(vetor.end_vet, qtd_ele));
    
    return 0;

}