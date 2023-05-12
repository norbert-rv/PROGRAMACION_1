/* Realizar un programa que permita cargar un arreglo cuyos elementos sean N caracteres y luego
permita presentarlo por pantalla. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int N;
    char caracteres[100];

    do {
        printf("\nIngresar cantidad de caracteres: ");
        scanf("%i", &N);
    } while (N <= 0);

    fgetc(stdin);

    for (int i = 0; i < N; i++) {
        printf("\nIngresar caracter: ");
        caracteres[i] = getchar();
        fgetc(stdin);
    }

    for (int i = 0; i < N; i++) {
        printf("\n\n>> Caracter en posición %i: %c ", i + 1, caracteres[i]);
    }

    printf("\n\n");

    return 0;
}