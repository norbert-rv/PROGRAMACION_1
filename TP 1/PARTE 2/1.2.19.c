/* Implementar el programa del ejercicio anterior considerando que el usuario puede
introducir las opciones del 1 al 8, en donde 1- Lunes, 2- Martes, 3 -Miércoles, 4- Jueves, 5-
Viernes, 6-Sábado, 7-Domingo, 8-Salir. Ud debe mostrarlas en un menú y presentar por
pantalla el mensaje correspondiente, solo debe salir del programa si el usuario presiona 8.
Sugerencia combinar do while y switch. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int opcion;

    do {
        printf("Ingrese una de las siguientes opciones: \n1. Lunes \n2. Martes \n3. Miércoles \n4. Jueves \n5. Viernes \n6. Sábado \n7. Domingo \n8. Salir \nElegir opción: ");
        scanf("%i", &opcion);
    } while (opcion < 1 || opcion > 8);

    switch (opcion) {
        case 1:
            printf("Usted eligió Lunes.\n");
            break;
        case 2:
            printf("Usted eligió Martes.\n");
            break;
        case 3:
            printf("Usted eligió Miércoles.\n");
            break;
        case 4:
            printf("Usted eligió Jueves.\n");
            break;
        case 5:
            printf("Usted eligió Viernes.\n");
            break;
        case 6:
            printf("Usted eligió Sábado.\n");
            break;
        case 7:
            printf("Usted eligió Domingo.\n");
            break;
        case 8:
            break;
    }

    return 0;
}