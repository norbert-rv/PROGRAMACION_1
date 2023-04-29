/* (Referencia ejercicio 2 del TP2-Parte 3)Ingresar N caracteres en un programa, identificar
cuántos caracteres son letras minúsculas e indicar el porcentaje con respecto al total de
caracteres.
Por ejemplo: se ingresa N= 10 y se ingresan los siguientes caracteres: e 5 T 1 C i ? / 1 >
Se debe mostrar que el porcentaje de minúsculas fue del 20%.
Para ello usar funciones para:
● controlar el valor de N,
● contar cuantos caracteres en minúsculas se ingresaron, con una función con la
siguiente declaración:
void contarMinusculas(char c, int *cantidadMinusculas);
● calcular el porcentaje con una función con esta declaración:
void calcularPorcentaje(int cantidad, int total, float *porcentaje);
● presentar por pantalla el promedio, con una función con la siguiente declaración:
void mostrarPorcentaje(float porcentaje);
*/

#include <ctype.h>
#include <stdio.h>

int es_positivo(int);
void contarMinusculas(char c, int *cantidadMinusculas);
void calcularPorcentaje(int cantidad, int total, float *porcentaje);
void mostrarPorcentaje(float porcentaje);

int main(int argc, char *argv[]) {
    int N, cantidadMinusculas = 0;
    float porcentaje;
    char car;

    do {
        printf("\nIngresar el número N de caracteres a ingresar: ");
        scanf("%i", &N);
    } while (!es_positivo(N));

    while (getchar() != '\n')
        ;

    for (int i = 0; i < N; i++) {
        printf("Ingresar caracter: ");
        car = getchar();
        while (getchar() != '\n')
            ;
        contarMinusculas(car, &cantidadMinusculas);
    }

    calcularPorcentaje(cantidadMinusculas, N, &porcentaje);
    mostrarPorcentaje(porcentaje);

    return 0;
}

int es_positivo(int num) {
    if (num > 0)
        return 1;
    else
        return 0;
}

void contarMinusculas(char c, int *cantidadMinusculas) {
    if (islower(c))
        *cantidadMinusculas = *cantidadMinusculas + 1;
}

void calcularPorcentaje(int cantidad, int total, float *porcentaje) {
    *porcentaje = (cantidad * 100) / (total * 1.0);
}

void mostrarPorcentaje(float porcentaje) {
    printf("\nEl porcentaje de letras minúsculas es del %.2f%%\n\n", porcentaje);
}