/* Realizar un programa que permita cargar un arreglo de orden N de números enteros. Luego ordenar
sus elementos en forma descendente y presentarlos por pantalla. No utilizar un arreglo auxiliar
para el ordenamiento. */

// repasar implementación de BubbleSort.

#include <stdio.h>

int pedirOrdenArreglo();
void ingresarArregloEnteros(int orden, int arreglo[]);
void mostrarArreglo(int orden, int arreglo[]);
void ordenarDescendente(int orden, int arreglo[]);

int main(int argc, char *argv[]) {
    int arregloEnteros[100];
    int orden = pedirOrdenArreglo();

    ingresarArregloEnteros(orden, arregloEnteros);
    ordenarDescendente(orden, arregloEnteros);
    mostrarArreglo(orden, arregloEnteros);

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

void mostrarArreglo(int orden, int arreglo[]) {
    printf("\n> El arreglo ingresado (ordenado de forma descendente) es (");
    for (int i = 0; i < orden; i++) {
        if (i < orden - 1)
            printf("%i, ", arreglo[i]);
        else
            printf("%i)\n\n", arreglo[i]);
    }
}

void ordenarDescendente(int orden, int arreglo[]) {
    int aux, j;

    for (int i = 0; i < orden; i++) {
        for (j = 0; j < orden - 1; j++) {
            if (arreglo[i] > arreglo[j]) {
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
}