/* Realizar un programa que permita ingresar caracteres desde el teclado, el programa deberá escribir los
caracteres a medida que se ingresen en un archivo de texto llamado archivoTexto.txt El ingreso de
caracteres debe finalizar cuando se ingrese la letra F, esta última no deberá ser escrita en el archivo.
Luego debe presentar por pantalla el contenido del archivo cargado */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char caracter;
    char nombreArchivo[] = "archivoTexto.txt";

    FILE *p;

    // Verificacion de que se pueda abrir el archivo (iniciar el flujo).
    p = fopen(nombreArchivo, "rt");

    if (p == NULL) {
        printf("\nEl archivo no pudo abrirse.\n\n");
        exit(0);
    }

    fclose(p);

    p = fopen(nombreArchivo, "wt");

    printf("\nIngresar caracteres a continuación en archivo %s... (F para salir)\n", nombreArchivo);

    // nice...
    while (1) {
        printf("\nCaracter: ");
        caracter = getchar();
        while (getchar() != '\n')
            ;

        if (caracter == 'F') {
            break;
        } else {
            fputc(caracter, p);
        }
    }

    fclose(p);

    printf("\n\nA continuación se mostrará el contenido del archivo %s...\n\n", nombreArchivo);

    p = fopen(nombreArchivo, "rt");

    // para lectura uso el do-while!!! Ese funciona bien.
    do {
        caracter = fgetc(p);

        if (feof(p) == 0)
            fputc(caracter, stdout);
    } while (feof(p) == 0);

    fclose(p);

    printf("\n\n");

    return 0;
}