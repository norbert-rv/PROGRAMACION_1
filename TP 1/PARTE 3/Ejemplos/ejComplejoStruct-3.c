#include <stdio.h>

struct complejo {
    float real;
    float img;
};

int main(int argv, char *argc[]) {
    /*declaraci�n de variables*/
    struct complejo numeroA, numeroB = {6.2, 2.5}, numeroC;

    numeroA.real = 3;
    numeroA.img = 2.5;

    printf("Ingresar numeroC parte real ");
    scanf("%f", &numeroC.real);
    printf("Ingresar nummeroC parte imaginaria ");
    scanf("%f", &numeroC.img);

    printf("\nEl numeroA es %f + %fi ", numeroA.real, numeroA.img);
    printf("\nEl numeroB es %f + %fi ", numeroB.real, numeroB.img);
    printf("El numeroC es %f + %fi ", numeroC.real, numeroC.img);

    printf("\n\n");
    return 0;
}
