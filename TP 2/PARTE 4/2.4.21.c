/* Realizar un programa que permita ingresar N números enteros positivos, luego
determinar el valor promedio (o media aritmética) de los números ingresados que sean
primos.
Para resolver este problema deberá implementar las siguientes funciones:
a- ingresarEntero(): permite ingresar un número entero y controlar si el mismo es
positivo.
b- esPrimo(): para determinar si un número es primo.
c- promedioPrimos(): calcula el promedio de los números primos (esta función no debe
retornar un valor)
Se debe presentar por pantalla el promedio calculado, o en su defecto un mensaje si en
la serie ingresada no hay números primos.
Aclaración: Ud debe definir si las funciones arribas mencionadas reciben o no
parámetros, como así también si retornan o no valor */

#include <stdio.h>

int ingresarEntero();
int esPrimo(int);
void promedioPrimos(int numero, int *promedio);

int main(int argc, char *argv[]) {
    int numeroN, numero, promedio;

    do {
        printf("\nDetermine la cantidad de números a ingresar: ");
        scanf("%i", &numeroN);

        if (numeroN <= 0)
            printf("\nEl número debe ser positivo!...");
    } while (numeroN <= 0);

    for (int i = 0; i < numeroN; i++) {
        numero = ingresarEntero();
        promedioPrimos(numero, &promedio);
    }

    if (promedio != 0)
        printf("\n> El promedio de números primos es %i \n\n", promedio);
    else
        printf("\nNo se ingresó ningún número primo...\n\n");

    return 0;
}
// la función promedioPrimos usa variables static para acumular la cantidad de primos y el total que suman dichos primos.
void promedioPrimos(int numero, int *promedio) {
    static int cantidadPrimos, totalPrimos;
    if (esPrimo(numero)) {
        cantidadPrimos++;
        totalPrimos += numero;
        *promedio = totalPrimos / cantidadPrimos;
    }
}

int esPrimo(int numero) {
    int contador = 0;
    // descarto los dos casos iniciales que no son primos.
    if (numero == 0 || numero == 1)
        return 0;
    // cuento la cantidad de divisores y me detengo cuando se llegue a más de dos para no seguir ejecutando.
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0)
            contador++;
        if (contador > 2)
            break;
    }
    // si tiene más de dos divisores no es primo.
    if (contador > 2)
        return 0;
    else
        return 1;
}

int ingresarEntero() {
    int entero;
    do {
        printf("\nIngresar un número entero positivo: ");
        scanf("%i", &entero);

        if (entero <= 0)
            printf("\nEl número debe ser positivo!...\n");
    } while (entero <= 0);

    return entero;
}