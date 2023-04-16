/* Generar N números aleatorios e indicar la cantidad de números pares e impares. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int N, contador_pares = 0, contador_impares = 0, numero;
    time_t t;  // declaro la variable de tipo time_t definida en stdlib.h

    srand((unsigned)time(&t));

    do {
        printf("\nCantidad de números aleatorios a evaluar: ");
        scanf("%i", &N);
    } while (N <= 0);

    for (int i = 0; i < N; i++) {
        numero = rand() % 1000;

        printf("\n%i\n", numero);
        if (numero % 2 == 0)
            contador_pares++;
        else
            contador_impares++;
    }

    printf("\nCantidad pares: %i \nCantidad impares: %i\n\n", contador_pares, contador_impares);

    return 0;
}