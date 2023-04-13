/* Realizar un programa en lenguaje C que permita ingresar N caracteres alfabéticos en
mayúsculas y los muestre en minúsculas. */

#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int N, contador_car = 1;
    char caracter;

    do {
        printf("¿Cuál es el número de caracteres a ingresar?  ");
        scanf("%i", &N);
    } while (N <= 0);

    while (fgetc(stdin) != '\n')
        ;

    for (int i = 0; i < N; i++) {
        do {
            printf("Ingresar caracter %i:  ", contador_car);
            caracter = getchar();

            while (fgetc(stdin) != '\n')
                ;

            if (islower(caracter))
                printf("\nEl caracter debe estar en mayúsculas! \n\n");
        } while (!isalpha(caracter) || !isupper(caracter));

        printf("\n%c\n\n", tolower(caracter));

        contador_car++;
    }

    return 0;
}