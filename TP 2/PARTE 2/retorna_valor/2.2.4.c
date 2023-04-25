/* Realizar un programa en lenguaje C que permita ingresar un valor N y muestre las N letras en
mayúsculas en orden descendente.
Por ejemplo si se ingresa N = 5, deberá mostrar: Z, Y, X, W, V
Para resolver implementar:
a- una función que realice el control de que N sea positivo
b- una función que muestre las letras en mayúsculas en orden descendente */

#include <stdio.h>

int es_positivo(int);
void mostrar_mayus_descendente(int);

int main(int argc, char *argv[]) {
    int N;

    do {
        printf("\nIngrese un número positivo: ");
        scanf("%i", &N);

        if (!es_positivo(N))
            printf("\n>> Debe ingresar un número positivo! <<\n");
    } while (!es_positivo(N));

    mostrar_mayus_descendente(N);
    printf("\n");

    return 0;
}

int es_positivo(int num) {
    if (num > 0)
        return 1;
    else
        return 0;
}

void mostrar_mayus_descendente(int num) {
    char car = 'Z';
    printf("\n");
    for (int i = 0; i < num; i++) {
        if (car < 'A') {
            printf("\n\nYa no quedan letras mayúsculas para mostrar...\n");
            break;
        }

        printf("%c  ", car);
        car--;
    }
    printf("\n");
}