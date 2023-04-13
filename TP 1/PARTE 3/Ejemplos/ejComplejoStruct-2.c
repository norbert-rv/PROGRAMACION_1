#include <stdio.h>

typedef struct {
    float real;
    float img;
} complejo;

int main(int argv, char *argc[]) {
    /*declaraci�n de variables*/
    complejo numeroB;

    numeroB.real = 3.2;
    numeroB.img = 2.5;
    printf("El numeroB es %f + %fi ", numeroB.real, numeroB.img);
    printf("\n\n");
    return 0;
}
