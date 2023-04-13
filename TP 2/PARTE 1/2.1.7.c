/* Escribir un programa que muestre el resultado de la ecuación de tercer grado
para un valor x. Para ello, debe leer el valor de los
coeficientes (a,b,c y d) y el valor de x, todos estos son valores enteros positivos .Mostrar
por pantalla el resultado de la evaluación de la ecuación resultante. */

#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int a, b, c, d, X;
    double ecuacion;

    printf("Para la ecuación < ax³+bx²+cx+d >, ingrese el valor de los coeficientes...\n\n");

    do {
        printf("Ingrese el valor de a: ");
        scanf("%i", &a);
    } while (a <= 0);

    do {
        printf("\nIngrese el valor de b: ");
        scanf("%i", &b);
    } while (b <= 0);

    do {
        printf("\nIngresar el valor de c: ");
        scanf("%i", &c);
    } while (c <= 0);

    do {
        printf("\nIngresar el valor de d: ");
        scanf("%i", &d);
    } while (d <= 0);

    do {
        printf("\nAhora ingrese el valor de X: ");
        scanf("%i", &X);
    } while (X <= 0);

    ecuacion = a * pow(X, 3) + b * pow(X, 2) + c * X + d;

    printf("\nEl resultado de la ecuación es: %.0lf\n\n", ecuacion);

    return 0;
}