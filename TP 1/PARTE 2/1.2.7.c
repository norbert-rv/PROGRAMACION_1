/* Dado un número entero no negativo, presentar por pantalla un mensaje indicando si dicho
número es par o impar. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num;

    do {
        printf("Ingresar un número entero no negativo: ");
        scanf("%i", &num);
    } while (num < 0);

    if (num % 2 == 0)
        printf("Es par.\n");
    else
        printf("Es impar.\n");

    return 0;
}