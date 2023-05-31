/* Ingresar por línea de comandos, dos palabras (realizar el control de la cantidad de palabras
ingresadas). Luego mostrar por pantalla las palabras ordenadas en forma alfabética, o un
mensaje en caso de que sean iguales */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 3) {
        printf("\nDemasiadas palabras como argumentos...\n\n");
        return 0;
    } else {
        if (strcmp(argv[1], argv[2]) < 0)
            printf("\n%s - %s \n\n", argv[1], argv[2]);
        else if (strcmp(argv[1], argv[2]) > 0)
            printf("\n%s - %s \n\n", argv[2], argv[1]);
        else
            printf("\nLas dos palabras son iguales. \n\n");
    }

    return 0;
}