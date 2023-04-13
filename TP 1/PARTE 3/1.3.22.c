/* Ingresar números positivos, la carga debe terminar cuando se ingrese un cero; luego presentar
por pantalla el menor valor de los números ingresados, indicando el orden en que ingresaron.
Utilizar una estructura como la siguiente para almacenar los resultados:
typedef struct{
int valor;
int posicion;
}num;
*/

#include <stdio.h>

typedef struct {
    int valor;
    int posicion;
} num;

int main(int argc, char *argv[]) {
    num menor, orden;
    int numero, contador = 0;
    menor.valor = 999999999;  // valor máximo que podrá tomar el int.

    do {
        printf("Ingresar un número positivo: ");
        scanf("%i", &numero);
        if (numero <= 0) {
            printf("¡El número debe ser positivo!\n");
            continue;
        } else {
            contador++;
            if (numero < menor.valor) {
                menor.valor = numero;
                orden.posicion = contador;
            }
        }
    } while (numero != 0);

    if (contador == 0)
        printf("El programa finalizó.\n");
    else
        printf("El menor de los números ingresados es %i y fue ingresado en la posición %i.\n", menor.valor, orden.posicion);

    return 0;
}
