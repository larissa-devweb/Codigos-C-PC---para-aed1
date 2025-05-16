#include <stdio.h>

int main() {
    int num, multiplo;

    printf("Digite um número: ");
    scanf("%d", &num);

    multiplo = num * 2; // Começa do primeiro múltiplo maior que o número

    while (1) {
        printf("%d ", multiplo);
        multiplo += num; // Próximo múltiplo
    }

    return 0;
}
#include <stdio.h>

int ehmultiplo(int n1, int n2) {
     if (n2 == 0) return 0;
    return (n1 % n2 == 0);
}

int main() {
    int n1, n2;

    while (1) {
        printf("Digite o primeiro número (-1 para sair): ");
        scanf("%d", &n1);

        if (n1 == -1) {
            break;
        }

        printf("Digite o segundo número (-1 para sair): ");
        scanf("%d", &n2);

        if (n2 == -1) {
            break;
        }

        //resultado = ehmultiplo(n1, n2);

        if (ehmultiplo(n1, n2)) {
            printf("%d é múltiplo de %d\n", n1, n2);
        } else {
            printf("%d não é múltiplo de %d\n", n1, n2);
        }
    }

    return 0;
}

