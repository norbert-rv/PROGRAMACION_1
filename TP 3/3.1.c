/* Realizar un programa que permita cargar un arreglo cuyos elementos sean N números enteros y
luego permita presentarlo por pantalla. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int N;
    // declaración del arreglo
    int numeros[100];

    do {
        printf("\nIngresar el tamaño del arreglo: ");
        scanf("%i", &N);

        if (N > 100)
            printf("\n> El tamaño no puede ser mayor que 100! \n");
    } while (N <= 0 || N > 100);

    for (int i = 0; i < N; i++) {
        printf("\nIngresar número: ");
        scanf("%i", &numeros[i]);
    }

    printf("\n>> El arreglo ingresado es: (");

    for (int i = 0; i < N; i++) {
        if (i < N - 1)
            printf("%i, ", numeros[i]);
        else
            printf("%i)\n\n", numeros[i]);
    }

    return 0;
}