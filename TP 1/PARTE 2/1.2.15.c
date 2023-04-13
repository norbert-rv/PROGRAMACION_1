/* Presentar por pantalla todos los números enteros positivos que tengan cuatro dígitos
utilizando una estructura "while". */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num = 1000;

    while (num < 10000) {
        printf("%i ", num);
        num++;
    }
    printf("\n");
    return 0;
}