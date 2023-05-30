/* Ingresar los datos de UN huésped. Luego presentar por pantalla los datos del mismo
(apellido/s, nombre/s, ciudad de origen, cantidad de días que se va a hospedar, importe
que debe abonar por los días que se quede). Para presentar por pantalla usar este formato:
Huesped: Younes, José Ciudad de origen: Cordoba
Dias Hospedaje: 5 dias Importe a abonar:7500.00
*/

#include <stdio.h>

typedef struct {
    char apellido[40];
    char nombre[40];
    char ciudad[20];
    float precio;
    int dias;
} huesped;

int funcion(huesped arregloDeHuespedes[]);

int main(int argc, char *argv[]) {
    huesped arregloDeHuespedes[20];
    fgets(arregloDeHuespedes[0].apellido, 40, stdin);

    funcion(arregloDeHuespedes);
}

int funcion(huesped arregloDeHuespedes[]) {
    printf("\n%s y pedro\n\n", arregloDeHuespedes[0].apellido);
}