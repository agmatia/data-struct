#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matr;
    char sexo;
    char nome[50];
    float altura;
} tAluno;

int main()
{
    tAluno aluno1;
    aluno1.matr = 123456;
    aluno1.sexo = 'F';
    aluno1.altura = 1.63;
    strcpy(aluno1.nome, "Amanda");

    printf("matr...: %d\n", aluno1.matr);
    printf("nome...: %s\n", aluno1.nome);
    printf("altura.: %.2f\n", aluno1.altura);
    printf("sexo...: %c\n", aluno1.sexo);
}
