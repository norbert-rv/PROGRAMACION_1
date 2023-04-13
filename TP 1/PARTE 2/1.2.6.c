/* Ingresar tres números enteros, ordenarlos en forma ascendente y presentarlos por pantalla.
En caso de ser los tres iguales, imprimir un mensaje que diga: Son iguales. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num1, num2, num3;

    printf("Ingresar número 1: ");
    scanf("%i", &num1);
    printf("Ingresar número 2: ");
    scanf("%i", &num2);
    printf("Ingresar número 3: ");
    scanf("%i", &num3);

    if (num1 == num2 && num1 == num3) printf("Son iguales.\n");

    if (num1 < num2 && num2 < num3)
        printf("%i %i %i\n", num1, num2, num3);
    if (num1 < num3 && num3 < num2)
        printf("%i %i %i\n", num1, num3, num2);
    if (num2 < num3 && num3 < num1)
        printf("%i %i %i\n", num2, num3, num1);
    if (num2 < num1 && num1 < num3)
        printf("%i %i %i\n", num2, num1, num3);
    if (num3 < num2 && num2 < num1)
        printf("%i %i %i\n", num3, num2, num1);
    if (num3 < num1 && num1 < num2) printf("%i %i %i\n", num3, num1, num2);

    return 0;
}