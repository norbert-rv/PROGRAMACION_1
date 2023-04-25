/* Codificar un programa en el que se solicita el ingreso de un carácter alfabético, luego presentar
por pantalla el carácter en mayúscula si el mismo fue ingresado en minúscula y viceversa. Para
resolver este ejercicio deberá implementar:
a- una función para ingresar el carácter y controlar que sea alfabético.
b- una función para devolver el carácter convertido
c-una función para mostrar por pantalla el caracter convertido(esta función no es
necesario que retorno valor) */

#include <ctype.h>
#include <stdio.h>

char pedir_caracter_alfa();
char convertir_minus_mayus(char);
void mostrar_caracter_convertido(char);

int main(int argc, char *argv[]) {
    char caracter;

    caracter = pedir_caracter_alfa();
    caracter = convertir_minus_mayus(caracter);
    mostrar_caracter_convertido(caracter);

    return 0;
}

char pedir_caracter_alfa() {
    char car;

    do {
        printf("\nIngresar un caracter: ");
        car = getchar();
        fgetc(stdin);

        if (!isalpha(car))
            printf("\n> El caracter debe ser alfabético! <\n");
    } while (!isalpha(car));

    return car;
}

char convertir_minus_mayus(char car) {
    if (isupper(car))
        car = tolower(car);
    else
        car = toupper(car);

    return car;
}

void mostrar_caracter_convertido(char car) {
    printf("\n> El caracter convertido es %c\n\n", car);
}