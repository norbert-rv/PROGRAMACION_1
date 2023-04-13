/* Diseñar un programa que permita ingresar un número entero positivo de 2 o más
dígitos (realizar el control). Determinar la suma de los dígitos del número que sean
impares. Presentar por pantalla el resultado en el programa principal */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num, suma_impares = 0;

    do {
        printf("Ingresar un número entero positivo de 2 o más digitos: ");
        scanf("%i", &num);
    } while (num <= 9);

    while (num != 0) {
        if (num % 10 % 2 != 0) {
            suma_impares += num % 10;
        }
        num /= 10;
    }

    printf("La suma de los digitos impares es: %i.\n", suma_impares);

    return 0;
}