/* Solicitar al usuario el ingreso de un carácter y luego mostrarlo por pantalla. Realizar la
lectura y presentación por pantalla empleando las funciones: scanf, fgetc, getchar, printf, fputc y putchar */

#include <stdio.h>

int main(int argc, char *argv[]) {
    char caracter;

    printf("Por favor, ingresar un caracter:  ");
    caracter = getchar();  // no hace falta fgetc(stdin) porque getchar() toma un caracter y limpia el resto del buffer
    printf("\n");
    putchar(caracter);
    printf("\n\n");

    return 0;
}