/* Codificar un programa en el que se solicita el ingreso de un carácter, luego presentar por pantalla
un mensaje que indique si dicho carácter es un dígito, una letra del alfabeto en mayúscula, una
letra del alfabeto en minúscula o de otro tipo de carácter. Para resolver deberá implementar:
a- una función para ingresar el carácter
b-una función para mostrar por pantalla qué tipo de carácter es (esta función no es
necesario que retorne valor)
*/

#include <ctype.h>
#include <stdio.h>

char pedir_caracter();
void tipo_caracter(char);

int main(int argc, char *argv[]) {
    char caracter;

    caracter = pedir_caracter ();
    tipo_caracter (caracter);

    return 0;
}

char pedir_caracter() {
    char car;
    printf("\nIngrese un caracter: ");
    car = getchar();

    return car;
}

void tipo_caracter(char car) {
    if (isdigit(car))
        printf("\n> El caracter ingresado es un digito.\n\n");
    else if (isalpha(car))
        if (car == toupper(car))
            printf("\n> El caracter ingresado es una letra del alfabeto en mayúscula.\n\n");
        else
            printf("\n> El caracter ingresado es una letra del alfabeto en minúscula.\n\n");
    else
        printf("\n> El caracter ingresado es de otro tipo de dato.\n\n");
}