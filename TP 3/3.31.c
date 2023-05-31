/* Realizar un programa que permita cargar un arreglo bidimensional con N filas y M columnas cuyos
elementos sean números enteros y luego lo presente por pantalla recorriendolo por filas. Utilizar
una función para controlar que los valores de la cantidad de filas y columnas sean mayores que 1 y
menores que el máximo definido para el arreglo. */

#include <stdio.h>

int pedirFilasyColumnas(int limiteFilas, int limiteColumnas, int *columnas);
void cargarMatrizEntera(int filas, int columnas, int matriz[20][20]);
void mostrarMatrizEntera(int filas, int columnas, int matriz[20][20]);

int main(int argc, char *argv[]) {
    int matrizEnteros[20][20];
    int filas, columnas;

    filas = pedirFilasyColumnas(20, 20, &columnas);

    cargarMatrizEntera(filas, columnas, matrizEnteros);

    mostrarMatrizEntera(filas, columnas, matrizEnteros);

    printf("\n");

    return 0;
}

void cargarMatrizEntera(int filas, int columnas, int matriz[20][20]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("\n\nElemento de la fila > %i <, columna > %i <: ", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
        }
    }
}

int pedirFilasyColumnas(int limiteFilas, int limiteColumnas, int *columnas) {
    int filas;

    printf("\nIngresar numero de filas: ");
    do {
        scanf("%i", &filas);
    } while (filas <= 0 || filas > limiteFilas);

    printf("\nIngresar numero de columnas: ");
    do {
        scanf("%i", columnas);
    } while (*columnas <= 0 || *columnas > limiteColumnas);

    return filas;
}

void mostrarMatrizEntera(int filas, int columnas, int matriz[20][20]) {
    for (int i = 0; i < filas; i++) {
        printf("\n");
        for (int j = 0; j < columnas; j++) {
            printf("%i   ", matriz[i][j]);
        }
    }
    printf("\n");
}