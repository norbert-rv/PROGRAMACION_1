/* Ingresar un número entero positivo X de UN SOLO DÍGITO. Luego ingresar un número
entero positivo de dos o más dígitos.Realizar ambos controles. Presentar por pantalla la
cantidad de veces que el dígito X aparece en el número. Ejemplo: X=7, se ingresa:
327578 Salida por pantalla: "Aparece 2 veces". */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int X, num, contador = 0;

    do {
        printf("Ingresar un número entero positivo de un solo dígito: ");
        scanf("%i", &X);
    } while (X > 9 || X < 0);

    do {
        printf("Ingresar el número entero positivo a evaluar: ");
        scanf("%i", &num);
    } while (num <= 9 || num > 999999999);

    while (num != 0) {
        if (num % 10 == X) {
            contador++;
        }
        num /= 10;
    }

    printf("Aparece %i veces.\n", contador);

    return 0;
}