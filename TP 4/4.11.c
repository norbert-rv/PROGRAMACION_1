/* Ingresar dos cadenas de caracteres (apellidos y nombres). Convertir el primer carácter de cada
una a mayúscula. Recordar que una persona puede tener más de un apellido o nombre. Generar
una nueva cadena concatenando las dos anteriores. Usar strcat(). */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 50

void primeraLetraMayuscula(char nombre[], char apellido[]);

int main(int argc, char *argv[]) {
    char nombre[MAX], apellido[MAX];

    printf("\nIngresar Nombre: ");
    fgets(nombre, MAX, stdin);
    nombre[strlen(nombre) - 1] = '\0';

    printf("\nIngresar apellido: ");
    fgets(apellido, MAX, stdin);
    apellido[strlen(apellido) - 1] = '\0';

    primeraLetraMayuscula(nombre, apellido);
    
    strcat(nombre, apellido);

    printf("\n%s\n\n", nombre);

    return 0;
}

void primeraLetraMayuscula(char nombre[], char apellido[]) {
    nombre[0] = toupper(nombre[0]);
    apellido[0] = toupper(apellido[0]);

    // si encuentro un espacio, la letra que le sigue va en mayuscula
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (nombre[i] == ' ')
            nombre[i + 1] = toupper(nombre[i + 1]);
    }

    for (int i = 0; apellido[i] != '\0'; i++) {
        if (apellido[i] == ' ')
            apellido[i + 1] = toupper(apellido[i + 1]);
    }
}