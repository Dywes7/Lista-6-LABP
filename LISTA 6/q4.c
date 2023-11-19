#include <stdio.h>

#define TAM 3

struct Aluno {

    float nota1;
    float nota2;
    float media;

};

void inicializaNotasAlunos(struct Aluno *aluno, int tamanho) {

    for (int i = 0; i < tamanho; i++) {

        printf("Digite a nota 1 do aluno %d: ", i);
        scanf("%f", &aluno[i].nota1);

        printf("Digite a nota 2 do aluno %d: ", i);
        scanf("%f", &aluno[i].nota2);

        printf("\n");

    }

}  

void calculaMedias(struct Aluno *aluno, int tamanho) {

     for (int i = 0; i < tamanho; i++) {

        aluno[i].media = (aluno[i].nota1 + aluno[i].nota2) / 2;

    }

}

void imprimeMedias(struct Aluno *aluno, int tamanho) {

    printf("\n");
    for (int i = 0; i < tamanho; i++) {

        printf("MEDIA ALUNO %d: %.2f\n", i, aluno[i].media);

    }
    
}

int main() {

    struct Aluno alunos[TAM];

    inicializaNotasAlunos(alunos, TAM);
    calculaMedias(alunos, TAM);
    imprimeMedias(alunos, TAM);

    return 0;

}