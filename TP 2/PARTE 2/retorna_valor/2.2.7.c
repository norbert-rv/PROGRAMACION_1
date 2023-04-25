/* Ingresar dos números enteros número y base, controlar mediante una función que número sea
positivo y mediante otra función controlar que base sea mayor que 1 y menor que 10. Utilizar
una función para realizar la conversión de número a la base representada por el valor base.
Presentar ambos números por pantalla. */

// TENGO QUE VER EL CASO DE LOS CEROS AL FINAL!

#include <stdio.h>

int es_positivo(int);
int es_mayor1_menor10(int);
int conversor_base(int, int);
int invertido(int);

int main(int argc, char *argv[]) {
    int numero, base;

    do {
        printf("\nIngresar un número positivo: ");
        scanf("%i", &numero);

        if (!es_positivo(numero))
            printf("\n>> Ingrese un número válido! <<\n");
    } while (!es_positivo(numero));

    printf("\n");

    do {
        printf("Ingresar otro número entre 1 y 10: ");
        scanf("%i", &base);

        if (!es_mayor1_menor10(base))
            printf("\n>> Ingresar un número válido! <<\n\n");
    } while (!es_mayor1_menor10(base));

    printf("\n> El número ingresado es %i, en base %i el número es: %i \n\n", numero, base, conversor_base(numero, base));

    return 0;
}

int es_positivo(int num) {
    if (num > 0)
        return 1;
    else
        return 0;
}

int es_mayor1_menor10(int num) {
    if (num > 1 && num < 10)
        return 1;
    else
        return 0;
}

int conversor_base(int numero, int base) {
    int resto, aux = 0, numero_convertido;

    while (numero > 0) {
        resto = numero % base;
        aux = aux * 10 + resto;
        numero /= base;
    }
    numero_convertido = invertido(aux);

    return numero_convertido;
}

int invertido(int num) {
    int resto, num_invertido = 0;

    while (num > 0) {
        resto = num % 10;
        num_invertido = num_invertido * 10 + resto;
        num /= 10;
    }

    return num_invertido;
}