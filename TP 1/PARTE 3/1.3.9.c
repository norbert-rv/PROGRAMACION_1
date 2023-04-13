/* Dado un número natural de 4 o más dígitos(realizar este control), presentar por pantalla
el número y su invertido. Ejemplo : número = 34256, invertido = 65243 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num, aux, resto, invertido = 0;

    do {
        printf("Ingresar un número natural de 4 o más dígitos: ");
        scanf("%i", &num);

    } while (num <= 999);

    aux = num;

    while (num != 0) {
        resto = num % 10;
        num /= 10;
        invertido = invertido * 10 + resto;
    }

    printf("El número ingresado es %i y su invertido es %i.\n", aux, invertido);

    return 0;
}