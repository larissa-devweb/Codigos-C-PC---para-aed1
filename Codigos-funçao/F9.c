#include <stdio.h>

// Função para calcular potência (base^expoente)
int potencia(int base, int expoente) {
    int resultado = 1; // Começamos com 1

    for (int i = 0; i < expoente; i++) { // Repetimos expoente vezes
        resultado *= base; // Multiplicamos o resultado pela base
    }

    return resultado; // Retornamos o valor final
}

int main() {
    int base, exp;

    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &exp);
// Verifica se o expoente é negativo
    if (exp < 0) {
        printf("Expoente negativo não suportado com inteiros.\n");
    } else {
        // Chama a função e exibe o resultado
        printf("%d elevado a %d é %d\n", base, exp, potencia(base, exp));
    }

    return 0;
}
