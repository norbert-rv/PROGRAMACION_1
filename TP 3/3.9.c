/* Dado un arreglo V de orden N que contiene enteros positivos, generar un arreglo P de orden M que
contenga los elementos de V que sean números primos. Si el arreglo V no tiene números primos
entonces presentar un mensaje por pantalla.
Utilizar funciones para
● Controlar que el orden del arreglo que se va a cargar sea un entero positivo y que no
supere el valor máximo que puede contener el arreglo.
● Controlar que los valores ingresados sean positivos.
● Determinar si un número es primo o no.
● Armar el nuevo vector.
*/

#include <stdio.h>

int esPrimo(int);
int pedirOrdenArreglo();
void ingresarArregloEnterosPositivos(int orden, int arreglo[]);
// arreglo_original es el arreglo ingresado, arreglo_primo el nuevo arreglo con los primos del original
// función para armar un arreglo con los numeros primos y devolver un entero que será la cantidad de elementos del nuevo arreglo
int arregloPrimos(int arreglo_original[], int ordenArrOriginal, int arreglo_primos[]);
void mostrarArreglo(int orden, int arreglo[]);

int main(int argc, char *argv[]) {
    int V[100], P[100];
    int ordenV = pedirOrdenArreglo();
    int ordenP;

    ingresarArregloEnterosPositivos(ordenV, V);
    ordenP = arregloPrimos(V, ordenV, P);

    mostrarArreglo(ordenP, P);

    return 0;
}

int esPrimo(int num) {
    int contador = 0;

    if (num == 0 || num == 1)  // caso por si numero es igual a 1 o 0.
        return 0;

    for (int i = 1; i <= num; i++) {
        if (num % i == 0)
            contador++;
        if (contador > 2)
            break;
    }

    if (contador > 2)
        return 0;
    else
        return 1;
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

void ingresarArregloEnterosPositivos(int orden, int arreglo[]) {
    for (int i = 0; i < orden; i++) {
        do {
            printf("\n> Ingresar elemento %i: ", i + 1);
            scanf("%i", &arreglo[i]);

            if (arreglo[i] <= 0)
                printf("\n>> El número debe ser un entero positivo! \n");
        } while (arreglo[i] <= 0);
    }
}

int arregloPrimos(int arreglo_original[], int ordenArrOriginal, int arreglo_primos[]) {
    int indice = 0;
    int cantidadElementosP = 0;
    for (int i = 0; i < ordenArrOriginal; i++) {
        if (esPrimo(arreglo_original[i])) {
            arreglo_primos[indice] = arreglo_original[i];
            indice++;
            cantidadElementosP++;
        }
    }

    return cantidadElementosP;
}

void mostrarArreglo(int orden, int arreglo[]) {
    printf("\n> El arreglo resultante es: |");

    for (int i = 0; i < orden; i++) {
        printf(" %i |", arreglo[i]);
    }

    printf("\n");
}