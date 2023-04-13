/* Se ingresan N números enteros, presentar el promedio de los pares y el promedio de los
impares. No considerar el número cero como número par ni como impar. Controlar que
el valor de N sea positivo */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int N, num, suma_pares = 0, suma_impares = 0, contador_pares = 0, contador_impares = 0;
    float promedio_pares = 0, promedio_impares = 0;

    do {
        printf("Ingresar la cantidad de números a ingresar: ");
        scanf("%i", &N);

    } while (N <= 0);

    for (int i = 0; i < N; i++) {
        printf("Ingresar un número: ");
        scanf("%i", &num);

        if (num == 0) continue;

        if (num % 2 == 0) {
            suma_pares += num;
            contador_pares++;

        } else {
            suma_impares += num;
            contador_impares++;
        }
    }

    if (contador_pares != 0) promedio_pares = suma_pares / contador_pares;
    if (contador_impares != 0) promedio_impares = suma_impares / contador_impares;

    printf("El promedio de números pares es: %.2f\nEl promedio de números impares es: %.2f\n", promedio_pares, promedio_impares);

    return 0;
}