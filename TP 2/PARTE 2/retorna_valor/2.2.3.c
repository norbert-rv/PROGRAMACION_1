/* Ingresar un número entero positivo, luego presentar por pantalla un mensaje que indique si el
número ingresado es o no es primo. Para resolver implementar:
a- una función que realice el control de que el número sea positivo.
b- una función que determine si un número es primo. */

#include <stdio.h>

int es_positivo(int);
int es_primo(int);

int main(int argc, char *argv[]) {
    int numero;

    do {
        printf("\nIngrese un número positivo: ");
        scanf("%i", &numero);

        if (!es_positivo(numero))
            printf("\n>> Debe ingresar un número positivo! <<\n");
    } while (!es_positivo(numero));

    if (es_primo(numero))
        printf("\nEl número %i es primo.\n\n", numero);
    else
        printf("\nEl número %i no es primo.\n\n", numero);
}

int es_positivo(int num) {
    if (num > 0)
        return 1;
    else
        return 0;
}

int es_primo(int num) {
    int contador = 0;

    for (int i = 1; i <= num; i++) {
        if (num % i == 0)
            contador++;
        if (contador > 2)
            break;
    }

    if (contador > 2)
        return 0;
    else
        return 1;
}