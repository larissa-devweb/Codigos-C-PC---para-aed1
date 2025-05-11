#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
    float peso;
    float altura;
};

// Função para preencher os dados de uma pessoa (por referência)
void preencherPessoa(struct Pessoa *pessoa, int indice) {

    printf("\nInforme o nome da pessoa %d: ", indice + 1);
    fgets(pessoa->nome, sizeof(pessoa->nome), stdin);

    printf("Informe a idade de %s: ", pessoa->nome);
    scanf("%d", &pessoa->idade);

    printf("Informe o peso de %s: ", pessoa->nome);
    scanf("%f", &pessoa->peso);

    printf("Informe a altura de %s: ", pessoa->nome);
    scanf("%f", &pessoa->altura);
    getchar();
}

// Função para exibir os dados de uma pessoa (por referência)
void exibirPessoa( struct Pessoa *pessoa) {
    printf("\nNome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Peso: %.2f\n", pessoa->peso);
    printf("Altura: %.2f\n", pessoa->altura);
}

int main() {
    int tamanho;
    FILE *arquivo;

    printf("Quantas pessoas quer guardar? ");
    scanf("%d", &tamanho);
    getchar();

    struct Pessoa *pessoas = (struct Pessoa *) malloc(sizeof(struct Pessoa) * tamanho);
    if (pessoas == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
// Preenche os dados de cada pessoa usando a função por referência
    for (int i = 0; i < tamanho; i++) {
        preencherPessoa(pessoas, i);
    }

    arquivo = fopen("informacoes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        free(pessoas);
        return 1;
    }

// Salva os dados das pessoas no arquivo
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "Pessoa %d\n", i + 1);
        fprintf(arquivo, "Nome: %s\n", pessoas[i].nome);
        fprintf(arquivo, "Idade: %d\n", pessoas[i].idade);
        fprintf(arquivo, "Peso: %.2f\n", pessoas[i].peso);
        fprintf(arquivo, "Altura: %.2f\n\n", pessoas[i].altura);
    }

    fclose(arquivo);

    printf("\nDados das pessoas:\n");
    for (int i = 0; i < tamanho; i++) {
        exibirPessoa(&pessoas[i]);
    }
    free(pessoas);

    return 0;
}
