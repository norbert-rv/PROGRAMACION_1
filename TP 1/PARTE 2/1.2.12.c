/*  Presentar por pantalla los N primeros números impares positivos. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int N, i = 1;

    do {
        printf("Ingresar N: ");
        scanf("%i", &N);
    } while (N <= 0);

    N++;

    while (i != N) {
        if (i % 2 != 0)
            printf("%i\n", i);
        i++;
    }

    return 0;
}