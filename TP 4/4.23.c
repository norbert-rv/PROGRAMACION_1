/* Escribe un programa en C que reciba dos números enteros como argumentos en la función main
y muestre la suma de los dos números por pantalla. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num1 = atoi(argv[1]), num2 = atoi(argv[2]);

    printf("\n%i \n\n", num1 + num2);

    return 0;
}