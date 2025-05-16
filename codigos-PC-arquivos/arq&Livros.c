#include <stdio.h>

int main (){

        int i, tamanho, somaPag, nPag;
        char nome[100];
        float preco;
        FILE *arquivo;
        printf ("quantos livros? ");
        scanf ("%d", &tamanho);
        getchar();
        arquivo =fopen ("livro.txt", "w");
        if (arquivo== NULL){
            printf ("erro");
            exit(1);
        }
        for (i=0; i< tamanho; i++){
            printf("nome: ", i+1);
            fgets(nome, 100,stdin);
            printf("Número de páginas: ");
        scanf("%d", &nPag);
         somaPag+=nPag;

        printf("Preço: ");
        scanf("%f", &preco);
        getchar();
        fprintf(arquivo, "nome: %s\n", nome);
        fprintf(arquivo, "preco: %f", preco);
          fprintf(arquivo, "paginas: %d", nPag);

        }
        fclose(arquivo);
        int arquivo_lido;
        arquivo =fopen("livro.txt", "r");
        if (arquivo==NULL){
            printf("erro");
            exit(1);
        }
        for (i=0 ; i <arquivo_lido; i++){
         while (fgets(nome, 100, arquivo) && fscanf(arquivo, "%d %f", &nPag, &preco) == 2) {
        printf("Nome: %sNúmero de páginas: %d, Preço: R$ %.2f\n", nome, nPag, preco);
    }
        }
        fclose(arquivo);
        float media = (float)somaPag/tamanho;
        printf ("media: %.2f", media);


}
