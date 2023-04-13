/* Definir una estructura cuyos campos permitan guardar la cantidad de caracteres que sean
vocales y la cantidad que sean consonantes. Luego debe ingresar N caracteres, y contabilizar en
la estructura definida los caracteres de acuerdo a su tipo (vocales o consonantes) */

#include <stdio.h>

struct caracteres {
    int vocales;
    int consonantes;
};

int main(int argc, char *argv[]) {
    struct caracteres cantidad1, cantidad2;
    cantidad1.vocales = 0;
    cantidad2.consonantes = 0;
    int N, aux = 1;
    char car;

    do {
        printf("Ingresar el número N de caracteres: ");
        scanf("%i", &N);
    } while (N <= 0 || N > 999999999);

    while (fgetc(stdin) != '\n')
        ;

    for (int i = 0; i < N; i++) {
        printf("Ingresar caracter %i: ", aux);
        scanf("%c", &car);

        while (fgetc(stdin) != '\n')
            ;

        aux++;

        if (car == 'a' || car == 'A' || car == 'e' || car == 'E' || car == 'i' || car == 'I' || car == 'o' || car == 'O' || car == 'u' || car == 'U') {
            cantidad1.vocales++;
        } else if ((car > 64 && car < 91) || (car > 96 && car < 123)) {
            if (car != 'a' || car != 'A' || car != 'e' || car != 'E' || car != 'i' || car != 'I' || car != 'o' || car != 'O' || car != 'u' || car != 'U') {
                cantidad2.consonantes++;
            }
        }
    }

    printf("Hay %i vocales y %i consonantes.\n", cantidad1.vocales, cantidad2.consonantes);

    return 0;
}