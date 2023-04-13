/* Dados N1 menor que N2 (realizar este control), diseñar un programa que sume los
números enteros comprendidos entre N1 y N2. Presentar por pantalla dicha suma.
Ejemplo: N1 = 6, N2 = 12; Suma = 45 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int numero1, numero2, suma = 0;

    do {
        printf("Ingresar número 1 y número 2 (número 1 menor que número 2).\nNúmero 1: ");
        scanf("%i", &numero1);
        printf("Número 2: ");
        scanf("%i", &numero2);
    } while (numero1 >= numero2);

    numero1++;

    for (int i = numero1; i < numero2; i++) {
        suma += i;
    }

    printf("La suma de los enteros entre los números ingresados es: %i.\n", suma);

    return 0;
}