/* Realizar un programa que permita utilizar el mismo tipo de dato que el ejercicio anterior en UNA ÚNICA
variable y la almacene en un archivo binario llamado procesadores.dat. El menú debe ser:
A- Ingresar información de un procesador
B- Mostrar por pantalla el contenido del archivo
S- Salir del programa
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char marca[30];
    char modelo[30];
    float precio;
} procesador;

char menu(void);
procesador ingresoProcesador(void);
void aperturaArchivo(char nombre[]);
void escrituraProcesador(char nombre[]);
void mostrarContenidoArchivo(char nombre[]);

int main(int argc, char *argv[]) {
    procesador unProcesador;
    char nombre[] = "procesadores.dat";
    int bandera = 0; /* 0 si no se ingesó nada, 1 si ya hubo un ingreso */

    aperturaArchivo(nombre);

    while (1) {
        switch (toupper(menu())) {
            case 'A':
                escrituraProcesador(nombre);
                bandera = 1;
                break;
            case 'B':
                if (bandera)
                    mostrarContenidoArchivo(nombre);
                else
                    printf("\nAún no se ingresó ningun procesador. Nada que mostrar...\n");
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

void aperturaArchivo(char nombre[]) {
    FILE *p;

    p = fopen(nombre, "rb");

    if (p == NULL) {
        printf("\nEl archivo no existe. Se creará un archivo llamado '%s'...\n", nombre);

        p = fopen(nombre, "wb");

        if (p == NULL) {
            printf("\nNo se pudo crear el archivo. Saliendo...\n\n");
            exit(0);
        }
    } else {
        printf("\nLos datos se escribirán sobre el archivo '%s'...\n", nombre);
    }

    fclose(p);
}

/* Entonces, cuando haga una función para la escritura, tengo que declarar y llenar la variable dentro de la misma función,
cuando la intento ingresar a la variable por referencia no funciona. */
void escrituraProcesador(char nombre[]) {
    procesador unProcesador = ingresoProcesador();  // asi...
    FILE *p;

    p = fopen(nombre, "wb");

    fwrite(&unProcesador, sizeof(unProcesador), 1, p);

    fclose(p);
}

void mostrarContenidoArchivo(char nombre[]) {
    procesador unProcesador;

    FILE *p;

    p = fopen(nombre, "rb");

    fread(&unProcesador, sizeof(unProcesador), 1, p);

    fclose(p);

    printf("\nMARCA       MODELO      PRECIO\n");
    printf("%s         %s         %.2f", unProcesador.marca, unProcesador.modelo, unProcesador.precio);
    printf("\n\n");
}