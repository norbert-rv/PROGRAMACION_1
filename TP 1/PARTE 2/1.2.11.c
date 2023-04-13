/* Presentar por pantalla los números del 1 al 40 que sean pares utilizando una estructura "do
while" */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num = 1;

    do {
        if (num % 2 == 0)
            printf("%i\n", num);
        num++;
    } while (num < 41);

    return 0;
}