/* Realizar un programa que permita ingresar N números enteros positivos y muestre la
suma de todos ellos. Para esto, escriba una función que reciba un número entero como
argumento y devuelva la suma acumulativa de todos los números ingresados. Utilice una
variable estática para almacenar la suma acumulativa. */

#include <stdio.h>

int sumaAcumulativa(int);

int main(int argc, char *argv[]) {
    int N, num, suma;
    do {
        printf("\nCuántos números enteros ingresará? ");
        scanf("%i", &N);
    } while (N <= 0);

    for (int i = 0; i < N; i++) {
        do {
            printf("Ingresar número: ");
            scanf("%i", &num);

            if (num <= 0)
                printf("\nIngresar un número entero positivo!...\n");
        } while (num <= 0);

        suma = sumaAcumulativa(num);
    }

    printf("\nLa suma de todos los números ingresados es %i \n\n", suma);
}

int sumaAcumulativa(int num) {
    static int suma = 0;
    suma += num;
    return suma;
}