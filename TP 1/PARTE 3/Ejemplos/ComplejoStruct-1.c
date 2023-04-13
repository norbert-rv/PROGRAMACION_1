#include <stdio.h>

struct complejo {
    float real;
    float img;
} num1, num2;
// NO usamos esta forma de declaración de variables

int main(int argv, char *argc[]) {
    /*declaraci�n de variables*/
    struct complejo numeroA, numeroB;

    numeroA.real = 3;
    numeroA.img = 2.5;

    printf("Ingresar num1 parte real ");
    scanf("%f", &num1.real);
    printf("Ingresar num1 parte imaginaria ");
    scanf("%f", &num1.img);

    printf("El num1 es %f + %fi ", num1.real, num1.img);
    printf("\nEl numeroA es %f + %fi ", numeroA.real, numeroA.img);

    printf("\n\n");
    return 0;
}
