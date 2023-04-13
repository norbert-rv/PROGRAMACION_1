/* Ingresar N caracteres, luego presentar por pantalla la cantidad de vocales. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int N_caracteres, cant_vocales = 0;
    char caracter;

    do {
        printf("Número de caracteres a ingresar: ");
        scanf("%i", &N_caracteres);
    } while (N_caracteres <= 0);

    while (fgetc(stdin) != '\n')
        ;

    for (int i = 0; i < N_caracteres; i++) {
        printf("Ingresar un caracter: ");
        scanf("%c", &caracter);
        if (caracter == 'a' || caracter == 'A' || caracter == 'e' || caracter == 'E' || caracter == 'i' || caracter == 'I' || caracter == 'o' || caracter == 'O' || caracter == 'u' || caracter == 'U') {
            cant_vocales++;
        }
        while (fgetc(stdin) != '\n')
            ;
    }

    printf("La cantidad de vocales es %i.\n", cant_vocales);

    return 0;
}