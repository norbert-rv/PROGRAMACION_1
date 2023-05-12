/* Realizar un programa que permita cargar un arreglo cuyos elementos sean N números enteros y
luego permita presentarlo por pantalla. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int N;
    // declaración del arreglo
    int numeros[100];

    do {
        printf("\nIngresar el número de elementos que se ingresarán en el arreglo: ");
        scanf("%i", &N);
    } while (N <= 0);

    for (int i = 0; i < N; i++) {
        printf("\nIngresar número: ");
        scanf("%i", &numeros[i]);
    }

    for (int i = 0; i < N; i++) {
        printf("\n>> Número en posición %i: %i \n", i + 1, numeros[i]);
    }

    printf("\n\n");

    return 0;
}