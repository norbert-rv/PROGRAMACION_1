#include <stdio.h>

int main(int argc, char *argv[]) {
    float radio, longitud;
    const float pi = 3.14;
    printf("Ingrese el valor del radio: ");
    scanf("%f", &radio);

    longitud = 2 * pi * radio;

    printf("La longitud de la circunferencia es %.2f.\n", longitud);

    return 0;
}