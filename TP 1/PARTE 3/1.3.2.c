/* Ingresar 3 carácteres por teclado y luego presentar por pantalla un mensaje con la
siguiente leyenda "Los carácteres ingresados son …(mostrar los carácteres ingresados)" */

#include <stdio.h>

int main(int argc, char *argv[]) {
    char car1, car2, car3;

    printf("Ingresar 3 caracteres: \nCaracter 1: ");
    scanf("%c", &car1);
    while (fgetc(stdin) != '\n')
        ;
    printf("Caracter 2: ");
    scanf("%c", &car2);
    while (fgetc(stdin) != '\n')
        ;
    printf("Caracter 3: ");
    scanf("%c", &car3);
    while (fgetc(stdin) != '\n')
        ;

    printf("Los caracteres ingresados son %c %1c %1c.\n", car1, car2, car3);

    return 0;
}