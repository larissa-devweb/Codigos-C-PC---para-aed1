#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *entrada, *saida;
    char turma[50];
    int numAlunos, aprovados = 0, notas10 = 0;
    float nota, somaNotas = 0;

    // Abrindo o arquivo de entrada e de saída
    entrada = fopen("registro_alunos.txt", "r");
    saida = fopen("resumo_turmas.txt", "w");

    // Verificando se os arquivos foram abertos corretamente
    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    // Lendo os dados de cada turma
    while (fscanf(entrada, "%s %d", turma, &numAlunos) == 2) {
        somaNotas = 0;
        aprovados = 0;
        notas10 = 0;

        // Lendo as notas dos alunos
        for (int i = 0; i < numAlunos; i++) {
            fscanf(entrada, "%f", &nota);
            somaNotas += nota;

            // Verifica se o aluno foi aprovado (nota >= 7)
            if (nota >= 7) aprovados++;

            // Verifica se o aluno tirou nota 10
            if (nota == 10) notas10++;
        }

        // Calculando a média da turma
        float media = somaNotas / numAlunos;

        // Escrevendo os resultados no arquivo de saída
        fprintf(saida, "Turma: %s\n", turma);
        fprintf(saida, "Média: %.2f\n", media);
        fprintf(saida, "Aprovados: %d\n", aprovados);
        fprintf(saida, "Notas 10: %d\n\n", notas10);
    }

    // Fechando os arquivos
    fclose(entrada);
    fclose(saida);

    printf("Resumo das turmas gerado no arquivo resumo_turmas.txt.\n");

    return 0;
}
