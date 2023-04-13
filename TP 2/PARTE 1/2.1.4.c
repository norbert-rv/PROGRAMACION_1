/* Realizar un programa en lenguaje C que permita ingresar N caracteres alfabéticos y los
muestre en minúsculas. En caso de ingresar uno que no sea alfabético volver a
solicitarlo. */

#include <ctype.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char caracter;
    int N, contador_car = 1;

    do {
        printf("¿Cuántos caracteres ingresará?   ");
        scanf("%i", &N);

        if (N <= 0)
            printf("\nIngrese un número positivo \n\n");
    } while (N <= 0);

    fgetc(stdin);

    for (int i = 0; i < N; i++) {
        do {
            printf("Ingresar caracter %i: ", contador_car);
            caracter = getchar();
            while (fgetc(stdin) != '\n')
                ;
        } while (!isalpha(caracter));

        if (isupper(caracter))
            printf("\n%c\n\n", tolower(caracter));
        else
            printf("\n%c\n\n", caracter);

        contador_car++;
    }
    return 0;
}
