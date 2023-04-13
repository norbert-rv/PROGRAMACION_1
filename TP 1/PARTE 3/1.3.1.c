/* Leer un carácter por teclado y luego presentar por pantalla un mensaje con la siguiente
leyenda "El carácter es …(mostrar el carácter ingresado)". */

#include <stdio.h>

int main(int argc, char *argv[]) {
    char caracter;

    printf("Ingresar un caracter: ");
    scanf("%c", &caracter);
    printf("El caracter ingresado es %c.\n", caracter);
}