#include <stdio.h>  // Inclui a biblioteca para entrada e saída padrão de dados

// Definição da struct Aluno
struct Aluno {
    int matricula;       // Matrícula do aluno
    char nome[50];       // Nome do aluno
    float nota1, nota2, nota3; // Notas das 3 provas
};

int main() {
    struct Aluno alunos[5];  // Vetor para armazenar os dados de 5 alunos

    // Loop para ler os dados dos 5 alunos
    for (int i = 0; i < 5; i++) {
        printf("Informe os dados do aluno %d:\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        getchar();  // Limpa o buffer

        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        printf("Nota da primeira prova: ");
        scanf("%f", &alunos[i].nota1);

        printf("Nota da segunda prova: ");
        scanf("%f", &alunos[i].nota2);

        printf("Nota da terceira prova: ");
        scanf("%f", &alunos[i].nota3);
    }

    // Encontrando o aluno com a maior nota na primeira prova
    int maiorNota1 = 0;  // Índice do aluno com maior nota na 1ª prova
    for (int i = 1; i < 5; i++) {
        if (alunos[i].nota1 > alunos[maiorNota1].nota1) {
            maiorNota1 = i;
        }
    }
    printf("\nAluno com maior nota na primeira prova: %s", alunos[maiorNota1].nome);

    // Calculando a média geral de cada aluno e encontrando o maior e menor
    float maiorMedia = 0, menorMedia = 999;  // Variáveis para as médias
    int alunoMaiorMedia, alunoMenorMedia;    // Índices dos alunos

    for (int i = 0; i < 5; i++) {
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
        if (media > maiorMedia) {
            maiorMedia = media;
            alunoMaiorMedia = i;
        }
        if (media < menorMedia) {
            menorMedia = media;
            alunoMenorMedia = i;
        }
    }

    printf("\nAluno com maior média geral: %s", alunos[alunoMaiorMedia].nome);
    printf("\nAluno com menor média geral: %s", alunos[alunoMenorMedia].nome);

    // Verifica se o aluno foi aprovado ou reprovado (nota mínima 7)
    for (int i = 0; i < 5; i++) {
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
        if (media >= 7) {
            printf("\nAluno %s foi aprovado!", alunos[i].nome);
        } else {
            printf("\nAluno %s foi reprovado!", alunos[i].nome);
        }
    }

    return 0;  // Finaliza o programa
}
