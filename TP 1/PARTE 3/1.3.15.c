/* Ingresar un número entero (controlar que no sea negativo), presentar por pantalla, en el
programa principal un mensaje que indique si el mismo tiene formato binario, es decir
que solo esté conformado por 1 o 0. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num, es_binario = 1, aux;

    do {
        printf("Ingresar un número entero no negativo: ");
        scanf("%i", &num);
    } while (num < 0);

    aux = num;

    while (num != 0) {
        if (num % 10 != 1 && num % 10 != 0) {
            es_binario = 0;
        }
        num /= 10;
    }

    if (es_binario == 1) {
        printf("El número %i TIENE formato binario.\n", aux);
    } else {
        printf("El número %i NO TIENE formato binario.\n", aux);
    }

    return 0;
}