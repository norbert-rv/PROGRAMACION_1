/* Ingresar los datos de UN huésped. Luego presentar por pantalla los datos del mismo
(apellido/s, nombre/s, ciudad de origen, cantidad de días que se va a hospedar, importe
que debe abonar por los días que se quede). Para presentar por pantalla usar este formato:
Huesped: Younes, José Ciudad de origen: Cordoba
Dias Hospedaje: 5 dias Importe a abonar:7500.00
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char apellido[40];
    char nombre[40];
    char ciudad[20];
    float precio;
    int dias;
} huesped;

void pedirDatosHuesped(huesped *unHuesped);
void mostrarDatosHuesped(huesped unHuesped);

int main(int argc, char *argv[]) {
    huesped unHuesped;

    pedirDatosHuesped(&unHuesped);
    mostrarDatosHuesped(unHuesped);

    printf("\n");

    return 0;
}

void pedirDatosHuesped(huesped *unHuesped) {
    printf("\nApellido: ");
    fgets(unHuesped->apellido, 40, stdin);
    unHuesped->apellido[strlen(unHuesped->apellido) - 1] = '\0';
    printf("\nNombre: ");
    fgets(unHuesped->nombre, 40, stdin);
    unHuesped->nombre[strlen(unHuesped->nombre) - 1] = '\0';
    printf("\nCiudad: ");
    fgets(unHuesped->ciudad, 20, stdin);
    unHuesped->ciudad[strlen(unHuesped->ciudad) - 1] = '\0';

    printf("\nPrecio: ");
    do {
        scanf("%f", &unHuesped->precio);
    } while (unHuesped->precio <= 0);

    printf("\nDias: ");
    do {
        scanf("%i", &unHuesped->dias);
    } while (unHuesped->dias <= 0);
}

void mostrarDatosHuesped(huesped unHuesped) {
    printf("\nHuesped: %s, %s.", unHuesped.apellido, unHuesped.nombre);
    printf("\tCiudad de origen: %s.", unHuesped.ciudad);
    printf("\nDías Hospedaje: %i días.", unHuesped.dias);
    printf("\tImporte a abonar: %.2f.", unHuesped.precio);
    printf("\n");
}