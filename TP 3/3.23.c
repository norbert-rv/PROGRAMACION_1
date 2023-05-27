/* Realizar un programa que permita ingresar los datos de las fechas de nacimiento de una cantidad N
personas en un arreglo de estructuras. Luego presentar el arreglo por pantalla. Resolver el ejercicio
sin utilizar funciones para la carga y presentación por pantalla del arreglo correspondiente. Utilizar
funciones únicamente para la carga y presentación de cada estructura. Los campos de la estructura
deben almacenar los siguientes datos: día, mes, año y nombre (inicial):
typedef struct{
int dia, mes, anio;
char nombre;
}datos;
*/

#include <ctype.h>
#include <stdio.h>

#define MAX 50

typedef struct {
    int dia, mes, anio;
    char nombre;
} datos;

int pedirOrden(int limite);
void ingresarDatosPersona(datos arregloDatos[]);

int main(int argc, char *argv[]) {
    datos datosPersonas[MAX];
    int orden = pedirOrden(MAX);  // la cantidad de personas de las que ingresare fecha de nacimiento

    // ingreso los datos de N personas
    for (int i = 0; i < orden; i++) {
        printf("\n>> Persona %i: ", i + 1);
        ingresarDatosPersona(datosPersonas);
    }

    // muestro por pantalla los resultados
    for (int i = 0; i < orden; i++) {
        printf("\nFecha de nacimiento persona %i: ", i + 1);
        printf("\n\nNombre: %c", datosPersonas->nombre);
        printf("\nDía: %i", datosPersonas->dia);
        printf("\nMes: %i", datosPersonas->mes);
        printf("\nAño: %i\n\n", datosPersonas->anio);
    }

    return 0;
}

int pedirOrden(int limite) {
    int orden;

    do {
        printf("\n> Cantidad de personas a ingresar: ");
        scanf("%i", &orden);

        if (orden <= 0 || orden > limite)
            printf("\n> El orden debe estar entre 1 y %i! \n", limite);
    } while (orden <= 0 || orden > limite);

    return orden;
}

void ingresarDatosPersona(datos arregloDatos[]) {
    do {
        printf("\n> Ingresar el dia de nacimiento: ");
        scanf("%i", &arregloDatos->dia);

        if (arregloDatos->dia <= 0 || arregloDatos->dia > 31)
            printf("\n> Ingrese un dia valido! \n");
    } while (arregloDatos->dia <= 0 || arregloDatos->dia > 31);

    do {
        printf("\n> Ingresar el mes: ");
        scanf("%i", &arregloDatos->mes);

        if (arregloDatos->mes <= 0 || arregloDatos->mes > 12)
            printf("\n> Ingrese un mes valido! \n");
    } while (arregloDatos->mes <= 0 || arregloDatos->mes > 12);

    do {
        printf("\n> Ingrese el año: ");
        scanf("%i", &arregloDatos->anio);

        if (arregloDatos->anio <= 0 || arregloDatos->anio > 2023)
            printf("\n> Ingresar un año valido! \n");
    } while (arregloDatos->anio <= 0 || arregloDatos->anio > 2023);

    while (getchar() != '\n')
        ;

    do {
        printf("\n> Ingresar la inicial de la persona: ");
        arregloDatos->nombre = getchar();
    } while (!isalpha(arregloDatos->nombre));
}