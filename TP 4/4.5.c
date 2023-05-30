/* Ingresar una cadena de caracteres, contabilizar cuántos caracteres alfabéticos, numéricos y de
otro tipo hay en la misma. Mostrar la cadena leída y las cantidades encontradas. */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

int tipoCar(char cadena[], int *digit, int *otro);

int main(int argc, char *argv[]) {
    char cadena[MAX];
    int cantAlfa, cantDigit = 0, cantOtro = 0;

    printf("\nIngresar cadena de caracteres: ");
    fgets(cadena, MAX, stdin);
    cadena[strlen(cadena) - 1] = '\0';

    cantAlfa = tipoCar(cadena, &cantDigit, &cantOtro);

    printf("\n\nCantidad de caracteres alfabéticos: %i", cantAlfa);
    printf("\nCantidad de caracteres numéricos: %i", cantDigit);
    printf("\nCantidad de caracteres de otro tipo: %i\n\n", cantOtro);

    return 0;
}

int tipoCar(char cadena[], int *digit, int *otro) {
    int alfa = 0;
    int i = 0;

    while (cadena[i] != '\0') {
        if (isalpha(cadena[i]))
            alfa++;
        else if (isdigit(cadena[i]))
            *digit = *digit + 1;
        else
            *otro = *otro + 1;

        i++;
    }

    return alfa;
}