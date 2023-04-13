/* Ingresar un número, luego presentar por pantalla el factorial del mismo. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num, factorial = 1;
    int aux;

    printf("Ingresar un número: ");
    scanf("%i", &num);

    aux = num;

    while (num != 0) {
        factorial *= num;
        num--;
    }

    printf("El factorial es %i! = %i.\n", aux, factorial);

    return 0;
}