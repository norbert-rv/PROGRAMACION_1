/* Realizar un programa que solicite una fecha (ingresando día, mes y año), luego deberá
realizar un control de la misma para considerarla válida, es decir que el valor numérico de
día, mes y año sean positivos; día no debe superar el valor 31 y mes el valor 12. El programa
deberá mostrar el mensaje correspondiente para cada caso. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int dia, mes, annio;
    int valida = 1;

    printf("Ingresar el día: ");
    scanf("%i", &dia);
    printf("Ingresar el mes: ");
    scanf("%i", &mes);
    printf("Ingresar el año: ");
    scanf("%i", &annio);

    if (dia < 0 || dia > 31) {
        valida = 0;
        if (dia < 0) printf("El día ingresado es menor que 0.\n");
        if (dia > 31) printf("El día ingresado es mayor que 31.\n");
    }
    if (mes < 0 || mes > 12) {
        valida = 0;
        if (mes < 0) printf("El mes ingresado es menor que 0.\n");
        if (mes > 12) printf("El mes ingresado es mayor que 12.\n");
    }
    if (annio < 1) {
        valida = 0;
        printf("El año ingresado es menor que 1.\n");
    }

    if (valida == 0) printf("Por lo tanto, la fecha %i / %i / %i es inválida.\n", dia, mes, annio);

    if (valida == 1) printf("La fecha %i / %i / %i es válida.\n", dia, mes, annio);

    return 0;
}