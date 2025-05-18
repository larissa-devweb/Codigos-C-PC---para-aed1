//1. Two Sum (Soma de Dois Números) - Problema #1
//Problema: Dado um array de números inteiros e um alvo, retorne os índices dos dois números que somados resultam no alvo.
/*O problema Two Sum essencialmente requer o uso de vetor/matriz para armazenar e acessar múltiplos valores. Sem isso,
 não há como comparar os diferentes pares de números da entrada. A segunda versão mostra a solução mínima viável em C.*/
 #include <stdio.h>

// Função básica que soma dois números
int soma(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    // Chama a função soma e mostra o resultado
    int resultado = soma(num1, num2);
    printf("A soma é: %d\n", resultado);

    return 0;
}
