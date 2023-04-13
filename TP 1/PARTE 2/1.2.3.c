/* Ingresar un número entero, luego presentar por pantalla un mensaje indicando si dicho
número es igual a cero, positivo o negativo. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num;

    printf("Ingresar un número entero: ");
    scanf("%i", &num);

    if (num > 0)
        printf("El número es positivo.\n");
    else if (num < 0)
        printf("El número es negativo.\n");
    else
        printf("El número es igual a 0.\n");

    return 0;
}