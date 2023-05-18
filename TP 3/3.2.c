/* Realizar un programa que permita cargar un arreglo cuyos elementos sean N caracteres y luego
permita presentarlo por pantalla. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int N;
    char caracteres[100];

    do {
        printf("\nIngresar orden del arreglo de caracteres: ");
        scanf("%i", &N);

        if (N <= 0 || N > 100)
            printf("\n> El orden debe estar entre 1 y 100! \n");
    } while (N <= 0 || N > 100);

    while (getchar() != '\n')
        ;

    for (int i = 0; i < N; i++) {
        printf("\nIngresar caracter: ");
        caracteres[i] = getchar();
        fgetc(stdin);
    }

    printf("\n> El arreglo ingresado es: (");

    for (int i = 0; i < N; i++) {
        if (i < N - 1)
            printf("%c, ", caracteres[i]);
        else
            printf("%c)\n\n", caracteres[i]);
    }

    return 0;
}