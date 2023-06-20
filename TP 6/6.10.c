/* Modificar el programa anterior y agregar al menú las opciones:
6- Mostrar los datos de los productos vencidos
7- Generar y presentar por pantalla otro archivo llamado vencidos.dat que contendrá los
productos vencidos.
La opción 6, debe solicitar el ingreso del mes y año actual para comparar con la fecha de vencimiento,
luego el programa debe mostrar los datos de los productos vencidos.
La opción 7, debe solicitar el ingreso del mes y año actual, para comparar con la fecha de vencimiento de
cada producto, en caso de encontrar productos vencidos, el programa deberá: generar y presentar por
pantalla otro archivo llamado vencidos.dat que contendrá los productos vencidos. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct {
    int mes, anio;
} vencimiento;

typedef struct {
    char nombre[MAX];
    char marca[MAX];
    float precio;
    vencimiento fecha;
} producto;

void aperturaArchivo(char nombre[]);
void reiniciarArchivo(char nombre[]);
int menu();
producto ingresarProducto();
void escribirProducto(char nombre[]);
void mostrarProducto(producto prod, int numero);
void mostrarTodosProductos(char nombre[]);
void ordenarAscendente(char nombre[]);
void consultaPorNombre(char nombre[]);
void cambiarPrecio(char nombre[]);
int noEstaVencido(producto prod, int, int); /* la funcion me dice si el producto está vencido o no */
void mostrarProductosVencidos(char nombre[]);
void archivosVencidos(char nombre[], char nombreVencidos[]);

int main(int argc, char *argv[]) {
    char nombreArchivo[] = "productosAlmacen.dat";
    char archivoVencidos[] = "vencidos.dat";
    int huboIngreso = 0; /* bandera para saber si se ingresó al menos un producto o no */

    aperturaArchivo(nombreArchivo);
    reiniciarArchivo(nombreArchivo); /* cada vez que se ejecute el programa se escribe en un archivo en blanco. */

    while (1) {
        switch (menu()) {
            case 1:
                if (!huboIngreso) {
                    escribirProducto(nombreArchivo);
                    huboIngreso = 1;
                } else
                    escribirProducto(nombreArchivo);
                break;
            case 2:
                if (huboIngreso) {
                    mostrarTodosProductos(nombreArchivo);
                } else
                    printf("\n>> Aún no se ingresó ningún producto. Nada que mostrar... \n");
                break;
            case 3:
                if (huboIngreso) {
                    ordenarAscendente(nombreArchivo);
                } else
                    printf("\n>> Aún no se ingresó ningún producto. Nada que hacer... \n");
                break;
            case 4:
                if (huboIngreso) {
                    consultaPorNombre(nombreArchivo);
                } else
                    printf("\n>> Aún no se ingresó ningún producto. Nada que buscar... \n");
                break;
            case 5:
                if (huboIngreso) {
                    cambiarPrecio(nombreArchivo);
                } else
                    printf("\n>> Aún no se ingresó ningún producto. Nada que cambiar... \n");
                break;
            case 6:
                if (huboIngreso) {
                    mostrarProductosVencidos(archivoVencidos);
                } else
                    printf("\n>> Aún no se ingresó ningún producto. Nada que hacer... \n");
                break;
            case 7:
                if (huboIngreso) {
                    archivosVencidos(nombreArchivo, archivoVencidos);
                } else
                    printf("\n>> Aún no se ingresó ningún producto. Nada que hacer... \n");
                break;
            case 99:
                printf("\n>> Saliendo del programa... \n\n");
                exit(0);
            default:
                printf("\n>> Seleccione una opción dentro del menú...");
                break;
        }
    }

    return 0;
}

void ordenarAscendente(char nombre[]) {
    producto prodA, prodB;
    long i, j, t;       /* t es el total de estructuras dentro del archivo, i y j son los indices para el bubble sort */
    long tamanioStruct; /* en tamañoStruct está el tamaño en bytes de cada estructura en el archivo (sirve para el desplazamiento) */
    FILE *p;
    printf("\n>> Los productos serán ordenados de forma ascendente... \n");

    p = fopen(nombre, "r+b");
    fseek(p, 0, 2);
    t = ftell(p) / sizeof(prodA);

    /* Si solo hay una estructura en el archivo, no hay nada para ordenar (ya está ordenada) */
    if (t == 1)
        return;

    rewind(p);
    tamanioStruct = sizeof(prodA); /* tamaño del struct */

    /* Bubble sort para estructuras, utilizo fseek para ir seleccionando las posiciones.
    strcmp() < 0 para ordenar de forma alfabetica ascendente */
    for (i = 0; i < t; i++) {
        for (j = 0; j < t - 1; j++) {
            fseek(p, i * tamanioStruct, 0);
            fread(&prodA, sizeof(prodA), 1, p);
            fseek(p, j * tamanioStruct, 0);
            fread(&prodB, sizeof(prodB), 1, p);
            if (strcmp(prodA.nombre, prodB.nombre) < 0) {
                fseek(p, i * tamanioStruct, 0);
                fwrite(&prodB, sizeof(prodB), 1, p);
                fseek(p, j * tamanioStruct, 0);
                fwrite(&prodA, sizeof(prodA), 1, p);
            }
        }
    }

    fclose(p);
}

