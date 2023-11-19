#include <stdio.h>

struct Aluno {

    float nota1;
    float nota2;
    float media;

};

int main() {

    struct Aluno a1;

    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &a1.nota1);

    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &a1.nota2);

    a1.media = (a1.nota1 + a1.nota2) / 2;

    printf("MEDIA DO ALUNO: %.2f\n", a1.media);

}