#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *punteroFILE;
    char cadena[100];

    if (argv[1] == NULL) {
        printf("\nDebe ingresar el nombre del archivo entre comillas...\n\n");
        exit(0);
    }

    punteroFILE = fopen(argv[1], "rt");

    if (punteroFILE == NULL) {
        printf("\nNo existe el archivo. Saliendo...\n\n");
        exit(0);
    } else {
        printf("\nEl contenido del archivo (de un string) '%s' es: \n", argv[1]);
        // lo hago de forma directa porque en el archivo hay un único string...
        fgets(cadena, 100, punteroFILE);
        printf("\n%s\n", cadena);
    }

    fclose(punteroFILE);

    return 0;
}