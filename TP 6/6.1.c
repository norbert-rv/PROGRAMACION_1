/* Realizar un programa que solicite el ingreso de los datos de UNA persona: Apellido, Nombre, día, mes y
año de nacimiento; debe utilizar una estructura para contener dichos datos. Luego el programa deberá
escribir la estructura en un archivo binario llamado archivoBinario.dat */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[30], apellido[30];
    int dia, mes, anio;
} persona;

int main(int argc, char *argv[]) {
    persona unaPersona;
    FILE *p;

    /* Ingreso de datos de UNA persona */
    printf("\nIngresar datos de una persona: \n");
    printf("\nNombre: ");
    fgets(unaPersona.nombre, 30, stdin);
    unaPersona.nombre[strlen(unaPersona.nombre) - 1] = '\0';

    printf("\nApellido: ");
    fgets(unaPersona.apellido, 30, stdin);
    unaPersona.apellido[strlen(unaPersona.apellido) - 1] = '\0';

    printf("\nFecha de nacimiento... \n");
    do {
        printf("\nDia: ");
        scanf("%i", &unaPersona.dia);
    } while (unaPersona.dia <= 0 || unaPersona.dia > 31);

    do {
        printf("\nMes: ");
        scanf("%i", &unaPersona.mes);
    } while (unaPersona.mes <= 0 || unaPersona.mes > 12);

    do {
        printf("\nAño: ");
        scanf("%i", &unaPersona.anio);
    } while (unaPersona.anio < 1700 || unaPersona.anio > 2023);

    p = fopen("archivoBinario.dat", "rb");
    if (p == NULL) {
        p = fopen("archivoBinario.dat", "wb");
        if (p == NULL) {
            printf("\nError en la escritura del archivo. Saliendo... \n\n");
            exit(0);
        }
    }
    fclose(p);

    /* Escribo los datos en el archivo binario */
    p = fopen("archivoBinario.dat", "wb");
    fwrite(&unaPersona, sizeof(unaPersona), 1, p);
    fclose(p);

    return 0;
}