//1. Two Sum (Soma de Dois N�meros) - Problema #1
//Problema: Dado um array de n�meros inteiros e um alvo, retorne os �ndices dos dois n�meros que somados resultam no alvo.
/*O problema Two Sum essencialmente requer o uso de vetor/matriz para armazenar e acessar m�ltiplos valores. Sem isso,
 n�o h� como comparar os diferentes pares de n�meros da entrada. A segunda vers�o mostra a solu��o m�nima vi�vel em C.*/
 #include <stdio.h>

// Fun��o b�sica que soma dois n�meros
int soma(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;

    printf("Digite o primeiro n�mero: ");
    scanf("%d", &num1);

    printf("Digite o segundo n�mero: ");
    scanf("%d", &num2);

    // Chama a fun��o soma e mostra o resultado
    int resultado = soma(num1, num2);
    printf("A soma �: %d\n", resultado);

    return 0;
}
