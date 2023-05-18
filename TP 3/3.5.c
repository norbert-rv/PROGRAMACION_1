/* Dado un arreglo de orden N, realizar un programa que permita ingresar números enteros a dicho
arreglo. Controlar que la cantidad de elementos ingresados no supere el orden permitido del
arreglo. Luego mostrar por pantalla el arreglo ingresado, el valor del promedio de los elementos
ingresados, la cantidad de elementos ingresados que son mayores al promedio y la cantidad de
elementos ingresados que sean menores al promedio */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int numeros[100];
    int N, suma_elementos = 0, cant_mayores = 0, cant_menores = 0;
    float promedio;

    do {
        printf("\nIngresar el orden del arreglo: ");
        scanf("%i", &N);

        if (N <= 0 || N > 100)
            printf("\n> El orden debe estar entre 1 y 100! \n");
    } while (N <= 0 || N > 100);

        // ingreso elementos al arreglo y al mismo tiempo voy sumando los valores ingresados para sacar el promedio
    for (int i = 0; i < N; i++) {
        printf("\nIngresar número: ");
        scanf("%i", &numeros[i]);
        suma_elementos += numeros[i];
    }

    // muestro el arreglo con los elementos uno al lado del otro
    printf("\n> Arreglo 'numeros': ");
    for (int i = 0; i < N; i++) {
        printf("%i  ", numeros[i]);
    }

    promedio = suma_elementos / (N * 1.0);
    printf("\n\n> El promedio de los elementos es: %.2f\n", promedio);

    // hago el conteo de cuántos son mayores y cuántos menores que el promedio
    for (int i = 0; i < N; i++) {
        if (numeros[i] > promedio)
            cant_mayores++;
        if (numeros[i] < promedio)
            cant_menores++;
    }

    printf("\n> Cantidad de elementos mayores que el promedio: %i ", cant_mayores);
    printf("\n\n> Cantidad de elementos menores que el promedio: %i \n\n", cant_menores);

    return 0;
}