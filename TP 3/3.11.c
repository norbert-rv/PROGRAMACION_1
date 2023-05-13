/* Dado un arreglo de N elementos enteros, se debe guardar sus elementos en otro arreglo de orden
N pero en sentido invertido. Ej: Arreglo dado: V=(2,4,7,9,5,6); Arreglo invertido: W=(6,5,9,7,4,2). */

#include <stdio.h>

int pedirOrdenArreglo();
void ingresarArregloEnteros(int orden, int arreglo[]);
void invertirArreglo(int orden, int arreglo[], int invertido[]);
void mostrarArreglos(int orden, int arreglo[], int invertido[]);

int main(int argc, char *argv[]) {
    int orden = pedirOrdenArreglo();
    int arregloEnteros[orden], invertido[orden];

    ingresarArregloEnteros(orden, arregloEnteros);
    invertirArreglo(orden, arregloEnteros, invertido);
    printf("\n-----------------------------------\n");
    mostrarArreglos(orden, arregloEnteros, invertido);

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

void invertirArreglo(int orden, int arreglo[], int invertido[]) {
    int indice = orden - 1;
    for (int i = 0; i < orden; i++) {
        invertido[indice] = arreglo[i];
        indice--;
    }
}

void mostrarArreglos(int orden, int arreglo[], int invertido[]) {
    printf("\n> El arreglo ingresado es (");
    for (int i = 0; i < orden; i++) {
        if (i < orden - 1)
            printf("%i, ", arreglo[i]);
        else
            printf("%i)\n\n", arreglo[i]);
    }

    printf("> El arreglo invertido es (");
    for (int i = 0; i < orden; i++) {
        if (i < orden - 1)
            printf("%i, ", invertido[i]);
        else
            printf("%i)\n", invertido[i]);
    }
    printf("\n");
}