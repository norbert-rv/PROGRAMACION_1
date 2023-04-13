/* Codificar un programa en el que se solicita el ingreso de un carácter alfabético, luego
presentar por pantalla el carácter en mayúscula si el mismo fue ingresado en minúscula
y viceversa. */

#include <ctype.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char caracter;

    do {
        printf("Ingresar un caracter: ");
        caracter = fgetc(stdin);
        while (fgetc(stdin) != '\n')
            ;
    } while (!isalpha(caracter));

    if (islower(caracter))
        printf("%c\n", toupper(caracter));
    else
        printf("%c\n", tolower(caracter));

    return 0;
}