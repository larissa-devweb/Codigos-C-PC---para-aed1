#include <stdio.h>

int main() {
    int num, multiplo;

    printf("Digite um n�mero: ");
    scanf("%d", &num);

    multiplo = num * 2; // Come�a do primeiro m�ltiplo maior que o n�mero

    while (1) {
        printf("%d ", multiplo);
        multiplo += num; // Pr�ximo m�ltiplo
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
        printf("Digite o primeiro n�mero (-1 para sair): ");
        scanf("%d", &n1);

        if (n1 == -1) {
            break;
        }

        printf("Digite o segundo n�mero (-1 para sair): ");
        scanf("%d", &n2);

        if (n2 == -1) {
            break;
        }

        //resultado = ehmultiplo(n1, n2);

        if (ehmultiplo(n1, n2)) {
            printf("%d � m�ltiplo de %d\n", n1, n2);
        } else {
            printf("%d n�o � m�ltiplo de %d\n", n1, n2);
        }
    }

    return 0;
}

