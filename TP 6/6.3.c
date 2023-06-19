/* Realizar un programa que permita utilizar una variable tipo estructura, que contendrá información
referente a procesadores de computadoras (marca, modelo y precio). Mostrar por pantalla un menú
interactivo, que contenga las siguientes opciones:
A- Ingresar información de un procesador
B- Mostrar por pantalla la información del procesador
C- Salir del programa
Para resolver:
○ Respetar las opciones del menú como se indican
○ Usar una función para implementar el menú
○ Usar una función para ingresar los datos de cada procesador
○ Usar una función para mostrar por pantalla los datos de cada procesador. En el formato de
salida mostrar los títulos: Marca - Modelo - Precio y debajo un procesador por línea. Por
ejemplo:
    MARCA MODELO PRECIO
    X925 124rT 385,22
    INTEL 386MM 1589,00
○ Implementar controles de datos, en todos los casos si no se cumple el control se solicita el
reingreso:
    i. Marca solo puede contener dígitos, letras y espacio
    ii. Modelo solo puede contener dígitos, letras y guiones
    iii. Precio es un valor real mayor que cero */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char marca[30];
    char modelo[30];
    float precio;
} procesador;

char menu(void);
procesador ingresoProcesador(void);
void mostrarDatosProcesadores(int orden, procesador procesadores[]);

int main(int argc, char *argv[]) {
    procesador listaProcesadores[20];
    int ordenLista = 0;

    while (1) {
        switch (menu()) {
            case 'A':
                listaProcesadores[ordenLista] = ingresoProcesador();
                ordenLista++;
                break;
            case 'B':
                if (ordenLista != 0)
                    mostrarDatosProcesadores(ordenLista, listaProcesadores);
                else
                    printf("\n>> Aún no se ingresó ningún procesador. No hay nada para mostrar...\n");
                break;
            case 'C':
                printf("\n>> Saliendo del programa... \n\n");
                exit(0);
            default:
                printf("\n>> Seleccione una opción dentro del menu... \n");
                break;
        }
    }

    return 0;
}

char menu(void) {
    char opcion;

    printf("\nMenu de opciones: \n");
    printf("\nA. Ingresar información de un procesador");
    printf("\nB. Mostrar por pantalla la información del procesador");
    printf("\nC. Salir del programa");

    printf("\n\nOpcion: ");
    opcion = getchar();
    getchar();

    return opcion;
}

procesador ingresoProcesador(void) {
    procesador unProcesador;

    printf("\n>> Ingreso de datos de un procesador... \n");
    printf("\nMarca: ");
    fscanf(stdin, "%s[a-Z 0-9]", unProcesador.marca);
    getchar(); /* limpio el enter que la función fscanf() no toma */

    printf("\nModelo: ");
    fscanf(stdin, "%s[a-Z-0-9]", unProcesador.modelo);
    getchar();

    printf("\nPrecio: ");
    do {
        scanf("%f", &unProcesador.precio);
    } while (unProcesador.precio <= 0);
    getchar();

    return unProcesador;
}

void mostrarDatosProcesadores(int orden, procesador procesadores[]) {
    printf("\nMARCA     MODELO      PRECIO\n");
    for (int i = 0; i < orden; i++) {
        printf("\n%s      %s      %.2f", procesadores[i].marca, procesadores[i].modelo, procesadores[i].precio);
    }
    printf("\n");
}