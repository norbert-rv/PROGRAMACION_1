/* Realizar un programa que permita abrir el archivo llamado archivoBinario.dat. Se debe VERIFICAR si
existe un archivo con ese nombre, si el mismo no existe se lo debe crear y permitir el INGRESO de los
datos de UNA persona, utilizando una estructura: Apellido, Nombre, día, mes y año de nacimiento. Si el
archivo existe se debe MOSTRAR el contenido de dicho archivo por pantalla. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[30], apellido[30];
    int dia, mes, anio;
} persona;

int main(int argc, char *argv[]) {
    FILE *p;
    persona unaPersona;

    p = fopen("archivoBinario.dat", "rb");

    if (p == NULL) {
        p = fopen("archivoBinario.dat", "wb");
        if (p == NULL) {
            printf("\nEl archivo no pudo crearse. Saliendo...\n\n");
            exit(0);
        } else {
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

            /* Escribo la estructura en el archivo */
            fwrite(&unaPersona, sizeof(unaPersona), 1, p);
        }
    } else {
        fread(&unaPersona, sizeof(unaPersona), 1, p);
        if (feof(p) == 0) {
            printf("\nMostrando los datos de una persona... \n");
            printf("\nNombre: %s", unaPersona.nombre);
            printf("\nApellido: %s", unaPersona.apellido);
            printf("\n\nFecha de nacimiento...");
            printf("\nDia: %i", unaPersona.dia);
            printf("\nMes: %i", unaPersona.mes);
            printf("\nAño: %i", unaPersona.anio);
            printf("\n\n");
        }
    }

    fclose(p);

    return 0;
}