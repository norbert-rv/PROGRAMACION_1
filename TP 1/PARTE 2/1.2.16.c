/* Presentar por pantalla todos los números enteros positivos que tengan cuatro dígitos
utilizando una estructura "for". */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num;

    for (int i = 1000; i < 10000; i++) {
        printf("%i ", i);
    }

    printf("\n");

    return 0;
}