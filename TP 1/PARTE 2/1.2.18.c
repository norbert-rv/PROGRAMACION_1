/* Se ingresan N valores numéricos. Se desea saber cuántos son positivos, cuántos son
negativos y cuantos iguales a cero. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int N, num, contador_cero = 0, contador_negativo = 0, contador_positivo = 0;
    int i = 1;

    do {
        printf("Cantidad de números a ingresar: ");
        scanf("%i", &N);
    } while (N <= 0);

    while (N > 0) {
        printf("Ingresar número %i: ", i);
        scanf("%i", &num);
        if (num > 0)
            contador_positivo++;
        else if (num < 0)
            contador_negativo++;
        else
            contador_cero++;

        N--;
        i++;
    }

    printf("Positivos: %i\nNegativos: %i\nIguales a cero: %i\n", contador_positivo, contador_negativo, contador_cero);

    return 0;
}