/* Ingresar, en una variable tipo estructura, los datos referentes a una fecha (día, mes, año). Luego
usar una función para presentar por pantalla el contenido de dicha variable con el siguiente
formato "la fecha ingresada es 5-4-1996"(dónde 5 corresponde a los días, 4 a los meses y 1996 a
los años).
Usar la siguiente estructura para la fecha
typedef struct {
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

void mostrar_fecha(fecha una_fecha);

int main(int argc, char *argv[]) {
    fecha una_fecha;

    printf("\nIngrese los datos de una fecha...\n\n");
    do {
        printf("Ingrese el día: ");
        scanf("%i", &una_fecha.dia);

        if (una_fecha.dia < 1 || una_fecha.dia > 31)
            printf("\n>> Ingrese un día válido! <<\n");
    } while (una_fecha.dia < 1 || una_fecha.dia > 31);

    do {
        printf("Ingrese el mes: ");
        scanf("%i", &una_fecha.mes);

        if (una_fecha.mes < 1 || una_fecha.mes > 12)
            printf("\n>> Ingrese un mes válido! << \n");
    } while (una_fecha.mes < 1 || una_fecha.mes > 12);

    do {
        printf("Ingrese el año: ");
        scanf("%i", &una_fecha.anio);

        if (una_fecha.anio < 1)
            printf("\n>> Ingrese un año válido! << \n");
    } while (una_fecha.anio < 1);

    mostrar_fecha(una_fecha);

    return 0;
}

void mostrar_fecha(fecha una_fecha) {
    printf("\n\n>> La fecha ingresada es %1i-%1i-%1i\n\n", una_fecha.dia, una_fecha.mes, una_fecha.anio);
}
