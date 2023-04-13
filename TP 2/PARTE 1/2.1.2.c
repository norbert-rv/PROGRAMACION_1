/* Realizar un programa que halle cualquier raíz de un número entero positivo. El usuario
deberá indicar el número (por ejemplo, 2) y el índice de la raíz (por ejemplo, 3 para la
raíz cúbica). Pista: hallar la raíz cúbica de 2 es lo mismo que elevar 2 a 1/3. */

#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    double numero, indice_raiz, raiz;

    do {
        printf("Ingresar un número entero positivo: ");
        scanf("%lf", &numero);
        printf("%.2lf\n", numero);

        if (numero <= 0)
            printf("> El número debe ser entero positivo! <\n\n");
    } while (numero <= 0);

    do {
        printf("Ingresar el índice de la raíz: ");
        scanf("%lf", &indice_raiz);
        printf("%.2lf\n", indice_raiz);
        if (indice_raiz < 2)
            printf("> El número debe ser mayor o igual a 2! \n\n");
    } while (indice_raiz < 2);

    //   raiz = pow(numero, 1/indice_raiz);
    printf("\nLa raíz es: %.2lf\n\n", pow(numero, 1 / indice_raiz));

    return 0;
}