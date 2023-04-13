/*Codificar un programa en el que se solicita el ingreso de un carácter, luego presentar por
pantalla un mensaje que indique si dicho carácter es un dígito, una letra del alfabeto en
mayúscula, una letra del alfabeto en minúscula o de otro tipo de carácter */

#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char caracter;

    printf("\nIngresar un caracter: ");
    caracter = getchar();
    fgetc(stdin);

    if (isdigit(caracter))
        printf("\nEl caracter ingresado es un dígito.\n\n");
    else if (isalpha(caracter) && isupper(caracter))
        printf("\nEl caracter ingresado es una letra del alfabeto mayúscula.\n\n");
    else if (isalpha(caracter) && islower(caracter))
        printf("\nEl caracter ingresado es una letra del alfabeto minúsula.\n\n");
    else
        printf("\nEl caracter ingresado es de otro tipo.\n\n");

    return 0;
}