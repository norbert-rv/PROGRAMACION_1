/* 1. Ingresar dos números reales, luego presentar por pantalla el valor de la suma y el producto
de los números ingresados. (Resuelto) */

#include <stdio.h>

int main(int argc, char *argv[]) {
    float numero1, numero2, suma, producto;

    printf("Ingresar número 1: ");
    scanf("%f", &numero1);
    printf("Ingresar número 2: ");
    scanf("%f", &numero2);

    suma = numero1 + numero2;
    producto = numero1 * numero2;

    printf("La suma es %.2f.\nEl producto es %.2f.\n", suma, producto);

    return 0;
}