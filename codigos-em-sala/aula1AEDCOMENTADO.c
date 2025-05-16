#include <stdio.h>      // Biblioteca para entrada/saída (printf, scanf, etc.)
#include <string.h>     // Biblioteca para manipulação de strings (strcpy, strcat, etc.)
#include <stdlib.h>     // Biblioteca para alocação de memória (malloc, free)

// Variáveis globais
char *lista_nomes = NULL;  // Ponteiro para armazenar todos os nomes em uma única string
int total_nomes = 0;       // Contador de quantos nomes estão armazenados
int tamanho;               // Capacidade máxima de nomes que podem ser armazenados

// Protótipos das funções
void adicionar_nome();     // Declaração da função para adicionar nomes
void listar_nomes();       // Declaração da função para listar nomes

int main() {
    // Pede ao usuário a quantidade máxima de nomes
    printf("Quantos nomes deseja armazenar? ");
    scanf("%d", &tamanho);
    getchar();  // Limpa o buffer do teclado

    // Verifica se o tamanho é válido
    if (tamanho <= 0) {
        printf("Não pode numero abaixo de zero!\n");
        return 1;  // Termina o programa com erro
    }

    // Aloca memória para armazenar os nomes
    lista_nomes = (char *)malloc(sizeof(char) * tamanho);
    lista_nomes[0] = '\0';  // Inicializa a string vazia

    int opcao = 0;  // Variável para armazenar a opção do menu

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

        // Executa a ação conforme a opção escolhida
        if (opcao == 1) {
            adicionar_nome();
        }
        else if (opcao == 2) {
            remover_nome();  // Nota: Esta função não está implementada no código
        }
        else if (opcao == 3) {
            listar_nomes();
        }
        else if (opcao == 4) {
            printf("Saindo.");
        }
        else {
            printf("Invalida!\n");  // Opção inválida
        }
    }

    // Libera a memória alocada antes de terminar o programa
    free(lista_nomes);
    return 0;  // Programa terminado com sucesso
}

void adicionar_nome() {
    // Verifica se ainda há espaço para mais nomes
    if (total_nomes >= tamanho) {
        printf("Limite maximo de %d nomes alcançado!\n", tamanho);
        return;
    }

    char nome[100];  // Buffer para ler o nome
    printf("Digite o nome: ");
    fgets(nome, 100, stdin);  // Lê o nome do teclado

    // Se for o primeiro nome, copia diretamente
    if (total_nomes == 0) {
        strcpy(lista_nomes, nome);
    }
    else {
        // Se não for o primeiro, adiciona um espaço e depois o nome
        strcat(lista_nomes, " ");  // Adiciona espaço como separador
        strcat(lista_nomes, nome); // Adiciona o novo nome
    }

    total_nomes++;  // Incrementa o contador de nomes
    printf("Nome adicionado! (%d/%d)\n", total_nomes, tamanho);
}

void listar_nomes() {
    // Verifica se há nomes para listar
    if (total_nomes == 0) {
        printf("Nenhum nome cadastrado.\n");
        return;
    }

    printf("Nomes cadastrados (%d/%d):\n", total_nomes, tamanho);

    // Cria uma cópia temporária porque strtok modifica a string original
    char temp[tamanho * 100];  // Buffer temporário
    strcpy(temp, lista_nomes);  // Copia os nomes para o buffer

    // Separa os nomes (que estão divididos por espaços)
    char *nome = strtok(temp, " ");  // Pega o primeiro nome
    while (nome != NULL) {
        printf("- %s\n", nome);      // Imprime o nome
        nome = strtok(NULL, " ");    // Pega o próximo nome
    }
}
void remover_nome() {
    if (total_nomes == 0) {
        printf("Nenhum nome cadastrado para remover.\n");
        return;
    }

    // Mostra quantos nomes existem
    printf("Existem %d nomes cadastrados.\n", total_nomes);

    // Pede diretamente o número do nome a remover
    printf("Digite o número do nome a remover (1 a %d): ", total_nomes);
    int num;
    scanf("%d", &num);
    getchar();

    if (num < 1 || num > total_nomes) {
        printf("Número inválido!\n");
        return;
    }

    // Encontra a posição do nome na string
    char *ptr = lista_nomes;
    int atual = 1;

    // Pula os nomes até chegar no que queremos remover
    while (atual < num && *ptr != '\0') {
        if (*ptr == ' ') {
            atual++;
        }
        ptr++;
    }

    // Marca onde começa o nome a remover
    char *inicio_remocao = ptr;

    // Encontra onde termina o nome
    while (*ptr != ' ' && *ptr != '\0') {
        ptr++;
    }

    // Remove o nome
    if (*ptr == ' ') {
        strcpy(inicio_remocao, ptr + 1);  // Copia tudo depois do espaço
    } else {
        *inicio_remocao = '\0';  // Se for o último nome, termina a string
    }

    total_nomes--;
    printf("Nome removido com sucesso!\n");
}
