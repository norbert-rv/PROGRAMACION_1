/* Implementar un programa que permita determinar si una fecha es válida, para esto :
a- Implementar una función permita el ingreso de una fecha y que retorne la misma al
programa principal.
b- Implementar una función para controlar la validez de la fecha: día entre 1 y 31, mes
entre 1 y 12, año mayor a 1900. Puede además controlar para cada mes la cantidad de
días que corresponden.
c- Implementar una función para mostrar una fecha con el formato dd/mm/aaaa, por
ejemplo 10/4/2022.
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
void mostrar_fecha(fecha);

int main(int argc, char *argv[]) {
    fecha una_fecha;
    printf("\nIngresar una fecha...\n");
    do {
        una_fecha = pedir_fecha();
        if (!controlar_fecha(una_fecha))
            printf("\n>> La fecha ingresada no es válida.\n>> Intente nuevamente...\n");
    } while (!controlar_fecha(una_fecha));

    mostrar_fecha(una_fecha);

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
    else if (una_fecha.mes == 2 && una_fecha.dia > 29)
        return 0;
    else if (una_fecha.mes == 4 || una_fecha.mes == 6 || una_fecha.mes == 9 || una_fecha.mes == 11 && una_fecha.dia > 30)
        return 0;
    else
        return 1;
}

void mostrar_fecha(fecha una_fecha) {
    printf("\n>     %1i-%1i-%1i\n\n", una_fecha.dia, una_fecha.mes, una_fecha.anio);
}