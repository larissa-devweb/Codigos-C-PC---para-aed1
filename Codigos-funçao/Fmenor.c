// Online C compiler to run C program online
#include <stdio.h>
int menor(int a, int b);
int main() {

   int n1,n2;
    printf("Digite dois n�meros: ");
    scanf("%d %d", &n1, &n2);
    printf("menor �: %d", menor(n1,n2));

    return 0;
}
int menor(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
