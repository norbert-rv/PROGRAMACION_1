/* Resolver el problema anterior pero ahora empleando funciones para:
○ solicitar los datos de cada persona
○ cargar el arreglo llamando a la función del punto anterior
○ mostrar los datos de cada persona
○ mostrar el arreglo correspondiente llamando a la función del punto anterior
*/

#include <ctype.h>
#include <stdio.h>

#define MAX 50

typedef struct {
    int dia, mes, anio;
    char nombre;
} datos;

int pedirOrden(int limite);
void ingresarFechaNacimiento(datos *unaPersona);
void ingresarFechasDeNacimiento(int cantidad, datos arregloDatos[]);
void mostrarDatosUnaPersona(datos unaPersona);
void mostrarDatosPersonas(int cantidad, datos arregloDatos[]);

int main(int argc, char *argv[]) {
    datos datosPersonas[MAX];
    int cantidadPersonas = pedirOrden(MAX);  // la cantidad de personas de las que ingresare fecha de nacimiento

    ingresarFechasDeNacimiento(cantidadPersonas, datosPersonas);
    mostrarDatosPersonas(cantidadPersonas, datosPersonas);

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

void ingresarFechaNacimiento(datos *unaPersona) {
    do {
        printf("\n> Ingresar el dia de nacimiento: ");
        scanf("%i", &unaPersona->dia);

        if (unaPersona->dia <= 0 || unaPersona->dia > 31)
            printf("\n> Ingrese un dia valido! \n");
    } while (unaPersona->dia <= 0 || unaPersona->dia > 31);

    do {
        printf("\n> Ingresar el mes: ");
        scanf("%i", &unaPersona->mes);

        if (unaPersona->mes <= 0 || unaPersona->mes > 12)
            printf("\n> Ingrese un mes valido! \n");
    } while (unaPersona->mes <= 0 || unaPersona->mes > 12);

    do {
        printf("\n> Ingrese el año: ");
        scanf("%i", &unaPersona->anio);

        if (unaPersona->anio <= 0 || unaPersona->anio > 2023)
            printf("\n> Ingresar un año valido! \n");
    } while (unaPersona->anio <= 0 || unaPersona->anio > 2023);

    while (getchar() != '\n')
        ;

    do {
        printf("\n> Ingresar la inicial de la persona: ");
        unaPersona->nombre = getchar();
    } while (!isalpha(unaPersona->nombre));
}

void ingresarFechasDeNacimiento(int cantidad, datos arregloDatos[]) {
    for (int i = 0; i < cantidad; i++) {
        printf("\n>> Persona %i: ", i + 1);
        ingresarFechaNacimiento(&arregloDatos[i]);
    }
}

void mostrarDatosUnaPersona(datos unaPersona) {
    printf("\nFecha de nacimiento: ");
    printf("\n\nNombre: %c", unaPersona.nombre);
    printf("\nDía: %i", unaPersona.dia);
    printf("\nMes: %i", unaPersona.mes);
    printf("\nAño: %i\n\n", unaPersona.anio);
}

void mostrarDatosPersonas(int cantidad, datos arregloDatos[]) {
    for (int i = 0; i < cantidad; i++) {
        mostrarDatosUnaPersona(arregloDatos[i]);
    }
}