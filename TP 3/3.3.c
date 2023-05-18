/* Realizar un programa que permita cargar un arreglo cuyos elementos sean N números de punto
flotante y luego permita presentarlo por pantalla. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int N;
    float numeros[100];

    do {
        printf("\nIngresar el número de elementos que se ingresarán en el arreglo: ");
        scanf("%i", &N);

        if (N <= 0 || N > 100)
            printf("\n> El orden debe estar entre 1 y 100! \n");
    } while (N <= 0 || N > 100);

    for (int i = 0; i < N; i++) {
        printf("\nIngresar número: ");
        scanf("%f", &numeros[i]);
    }

    printf("\n> El arreglo ingresado es: (");

    for (int i = 0; i < N; i++) {
        if (i < N - 1)
            printf("%.2f, ", numeros[i]);
        else
            printf("%.2f)\n\n", numeros[i]);
    }

    return 0;
}