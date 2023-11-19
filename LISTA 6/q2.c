#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50
#define PRECO_MAX 1000
#define N_PEDIDO 10000

struct Estoque {

    char nomePeca[40];
    int id;
    float preco;
    int n_pedido;

};

void adicionarEstoque(int qtd, struct Estoque **vet) {


    for (int i = 0; i < qtd; i++) {

        struct Estoque *produto = (struct Estoque*)malloc(sizeof(struct Estoque));
        vet[i] = produto;

        printf("Nome do produto: ");
        scanf("%s", produto->nomePeca);

        produto->id = i;
        produto->preco = ((float)rand() / RAND_MAX) * PRECO_MAX;
        produto->n_pedido = 1 + (rand() % (N_PEDIDO + 1));

    }

}

void exibirProduto(struct Estoque **pro, int tam) {

    for (int i = 0; i < tam; i++) {

        printf("\nNome do produto: %s\n", pro[i]->nomePeca);
        printf("ID: %d\n", pro[i]->id);
        printf("Preco: %.2f\n", pro[i]->preco);
        printf("Numero do pedido: %d\n", pro[i]->n_pedido);

    }
    

}

int main() {

    struct Estoque *p1[TAM];
    int qtd_pro;
    
    printf("Digite a quatidade de produtoes a serem adicionados: ");
    scanf("%d", &qtd_pro);

    adicionarEstoque(qtd_pro, p1);

    exibirProduto(p1, TAM);

    for (int i = 0; i < qtd_pro; i++) {

        free(p1[i]);

    }

    return 0;

}