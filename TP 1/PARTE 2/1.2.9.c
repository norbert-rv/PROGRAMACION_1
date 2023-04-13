/* Presentar por pantalla los números del 1 al 40 utilizando una estructura "while" */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num = 1;

    while (num != 41) {
        printf("%i\n", num);
        num++;
    }

    return 0;
}