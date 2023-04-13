/* Se ingresan N números enteros. Determinar el mayor y el menor de los valores
ingresados Ejemplo: N = 7, Se ingresan: -12, 5, -8, 30, 0, -20, 15 Mayor valor:30 Menor valor: -20. Controlar que el valor de N sea positivo.*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    int N, num, mayor = 0, menor = 0;
    int i = 0;

    do {
        printf("Ingresar la cantidad de números enteros: ");
        scanf("%i", &N);

    } while (N <= 0);

    for (int i = 0; i < N; i++) {
        printf("Ingresar un número: ");
        scanf("%i", &num);

        if (num > mayor) mayor = num;
        if (num < menor) menor = num;
    }

    printf("El mayor de los números ingresados es %i.\nEl menor de los números ingresados es %i.\n", mayor, menor);

    return 0;
}