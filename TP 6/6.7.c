/* Utilizar el programa del ejercicio anterior agregando una opción al menú “4- Modificación de datos,
buscando por apellido y nombre”. La opción 4, debe solicitar al usuario el ingreso del apellido y nombre,
en caso de encontrar más de una coincidencia el programa deberá mostrar por pantalla las mismas y
pedir el código de la persona a modificar. Luego permite reingresar todos los datos excepto el código.
Consideraciones:
● Al buscar tener en cuenta que el usuario puede ingresar los datos con mayúscula o minúscula, no
tener en cuenta esa diferencia al momento de comparar.
● Debe modificar solo esa porción del struct y actualizar esa persona en el archivo.
● Considerar que en el ingreso de los datos debe realizar los controles de datos antes especificados.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia, mes, anio;
} fechaNacimiento;

typedef struct {
    char nombre[30], apellido[30];
    fechaNacimiento nacimiento;
    int codigo;
} persona;

persona ingresarDatos(int codigo);
void aperturaArchivo(char nombre[]);
int menu();
void mostrarArchivo(char nombre[]);
void busquedaPorMes(char nombre[], int mes);
void escribirPersona(char nombre[], persona pers);
void reiniciarArchivo(char nombre[]);
void modificacionDatos(char nombre[]);
int coincideCadena(char cadenaA[], char cadenaB[]);

int main(int argc, char *argv[]) {
    char nombre[] = "personas.dat";
    persona pers;
    int codigo = 1, mes;

    aperturaArchivo(nombre);
    reiniciarArchivo(nombre); /* reinicio los datos del archivo en caso de existir */

    while (1) {
        switch (menu()) {
            case 1:
                pers = ingresarDatos(codigo);
                codigo++;
                escribirPersona(nombre, pers);
                break;
            case 2:
                if (codigo != 1) {
                    mostrarArchivo(nombre);
                } else
                    printf("\n>> Aún no se registró ningún ingreso de persona... \n");
                break;
            case 3:
                if (codigo != 1) {
                    printf("\nIngrese el mes: ");
                    scanf("%i", &mes);
                    busquedaPorMes(nombre, mes);
                } else
                    printf("\n>> Aún no se registró ningún ingreso de persona... \n");
                break;
            case 4:
                if (codigo != 1) {
                    modificacionDatos(nombre);
                } else
                    printf("\n>> Aún no se registró ningún ingreso de persona... \n");
                break;
            case 99:
                printf("\nFinalizando programa... \n\n");
                exit(0);
            default:
                printf("\n>> Ingrese una opción válida...\n");
                break;
        }
    }
}

persona ingresarDatos(int codigo) {
    persona p;  // p de persona

    printf("\nNombre: ");
    fscanf(stdin, "%s[a-Z ']", p.nombre);
    while (fgetc(stdin) != '\n')
        ;

    printf("\nApellido: ");
    fscanf(stdin, "%s[a-Z ']", p.apellido);
    while (fgetc(stdin) != '\n')
        ;

    printf("\nFecha de nacimiento: ");
    do {
        printf("\nDia: ");
        scanf("%i", &p.nacimiento.dia);
    } while (p.nacimiento.dia <= 0 || p.nacimiento.dia > 31);

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
    printf("\n4. Modificación de datos, buscando por apellido y nombre");
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
            printf("\nApellido y Nombre: %s, %s  Fecha de Nac: %i/%i/%i  Código: %i ", pers.apellido, pers.nombre, pers.nacimiento.dia, pers.nacimiento.mes, pers.nacimiento.anio, pers.codigo);
        }
    } while (feof(p) == 0);

    fclose(p);

    printf("\n");
}

void busquedaPorMes(char nombre[], int mes) {
    persona pers;
    FILE *p;

    p = fopen(nombre, "rb");

    do {
        fread(&pers, sizeof(pers), 1, p);
        if (feof(p) == 0 && pers.nacimiento.mes == mes) {
            printf("\nApellido y Nombre: %s, %s  Fecha de Nac: %i/%i/%i  Código: %i ", pers.apellido, pers.nombre, pers.nacimiento.dia, pers.nacimiento.mes, pers.nacimiento.anio, pers.codigo);
        }
    } while (feof(p) == 0);

    fclose(p);
}

void escribirPersona(char nombre[], persona pers) {
    FILE *p;

    p = fopen(nombre, "ab");

    fwrite(&pers, sizeof(pers), 1, p);

    fclose(p);
}

void reiniciarArchivo(char nombre[]) {
    FILE *p;

    p = fopen(nombre, "wb");

    fclose(p);
}

void modificacionDatos(char nombreArchivo[]) {
    long i, t;
    int posiciones[10]; /* voy guardando las posiciones que coinciden con la busqueda (maximo 10) */
    char nombre[30], apellido[30];
    persona pers;
    FILE *p;

    /* Ingreso nombre y apellido para busar en el archivo */
    printf("\nIngresando datos a buscar... \n");
    printf("\nNombre: ");
    fscanf(stdin, "%s[a-Z ']", nombre);
    while (fgetc(stdin) != '\n')
        ;

    printf("\nApellido: ");
    fscanf(stdin, "%s[a-Z ']", apellido);
    while (fgetc(stdin) != '\n')
        ;

    p = fopen(nombreArchivo, "r+b");

    fseek(p, 0, 2);
    t = ftell(p) / sizeof(pers);
    rewind(p);

    for (i = 0; i < t; i++) {
        fread(&pers, sizeof(pers), 1, p);
        if (coincideCadena(nombre, pers.nombre) && coincideCadena(apellido, pers.apellido)) {
            printf("\nCambiar datos de '%s, %s'... \n", nombre, apellido);
            int j = pers.codigo;
            pers = ingresarDatos(j);
            fseek(p, -1 * sizeof(pers), 1);
            fwrite(&pers, sizeof(pers), 1, p);
        }
    }

    fclose(p);
}

int coincideCadena(char cadenaBuscar[], char cadena[]) {
    int cantidad = 0;

    for (int i = 0; i < strlen(cadenaBuscar); i++) {
        if (isalpha(cadenaBuscar[i]) && isalpha(cadena[i])) {
            if (tolower(cadenaBuscar[i]) == tolower(cadena[i]))
                cantidad++;
        } else if ((cadenaBuscar[i] == ' ' || cadenaBuscar[i] == 39) && (cadena[i] == ' ' || cadena[i] == 39)) {
            if (cadenaBuscar[i] == cadena[i])
                cantidad++;
        }
    }

    if (cantidad == strlen(cadenaBuscar) && cantidad == strlen(cadena))
        return 1;
    else
        return 0;
}