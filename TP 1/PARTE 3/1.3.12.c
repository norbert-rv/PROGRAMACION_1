/* Diseñar un programa que permita el ingreso de dos números enteros positivos y
calcular el producto de dichos números utilizando el método de sumas sucesivas */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int numero1, numero2, producto = 0;

    do {
        printf("Ingresar dos números enteros positivos:\nNúmero 1: ");
        scanf("%i", &numero1);
        printf("Número 2: ");
        scanf("%i", &numero2);
    } while (numero1 <= 0 || numero2 <= 0);

    for (int i = 0; i < numero2; i++) {
        producto += numero1;
    }

    printf("El producto entre los números es: %i.\n", producto);

    return 0;
}