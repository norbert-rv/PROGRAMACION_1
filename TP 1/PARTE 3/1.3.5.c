/* Presentar por pantalla las letras que estén entre la "a" y la ''m" utilizando una estructura
"for". No mostrar la a y m solo las intermedias. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    char aux;

    for (char i = 'a'; i < 'l'; i++) {
        aux = i;
        printf("%c\n", ++aux);
    }

    return 0;
}