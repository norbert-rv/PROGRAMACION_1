/* Realizar un programa que permita cargar un arreglo V de orden N de números enteros y luego
presente por pantalla el arreglo ingresado y genere otro arreglo P que contenga todos los números
pares de V, y lo presente por pantalla. En caso de que V no tenga números pares mostrar el
correspondiente mensaje por pantalla. */

#include <stdio.h>

int pedirOrdenArreglo();
void ingresarArregloEnteros(int orden, int arreglo[]);
int esPar(int);
// función que crea un arreglo con los elementos pares del otro arreglo
int generadorPares(int orden, int arreglo[], int pares[]);
void mostrarArreglo(int orden, int arreglo[]);
void mostrarPares(int orden, int arreglo[]);

int main(int argc, char *argv[]) {
    int enteros[100], pares[100];
    int orden = pedirOrdenArreglo(), cant_pares;

    ingresarArregloEnteros(orden, enteros);
    mostrarArreglo(orden, enteros);

    cant_pares = generadorPares(orden, enteros, pares);

    if (pares == 0)
        printf("\n> El arreglo ingresado no contiene números pares.\n");
    else
        mostrarPares(cant_pares, pares);

    return 0;
}

int pedirOrdenArreglo() {
    int N;

    do {
        printf("\nIngresar el orden del arreglo: ");
        scanf("%i", &N);

        if (N <= 0 || N > 100)
            printf("\n> El orden debe estar entre 1 y 100! \n");
    } while (N <= 0 || N > 100);

    return N;
}

void ingresarArregloEnteros(int orden, int arreglo[]) {
    for (int i = 0; i < orden; i++) {
        printf("\n> Ingresar elemento %i: ", i + 1);
        scanf("%i", &arreglo[i]);
    }
}

int esPar(int numero) {
    if (numero % 2 == 0)
        return 1;
    else
        return 0;
}

int generadorPares(int orden, int arreglo[], int pares[]) {
    int contadorPares = 0;
    int indice = 0;

    for (int i = 0; i < orden; i++) {
        if (esPar(arreglo[i])) {
            pares[indice] = arreglo[i];
            indice++;
            contadorPares++;
        }
    }

    return contadorPares;
}

void mostrarArreglo(int orden, int arreglo[]) {
    printf("\n> El arreglo ingresado es (");
    for (int i = 0; i < orden; i++) {
        if (i < orden - 1)
            printf("%i, ", arreglo[i]);
        else
            printf("%i)\n\n", arreglo[i]);
    }
}

void mostrarPares(int orden, int arreglo[]) {
    printf("\n> El arreglo ingresado tiene %i números pares y el arreglo resultante es: (", orden);

    for (int i = 0; i < orden; i++) {
        if (i < orden - 1)
            printf("%i, ", arreglo[i]);
        else
            printf("%i)\n\n", arreglo[i]);
    }
}