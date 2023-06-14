/* Realizar un programa que solicite que se ingrese por teclado el nombre de algún archivo de texto,
trabajado hasta el momento en el práctico, para luego mostrar por pantalla el contenido del mismo, en
caso de no encontrar ese archivo mostrar un mensaje. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char nombreArchivo[100];

    printf("\nIngresar el nombre de un archivo: ");
    fgets(nombreArchivo, 100, stdin);
    nombreArchivo[strlen(nombreArchivo) - 1] = '\0';

    FILE *p;
    char cadena[400];
    p = fopen(nombreArchivo, "rt");
    if (p == NULL) {
        printf("\nEl archivo no existe o no se pudo abrir. Saliendo... \n\n");
        exit(0);
    }
    fclose(p);

    p = fopen(nombreArchivo, "rt");
    do {
        fgets(cadena, 400, p);

        if (feof(p) == 0) {
            printf("\n%s", cadena);
        }
    } while (feof(p) == 0);
    fclose(p);

    printf("\n\n");
    return 0;
}