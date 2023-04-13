/* Ingresar números, hasta que se ingrese un valor igual a cero, luego presentar por pantalla la
cantidad de números ingresados. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num, contador = 0;

    do {
        printf("Ingresar un número: ");
        scanf("%i", &num);
        if (num != 0) contador++;
    } while (num != 0);

    printf("La cantidad de números ingresados es %i.\n", contador);

    return 0;
}