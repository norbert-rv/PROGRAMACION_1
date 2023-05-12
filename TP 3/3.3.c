/* Realizar un programa que permita cargar un arreglo cuyos elementos sean N números de punto
flotante y luego permita presentarlo por pantalla. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int N;
    float numeros[100];

    do {
        printf("\nIngresar el número de elementos que se ingresarán en el arreglo: ");
        scanf("%i", &N);
    } while (N <= 0);

    for (int i = 0; i < N; i++) {
        printf("\nIngresar número: ");
        scanf("%f", &numeros[i]);
    }

    for (int i = 0; i < N; i++) {
        printf("\n>> Número en posición %i: %.2f \n", i + 1, numeros[i]);
    }

    printf("\n\n");

    return 0;
}