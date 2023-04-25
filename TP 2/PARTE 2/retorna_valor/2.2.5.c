// PINGO QUE TE VOY A COMENTAR EL CÓDIGO

#include <stdio.h>

int ingresarEntero();
int es_positivo(int);
int controlarNumeros(int, int);
void sumarPrimos(int, int);
int es_primo(int);

int main(int argc, char *argv[]) {
    int N1, N2;

    N1 = ingresarEntero();
    do {
        N2 = ingresarEntero();

        if (!controlarNumeros(N1, N2))
            printf("\n>> El número debe ser mayor que el primer número ingresado! << \n");
    } while (!controlarNumeros(N1, N2));

    sumarPrimos(N1, N2);

    return 0;
}

int ingresarEntero() {
    int numero;

    do {
        printf("\nIngresar un número entero: ");
        scanf("%i", &numero);

        if (!es_positivo(numero))
            printf("\n>> El número debe ser positivo! << \n");
    } while (!es_positivo(numero));

    return numero;
}

int controlarNumeros(int num1, int num2) {
    if (num1 < num2)
        return 1;
    else
        return 0;
}

void sumarPrimos(int num1, int num2) {
    int suma_primos = 0;

    for (int i = ++num1; i < num2; i++) {
        if (es_primo(i))
            suma_primos += i;
    }

    printf("\n>> El resultado de la suma es: %i\n\n", suma_primos);
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