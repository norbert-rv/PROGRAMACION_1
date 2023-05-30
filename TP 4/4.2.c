/* Solicitar al usuario el ingreso de una cadena de caracteres que puede contener solamente los
dígitos 0-9, luego presentarla por pantalla. Realizar el ingreso usando scanf() con las opciones de
juego de inspección. */

#include <stdio.h>

#define MAX 50

int main(int argc, char *argv[]) {
    char digitos[MAX];

    printf("\nIngresar una cadena de números: ");
    scanf("%[0-9 ]s", digitos);  // se detiene cuando ingreso un caracter que no sea uno de esos (no toma lo que sigue)

    printf("\nLa cadena de números ingresada es: %s\n\n", digitos);

    return 0;
}