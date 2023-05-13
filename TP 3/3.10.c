/* Realizar un programa que permita ingresar números enteros en un arreglo de orden N, luego
desplazar sus elementos X lugares a la derecha (tener en cuenta que al mover los elementos unba
posición hacia la derecha, el último elemento del arreglo pasará a ser el primer elemento del
arreglo). Mostrar por pantalla el arreglo ingresado y el arreglo modificado. Por ejemplo, si se ingresa
el siguiente arreglo: (3, 0, 8, 2, 1, 7) y X=3, entonces el arreglo modificado debe quedar del siguiente
modo: (2, 1, 7, 3, 0, 8). */

#include <stdio.h>

int pedirOrdenArreglo();
void ingresarArregloEnteros(int orden, int arreglo[]);
void moverElementosArreglo(int X_lugares, int ordenArr, int arregloOriginal[], int nuevoArreglo[]);
void mostrarArreglos(int orden, int ArrOriginal[], int nuevoArr[], int X_lugares);

int main(int argc, char *argv[]) {
    int ordenN = pedirOrdenArreglo(), X;  // X es el numero de lugares que se desplazaran los elementos
    int arregloEnteros[ordenN], arregloDesplazado[ordenN];

    ingresarArregloEnteros(ordenN, arregloEnteros);

    // controlo la entrada de datos del numero de posiciones a desplazar
    do {
        printf("\n¿Cuántas posiciones desplazará los elementos del arreglo? ");
        scanf("%i", &X);

        if (X < 0)
            printf("\n>> No puede ser un valor negativo! \n");
    } while (X < 0);

    moverElementosArreglo(X, ordenN, arregloEnteros, arregloDesplazado);
    mostrarArreglos(ordenN, arregloEnteros, arregloDesplazado, X);

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

void moverElementosArreglo(int X_lugares, int ordenArr, int arregloOriginal[], int nuevoArreglo[]) {
    // (i + X) % orden me permite asegurarme de que nunca se pase el orden del arreglo y vuelva a empezar desde 0 si i + X es mayor que el orden
    for (int i = 0; i < ordenArr; i++) {
        nuevoArreglo[(i + X_lugares) % ordenArr] = arregloOriginal[i];
    }
}

void mostrarArreglos(int orden, int ArrOriginal[], int nuevoArr[], int X_lugares) {
    printf("\n> El arreglo original ingresado es: (");
    for (int i = 0; i < orden; i++) {
        if (i < orden - 1)
            printf("%i, ", ArrOriginal[i]);
        else
            printf("%i)\n", ArrOriginal[i]);
    }

    printf("\n> El nuevo arreglo desplazado %i lugares es: (", X_lugares);
    for (int i = 0; i < orden; i++) {
        if (i < orden - 1)
            printf("%i, ", nuevoArr[i]);
        else
            printf("%i)\n", nuevoArr[i]);
    }

    printf("\n");
}