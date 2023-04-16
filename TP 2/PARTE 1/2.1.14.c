/* Codificar un programa que solicite los datos de N usuarios y lo almacene en una
estructura como el siguiente formato:
typdef struct {
char nombre; //almacenar sólo la inicial
int dni;
}usuario;
Mostrar por pantalla los nombres de los usuarios que fueron ingresados en mayúsculas
si su dni es un número par y en minúscula si su dni es un número impar. Por ejemplo se
ingresan 3 usuarios:
Usuario: a - DNI: 145823
Usuario: t - DNI: 7845152
Usuario: P - DNI: 748452
Debe mostrar por pantalla: a , T, P */

#include <ctype.h>
#include <stdio.h>

typedef struct {
    char nombre;  // inicial
    int dni;
} usuario;
int main(int argc, char *argv[]) {
    int N, contador_usuarios = 1;
    usuario un_usuario;

    do {
        printf("\nCantidad de usuarios a ingresar:  ");
        scanf("%i", &N);
    } while (N <= 0);

    while (fgetc(stdin) != '\n')
        ;

    for (int i = 0; i < N; i++) {
        printf("\n> Persona n° %i\n", contador_usuarios);

        do {
            printf("\nIngrese la inicial del nombre:  ");
            un_usuario.nombre = getchar();
        } while (!isalpha(un_usuario.nombre));

        do {
            printf("\nIngrese el dni:  ");
            scanf("%i", &un_usuario.dni);
        } while (un_usuario.dni < 1 || un_usuario.dni > 99999999);

        while (fgetc(stdin) != '\n')
            ;

        if (un_usuario.dni % 2 == 0)
            printf("\n%c\n", toupper(un_usuario.nombre));
        else
            printf("\n%c\n", tolower(un_usuario.nombre));

        contador_usuarios++;
    }

    putchar('\n');

    return 0;
}