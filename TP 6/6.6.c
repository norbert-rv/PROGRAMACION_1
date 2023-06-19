/* Implementar un programa que permita registrar su agenda en un archivo binario. Para esto debe:
○ Utilizar una variable tipo estructura que contendrá información referente a personas: Fecha de
nacimiento (día, mes y año), Apellido, Nombre, Código. Usar una estructura anidada para
guardar la fecha.
○ El código será un valor numérico que inicia en uno y se incrementa de uno en uno.
○ Realizar controles de datos
i. apellido y nombre pueden contener solamente letras, espacio y apóstrofe (D’Urso)
ii. fecha: considerar campos enteros con los rangos de valores según sea día, mes y año.
○ Debe utilizar un archivo binario llamado personas.dat rara registrar los datos ingresados.
○ Implementar una función para el menú que contenga las siguientes opciones:
1- Ingresar información de una persona
2- Mostrar por pantalla los datos de las personas registradas
3- Consulta de información, buscando por mes de nacimiento
99- Salir del programa
○ Formato de salida:
Apellido y Nombre: Younes, José Fecha de Nac: 23/05/1968 Código: 1
Apellido y Nombre: Perez, Jorge Luis Fecha de Nac: 05/05/2010 Código: 2
La opción 3, debe solicitar al usuario el ingreso de un mes, luego el programa deberá mostrar por
pantalla los datos de las personas en donde coincida el mes ingresado con el mes de nacimiento
registrado en el archivo */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, anio;
} fechaNacimiento;

typedef struct {
    char nombre[30], apellido[30];
    fechaNacimiento nacimiento;
    int codigo = 1;
} persona;

persona ingresarDatos(int codigo);
void aperturaArchivo(char nombre[]);
int menu();
void mostrarArchivo(char nombre[]);
void busquedaPorMes(char nombre[], int mes);

int main(int argc, char *argv[]) {
    char nombre[] = "personas.dat";
    persona pers;

    aperturaArchivo(nombre);

    while(1){
        switch(menu()){
            case 1:
                pers = ingresarDatos();
        }
    }
}

persona ingresarDatos(int codigo) {
    persona p;  // p de persona

    printf("\nNombre: ");
    fscanf(stdin, "%s[a-Z ']", p.nombre);
    getchar();

    printf("\nApellido: ");
    fscanf(stdin, "%s[a-Z ']", p.apellido);
    getchar();

    printf("\nFecha de nacimiento: ");
    do {
        printf("\nDia: ");
        scanf("%i", &p.nacimiento.dia);
    } while (p.nacimiento.dia <= 0 || p.nacimiento.dia);

    do {
        printf("\nMes: ");
        scanf("%i", &p.nacimiento.mes);
    } while (p.nacimiento.mes <= 0 || p.nacimiento.mes > 12);

    do {
        printf("\nAño: ");
        scanf("%i", &p.nacimiento.anio);
    } while (p.nacimiento.anio < 1800 || p.nacimiento.anio > 2023);

    getchar();

    p.codigo = codigo;
    return p;
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

int menu() {
    int opcion;

    printf("\nMenu interactivo... \n");
    printf("\n1. Ingresar información de una persona");
    printf("\n2. Mostrar por pantalla los datos de las personas registradas");
    printf("\n3. Consulta de información, buscando por mes de nacimiento");
    printf("\n99. Salir del programa");
    printf("\nOpción: ");
    scanf("%i", &opcion);
    getchar();
    printf("\n");
    return opcion;
}

void mostrarArchivo(char nombre[]) {
    persona pers;  // pers de persona
    FILE *p;

    p = fopen(nombre, "rb");

    do {
        fread(&pers, sizeof(pers), 1, p);
        /* Apellido y Nombre: Younes, José Fecha de Nac: 23/05/1968 Código: 1 */
        if (feof(p) == 0) {
            printf("\nApellido y Nombre: %s, %s  Fecha de Nac: %i/%i/%i  Código: %i ", pers.apellido, pers.nombre, pers.nacimiento.dia, pers.nacimiento.mes, pers.nacimiento.anio);
        }
    } while (feof(p) == 0);

    fclose(p);
}

void busquedaPorMes(char nombre[], int mes){
    persona pers;
    FILE *p;

    p = fopen(nombre, "rb");

    do {
        fread(&pers, sizeof(pers), 1, p);
        if (feof(p) == 0 && pers.nacimiento.mes == mes) {
            printf("\nApellido y Nombre: %s, %s  Fecha de Nac: %i/%i/%i  Código: %i ", pers.apellido, pers.nombre, pers.nacimiento.dia, pers.nacimiento.mes, pers.nacimiento.anio);
        }
    } while (feof(p) == 0);

    fclose(p);
}