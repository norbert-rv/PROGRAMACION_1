/* Realizar un programa que permita mostrar por pantalla el contenido del archivoTexto.txt */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char nombre[] = "archivoTexto.txt";
    char caracter;

    FILE *p;

    p = fopen(nombre, "rt");

    if (p == 0) {
        printf("\nEl archivo no existe. Saliendo...\n\n");
        exit(0);
    } else {
        do {
            caracter = fgetc(p);

            if (feof(p) == 0)
                fputc(caracter, stdout);
        } while (feof(p) == 0);
    }

    fclose(p);

    printf("\n");

    return 0;
}