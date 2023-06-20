/* Modificar el ejercicio anterior para que se pueda almacenar información de varios procesadores en el
archivo. Cada vez que se ingrese a la opción A se agrega información al archivo. Agregar una opción
“Consultar por precio” en donde se solicite al usuario el ingreso de un precio, luego el programa deberá
mostrar por pantalla los datos de los procesadores que posean precio menor o igual que el ingresado. */

/* HACE ALGUNAS COSAS RARAS PARA LA LECTURA! */

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
void escrituraProcesador(char nombre[], int indice);
void mostrarContenidoArchivo(char nombre[], int indice);
int tieneContenido(char nombre[]);
void mostrarProcesador(procesador proc);

int main(int argc, char *argv[]) {
    char nombre[] = "procesadores.dat";
    int indiceProcesadores = 1;
    int bandera = 0; /* 0 si no se ingesó nada, 1 si ya hubo un ingreso */

    aperturaArchivo(nombre);

    while (1) {
        switch (toupper(menu())) {
            case 'A':
                escrituraProcesador(nombre, indiceProcesadores);
                indiceProcesadores++;
                break;
            case 'B':
                if (tieneContenido(nombre))
                    mostrarContenidoArchivo(nombre, indiceProcesadores);
                else
                    printf("\n>> Aún no se ingresó ningun procesador. Nada que mostrar...\n");
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
    while (fgetc(stdin) != '\n')
        ;

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
void escrituraProcesador(char nombre[], int indice) {
    procesador unProcesador = ingresoProcesador();  // asi...
    // indice++;                                       // para que indique la cantidad de datos 1, 2, 3, etc. en fwrite()
    FILE *p;

    p = fopen(nombre, "ab");

    fwrite(&unProcesador, sizeof(unProcesador), indice, p);

    fclose(p);
}

void mostrarProcesador(procesador proc) {
    printf("%s         %s         %.2f\n", proc.marca, proc.modelo, proc.precio);
}

void mostrarContenidoArchivo(char nombre[], int indice) {
    procesador proc;
    FILE *p;
    long t; /* número de estructuras del archivo */

    p = fopen(nombre, "rb");

    fseek(p, 0, 2);

    t = ftell(p) / sizeof(proc); /* sizeof me devuelve el tamaño físico de la estructura */

    rewind(p);

    printf("\nMARCA       MODELO      PRECIO\n");

    for (long i = 0; i < t; i++) {
        fread(&proc, sizeof(proc), 1, p);
        mostrarProcesador(proc);
    }

    fclose(p);
    /*
    procesador unProcesador;
    FILE *p;

    p = fopen(nombre, "rb");
    printf("\nMARCA       MODELO      PRECIO\n");

    do {
        fread(&unProcesador, sizeof(unProcesador), 1, p); /* pasa automaticamente a la siguiente posición

    if (feof(p) == 0)
        printf("%s         %s         %.2f\n", unProcesador.marca, unProcesador.modelo, unProcesador.precio);
    }
    while (feof(p) == 0)
        ;

    fclose(p);
    */

    printf("\n\n");
}

int tieneContenido(char nombre[]) {
    procesador proc;
    int booleano;
    FILE *p;
    p = fopen(nombre, "rb");

    fread(&proc, sizeof(proc), 1, p);

    if (feof(p) == 0)
        booleano = 1;
    else
        booleano = 0;

    fclose(p);

    return booleano;
}