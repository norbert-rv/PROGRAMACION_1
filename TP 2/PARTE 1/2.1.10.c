/* Codificar un programa en el que se solicita el ingreso de N carácteres, luego presentar
por pantalla las consonantes ingresadas en minúscula y las vocales en mayúscula. */

#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int N, contador_pantalla = 1;
    char caracter;

    do {
        printf("Ingresar el número N de caracteres: ");
        scanf("%i", &N);
    } while (N <= 0);

    while (fgetc(stdin) != '\n')
        ;

    for (int i = 0; i < N; i++) {
        do {
            printf("\nIngresar caracter %i:  ", contador_pantalla);
            scanf("%c", &caracter);

            while (fgetc(stdin) != '\n')
                ;
        } while (!isalpha(caracter));

        if (caracter == 'a' || caracter == 'A' || caracter == 'e' || caracter == 'E' || caracter == 'i' || caracter == 'I' || caracter == 'o' || caracter == 'O' || caracter == 'u' || caracter == 'U') {
            printf("\n%c\n\n", toupper(caracter));
        } else {
            printf("\n%c\n\n", tolower(caracter));
        }

        contador_pantalla++;
    }

    return 0;
}