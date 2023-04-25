/* Codificar un programa en el que se solicita el ingreso de N carácteres, luego presentar por
pantalla las consonantes ingresadas en minúscula y las vocales en mayúscula.
Para resolver este ejercicio deberá implementar:
a- función para controlar si el número N es un entero positivo.
b-función para solicitar el ingreso de los caracteres, evaluarlos y presentarlos por
pantalla (las vocales en mayúscula y las consonantes en minúscula) */

#include <ctype.h>
#include <stdio.h>

int es_entero_positivo(int);
void ingreso_evaluacion_caracteres();  // funcion que pide el ingreso de un caracter, lo evalua según las condiciones y lo presenta por pantalla.

int main(int argc, char *argv[]) {
    int N, contador_pantalla = 1;
    do {
        printf("\nIngrese el número N de caracteres a cargar: ");
        scanf("%i", &N);

        if (!es_entero_positivo(N))
            printf("\n> Ingresar un número entero positivo! <\n");
    } while (!es_entero_positivo(N));

    for (int i = 0; i < N; i++) {
        printf("\nCaracter %i...\n", contador_pantalla);
        ingreso_evaluacion_caracteres();
        contador_pantalla++;
    }

    printf("\n\nEl programa finalizó.\n\n");

    return 0;
}

int es_entero_positivo(int num) {
    if (num > 0)
        return 1;
    else
        return 0;
}

void ingreso_evaluacion_caracteres() {
    char car;

    while (fgetc(stdin) != '\n')
        ;

    printf("\nIngrese un caracter: ");
    car = getchar();

    if (isalpha(car)) {
        car = tolower(car);
        if (car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u') {
            car = toupper(car);
            printf("\n>> %c\n", car);
        } else
            printf("\n>> %c\n", car);
    } else
        printf("\nEl caracter ingresado no es alfabético...\n");
}