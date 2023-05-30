/* Solicitar al usuario el ingreso de una cadena de caracteres que puede contener solamente
caracteres alfabéticos, luego presentarla por pantalla. Realizar el ingreso usando scanf() con las
opciones de juego de inspección. */

#include <stdio.h>

#define MAX 50

int main(int argc, char *argv[]) {
    char alfa[MAX];

    printf("\nIngresar caracteres alfabéticos: ");
    scanf("%[a-z A-Z]s", alfa);

    printf("\nLa cadena ingresada es: %s\n", alfa);

    return 0;
}