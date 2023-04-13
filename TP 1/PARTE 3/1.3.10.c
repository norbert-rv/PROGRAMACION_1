/* Ingresar un número entero positivo (Controlar que el valor sea positivo) e indicar si es
primo o no. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num, divisores = 0;

    do {
        printf("Ingresar un número entero positivo: ");
        scanf("%i", &num);
    } while (num <= 0);

    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            divisores++;
        }
    }

    if (divisores == 2) {
        printf("%i es PRIMO.\n", num);
    } else {
        printf("%i NO ES PRIMO.\n", num);
    }

    return 0;
}