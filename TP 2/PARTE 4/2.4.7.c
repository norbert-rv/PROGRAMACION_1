/* Ingresar N números enteros no negativos, luego presentar por pantalla cuantas series de
números estrictamente crecientes aparecen. 5, 1, 9, 7, 6, 0, 1, 9, 3, 2, 4, 7, 9 => 3 series */

// NO FUNCIONA BIEN

#include <stdio.h>

int numeroCreciente();

int main(int argc, char *argv[]) {
    int numeroN, cantidadSeries;

    do {
        printf("\nCantidad de números a ingresar: ");
        scanf("%i", &numeroN);
    } while (numeroN <= 0);

    for (int i = 0; i < numeroN; i++) {
        cantidadSeries = numeroCreciente();
    }

    printf("\n> La cantidad de series de números crecientes es de %i\n\n", cantidadSeries);

    return 0;
}

int numeroCreciente() {
    int numero;
    static int numeroControl, caso0 = 1, contadorConsec = 0, contadorSeries = 0, sigueCreciendo = 1;
    do {
        printf("\nIngresar número entero no negativo: ");
        scanf("%i", &numero);
    } while (numero < 0);

    if (caso0) {
        numeroControl = numero;
        caso0 = 0;
    } else if (numero > numeroControl) {
        contadorConsec++;
        if (contadorConsec >= 1 && sigueCreciendo) {
            contadorSeries++;
            sigueCreciendo = 0;
        }
    } else {
        caso0 = 1;
        contadorConsec = 0;
        sigueCreciendo = 1;
    }

    return contadorSeries;
}
/*
int numeroCreciente() {
    int numero;
    // bandera para saber cuándo dejan de ser crecientes y consecutivos.
    int bandera = 0;
    static int caso0 = 1;

    // numeroControl para controlar si son consecutivos.
    static int numeroControl, contadorConsecutivos = 1, contadorSeries;

    do {
        printf("\nIngresar número entero no negativo: ");
        scanf("%i", &numero);
    } while (numero < 0);

    if (caso0) {
        numeroControl = numero;
        caso0 = 0;
    } else if (numero > numeroControl) {
        numeroControl = numero;
        if (contadorConsecutivos == 2) {
            contadorConsecutivos++;
            contadorSeries++;
        }
    } else {
        bandera = 1;
        caso0 = 1;
    }

    // if () {
    //     contadorSeries++;
    //     caso0 = 1;
    // }

    return contadorSeries;
} */