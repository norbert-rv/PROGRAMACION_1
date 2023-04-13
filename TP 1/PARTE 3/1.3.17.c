/* Implementar un programa en el que se soliciten el radio de la base y la altura de un cilindro
circular y luego se presenten por pantalla los datos. Usar una estructura como la siguiente:
struct cilindro{
float radio
float altura;
};
*/

#include <stdio.h>

struct cilindro {
    float radio;
    float altura;
};

int main(int argc, char *argv[]) {
    struct cilindro numeroA, numeroB;

    printf("Ingresar radio: ");
    scanf("%f", &numeroA.radio);
    printf("Ingresar altura: ");
    scanf("%f", &numeroB.altura);

    printf("Radio: %.2f \nAltura: %.2f\n", numeroA.radio, numeroB.altura);

    return 0;
}