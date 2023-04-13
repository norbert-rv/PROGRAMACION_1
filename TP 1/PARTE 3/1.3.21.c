/* Codificar un programa para: ingresar dos números N y D enteros positivos. Debe realizar el
control del ingreso de datos, luego calcular el valor del cociente y resto entre N y D utilizando el
método de restas sucesivas. Para almacenar y mostrar por pantalla el resultado utilizar la
siguiente estructura:
struct dividir{
float cociente;
int resto;
};
*/

#include <stdio.h>

struct dividir {
    float cociente;
    int resto;
};

int main(int argc, char *argv[]) {
    struct dividir numero;
    int N, D;
    numero.cociente = 0;

    printf("Ingresar dos números enteros positivos\n");

    do {
        printf("Número 1: ");
        scanf("%i", &N);
        if (N <= 0)
            printf("El número ingresado no es positivo! \nVolver a intentar...\n");
    } while (N <= 0);

    do {
        printf("Número 2: ");
        scanf("%i", &D);
        if (D <= 0)
            printf("El número ingresado no es positivo! \nVolver a intentar...\n");
    } while (D <= 0);

    while (N >= D) {
        numero.cociente++;
        N = N - D;
    }

    numero.resto = N;

    printf("El valor del cociente es %.0f\nEl valor del resto es %i\n", numero.cociente, numero.resto);

    return 0;
}