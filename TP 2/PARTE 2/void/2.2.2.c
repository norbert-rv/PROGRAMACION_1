/* Implementar un programa en el cual: se define una constante numérica llamada "PI" con el valor
3.14, se solicite que se ingrese un número que será el radio de una circunferencia, se calcule el
valor de la longitud de la circunferencia y se lo presente por pantalla.
Recordar que la longitud de la circunferencia = 2 * PI * radio.
Para este problema diseñar una función que reciba los dos valores y calcule el valor de la
solicitado */

#include <stdio.h>

void perimetro(double, double);

int main(int argc, char *argv[]) {
    const double PI = 3.14;
    double radio = 1;

    do {
        printf("Ingresar el valor del radio: ");
        scanf("%d", &radio);
        printf("%d", radio);
        if (radio <= 0)
            printf("\n>> El radio debe ser un número positivo! <<\n");
    } while (radio <= 0);

    perimetro(radio, PI);

    return 0;
}

void perimetro(double radio, double PI) {
    printf("\n>> El perímetro de una circunferencia de radio %d es: %d\n\n", radio, 2 * PI * radio);
}