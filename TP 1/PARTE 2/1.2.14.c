/* Ingresar un número positivo, luego presentar por pantalla el número ingresado y su
invertido. Ejemplo: si se ingresa el número 5219 -> el invertido es 9125 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num, invertido = 0, resto, aux;

    printf("Ingresar un número: ");
    scanf("%i", &num);

    aux = num;

    while (num != 0) {
        resto = num % 10;
        invertido = invertido * 10 + resto;
        num /= 10;
    }

    printf("El invertido es %i.\n", invertido);

    return 0;
}