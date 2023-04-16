/* Una materia solicitó a la cátedra crear un bolillero para sorteo de temas en exámenes,
para cumplir con este pedido se debe desarrollar un programa que genere un número
aleatorio entre dos valores enteros positivos a y b, los cuales hacen referencia al rango
de números de temas que entran en el sorteo. Se pide ingresar el rango de temas en la
variables a - b y mostrar el tema que salió en el sorteo. Por ejemplo:
Tema a = 2 , b=10 , implican en el sorteo entran los temas desde el 2 al 10 inclusive. Al
generar un número aleatorio el mismo debe estar contenido entre esos valores. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int A, B;  // variables que definen el rango de temas para la generación de numeros aleatorios

    do {
        printf("\nIngrese el inicio del rango de temas (A):  ");
        scanf("%i", &A);
    } while (A <= 0);

    do {
        printf("\nIngrese el final del rango de temas (B):  ");
        scanf("%i", &B);
    } while (B <= 0);

    printf("\nEl tema que salió en el sorteo es el... %i\n\n", rand() % (B + 1 - A) + A);

    return 0;
}