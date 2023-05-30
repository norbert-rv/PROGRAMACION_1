/* Ingresar una cadena de caracteres que contenga dos o más palabras separadas por un espacio
en blanco. Luego presentar por pantalla la cadena ingresada y la cantidad de palabras que posea.
Ejemplo: Se ingresa -> Tercer evaluativo de Programación I -> Muestra: 5 palabras. */

#include <stdio.h>

#define MAX 100

int contadorPalabras(char cadena[]);

int main(int argc, char *argv[]) {
    char cadena[MAX];
    int cantPalabras;

    printf("\nIngresar una cadena de caracteres: ");
    fgets(cadena, MAX, stdin);

    cantPalabras = contadorPalabras(cadena);

    printf("\nLa cadena ingresada tiene %i palabras. \n\n", cantPalabras);

    return 0;
}

int contadorPalabras(char cadena[]) {
    int cantPalabras = 1;

    // la funcion supone que si o si tiene que haber una palabra al menos. Si detecta un espacio y después de ese espacio no termina el string, entonces cuenta una palabra mas.
    for (int i = 0; cadena[i] != '\n'; i++) {
        if (cadena[i] == ' ' && cadena[i + 1] != '\n')
            cantPalabras++;
    }

    return cantPalabras;
}