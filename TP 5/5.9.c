/* Utilizando un editor de texto, almacenar el fragmento en un archivo de texto llamado lenguajeC.txt en el
directorio de trabajo. Implementar un programa que muestre el contenido de este archivo por pantalla. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char cadena[500];
    FILE *p;

    p = fopen("lenguajeC.txt", "rt");
    if (p == NULL) {
        printf("\nEl archivo no existe. Saliendo...\n\n");
        exit(0);
    }
    fclose(p);

    p = fopen("lenguajeC.txt", "rt");

    do {
        fgets(cadena, 500, p);

        if (feof(p) == 0) {
            printf("\n%s", cadena);
        }
    } while (feof(p) == 0);

    fclose(p);

    printf("\n\n");

    return 0;
}