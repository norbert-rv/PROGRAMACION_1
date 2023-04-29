/* (Referencia ejercicio 12 del TP2-Parte 2) Implementar un programa que permita determinar
si un medicamento se encuentra o no vencido, conociendo la fecha de vencimiento y la fecha
actual. Para resolver este ejercicio deberá:
○ Usar del ejercicio (Referencia ejercicio 11 del TP2-Parte 2) las funciones para leer una
fecha y controlar su validez.
○ Implementar una función que determine si el medicamento está vencido y que presente
por pantalla el mensaje correspondiente. (esta función no debe retornar un valor)
Almacenar la fecha en un dato tipo estructura con el siguiente formato:
typdef struct{
int dia;
int mes;
int anio;
}fecha;
*/

#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int anio;
} fecha;

fecha pedir_fecha();
int controlar_fecha(fecha);
void esta_vencido(fecha);

int main(int argc, char *argv[]) {
    fecha una_fecha, fecha_actual = {29, 4, 2023};

    do {
        una_fecha = pedir_fecha();

        if (!controlar_fecha(una_fecha))
            printf("\nLa fecha ingresada no es válida. Intentelo nuevamente...\n\n");
    } while (!controlar_fecha(una_fecha));

    esta_vencido(una_fecha);

    return 0;
}

fecha pedir_fecha() {
    fecha una_fecha;

    printf("\nIngresar el día: \n\n");
    scanf("%i", &una_fecha.dia);
    printf("\nIngresar el mes: \n\n");
    scanf("%i", &una_fecha.mes);
    printf("\nIngesar el año: \n\n");
    scanf("%i", &una_fecha.anio);

    return una_fecha;
}

int controlar_fecha(fecha una_fecha) {
    if (una_fecha.dia < 1 || una_fecha.dia > 31 || una_fecha.mes < 1 || una_fecha.mes > 12 || una_fecha.anio < 1900)
        return 0;
    else
        return 1;
}

void esta_vencido(fecha fechita) {
    if (fechita.anio > 2023 || (fechita.anio == 2023 && fechita.mes == 4 && fechita.dia >= 29) || (fechita.anio == 2023 && fechita.mes > 4))
        printf("\nEl producto está vencido. NO USAR!\n\n");
    else
        printf("\nEl producto no alcanzó su fecha de vencimiento. ES SEGURO USARLO!\n\n");
}