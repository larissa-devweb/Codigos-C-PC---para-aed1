#include <stdio.h>
#include <stdlib.h>

struct Horario {
    int hora;
    int minuto;
    int seg;
};

void salvarHorarios(int memoria) {
    int i;
    FILE *arquivo;

    // Aloca��o din�mica para o n�mero de hor�rios especificado
    struct Horario *horario = (struct Horario *) malloc(sizeof(struct Horario) * memoria);
    if (horario == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    // Preenche os dados de cada hor�rio
    for (i = 0; i < memoria; i++) {
        printf("\nDados do Horario %d:\n", i + 1);

        printf("Diga a hora: ");
        scanf("%d", &horario[i].hora);

        printf("Diga o minuto: ");
        scanf("%d", &horario[i].minuto);

        printf("Diga o segundo: ");
        scanf("%d", &horario[i].seg);
    }

    // Abre o arquivo para escrita (modo "w" cria ou sobrescreve o arquivo)
    arquivo = fopen("horarios.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        free(horario); // Libera a mem�ria alocada
        return;
    }

    // Salva os hor�rios no arquivo
    for (i = 0; i < memoria; i++) {
        fprintf(arquivo, "Horario %d: %02d:%02d:%02d\n", i + 1, horario[i].hora, horario[i].minuto, horario[i].seg);
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Exibe uma mensagem de sucesso
    printf("\nHorarios salvos no arquivo 'horarios.txt'!\n");

    // Libera a mem�ria alocada
    free(horario);
}

void lerHorarios() {
    FILE *arquivo;
    char linha[100];

    // Abre o arquivo para leitura (modo "r")
    arquivo = fopen("horarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    // Exibe os hor�rios salvos no arquivo
    printf("\nHorarios salvos:\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    // Fecha o arquivo
    fclose(arquivo);
}

int main() {
    int opcao, memoria;

    while (1) {
        // Menu de op��es
        printf("\nEscolha uma opcao:\n");
        printf("1 - Salvar horarios\n");
        printf("2 - Ler horarios salvos\n");
        printf("3 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Salvar hor�rios
                printf("Quantos horarios quer guardar? ");
                scanf("%d", &memoria);
                salvarHorarios(memoria);
                break;

            case 2:
                // Ler hor�rios salvos
                lerHorarios();
                break;

            case 3:
                // Sair do programa
                printf("Saindo...\n");
                return 0;

            default:
                // Op��o inv�lida
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}
