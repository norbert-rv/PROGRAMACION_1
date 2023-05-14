/* Ingresar en un arreglo de caracteres el nombre de una persona, ingresar cada letra en un elemento
del arreglo. Luego, ingresar un carácter por teclado y comprobar si dicho carácter pertenece al
nombre ingresado. Finalmente, mostrar el arreglo y el mensaje correspondiente */

// completar. Cómo debería trabajar? Ingresando caracter por caracter o usando %s? Creo que es para la próxima clase...

#include <ctype.h>
#include <stdio.h>

void ingresarNombre(char nombre[]);
void mostrarArregloCar(int orden, char arreglo[]);

int main(int argc, char *argv[]) {
    char nombre[100];

    ingresarNombre(nombre);
    mostrarArregloCar(8, nombre);
    return 0;
}
void ingresarNombre(char nombre[]) {
    printf("\nIngresar un nombre: ");
    scanf("%s", nombre);
}

void mostrarArregloCar(int orden, char arreglo[]) {
    printf("El nombre ingresado es: %s\n", arreglo);
}