void mostrarProducto(producto prod, int numero) {
    printf("\nProducto n° %i... \n", numero);
    printf("\nNombre Comercial: %s", prod.nombre);
    printf("\nMarca: %s", prod.marca);
    printf("\nPrecio: %.2f", prod.precio);
    printf("\nMes de vencimiento: %i", prod.fecha.mes);
    printf("\nAño de vencimiento: %i\n", prod.fecha.anio);
}

void mostrarTodosProductos(char nombre[]) {
    producto prod;
    FILE *p;
    long totalEstructuras;

    p = fopen(nombre, "rb");

    fseek(p, 0, 2);

    totalEstructuras = ftell(p) / sizeof(prod);

    rewind(p);

    for (long i = 0; i < totalEstructuras; i++) {
        fread(&prod, sizeof(prod), 1, p);
        if (feof(p) == 0)
            mostrarProducto(prod, i + 1);
    }

    fclose(p);
}

void escribirProducto(char nombre[]) {
    producto prod;
    FILE *p;

    p = fopen(nombre, "ab");

    prod = ingresarProducto();

    fwrite(&prod, sizeof(prod), 1, p);

    fclose(p);
}

void aperturaArchivo(char nombre[]) {
    FILE *p;

    p = fopen(nombre, "rb");

    if (p == NULL) {
        printf("El archivo no exite. Se intentará crearlo...\n");
        p = fopen(nombre, "wb");
        if (p == NULL) {
            printf("\nNo se pudo crear el archivo. Saliendo... \n\n");
            exit(0);
        }
    }
    fclose(p);
}

void reiniciarArchivo(char nombre[]) {
    FILE *p;
    p = fopen(nombre, "wb");
    fclose(p);
}

int menu() {
    int opcion;

    printf("\nSeleccione una opcion... \n");
    printf("\n1. Ingresar información de un nuevo producto");
    printf("\n2. Mostrar en pantalla los datos de todos los productos");
    printf("\n3. Ordenar el archivo en forma alfabética por nombre comercial: ordena de manera ascendente los productos en el archivo");
    printf("\n4. Consulta de productos por nombre comercial: muestra todos los productos en caso de haber coincidencias o un mensaje");
    printf("\n5. Modificación de datos de un producto (buscando por nombre comercial)");
    printf("\n6. Mostrar los datos de los productos vencidos");
    printf("\n7. Generar y presentar por pantalla otro archivo llamado vencidos.dat que contendrá los productos vencidos");
    printf("\n99. Salir del programa");
    printf("\n\nOpción: ");
    scanf("%i", &opcion);
    while (fgetc(stdin) != '\n')
        ;

    return opcion;
}

producto ingresarProducto() {
    producto prod;

    printf("\n >> Ingreso de producto... \n");
    printf("\nNombre del producto: ");
    scanf("%s[a-Z 0-9]", prod.nombre);
    while (fgetc(stdin) != '\n')
        ;

    printf("\nMarca: ");
    scanf("%s[a-Z 0-9]", prod.marca);
    while (fgetc(stdin) != '\n')
        ;

    printf("\nPrecio: ");
    do {
        scanf("%f", &prod.precio);

        if (prod.precio <= 0 || prod.precio > 999999)
            printf("\n>> Ingrese un precio válido... \n");
    } while (prod.precio <= 0 || prod.precio > 999999);

    do {
        printf("\nMes de vencimiento: ");
        scanf("%i", &prod.fecha.mes);

        if (prod.fecha.mes <= 0 || prod.fecha.mes > 12)
            printf("\n>> Ingrese un mes válido... \n");
    } while (prod.fecha.mes <= 0 || prod.fecha.mes > 12);

    do {
        printf("\nAño de vencimiento: ");
        scanf("%i", &prod.fecha.anio);

        if (prod.fecha.anio < 1950)
            printf("\n>> Ingrese un año válido... \n");
    } while (prod.fecha.anio < 1950);

    getchar();

    return prod;
}

