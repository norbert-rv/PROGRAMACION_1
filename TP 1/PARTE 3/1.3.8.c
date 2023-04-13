/* Ingresar un número entero positivo (realizar este control), luego presentar por pantalla
la cantidad de dígitos que posee dicho número. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num, numero_digitos = 0;

    do {
        printf("Ingresar un número entero positivo: ");
        scanf("%i", &num);

    } while (num <= 0);

    while (num > 0) {
        numero_digitos++;
        num /= 10;
    }

    printf("El número de dígitos es: %i.\n", numero_digitos);

    return 0;
}