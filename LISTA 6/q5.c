#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAT_VET 30
#define SEMESTRES 10
#define IDS 50
#define IDADES 65

struct Professor {

    char nome[40];
    int id;
    int idade;

};

struct Disciplina {

    char nome[40];
    int semestre;
    struct Professor docente; 

};

void geraMaterias(struct Disciplina **mat, int qtd) {

    printf("\n");
    for (int i = 0; i < qtd; i++) {

        struct Disciplina *newMateria = (struct Disciplina*)malloc(sizeof(struct Disciplina));
        mat[i] = newMateria;

        printf("Digite o nome da DISCIPLINA: ");
        scanf("%s", newMateria->nome);

        newMateria->semestre = 1 + (rand() % (SEMESTRES + 1));

        printf("DADOS DO PROFESSOR...\n");
        printf("Nome do PROFESSOR de ministra a disciplina: ");
        scanf("%s", newMateria->docente.nome);

        newMateria->docente.id = rand() % (IDS + 1);
        newMateria->docente.idade = 25 + (rand() % (IDADES + 1 - 25));

        printf("\n");

    }

}

void imprimeMaterias(struct Disciplina **mat, int qtd) {

    printf("\n");
    for (int i = 0; i < qtd; i++) {

        printf("MATERIA: %s\n", mat[i]->nome);
        printf("SEMESTRE: %d\n",mat[i]->semestre);
        printf("Professor que ministra...\n");
        printf("NOME DOCENTE: %s\n", mat[i]->docente.nome);
        printf("ID DOCENTE: %d\n", mat[i]->docente.id);
        printf("IDADE DOCENTE: %d\n\n", mat[i]->docente.idade);

    }

}


int main() {

    struct Disciplina *materias[MAT_VET];

    int qtd_materias;

    printf("Digite a quantidade de materias: ");
    scanf("%d", &qtd_materias);

    geraMaterias(materias, qtd_materias);
    imprimeMaterias(materias, qtd_materias);

    for (int i = 0; i < MAT_VET; i++) {

        free(materias[i]);

    }

    return 0;

}