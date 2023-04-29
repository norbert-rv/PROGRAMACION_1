/* Se reciben dos valores numéricos enteros, realizar con ellos la suma, resta, división y
multiplicación y mostrar los resultados en pantalla.
Para resolver este problema debe:
○ Crear un menú a través del cual se puedan seleccionar las operaciones a realizar
○ Cada una de las operaciones deberá ser resuelta por una función y los resultados
se mostrarán en la función principal main().
Observación: Tener en cuenta que las funciones deben ser:
menu(): Retorna Valor (devuelve la operación seleccionada) y no tiene
parámetros.
suma(): Retorna Valor (devuelve resultado de la suma) y usa parámetros por
valor.
resta(): No retorna valor, utiliza dos parámetros por valor y uno por referencia.
cociente(): Retorna valor y utiliza parámetros por valor. ¡Cuidado con la división
en cero!
producto(): No retorna valor, utiliza dos parámetros por valor y uno por
referencia.
*/

#include <stdio.h>

char menu();
int suma(int, int);
void resta(int, int, int *);
double cociente(int, int);
void producto(int, int, int *);

int main(int argc, char *argv[]) {
    int num1, num2;
    char opcion;
    int resultado;

    printf("\nCalculadora básica...\n\n");
    printf("Ingresar número 1: ");
    scanf("%i", &num1);
    printf("\n\nIngesar número 2: ");
    scanf("%i", &num2);

    opcion = menu();

    switch (opcion) {
        case 'a':
            printf("\n\nEl resultado de la suma es %i\n\n", suma(num1, num2));
            break;
        case 'b':
            resta(num1, num2, &resultado);
            printf("\n\nEl resultado de la resta es %i\n\n", resultado);
            break;
        case 'c':
            if (cociente(num1, num2) != 1)
                printf("\n\nEl resultado del cociente es %.2lf\n\n", cociente(num1, num2));
            else
                printf("\n\nNo es posible la división por 0!...\n\n");
            break;
        case 'd':
            producto(num1, num2, &resultado);
            printf("\n\nEl resultado del producto es %i \n\n", resultado);
            break;
    }

    return 0;
}

char menu() {
    char opcion;
    while (getchar() != '\n')
        ;

    printf("\nMenú: \n\n");
    printf("a. Sumar \n\nb. Restar \n\nc. Dividir \n\nd. Multiplicar\n");

    do {
        printf("\n> Elegir una opción: ");
        opcion = getchar();
        if (opcion != 'a' && opcion != 'b' && opcion != 'c' && opcion != 'd')
            printf("\nLa opción debe estar en el menú...\n");
        while (getchar() != '\n')
            ;
    } while (opcion != 'a' && opcion != 'b' && opcion != 'c' && opcion != 'd');

    return opcion;
}

int suma(int num1, int num2) {
    int suma = num1 + num2;
    return suma;
}

void resta(int num1, int num2, int *resultado) {
    *resultado = num1 - num2;
}

double cociente(int num1, int num2) {
    double cociente;

    if (num2 != 0) {
        cociente = num1 / (num2 * 1.0);
        return cociente;
    } else
        return 1;
}

void producto(int num1, int num2, int *resultado) {
    *resultado = num1 * num2;
}