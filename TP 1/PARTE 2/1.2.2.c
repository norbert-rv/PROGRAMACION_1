/* Dado el radio de un círculo, presentar por pantalla el diámetro, el perímetro y el área del
círculo. Realizar el control de que el valor del radio sea un número positivo. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    float radio, diametro, perimetro, area;

    do {
        printf("Ingresar el radio del círculo: ");
        scanf("%f", &radio);
    } while (radio <= 0);

    diametro = radio * 2;
    perimetro = 2 * 3.14 * radio;
    area = 3.14 * radio * radio;

    printf("El diámetro es %.2f.\nEl perímetro es %.2f.\nEl área es %.2f.\n", diametro, perimetro, area);

    return 0;
}