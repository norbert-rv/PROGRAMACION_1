#include <ctype.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char caracter;

    printf("Ingresar los caracteres separados por un espacio: ");  // lleno el buffer con los caracteres y los voy tomando de a uno (también funciona sin espacios)

    do {
        scanf("%c", &caracter);  // toma el siguiente caracter en el buffer

        // si es un caracter alfabetico y hago minuscula para el if
        caracter = tolower(caracter);
        if (isalpha(caracter)) {
            if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u')
                printf("%c   ", toupper(caracter));
            else
                printf("%c   ", tolower(caracter));
        }
    } while (caracter != '\n');  // caso final del enter

    printf("\n");

    return 0;
}