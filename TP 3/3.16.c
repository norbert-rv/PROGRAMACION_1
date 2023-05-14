/* Ingresar en un arreglo de caracteres el nombre de una persona, ingresar cada letra en un elemento
del arreglo. Luego, ingresar un carácter por teclado y comprobar si dicho carácter pertenece al
nombre ingresado. Finalmente, mostrar el arreglo y el mensaje correspondiente */

/* Lo hice con un truquito. Pero era más fácil hacerlo son scanf("%s", &nombre); pero no sé qué piden los profes...
decidí ingresarlo caracter por caracter. En realidad el programa me pida si el caracter pertenece o no al nombre ingresado,
yo le conté la cantidad de veces también, no me dí cuenta. */

#include <stdio.h>

void ingresarNombre(char nombre[]);
void mostrarArregloCar(char arreglo[]);
int buscadorCaracterCant(char arreglo[], char caracter);

int main(int argc, char *argv[]) {
    char nombre[100];
    char caracterBuscar;
    int cantidadCaracteres;

    ingresarNombre(nombre);

    printf("\n> ¿Qué caracter desea buscar dentro del nombre? ");
    caracterBuscar = getchar();
    getchar();

    cantidadCaracteres = buscadorCaracterCant(nombre, caracterBuscar);

    mostrarArregloCar(nombre);

    if (cantidadCaracteres != 0)
        if (cantidadCaracteres != 1)
            printf("> El caracter %c aparece %i veces...\n\n", caracterBuscar, cantidadCaracteres);
        else
            printf("> El caracter %c aparece 1 vez...\n\n", caracterBuscar);
    else
        printf("> El caracter %c no aparece ninguna vez en el nombre... \n\n", caracterBuscar);

    return 0;
}
void ingresarNombre(char nombre[]) {
    int i = 0;
    printf("\nIngresar un nombre: ");
    nombre[i] = getchar();
    while (nombre[i] != '\n') {
        i++;
        nombre[i] = getchar();
    }
}

void mostrarArregloCar(char arreglo[]) {
    int i = 0;

    printf("\n> El nombre ingresado es: ");
    while (arreglo[i] != '\n') {
        printf("%c", arreglo[i]);
        i++;
    }
    printf("\n\n");
}

int buscadorCaracterCant(char arreglo[], char caracter) {
    int indice = 0, contadorCar = 0;

    while (arreglo[indice] != '\n') {
        if (arreglo[indice] == caracter)
            contadorCar++;
        indice++;
    }

    return contadorCar;
}