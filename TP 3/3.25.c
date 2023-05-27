/* Ingresar los datos de una cierta cantidad de monitores en un arreglo de estructuras. Luego,
presentar por pantalla los datos de los monitores en donde el precio sea menor o igual a un precio
de búsqueda ingresado por teclado. Los campos de la estructura deben almacenar los siguientes
datos: inicial de la marca, precio y cantidad en stock:
typedef struct{
char marca;
float precio;
int stock;
}monitores;
Utilizar funciones para:
● Controlar que el orden del arreglo sea un entero positivo y menor que el valor máximo
de elementos que pueden contener el arreglo.
● Solicitar al usuario los datos de cada uno de los monitores.
● Cargar el arreglo que contiene los monitores llamando a la función del ítem anterior.
● Presentar por pantalla los datos de cada monitor.
● Buscar y presentar por pantalla los datos de los monitores que cumplan que su precio
sea menor o igual a un precio de búsqueda ingresado por teclado.
*/

#include <ctype.h>
#include <stdio.h>

#define MAX 50

typedef struct {
    char marca;
    float precio;
    int stock;
} monitores;

int pedirOrden(int limite);
void solicitarDatosMonitor(monitores *unMonitor);
void cargaMonitores(int cantidad, monitores catalogoMonitores[]);
void mostrarDatosMonitor(monitores unMonitor);
void buscarYMostrarPorPrecioMaximo(int cantidadMonitores, monitores Monitores[], float precioMaximo);

int main(int argc, char *argv[]) {
    monitores catalogoMonitores[MAX];
    int cantidadMonitores = pedirOrden(MAX);
    float precioMaximo;

    cargaMonitores(cantidadMonitores, catalogoMonitores);

    do {
        printf("\n\nBuscar monitores dentro del siguiente precio máximo: ");
        scanf("%f", &precioMaximo);
    } while (precioMaximo <= 0);

    buscarYMostrarPorPrecioMaximo(cantidadMonitores, catalogoMonitores, precioMaximo);

    return 0;
}

int pedirOrden(int limite) {
    int orden;

    do {
        printf("\n> Cantidad de monitores a ingresar: ");
        scanf("%i", &orden);

        if (orden <= 0 || orden > limite)
            printf("\n> El orden debe estar entre 1 y %i! \n", limite);
    } while (orden <= 0 || orden > limite);

    return orden;
}

void solicitarDatosMonitor(monitores *unMonitor) {
    while (getchar() != '\n')
        ;
    printf("\n> Ingresando nuevos datos de monitor... \n");
    printf("\n> Marca: ");
    do {
        unMonitor->marca = getchar();
        getchar();
    } while (!isalpha(unMonitor->marca));

    do {
        printf("\n> Precio: ");
        scanf("%f", &unMonitor->precio);
    } while (unMonitor->precio <= 0);

    do {
        printf("\n> Stock: ");
        scanf("%i", &unMonitor->stock);
    } while (unMonitor->stock < 0);
}

void cargaMonitores(int cantidad, monitores catalogoMonitores[]) {
    for (int i = 0; i < cantidad; i++) {
        solicitarDatosMonitor(&catalogoMonitores[i]);
    }
}

void mostrarDatosMonitor(monitores unMonitor) {
    printf("\n> Monitor <");
    printf("\n> Marca: %c", unMonitor.marca);
    printf("\n> Precio: %.2f", unMonitor.precio);
    printf("\n> Stock: %i\n\n", unMonitor.stock);
}

void buscarYMostrarPorPrecioMaximo(int cantidadMonitores, monitores Monitores[], float precioMaximo) {
    printf("\n> Monitores cuyo precio es menor o igua que %.2f... \n", precioMaximo);

    for (int i = 0; i < cantidadMonitores; i++) {
        if (Monitores[i].precio <= precioMaximo)
            mostrarDatosMonitor(Monitores[i]);
    }
}