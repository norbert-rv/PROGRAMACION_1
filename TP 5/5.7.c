/* Realizar un programa que solicite al usuario el nombre de un archivo, almacene caracteres en el mismo y
luego lo presente por pantalla. Al ingresar el nombre del archivo se debe verificar si existe, si el mismo
no existe se debe crear y permitir el ingreso de caracteres. Si el archivo existe se deben agregar
caracteres al final. Luego mostrar el contenido del archivo por pantalla. Usar:
○ Una función para verificar la existencia, en caso de no existir, realizar la creación del archivo.
○ Una función para solicitar al usuario los caracteres y almacenarlos en el archivo.
○ Una función para mostrar el contenido del archivo.
*/

#include <stdio.h>
#include <stdlib.h>

void aperturaArchivo(char nombre[]);
void ingresoCaracteresFinal(char nombre[]);
void mostrarArchivoCaracteres(char nombre[]);

int main(int argc, char *argv[]) {
    char nombreArchivo[100];

    printf("\nIngresar el nombre de un archivo: ");
    fscanf(stdin, "%s", nombreArchivo);
    getchar();  // limpio el buffer de entrada

    aperturaArchivo(nombreArchivo);

    printf("\nA continuación ingrese caracteres en el archivo... (se termina con 'F')\n");
    ingresoCaracteresFinal(nombreArchivo);

    printf("\nEl contenido del archivo '%s' es... \n\n", nombreArchivo);
    mostrarArchivoCaracteres(nombreArchivo);

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

void ingresoCaracteresFinal(char nombre[]) {
    FILE *p;
    char caracter;

    p = fopen(nombre, "at");

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

void mostrarArchivoCaracteres(char nombre[]) {
    char caracter;
    FILE *p;

    p = fopen(nombre, "rt");

    if (p == NULL) {
        printf("\nEl archivo no existe.\n\n");
        return;  // finaliza la FUNCION sin devolver un valor.
    } else {
        do {
            caracter = fgetc(p);

            if (feof(p) == 0)
                fputc(caracter, stdout);
        } while (feof(p) == 0);
    }
    fclose(p);
}