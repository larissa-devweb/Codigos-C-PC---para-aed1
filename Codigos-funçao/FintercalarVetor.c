#include <stdio.h>

// Função para intercalar dois vetores de 10 elementos cada
void intercalarVetores(int v1[], int v2[], int resultado[]) {
    int i, j = 0;

    // Intercalação dos vetores
    for (i = 0; i < 10; i++) {
        resultado[j++] = v1[i];
        resultado[j++] = v2[i];
    }
}

int main() {
    int vetor1[10], vetor2[10], intercalado[20];
    int i;

    // Leitura do primeiro vetor
    for (i = 0; i < 10; i++) {
        printf("Digite o valor para vetor1[%d]: ", i);
        scanf("%d", &vetor1[i]);
    }

    // Leitura do segundo vetor
    for (i = 0; i < 10; i++) {
        printf("Digite o valor para vetor2[%d]: ", i);
        scanf("%d", &vetor2[i]);
    }

    // Chama a função para intercalar os vetores
    intercalarVetores(vetor1, vetor2, intercalado);

    // Exibe o vetor intercalado
    printf("Vetor intercalado:\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", intercalado[i]);
    }
    printf("\n");

    return 0;
}
