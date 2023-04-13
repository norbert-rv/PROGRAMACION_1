#include <stdio.h>

int main(int argc, char *argv[]) {
    float num1, num2;

    printf("Ingresar el primer número: ");
    scanf("%f", &num1);
    printf("Ingresar el segundo número: ");
    scanf("%f", &num2);

    printf("La suma es %.2f y el producto es %.2f.\n", num1 + num2, num1 * num2);

    return 0;
}