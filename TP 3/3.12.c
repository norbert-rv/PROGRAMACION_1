/* Dado un arreglo de N elementos enteros, se debe invertir los elementos del mismo y presentar por
pantalla el arreglo resultante. No debe usar un arreglo auxiliar. Ej: El Arreglo dado: V=(2,4,7,9,5,6)
se convierte en: V=(6,5,9,7,4,2). */

#include <stdio.h>

int pedirOrdenArreglo();
void ingresarArregloEnteros(int orden, int arreglo[]);
void invertirArreglo(int orden, int arreglo[]);
void mostrarArreglo(int orden, int arreglo[]);

int main(int argc, char *argv[]) {
    int orden = pedirOrdenArreglo();
    int arreglo[orden];

    ingresarArregloEnteros(orden, arreglo);
    invertirArreglo(orden, arreglo);
    mostrarArreglo(orden, arreglo);

    return 0;
}

int pedirOrdenArreglo() {
    int N;

    do {
        printf("\nIngresar el orden del arreglo: ");
        scanf("%i", &N);

        if (N <= 0)
            printf("\n>> El orden debe ser mayor que 0!\n");
    } while (N <= 0 || N > 200);

    return N;
}

void ingresarArregloEnteros(int orden, int arreglo[]) {
    for (int i = 0; i < orden; i++) {
        printf("\n> Ingresar elemento %i: ", i + 1);
        scanf("%i", &arreglo[i]);
    }
}

void invertirArreglo(int orden, int arreglo[]) {
    // intercambio último elemento con primero elemento, anteúltimo elemento con segundo elemento, y así sucesivamente...
    int indice = orden - 1;
    int aux;

    // el ciclo se repite hasta la mitad de veces que el orden, ya que necesito recorrer la mitad de elementos para intercambiar de a pares
    for (int i = 0; i < (orden / 2); i++) {
        aux = arreglo[i];
        arreglo[i] = arreglo[indice];
        arreglo[indice] = aux;
        indice--;
    }
}

void mostrarArreglo(int orden, int arreglo[]) {
    printf("\n> El arreglo resultante es (");
    for (int i = 0; i < orden; i++) {
        if (i < orden - 1)
            printf("%i, ", arreglo[i]);
        else
            printf("%i)\n\n", arreglo[i]);
    }
}