#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char apellido[40];
    char nombre[40];
    char ciudad[20];
    float precio;
    int dias;
} huesped;

void pedirDatosHuesped(huesped *unHuesped);
void mostrarDatosHuesped(huesped unHuesped);
void ingresarNHuespedes(int cantidadHuespedes, huesped listaHuespedes[]);
void mostrarHuespedYCiudad(int cantidadHuespedes, huesped listaHuespedes[]);

int main(int argc, char *argv[]) {
    huesped listaHuespedes[MAX];
    int cantidadHuespedes;

    do {
        printf("\nCantidad de huespedes a ingresar: ");
        scanf("%i", &cantidadHuespedes);

        if (cantidadHuespedes <= 0 || cantidadHuespedes > MAX)
            printf("\nLa cantidad de huespedes a ingresar debe ser un número positivo menor o igual que %i...\n", MAX);
    } while (cantidadHuespedes <= 0 || cantidadHuespedes > MAX);

    while (getchar() != '\n')
        ;

    ingresarNHuespedes(cantidadHuespedes, listaHuespedes);
    mostrarHuespedYCiudad(cantidadHuespedes, listaHuespedes);

    printf("\n\n");

    return 0;
}

void pedirDatosHuesped(huesped *unHuesped) {
    while (getchar() != '\n')
        ;
    printf("\nApellido: ");
    // fgets(unHuesped->apellido, 40, stdin);
    // unHuesped->apellido[strlen(unHuesped->apellido) - 1] = '\0';
    scanf("%[a-z A-Z']s", &unHuesped->apellido);
    while (getchar() != '\n')
        ;
    printf("\nNombre: ");
    // fgets(unHuesped->nombre, 40, stdin);
    // unHuesped->nombre[strlen(unHuesped->nombre) - 1] = '\0';
    scanf("%[a-z A-Z'áéíóúÁÉÍÓÚ]s", &unHuesped->nombre);
    while (getchar() != '\n')
        ;
    printf("\nCiudad: ");
    fgets(unHuesped->ciudad, 20, stdin);
    unHuesped->ciudad[strlen(unHuesped->ciudad) - 1] = '\0';

    printf("\nPrecio: ");
    do {
        scanf("%f", &unHuesped->precio);
    } while (unHuesped->precio <= 0 || unHuesped->precio > 9999999);

    printf("\nDias: ");
    do {
        scanf("%i", &unHuesped->dias);
    } while (unHuesped->dias <= 0 || unHuesped->dias > 100);
}

void mostrarDatosHuesped(huesped unHuesped) {
    printf("\nHuesped: %s, %s.", unHuesped.apellido, unHuesped.nombre);
    printf("\tCiudad de origen: %s.", unHuesped.ciudad);
    printf("\nDías Hospedaje: %i días.", unHuesped.dias);
    printf("\tImporte a abonar: %.2f.", unHuesped.precio);
    printf("\n");
}

void ingresarNHuespedes(int cantidadHuespedes, huesped listaHuespedes[]) {
    for (int i = 0; i < cantidadHuespedes; i++) {
        printf("Ingreso huesped: ");
        pedirDatosHuesped(&listaHuespedes[i]);
    }
}

void mostrarHuespedYCiudad(int cantidadHuespedes, huesped listaHuespedes[]) {
    printf("\nHuesped                Ciudad de Origen");
    for (int i = 0; i < cantidadHuespedes; i++) {
        printf("\n%s, %s               %s", listaHuespedes[i].apellido, listaHuespedes[i].nombre, listaHuespedes[i].ciudad);
    }
}