/* Presentar por pantalla los N primeros números primos. Para esto utilice una función que
me devuelva el siguiente número primo, esta debe almacenar el anterior primo
mostrado en una variable estática.
int siguientePrimo();
*/

#include <stdio.h>

int esPrimo(int);
int pedirN();
int siguientePrimo();

// Función ppal
int main(int argc, char *argv[]) {
    int N = pedirN();

    for (int i = 0; i < N; i++) {
        printf("\n> %i \n\n", siguientePrimo());
    }

    return 0;
}

// Función que va pasando al siguiente numero primo (variable static int)
int siguientePrimo() {
    static int numero = 0;

    do {
        numero++;
    } while (!esPrimo(numero));

    return numero;
}

// Función para evaluar si un número es primo o no (boolean)
int esPrimo(int num) {
    int contador = 0;

    if (num == 0 || num == 1)  // caso por si numero es igual a 1 o 0.
        return 0;

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

// Función para pedir el número N
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