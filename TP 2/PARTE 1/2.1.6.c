/* Ingresar un número entero y mostrar por pantalla el número ingresado y su valor
absoluto. */

#include <math.h>
#include <stdio.h>

int main(void) {
    double numero;

    printf("Ingresar un número entero: ");
    scanf("%lf", &numero);

    printf("\nEl valor absoluto de %.0lf es %.0lf\n\n", numero, fabs(numero));

    return 0;
}