/* declaro puntero FILE
abro el archivo con fopen() => verifico que se abra correctamente
proceso el archivo (hago todo lo que tenga que hacer con el archivo)
cierro el archivo
*/

/* Realizar un programa que permita crear un archivo que tenga el nombre ejercicio1.txt, luego ingresar
por teclado una cadena de caracteres y escribirla en el archivo, finalmente cerrar el archivo. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char cadena[100];

    FILE *punteroFILE;

    punteroFILE = fopen("ejercicio1.txt", "wt");

    if (punteroFILE == NULL) {
        printf("\nNo se pude establecer la conección\n\n");
        exit(0);
    }

    printf("\nIngresar cadena de caracteres a escribir en el archivo: ");
    fgets(cadena, 100, stdin);
    cadena[strlen(cadena) - 1] = '\0';

    fputs(cadena, punteroFILE);

    fclose(punteroFILE);

    printf("\nEl programa finalizó.\n\n");

    return 0;
}