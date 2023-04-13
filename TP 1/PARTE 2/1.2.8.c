/* Durante un intervalo de 3 meses, una persona debe realizar cada mes un análisis de sangre
para determinar su cantidad de glóbulos rojos. Se necesita saber si en el intervalo de los 3
meses, los valores obtenidos de glóbulos rojos aumentan por cada mes que pasa, o si
descienden por cada mes que pasa, o si no se da ninguno de los dos casos anteriores.
Realizar un programa que permita ingresar el valor de glóbulos rojos por cada mes y luego
muestre el mensaje correspondiente. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int glob_rojos_mes1, glob_rojos_mes2, glob_rojos_mes3;

    printf("Cant. de globulos rojos del primer mes: ");
    scanf("%i", &glob_rojos_mes1);
    printf("Cant. de globulos rojos del segundo mes: ");
    scanf("%i", &glob_rojos_mes2);
    printf("Cant. de globulos rojos del tercer mes: ");
    scanf("%i", &glob_rojos_mes3);

    if (glob_rojos_mes1 < glob_rojos_mes2 && glob_rojos_mes2 < glob_rojos_mes3)
        printf("Los valores obtenidos aumentan por cada mes que pasa.\n");
    else if (glob_rojos_mes3 < glob_rojos_mes2 && glob_rojos_mes2 < glob_rojos_mes1)
        printf("Los valores obtenidos disminuyen por cada mes que pasa.\n");
    else
        printf("Los valores obtenidos no aumentan ni disminuyen en los 3 meses.\n");

    return 0;
}