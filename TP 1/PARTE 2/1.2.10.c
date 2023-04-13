/* Presentar por pantalla los números del 1 al 40 que sean pares utilizando una estructura
"for". */

#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < 41; i++) {
        if (i % 2 == 0)
            printf("%i\n", i);
    }

    return 0;
}