/* Se desea realizar un programa que permita ingresar en un arreglo los datos de N empleados, para luego
poder listarlos ordenados alfabéticamente por apellido en forma ascendente.
Utilizar funciones para:
● Cargar la lista de empleados.
● Solicitar los datos de un empleado en particular.
● Mostrar los datos de un empleado en particular.
● Ordenar la lista de empleados.
● Mostrar la lista de empleados.
Para cada elemento de la lista debe usar una estructura que contenga: la inicial del apellido, la inicial
del nombre y el número de documento. Al cargar cada empleado, la inicial del apellido y la inicial del
nombre deben ser caracteres alfabéticos y guardarse en mayúscula. No utilizar un arreglo auxiliar
para el ordenamiento.
Como sugerencia puede usar funciones con estas cabeceras:
void solicitarDatosEmpleado(struct Empleado *emp);
void mostrarDatosEmpleado(struct Empleado emp);
void cargarListaEmpleados(struct Empleado lista[], int numEmpleados);
void ordenarListaEmpleados(struct Empleado lista[], int numEmpleados);
void mostrarListaEmpleados(struct Empleado lista[], int numEmpleados);
*/

#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

#define MAX 50

typedef struct {
    char apellido, nombre;  // guardar en mayúscula
    int documento;
} Empleado;

int ingresarCantidadEmpleados(int limite);
void solicitarDatosEmpleado(Empleado *emp);
void mostrarDatosEmpleado(Empleado emp);
void cargarListaEmpleados(Empleado lista[], int numEmpleados);
void ordenarListaEmpleados(Empleado lista[], int numEmpleados);
void mostrarListaEmpleados(Empleado lista[], int numEmpleados);

int main(int argc, char *argv[]) {
    Empleado lista[MAX];
    int cantidadEmpleados = ingresarCantidadEmpleados(MAX);

    cargarListaEmpleados(lista, cantidadEmpleados);
    ordenarListaEmpleados(lista, cantidadEmpleados);

    printf("\nA continuación la lista de empleados ordenada alfabeticamente de forma ascendente... ");
    sleep(1);
    printf("\n");

    mostrarListaEmpleados(lista, cantidadEmpleados);

    return 0;
}

int ingresarCantidadEmpleados(int limite) {
    int orden;
    do {
        printf("\n> ¿Cuántos empleados ingresará en la base de datos? ");
        scanf("%i", &orden);

        if (orden <= 0 || orden > limite)
            printf("\n> La cantidad debe ser positiva y menor que %i! \n", limite);
    } while (orden <= 0 || orden > limite);

    return orden;
}

void solicitarDatosEmpleado(Empleado *emp) {
    while (getchar() != '\n')
        ;

    printf("\n> Datos empleado: ");

    do {
        printf("\nNombre (inicial): ");
        emp->nombre = getchar();
        getchar();

        if (!isalpha(emp->nombre))
            printf("\nLa inicial debe ser alfabética... \n");
    } while (!isalpha(emp->nombre));

    emp->nombre = toupper(emp->nombre);

    do {
        printf("\nApellido (inicial): ");
        emp->apellido = getchar();
        getchar();

        if (!isalpha(emp->apellido))
            printf("\nLa inicial debe ser alfabética... \n");
    } while (!isalpha(emp->apellido));

    emp->apellido = toupper(emp->apellido);

    do {
        printf("\nDocumento: ");
        scanf("%i", &emp->documento);

        if (emp->documento <= 0 || emp->documento > 99999999)
            printf("\nIngresar un documento válido. \n");
    } while (emp->documento <= 0 || emp->documento > 99999999);
}

void mostrarDatosEmpleado(Empleado emp) {
    printf("\n> Datos Empleado: ");
    printf("\nNombre: %c", emp.nombre);
    printf("\nApellido: %c", emp.apellido);
    printf("\nDocumento: %i\n\n", emp.documento);
}

void cargarListaEmpleados(Empleado lista[], int numEmpleados) {
    for (int i = 0; i < numEmpleados; i++) {
        solicitarDatosEmpleado(&lista[i]);
    }
}

// alfabeticamente por apellido en forma ASCENDENTE (alfabeticamente)
void ordenarListaEmpleados(Empleado lista[], int numEmpleados) {
    int j;
    Empleado aux;
    for (int i = 0; i < numEmpleados; i++) {
        for (j = 0; j < numEmpleados - 1; j++) {
            if (lista[i].apellido < lista[j].apellido) {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

void mostrarListaEmpleados(Empleado lista[], int numEmpleados) {
    for (int i = 0; i < numEmpleados; i++) {
        mostrarDatosEmpleado(lista[i]);
    }
}