/* Realizar un programa que permita cargar un arreglo bidimensional con N filas y M columnas cuyos
elementos sean caracteres y luego lo presente por pantalla recorriendolo por columnas. Utilizar una
función para controlar que los valores de la cantidad de filas y columnas sean mayores que 1 y
menores que el máximo definido para el arreglo. */

#include <stdio.h>

#define MAXfilas 20
#define MAXcolumnas 20

int pedirFilasyColumnas(int limiteFilas, int limiteColumnas, int *columnas);
void cargarMatrizCar(int filas, int columnas, char matrizCar[MAXfilas][MAXcolumnas]);
void mostrarMatrizCarColumnas(int filas, int columnas, char matrizCar[MAXfilas][MAXcolumnas]);

int main(int argc, char *argv[]) {
    char arregloCar[MAXfilas][MAXcolumnas];
    int filas, columnas;

    filas = pedirFilasyColumnas(MAXfilas, MAXcolumnas, &columnas);
    getchar();

    cargarMatrizCar(filas, columnas, arregloCar);

    mostrarMatrizCarColumnas(filas, columnas, arregloCar);

    printf("\n\n");

    return 0;
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

void cargarMatrizCar(int filas, int columnas, char matrizCar[MAXfilas][MAXcolumnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("\nElemento fila %i , columna %i: ", i + 1, j + 1);
            matrizCar[i][j] = getchar();
            getchar();
        }
    }
}

void mostrarMatrizCarColumnas(int filas, int columnas, char matrizCar[MAXfilas][MAXcolumnas]) {
    for (int i = 0; i < filas; i++) {
        printf("\n");
        for (int j = 0; j < columnas; j++) {
            printf("%c\t", matrizCar[i][j]);
        }
    }
}