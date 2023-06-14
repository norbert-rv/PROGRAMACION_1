/* Realizar un programa que permita ingresar cadenas de caracteres que contengan dos o más palabras en
un archivo llamado cadenas.txt., almacenar un renglón o línea de texto por cada cadena ingresada. El
ingreso de cadenas finaliza con la cadena: "Fin del ingreso". Consideraciones:
> El control de que las cadenas ingresadas tengan dos o más palabras debe realizarse con una
función.
> La cadena “Fin del ingreso” no debe ser escrita en el archivo
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aperturaArchivo(char nombre[]);
void ingresarCadenas2Palabras(char nombre[], char salida[]);
int tieneDosPalabras(char cadena[]);

int main(int argc, char *argv[]) {
    char nombreArchivo[] = "cadenas.txt";
    char cadenaDeSalida[] = "Fin del ingreso";

    aperturaArchivo(nombreArchivo);

    printf("\nA continuación ingrese cadenas (una por renglón)...\n");
    ingresarCadenas2Palabras(nombreArchivo, cadenaDeSalida);

    printf("\nFinalizando programa...\n\n");

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

void ingresarCadenas2Palabras(char nombre[], char salida[]) {
    char cadena[300];
    int caso0 = 1;

    FILE *p;
    /* Esta función sobreeescribe el archivo cada vez que se ejecuta */
    p = fopen(nombre, "wt");

    while (1) {
        printf("\nIngresar cadena: ");
        fgets(cadena, 300, stdin);
        cadena[strlen(cadena) - 1] = '\0';

        if (strcmp(cadena, salida) == 0)
            break;
        if (tieneDosPalabras(cadena)) {
            if (caso0)
                caso0 = 0;
            else
                fputc('\n', p);

            fputs(cadena, p);
        } else {
            printf("\nLa cadena debe tener al menos dos palabras! \n");
        }
    }

    fclose(p);
}

int tieneDosPalabras(char cadena[]) {
    int contadorEspacios = 0;

    for (int i = 0; i < strlen(cadena); i++) {
        if (cadena[i] == ' ')
            contadorEspacios++;
    }
    if (contadorEspacios != 0)
        return 1;
    else
        return 0;
}