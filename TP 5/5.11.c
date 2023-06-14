/* Diseñar un programa que permita leer el archivo del ejercicio 9 y cuente cuantas veces se hace
referencia a la frase: “lenguaje en C". En este caso 4 veces. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cantidadCoincidenciasString(char cadenaABuscar[], char nombreArchivo[]);

int main(int argc, char *argv[]) {
    char nombreArchivo[] = "lenguajeC.txt";
    char cadenaABuscar[] = "lenguaje en C";
    int coincidencias;

    FILE *p;
    p = fopen(nombreArchivo, "rt");
    if (p == NULL) {
        printf("\nEl archivo no existe. Saliendo... \n\n");
        exit(0);
    }
    fclose(p);

    printf("\nSe buscará la cantidad de veces que la frase '%s' aparece en el archivo '%s'...\n\n", cadenaABuscar, nombreArchivo);

    coincidencias = cantidadCoincidenciasString(cadenaABuscar, nombreArchivo);
    printf("\n\nLa cantidad de coincidencias es de %i \n\n", coincidencias);

    return 0;
}

int cantidadCoincidenciasString(char cadenaABuscar[], char nombreArchivo[]) {
    char cadenaAux[400];
    int contador = 0;

    FILE *p;
    p = fopen(nombreArchivo, "rt");

    do {
        fgets(cadenaAux, 400, p);
        fputs(cadenaAux, stdout);
        if (feof(p) == 0) {
            char *resultado = strstr(cadenaAux, cadenaABuscar); /* funcion strstr() para buscar subcadenas (devuelve puntero o NULL)*/
            if (resultado != NULL)
                contador++;
        }
    } while (feof(p) == 0);
    fclose(p);

    return contador;
}