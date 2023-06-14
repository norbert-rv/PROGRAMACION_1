/* Diseñar un programa que permita leer el archivo del ejercicio 9, solicite un caracter al usuario y cuente
cuántas veces se encuentra el caracter en el archivo. Presente el resultado por pantalla. */

#include <stdio.h>
#include <stdlib.h>

int cantidadCaracteresIguales(char caracter, char nombreArchivo[]);

int main(int argc, char *argv[]) {
    char nombreArchivo[] = "lenguajeC.txt";
    char caracterABuscar;
    int coincidencias;

    FILE *p;
    p = fopen(nombreArchivo, "rt");
    if (p == NULL) {
        printf("\nEl archivo no existe. Saliendo... \n\n");
        exit(0);
    }
    fclose(p);

    printf("\nIngrese el caracter a buscar en '%s': ", nombreArchivo);
    scanf("%c", &caracterABuscar);

    coincidencias = cantidadCaracteresIguales(caracterABuscar, nombreArchivo);

    printf("\nLa cantidad de coincidencias con el caracter '%c' es de %i.\n\n", caracterABuscar, coincidencias);

    return 0;
}

int cantidadCaracteresIguales(char caracter, char nombreArchivo[]) {
    int contador = 0;
    char carAux;

    FILE *p;
    p = fopen(nombreArchivo, "rt");

    do {
        carAux = fgetc(p);
        if (feof(p) == 0) {
            if (carAux == caracter)
                contador++;
        }
    } while (feof(p) == 0);

    return contador;
}