/* Realizar un programa que permita determinar cuántas veces se encuentra el valor x en un arreglo.
Para esto se deberá:
○ ingresar números enteros en un arreglo de orden N
○ ingresar un valor x
○ mostrar por pantalla el arreglo ingresado
○ mostrar el elemento buscado x y la cantidad de veces que se encontró el elemento
buscado. En caso de que el vector no contenga un elemento de valor igual a x, mostrar el
mensaje correspondiente */

#include <stdio.h>

int pedirOrdenArreglo();
void ingresarArregloEnteros(int orden, int arreglo[]);
int contadorApariciones(int numeroX, int ordenArreglo, int arreglo[]);
void mostrarArregloEntero(int orden, int arreglo[]);

int main(int argc, char *argv[]) {
    int ordenArreglo = pedirOrdenArreglo(), aparicionesDeX, numeroX;
    int Enteros[ordenArreglo];

    ingresarArregloEnteros(ordenArreglo, Enteros);

    printf("\n> Ingresar numero X a buscar en el arreglo: ");
    scanf("%i", &numeroX);

    aparicionesDeX = contadorApariciones(numeroX, ordenArreglo, Enteros);

    mostrarArregloEntero(ordenArreglo, Enteros);
    if (aparicionesDeX != 0)
        printf("\n> El elemento buscado es %i y apareció %i veces.\n\n", numeroX, aparicionesDeX);
    else
        printf("\n> El número %i no aparece en el arreglo.\n\n", numeroX);

    return 0;
}

int pedirOrdenArreglo() {
    int N;

    do {
        printf("\nIngresar el orden del arreglo: ");
        scanf("%i", &N);

        if (N <= 0)
            printf("\n>> El orden debe ser mayor que 0!\n");
    } while (N <= 0);

    return N;
}

void ingresarArregloEnteros(int orden, int arreglo[]) {
    for (int i = 0; i < orden; i++) {
        printf("\n> Ingresar elemento %i: ", i + 1);
        scanf("%i", &arreglo[i]);
    }
}

int contadorApariciones(int numeroX, int ordenArreglo, int arreglo[]) {
    int contador = 0;

    for (int i = 0; i < ordenArreglo; i++) {
        if (arreglo[i] == numeroX)
            contador++;
    }

    return contador;
}

void mostrarArregloEntero(int orden, int arreglo[]) {
    printf("\n> El arreglo ingresado es:  |");

    for (int i = 0; i < orden; i++) {
        printf(" %i |", arreglo[i]);
    }

    printf("\n");
}