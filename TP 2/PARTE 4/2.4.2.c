/* Un número triangular es un número que puede recomponerse en la forma de un
triángulo equilátero (por convención, el primer número triangular es el 1). Es decir, los
primeros números triangulares son 1, 3, 6, 10, etc. Elabore un programa que muestre en
pantalla los N primeros números triangulares. */

#include <stdio.h>

int pedirN();
int numeroTriangular();

int main(int argc, char *argv[]) {
    int contador = 1;
    printf("\nPrograma que muestra los N primeros números triangulares...\n");

    int N = pedirN();

    for (int i = 0; i < N; i++) {
        printf("\n%i. %i\n\n", contador, numeroTriangular());
        contador++;
    }

    return 0;
}

int numeroTriangular() {
    static int num = 1, auxiliar = 0;

    num += auxiliar;

    if (num == 1)
        auxiliar = 1;
    auxiliar++;

    return num;
}

int pedirN() {
    int num;

    do {
        printf("\nIngresar el número N: ");
        scanf("%i", &num);

        if (num <= 0)
            printf("> Ingresar un número positivo! <\n\n");
    } while (num <= 0);

    return num;
}