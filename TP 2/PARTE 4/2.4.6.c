/* Ingresar N números enteros, luego presentar por pantalla la cantidad de series de
números impares ingresados. Se considera serie si tiene 2 o más elementos seguidos.
Ejemplo: 4, 9, 2, 5, 3, 2, 15, 3, 7, 9
|-----| |------------|
1 2 2 series
*/

#include <stdio.h>

int pedirN();
int esPar(int);
int contadorSeries(int);

int main(int argc, char *argv[]) {
    printf("\nPrograma que muestra la cantidad de series de números impares ingresados...\n");

    int N = pedirN(), numero, cant_series;

    for (int i = 0; i < N; i++) {
        printf("\nIngresar un número: ");
        scanf("%i", &numero);
        cant_series = contadorSeries(numero);
    }

    printf("\n> La cantidad de series de números impares es: %1i \n\n", cant_series);

    return 0;
}

int contadorSeries(int num) {
    static int seriesImpares = 0, contador = 0;

    if (!esPar(num)) {
        contador++;
        printf("\n\n>>> %i\n\n", contador);
    } else {
        contador = 0;
    }

    if (contador >= 2) {
        seriesImpares++;
    }

    return seriesImpares;
}

int esPar(int num) {
    if (num % 2 == 0)
        return 1;
    else
        return 0;
}

int pedirN() {
    int num;

    do {
        printf("\nIngresar el número N: ");
        scanf("%i", &num);

        if (num <= 0)
            printf("> Ingresar un número positivo! <\n\n");
    } while (num <= 0);

    return num;
}