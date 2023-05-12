/* Dado un arreglo de orden N, realizar un programa que permita ingresar números enteros a dicho
arreglo. Controlar que la cantidad de elementos ingresados no supere el orden permitido del
arreglo. Luego contar los elementos del arreglo que sean mayores a un número entero ingresado
por teclado. Finalmente, mostrar por pantalla el arreglo ingresado, el número ingresado y la
cantidad de elementos del arreglo que son mayores al número ingresado. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int N, numero_referencia, contadorMayores = 0;

    do {
        printf("\nIngresar el orden del arreglo: ");
        scanf("%i", &N);

        if (N <= 0)
            printf("\n>> El orden debe ser mayor que 0!\n");
    } while (N <= 0);

    int numerosEnteros[N];

    printf("\nIngresar el número a comparar con los elementos del arreglo: ");
    scanf("%i", &numero_referencia);

    for (int i = 0; i < N; i++) {
        printf("\nIngresar elemento %i: ", i + 1);
        scanf("%i", &numerosEnteros[i]);

        if (numerosEnteros[i] > numero_referencia)
            contadorMayores++;
    }

    printf("\n> El arreglo ingresado es: ");
    for (int i = 0; i < N; i++) {
        printf("%i  ", numerosEnteros[i]);
    }
    printf("\n> El número ingresado para comparar es el %i ", numero_referencia);
    printf("\n> La cantidad de elementos mayores a dicho número es de %i \n\n", contadorMayores);

    return 0;
}