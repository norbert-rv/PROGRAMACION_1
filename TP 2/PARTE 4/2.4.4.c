/* Realizar un programa que permita generar N códigos incrementales automáticos a partir
de un cierto número base definido previamente. Por ejemplo, si se quieren generar 5
códigos incrementales a partir de un cierto número, como ser el 10000, se generarán los
siguientes códigos: 10001, 10002, 10003, 10004, 10005.
*/

#include <stdio.h>

int pedirN();
int generadorNumero();

int main(int argc, char *argv[]) {
    printf("\nPrograma para presentar los N códigos incrementales (base 5000)\n");

    int N = pedirN();

    for (int i = 0; i < N; i++) {
        printf("\n> %i\n\n", generadorNumero());
    }

    return 0;
}

// Función para códigos incrementales de base fija
int generadorNumero() {
    static int numero = 5000;  // defino la base para el código incremental (constante literal)
    numero++;
    return numero;
}

int pedirN() {
    int num;

    do {
        printf("\nIngresar el número N: ");
        scanf("%i", &num);

        if (num <= 0)
            printf("> Ingresar un número positivo! <\n\n");
    } while (num <= 0);

    return num;
}