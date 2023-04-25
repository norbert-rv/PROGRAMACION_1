/* Leer un número entero positivo de dos o más dígitos, y luego presentar por pantalla al número
ingresado y su invertido. Para resolver deberá implementar
a- función para controlar si un número es un entero positivo de dos o más dígitos
b- función para generar el invertido del número dado */

#include <stdio.h>

int enteroPositivoDosDig(int);
int invertido(int);

int main(int argc, char *argv[]) {
    int numero;

    do {
        printf("\nIngresar número entero positivo de dos o más digitos: ");
        scanf("%i", &numero);

        if (!enteroPositivoDosDig(numero))
            printf("\n>> El número ingresado no cumple las condiciones! Intente nuevamente... \n");
    } while (!enteroPositivoDosDig(numero));

    printf("\n > El número ingresado es %i y su invertido es %i \n\n", numero, invertido(numero));

    return 0;
}

int enteroPositivoDosDig(int num) {  // evalúa si el número ingresado es un entero positivo de dos o más dígitos.
    if (num <= 0 || num < 10)
        return 0;
    else
        return 1;
}

int invertido(int num) {  // ¿y qué pasa cuando el último dígito del número es un 0? ¿Cómo mostrar por pantalla ese 0?
    int resto, num_invertido = 0;

    while (num > 0) {
        resto = num % 10;
        num_invertido = num_invertido * 10 + resto;
        num /= 10;
    }

    return num_invertido;
}