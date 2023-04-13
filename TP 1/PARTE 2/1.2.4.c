/* Ingresar dos números enteros, determinar si fueron ingresados en orden creciente,
decreciente o si son iguales, presentar por pantalla el mensaje correspondiente. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int numero1, numero2;

    printf("Ingresar número 1: ");
    scanf("%i", &numero1);
    printf("Ingresar número 2: ");
    scanf("%i", &numero2);

    if (numero1 > numero2)
        printf("Fueron ingresados en orden decreciente.\n");
    else if (numero1 < numero2)
        printf("Fueron ingresados en orden creciente.\n");
    else
        printf("Los números ingresados son iguales.\n");

    return 0;
}