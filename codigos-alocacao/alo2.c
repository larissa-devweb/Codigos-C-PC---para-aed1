#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura para armazenar os dados dos registros
struct end {
    char nome[100];
    char rua[100];
    char cidade[100];
    char estado[100];
    unsigned long int cep;
};

struct end *reg = NULL;  // Ponteiro que vai armazenar os registros com base na STRUCT
   int memoria = 0;// Variável que vai armazenar o tamanho máximo da lista de registros. Tem de ficar aqui pois dentro do main da erro, ja que é usado em ourras funçoes

// Funções do programa
void insere(void);
void apaga(void);
void imprime(void);
int menu(void);
int livre(void);
void ler_string(char palavra[100], int tamanho);

int main() {
    int escolha;


    // Pergunta ao usuário o número máximo de registros
    printf("Digite o número máximo de registros: ");
    scanf("%d", &memoria);

    // Aloca dinamicamente a memória para 'memoria' registros do tipo struct end
    reg = (struct end *)malloc(memoria * sizeof(struct end));

    // Verifica se a alocação de memória foi bem-sucedida
    if (reg == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);  // Se falhar, o programa é encerrado
    }

    // Inicializa todos os registros com nome vazio. COloquei 0, mas acho que '\0' tambem taria certo.. por ser string. COmplicou
    for (int i = 0; i < memoria; i++) { //outra coisa, se tirar isso aqui, começa a aparecer um monte de MENU e nao para kkkk nao sei o motivo/o que fiz
        reg[i].nome[0] = 0;
    }

    // Laço principal do menu
    for (;;) {
        escolha = menu();  // Exibe o menu e obtém a escolha do usuário
        switch (escolha) {
        case 1:
            insere();  // Inserir um novo registro
            break;
        case 2:
            apaga();  // Excluir um registro
            break;
        case 3:
            imprime();  // Listar os registros
            break;
        case 4:
            free(reg);  // Libera a memória alocada
            exit(0);  // Sai do programa
            break;
        }
    }
    return 0;
}

// Função do menu que exibe as opções para o usuário
int menu(void) {
    int c = 0;
    do {
        printf("-- MENU:\n");
        printf("\t 1. Inserir um nome\n");
        printf("\t 2. Excluir um nome\n");
        printf("\t 3. Listar o arquivo\n");
        printf("\t 4. Sair\n");
        printf("-- Digite sua escolha: ");
        scanf("%d", &c);
    } while (c <= 0 || c > 4);  // Verifica se a escolha é válida
    getchar();  // Limpa o buffer de entrada
    return c;
}

// Função para ler uma string com segurança
void ler_string(char palavra[100], int tamanho) {
    int i = 0;
    char c;
    c = getchar();
    while ((c != '\n') && (i < tamanho)) {
        palavra[i++] = c;
        c = getchar();
    }
    palavra[i] = '\0';  // Adiciona o terminador de string

    // Limpeza do buffer caso o usuário tenha digitado mais do que o permitido
    if (c != '\n') {
        c = getchar();
        while ((c != '\n') && (c != EOF)) {
            c = getchar();
        }
    }
}

// Função que insere um novo registro na lista
void insere(void) {
    int posicao;

    posicao = livre();  // Obtém a primeira posição livre na lista
    if (posicao == -1) {
        printf("\nEstrutura Cheia!!\n");
        return;  // Se não houver espaço, exibe mensagem e retorna
    }

    // Solicita os dados do novo registro
    printf("-- Registro %d:\n", posicao);
    printf("\t Nome: ");
    ler_string(reg[posicao].nome, 100);
    printf("\t Rua: ");
    ler_string(reg[posicao].rua, 100);
    printf("\t Cidade: ");
    ler_string(reg[posicao].cidade, 100);
    printf("\t Estado: ");
    ler_string(reg[posicao].estado, 100);
    printf("\t CEP: ");
    scanf("%lu", &reg[posicao].cep);
}

// Função que retorna o índice da primeira posição livre
int livre(void) {
    for (int i = 0; i < memoria; i++) { //acrescenta memoria aqui
        if (reg[i].nome[0] == '\0') {
            return i;  // Retorna a posição livre
        }
    }
    return -1;  // Se não houver posições livres, retorna -1
}

// Função que apaga um registro (marca como vazio)
void apaga(void) {
    int posicao;
    printf("Número do Registro para excluir: ");
    scanf("%d", &posicao);

    // Verifica se a posição fornecida é válida
    if (posicao >= 0 && posicao < memoria) { //enquanto que posiçao for menor do tamanho da memoria dos registros/ quantos registros quis criar
        reg[posicao].nome[0] = '\0';  // Marca o nome como vazio, efetivamente apagando o registro
    } else {
        printf("Registro inválido.\n");
    }
}

void imprime(void) {
    for (int i = 0; i < memoria; i++) {
        if (reg[i].nome[0] != '\0') {  // Verifica se o registro não está vazio
            printf("-- Registro %d:\n", i);
            printf("\t Nome: %s", reg[i].nome);
            printf("\t Rua: %s", reg[i].rua);
            printf("\t Cidade: %s", reg[i].cidade);
            printf("\t Estado: %s\n", reg[i].estado);
            printf("\t CEP: %lu\n", reg[i].cep);
        }
    }
}
