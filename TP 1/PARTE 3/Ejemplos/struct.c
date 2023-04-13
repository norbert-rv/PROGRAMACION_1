struct fecha {
    int dia;
    int mes;
    int anio;
};

#include <stdio.h>

int main(int argv, char *argc[]) {
    /*declaraci�n de variables*/
    struct fecha nacimiento;

    /*Fecha de nacimiento*/
    printf("Ingresar anio de nacimiento: ");
    scanf("%i", &nacimiento.anio);
    printf("Ingresar mes de nacimiento: ");
    scanf("%i", &nacimiento.mes);
    printf("Ingresar dia de nacimiento: ");
    scanf("%i", &nacimiento.dia);

    printf("La persona nacio el %i del mes %i de %i ", nacimiento.dia, nacimiento.mes, nacimiento.anio);

    printf("\n\n");
    return 0;
}
