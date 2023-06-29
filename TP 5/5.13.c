/* Realizar un programa para gestionar el cumpleaños de UN amigo, usando una estructura que contenga
los siguientes campos: Nombre, Apellido y fecha de nacimiento. Luego almacenar los datos contenidos
en la estructura en un archivo de texto, utilizando un renglón o línea de texto con el siguiente formato:
nombre-apellido-dia-mes-anio, observar que se emplea como separador el guión. Luego presentar por
pantalla los datos de la persona registrados en el archivo. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, anio;
} fecha;

typedef struct {
    char nombre[30], apellido[30];
    fecha nacimiento;
} amigo;

amigo ingresarDatosAmigo();
void guardarDatosAmigo(char nombreArchivo[]);
void aperturaArchivo(char nombre[]);
void mostrarDatosAmigo(char nombre[]);

int main(int argc, char *argv[]) {
    char nombreArchivo[] = "datosAmigo.txt";

    aperturaArchivo(nombreArchivo);

    /* guardo los datos de un amigo en el archivo */
    guardarDatosAmigo(nombreArchivo);

    mostrarDatosAmigo(nombreArchivo);

    printf("\n");
    return 0;
}

void guardarDatosAmigo(char nombreArchivo[]) {
    amigo unAmigo;
    FILE *p;

    p = fopen(nombreArchivo, "wt");

    unAmigo = ingresarDatosAmigo();

    fprintf(p, "%s - %s - %i - %i - %i", unAmigo.nombre, unAmigo.apellido, unAmigo.nacimiento.dia, unAmigo.nacimiento.mes, unAmigo.nacimiento.anio);

    fclose(p);
}

amigo ingresarDatosAmigo() {
    amigo A;

    printf("\nNombre: ");
    scanf("%s", A.nombre);
    getchar();

    printf("\nApellido: ");
    scanf("%s", A.apellido);
    getchar();

    printf("\nDia nac: ");
    scanf("%i", &A.nacimiento.dia);

    printf("\nMes nac: ");
    scanf("%i", &A.nacimiento.mes);

    printf("\nAño nac: ");
    scanf("%i", &A.nacimiento.anio);
    getchar();

    return A;
}

void aperturaArchivo(char nombre[]) {
    FILE *p;

    p = fopen(nombre, "rt");

    if (p == NULL) {
        printf("\nEl archivo no existe. Se intentará crearlo... \n");
        p = fopen(nombre, "wt");
        if (p == NULL) {
            printf("\nNo se pudo crear el archivo. Saliendo... \n");
            exit(0);
        }
    }

    fclose(p);
}

void mostrarDatosAmigo(char nombre[]) {
    char c;
    FILE *p;

    p = fopen(nombre, "rt");

    printf("\n");

    do {
        c = fgetc(p);

        if (feof(p) == 0)
            printf("%c", c);
    } while (feof(p) == 0);

    fclose(p);
    printf("\n");
}