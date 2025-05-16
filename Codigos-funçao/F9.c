#include <stdio.h>

// Fun��o para calcular pot�ncia (base^expoente)
int potencia(int base, int expoente) {
    int resultado = 1; // Come�amos com 1

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
// Verifica se o expoente � negativo
    if (exp < 0) {
        printf("Expoente negativo n�o suportado com inteiros.\n");
    } else {
        // Chama a fun��o e exibe o resultado
        printf("%d elevado a %d � %d\n", base, exp, potencia(base, exp));
    }

    return 0;
}
