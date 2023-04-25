/* Presentar por pantalla, las N primeras letras del alfabeto en mayúsculas. */

#include <stdio.h>

int pedirN();
char letraAlfabeto();

int main(int argc, char *argv[]) {
    printf("\nPrograma que presenta por pantalla las N primeras letras mayúsculas del alfabeto...\n");

    int N = pedirN();

    for (int i = 0; i < N; i++) {
        printf("\n%c\n\n", letraAlfabeto());
    }

    return 0;
}

char letraAlfabeto() {
    char letra = 'A';
    static int siguienteletra = 0;

    letra += siguienteletra;
    siguienteletra++;

    return letra;
}

int pedirN() {
    int num;

    do {
        printf("\nIngresar el número N: ");
        scanf("%i", &num);

        if (num <= 0)
            printf("> Ingresar un número positivo! <\n\n");
    } while (num <= 0);

    return num;
}