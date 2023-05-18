/* Cargar un arreglo con N números enteros, luego buscar el menor elemento impar contenido en el
mismo. En caso de no encontrar elementos impares presentar un mensaje por pantalla */

// Pasa algo raro con el 1 y el 3... no pasa siempre, que me toma el 3 como el menor impar en vez del 1.

#include <stdio.h>

int esPar(int);
int pedirOrdenArreglo();
void ingresarArregloEnteros(int orden, int arreglo[]);
int buscarMenorImpar(int orden, int arregloEntero[]);

int main(int argc, char *argv[]) {
    int arregloEnteros[100];
    int orden = pedirOrdenArreglo(), menorImpar;

    ingresarArregloEnteros(orden, arregloEnteros);
    menorImpar = buscarMenorImpar(orden, arregloEnteros);

    if (menorImpar == 0)
        printf("\n> El arreglo de enteros ingresado no contiene números impares! \n\n");
    else
        printf("\n> El menor elemento impar del arreglo ingresado es el %i \n\n", menorImpar);

    return 0;
}

int esPar(int num) {
    if (num == 0)
        return 1;
    if (num == 1)
        return 0;

    if (num % 2 == 0)
        return 1;
    else
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

int buscarMenorImpar(int orden, int arregloEntero[]) {
    int menorImpar;
    int case0 = 1;

    for (int i = 0; i < orden; i++) {
        if (case0)
            if (!esPar(arregloEntero[i])) {
                menorImpar = arregloEntero[i];
                case0 = 0;
            } else if (!esPar(arregloEntero[i]))
                if (arregloEntero[i] < menorImpar)
                    menorImpar = arregloEntero[i];
    }

    if (case0 == 1)
        return 0;  // el 0 es par así que no generaría ningun problema: menorImpar nunca sería igual a 0.
    else
        return menorImpar;
}