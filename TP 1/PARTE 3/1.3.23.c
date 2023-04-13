/* Ingresar N números (realizar el control de que N sea positivo), contabilizar cuántos números
pares e impares se encontraron, luego mostrar los resultados por pantalla. Utilizar una
estructura como la siguiente:
typdef struct{
int pares;
int impares;
}categorias;
*/

#include <stdio.h>

typedef struct {
    int pares;
    int impares;
} categorias;

int main(int argc, char *argv[]) {
    int N, numero;
    categorias contador_pares, contador_impares;
    contador_pares.pares = 0;
    contador_impares.impares = 0;

    do {
        printf("Ingresar la cantidad N de números: ");
        scanf("%i", &N);
    } while (N <= 0);

    for (int i = 0; i < N; i++) {
        printf("Ingresar un número: ");
        scanf("%i", &numero);

        if (numero % 2 == 0)
            contador_pares.pares++;
        else
            contador_impares.impares++;
    }

    printf("La cantidad de pares es %i y la cantidad de impares es %i.\n", contador_pares.pares, contador_impares.impares);

    return 0;
}