/* Realizar un programa que solicite al usuario el nombre de un archivo. Se debe verificar si existe un
archivo con ese nombre, si el mismo no existe se debe crear y permitir el ingreso de caracteres. Si el
archivo existe se deben agregar caracteres al final. Luego mostrar el contenido del archivo por pantalla. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int main(int argc, char *argv[]) {
    char nombreArchivo[MAX];
    char caracter;
    FILE *p;

    // Solicito al usuario el nombre de un archivo...
    printf("\nIngrear el nombre de un archivo: ");
    fscanf(stdin, "%s", nombreArchivo);
    while (getchar() != '\n')
        ;

    // Compruebo la existencia del archivo, si no existe, lo creo.
    p = fopen(nombreArchivo, "rt");

    if (p == NULL) {
        printf("\nEl archivo no existe, se lo creará...\n");
        p = fopen(nombreArchivo, "wt");

        if (p == NULL) {
            printf("\nEl archivo no pudo crearse... se cerrará el programa.\n\n");
            exit(0);
        }
    } else {
        printf("\nEl archivo si existe, se escribirá sobre el mismo...\n");
    }
    fclose(p);

    // escribo caracteres al final del archivo.
    p = fopen(nombreArchivo, "at");

    printf("\nIngrese caracteres de a uno ('-' para salir)...\n");
    while (1) {
        printf("\nCaracter: ");
        caracter = getchar();
        while (getchar() != '\n')
            ;

        if (caracter == '-') {
            break;
        } else {
            fputc(caracter, p);
        }
    }
    fclose(p);

    // Muestro el contenido del archivo
    p = fopen(nombreArchivo, "rt");

    do {
        caracter = fgetc(p);

        if (feof(p) == 0)
            fputc(caracter, stdout);
    } while (feof(p) == 0);

    fclose(p);

    printf("\n\n");

    return 0;
}