void consultaPorNombre(char nombre[]) {
    char nombreBuscar[MAX];
    long t;               /* numero de estructuras dentro del archivo */
    int coincidencia = 0; /* si hay al menos una coincidencia, será distinto de 0 */
    producto prod;
    FILE *p;

    printf("\nNombre del producto a buscar: ");
    scanf("%s[a-Z 0-9]", &nombreBuscar);
    while (fgetc(stdin) != '\n')
        ;

    p = fopen(nombre, "rb");

    fseek(p, 0, 2);
    t = ftell(p) / sizeof(prod);
    rewind(p);

    for (long i = 0; i < t; i++) {
        fread(&prod, sizeof(prod), 1, p);

        if (strcmp(prod.nombre, nombreBuscar) == 0) {
            if (!coincidencia) {
                coincidencia = 1;
                printf("\n>> Productos que coinciden con el nombre '%s'... \n", nombreBuscar);
            }
            mostrarProducto(prod, i + 1);
        }
    }
    fclose(p);

    if (!coincidencia) {
        printf("\n>> No hubo coincidencias con el nombre \n");
    }
}

void cambiarPrecio(char nombre[]) {
    char nombreComercial[MAX];
    long i, t; /* t es el numero de estructuras dentro del archivo */
    float nuevoPrecio;
    int coincidencia = 0; /* para mostrar un mensaje si no hay ninguna coincidencia */
    producto prod;
    FILE *p;

    printf("\nNombre Comercial del producto: ");
    fgets(nombreComercial, MAX, stdin);
    nombreComercial[strlen(nombreComercial) - 1] = '\0';

    p = fopen(nombre, "r+b");

    fseek(p, 0, 2);
    t = ftell(p) / sizeof(prod);
    rewind(p);

    for (i = 0; i < t; i++) {
        fread(&prod, sizeof(prod), 1, p);
        if (strcmp(prod.nombre, nombreComercial) == 0) {
            if (!coincidencia) {
                coincidencia = 1;
            }
            /* cambio el precio en la variable prod para luego escribirla en el archivo */
            printf("\n>> Cambiar precio a %s marca %s... Nuevo precio:  ", prod.nombre, prod.marca);
            scanf("%f", &nuevoPrecio);
            prod.precio = nuevoPrecio;

            /* vuelvo a la posicion anterior del struct, ya que avanzó a la siguiente automáticamente luego de la lectura */
            fseek(p, -1 * sizeof(prod), 1);
            fwrite(&prod, sizeof(prod), 1, p);
            /* luego de la escritura la posición volvió adonde tiene que estar para la siguiente lectura */
            printf("\n");
        }
    }

    fclose(p);

    if (!coincidencia)
        printf("\n>> No se encontraron productos de nombre comercial '%s'... \n", nombreComercial);
}

/* 1 si no está vencido, 0 si está vencido */
int noEstaVencido(producto prod, int mesActual, int anioActual) {
    /* si es anterior al año actual, el producto está vencido */
    if (prod.fecha.anio < anioActual)
        return 0;
    /* si es posterior al año actual, no está vencido */
    if (prod.fecha.anio > anioActual)
        return 1;
    /* si el año es el actual y el mes anterior al actual, está vencido. Caso contrario, no está vencido */
    if (prod.fecha.anio == anioActual && prod.fecha.mes < mesActual)
        return 0;
    else
        return 1;
}

void mostrarProductosVencidos(char nombre[]) {
    long i, t;
    int coincidencia = 0;
    producto prod;
    FILE *p;

    p = fopen(nombre, "rb");
    fseek(p, 0, 2);
    t = ftell(p) / sizeof(prod);
    rewind(p);

    for (i = 0; i < t; i++) {
        fread(&prod, sizeof(prod), 1, p);
        if (!noEstaVencido(prod, 6, 2023)) {
            if (!coincidencia) {
                printf("\n>> Productos Vencidos... \n");
                coincidencia = 1;
            }
            mostrarProducto(prod, i + 1);
        }
    }

    fclose(p);

    if (!coincidencia)
        printf("\n>> No hay productos vencidos... \n");
}

void archivosVencidos(char nombre[], char nombreVencidos[]) {
    long i, t; /* t es la cantidad de estructuras en el archivo original */
    producto prod;
    FILE *productos;
    FILE *vencidos;

    aperturaArchivo(nombreVencidos);

    productos = fopen(nombre, "rb");
    vencidos = fopen(nombreVencidos, "wb");

    fseek(productos, 0, 2);
    t = ftell(productos) / sizeof(prod);
    rewind(productos);

    for (i = 0; i < t; i++) {
        fread(&prod, sizeof(prod), 1, productos);
        if (!noEstaVencido(prod, 6, 2023)) {
            fwrite(&prod, sizeof(prod), 1, vencidos);
        }
    }

    fclose(productos);
    fclose(vencidos);

    /* muestro todos los productos en el archivo de vencidos */
    printf("\n>> Archivo de productos vencidos... \n");
    mostrarTodosProductos(nombreVencidos);
}