#include <stdio.h>      // Biblioteca para entrada/sa�da (printf, scanf, etc.)
#include <string.h>     // Biblioteca para manipula��o de strings (strcpy, strcat, etc.)
#include <stdlib.h>     // Biblioteca para aloca��o de mem�ria (malloc, free)

// Vari�veis globais
char *lista_nomes = NULL;  // Ponteiro para armazenar todos os nomes em uma �nica string
int total_nomes = 0;       // Contador de quantos nomes est�o armazenados
int tamanho;               // Capacidade m�xima de nomes que podem ser armazenados

// Prot�tipos das fun��es
void adicionar_nome();     // Declara��o da fun��o para adicionar nomes
void listar_nomes();       // Declara��o da fun��o para listar nomes

int main() {
    // Pede ao usu�rio a quantidade m�xima de nomes
    printf("Quantos nomes deseja armazenar? ");
    scanf("%d", &tamanho);
    getchar();  // Limpa o buffer do teclado

    // Verifica se o tamanho � v�lido
    if (tamanho <= 0) {
        printf("N�o pode numero abaixo de zero!\n");
        return 1;  // Termina o programa com erro
    }

    // Aloca mem�ria para armazenar os nomes
    lista_nomes = (char *)malloc(sizeof(char) * tamanho);
    lista_nomes[0] = '\0';  // Inicializa a string vazia

    int opcao = 0;  // Vari�vel para armazenar a op��o do menu

    // Loop principal do programa
    while (opcao != 4) {
        // Mostra o menu
        printf("\nMENU PRINCIPAL\n");
        printf("1 - Adicionar nome\n");
        printf("2 - Remover nome\n");
        printf("3 - Listar nomes\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();  // Limpa o buffer do teclado

        // Executa a a��o conforme a op��o escolhida
        if (opcao == 1) {
            adicionar_nome();
        }
        else if (opcao == 2) {
            remover_nome();  // Nota: Esta fun��o n�o est� implementada no c�digo
        }
        else if (opcao == 3) {
            listar_nomes();
        }
        else if (opcao == 4) {
            printf("Saindo.");
        }
        else {
            printf("Invalida!\n");  // Op��o inv�lida
        }
    }

    // Libera a mem�ria alocada antes de terminar o programa
    free(lista_nomes);
    return 0;  // Programa terminado com sucesso
}

void adicionar_nome() {
    // Verifica se ainda h� espa�o para mais nomes
    if (total_nomes >= tamanho) {
        printf("Limite maximo de %d nomes alcan�ado!\n", tamanho);
        return;
    }

    char nome[100];  // Buffer para ler o nome
    printf("Digite o nome: ");
    fgets(nome, 100, stdin);  // L� o nome do teclado

    // Se for o primeiro nome, copia diretamente
    if (total_nomes == 0) {
        strcpy(lista_nomes, nome);
    }
    else {
        // Se n�o for o primeiro, adiciona um espa�o e depois o nome
        strcat(lista_nomes, " ");  // Adiciona espa�o como separador
        strcat(lista_nomes, nome); // Adiciona o novo nome
    }

    total_nomes++;  // Incrementa o contador de nomes
    printf("Nome adicionado! (%d/%d)\n", total_nomes, tamanho);
}

void listar_nomes() {
    // Verifica se h� nomes para listar
    if (total_nomes == 0) {
        printf("Nenhum nome cadastrado.\n");
        return;
    }

    printf("Nomes cadastrados (%d/%d):\n", total_nomes, tamanho);

    // Cria uma c�pia tempor�ria porque strtok modifica a string original
    char temp[tamanho * 100];  // Buffer tempor�rio
    strcpy(temp, lista_nomes);  // Copia os nomes para o buffer

    // Separa os nomes (que est�o divididos por espa�os)
    char *nome = strtok(temp, " ");  // Pega o primeiro nome
    while (nome != NULL) {
        printf("- %s\n", nome);      // Imprime o nome
        nome = strtok(NULL, " ");    // Pega o pr�ximo nome
    }
}
void remover_nome() {
    if (total_nomes == 0) {
        printf("Nenhum nome cadastrado para remover.\n");
        return;
    }

    // Mostra quantos nomes existem
    printf("Existem %d nomes cadastrados.\n", total_nomes);

    // Pede diretamente o n�mero do nome a remover
    printf("Digite o n�mero do nome a remover (1 a %d): ", total_nomes);
    int num;
    scanf("%d", &num);
    getchar();

    if (num < 1 || num > total_nomes) {
        printf("N�mero inv�lido!\n");
        return;
    }

    // Encontra a posi��o do nome na string
    char *ptr = lista_nomes;
    int atual = 1;

    // Pula os nomes at� chegar no que queremos remover
    while (atual < num && *ptr != '\0') {
        if (*ptr == ' ') {
            atual++;
        }
        ptr++;
    }

    // Marca onde come�a o nome a remover
    char *inicio_remocao = ptr;

    // Encontra onde termina o nome
    while (*ptr != ' ' && *ptr != '\0') {
        ptr++;
    }

    // Remove o nome
    if (*ptr == ' ') {
        strcpy(inicio_remocao, ptr + 1);  // Copia tudo depois do espa�o
    } else {
        *inicio_remocao = '\0';  // Se for o �ltimo nome, termina a string
    }

    total_nomes--;
    printf("Nome removido com sucesso!\n");
}
