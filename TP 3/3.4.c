/* Cargar caracteres en un arreglo de orden N. Luego contabilizar cuántos caracteres del arreglo son
alfabéticos, cuántos son dígitos y cuántos de otras categorías. */

#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char caracteres[50];
    int N;
    int cantidad_alfa = 0, cantidad_digit = 0, cantidad_otro = 0;

    do {
        printf("\nIngresar el orden del arreglo: ");
        scanf("%i", &N);

        if (N <= 0 || N > 50)
            printf("\n>> El orden debe estar entre 1 y 50! \n");
    } while (N <= 0 || N > 50);

    fgetc(stdin);

    for (int i = 0; i < N; i++) {
        printf("\nIngresar caracter: ");
        caracteres[i] = getchar();
        fgetc(stdin);
        if (isalpha(caracteres[i]))
            cantidad_alfa++;
        else if (isdigit(caracteres[i]))
            cantidad_digit++;
        else
            cantidad_otro++;
    }

    printf("\n> Cantidad de caracteres alfabéticos: %i \n", cantidad_alfa);
    printf("\n> Cantidad de digitos: %i \n", cantidad_digit);
    printf("\n> Cantidad de caracteres de otro tipo: %i \n\n", cantidad_otro);

    return 0;
}