/* Realizar un programa que permita ingresar caracteres desde el teclado, el programa deberá escribir los
caracteres a medida que se ingresen en un archivo de texto llamado archivoTexto.txt El ingreso de
caracteres debe finalizar cuando se ingrese la letra F, esta última no deberá ser escrita en el archivo. */

#include <stdio.h>
#include <stdlib.h>

void aperturaArchivo(char nombre[]);
void ingresoCaracteres(char nombre[]);

int main(int argc, char *argv[]) {
    char nombreArchivo[] = "archivoTexto.txt";

    aperturaArchivo(nombreArchivo);

    printf("\nA continuación ingresará caracteres en el archivo... \n\n");
    ingresoCaracteres(nombreArchivo);

    printf("\n\n");

    return 0;
}

void aperturaArchivo(char nombre[]) {
    FILE *p;

    p = fopen(nombre, "rt");

    if (p == NULL) {
        printf("\nEl archivo no existe. Se lo creará...\n");

        p = fopen(nombre, "wt");

        if (p == NULL) {
            printf("\nNo se pudo crear el archivo. Saliendo... \n\n");
            exit(0);
        }
    }

    fclose(p);
}

void ingresoCaracteres(char nombre[]) {
    FILE *p;
    char caracter;

    p = fopen(nombre, "wt");

    while (1) {
        printf("\nCaracter: ");
        caracter = fgetc(stdin);
        while (getchar() != '\n')
            ;

        if (caracter == 'F')
            break;
        else
            fputc(caracter, p);
    }

    fclose(p);
}