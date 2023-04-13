#include <stdio.h>

int main(int argc, char *argv[]) {
    int num1, num2;

    printf("Ingresar número 1: ");
    scanf("%i", &num1);
    printf("Ingresar número 2: ");
    scanf("%i", &num2);

    printf("El producto es: %i. \nLa suma es: %i. \nLa media aritmética es: %i.\n", num1 * num2, num1 + num2, (num1 + num2) / 2);

    return 0;
}