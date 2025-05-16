/*.
.*/
#include <stdio.h>

int ehPositivo( int a ){
    return a >=0;

}

int main() {

    int num1;

    printf ("digite 1 numeros: ");
    scanf ("%d", &num1);

    if (num1 >=0 ){
        printf (" %d é positivo.",num1);
    } else {
        printf ("neg");
    }
    return 0;
}
