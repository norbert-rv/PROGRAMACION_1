/* Diseñar un programa que emplee un arreglo de números enteros de orden N y que cuente con un
menú interactivo con las siguientes opciones:
● a.Cargar arreglo de enteros
● b.Mostrar arreglo de enteros
● c.Mostrar el valor del mayor elemento del arreglo
● d.Mostrar el valor del menor elemento del arreglo.
Tener en cuenta que el usuario puede presionar la opción b, c o d sin haber cargado previamente el
arreglo (opción a), por lo que deberá controlar esta situación. Además, controlar que el valor de N,
ingresado por el usuario, sea un entero positivo y se encuentre en el rango permitido.
*/

// Falta completar

#include <ctype.h>
#include <stdio.h>

int pedirOrdenArreglo();
void ingresarArregloEnteros(int orden, int arreglo[]);
char menuInteractivo();
void mostrarArregloEnteros(int orden, int arreglo[]);
void mayorElemento(int orden, int arreglo[]);
void menorElemento(int orden, int arreglo[]);

int main(int argc, char *argv[]) {
    char opcion;

    printf("\n\nBienvenido al programa! ");
    do {
        opcion = menuInteractivo();

        if (opcion != 'a')
            printf(">>>>>>> Aún no ingreso ningún arreglo... <<<<<<<<<");
    } while (opcion != 'a');
}

int pedirOrdenArreglo() {
    int N;

    do {
        printf("\nIngresar el orden del arreglo: ");
        scanf("%i", &N);

        if (N <= 0)
            printf("\n>> El orden debe ser mayor que 0!\n");
    } while (N <= 0 || N > 200);

    return N;
}

void ingresarArregloEnteros(int orden, int arreglo[]) {
    for (int i = 0; i < orden; i++) {
        printf("\n> Ingresar elemento %i: ", i + 1);
        scanf("%i", &arreglo[i]);
    }
}

char menuInteractivo() {
    char opcion;
    while (getchar() != '\n')
        ;

    printf("\n\nSeleccione una de las siguientes opciones...");
    printf("\n   a. Cargar arreglo de enteros");
    printf("\n   b. Mostrar arreglo de enteros");
    printf("\n   c. Mostrar el valor del mayor elemento del arreglo");
    printf("\n   d. Mostrar el valor del menor elemento del arreglo");

    do {
        scanf("\n\nOpción: %c", &opcion);
        getchar();

        if (tolower(opcion) != 'a' && tolower(opcion) != 'b' && tolower(opcion) != 'c' && tolower(opcion) != 'd')
            printf("...Ingrese una opción de la lista por favor");
    } while (tolower(opcion) != 'a' && tolower(opcion) != 'b' && tolower(opcion) != 'c' && tolower(opcion) != 'd');

    return tolower(opcion);
}

void mostrarArregloEnteros(int orden, int arreglo[]) {
    for (int i = 0; i < orden; i++) {
        printf("El arreglo ingresado es: (");
        if (i != orden - 1)
            printf("%i, ", arreglo[i]);
        else
            printf("%i)\n", arreglo[i]);
    }
}

void mayorElemento(int orden, int arreglo[]) {
    int mayor;

    for (int i = 0; i < orden; i++) {
        if (i = 0)
            mayor = arreglo[i];
        else if (arreglo[i] > mayor)
            mayor = arreglo[i];
    }

    printf("\n> El valor del mayor elemento es %i ", mayor);
}

void menorElemento(int orden, int arreglo[]) {
    int menor;

    for (int i = 0; i < orden; i++) {
        if (i = 0)
            menor = arreglo[i];
        else if (arreglo[i] < menor)
            menor = arreglo[i];
    }

    printf("\n> El valor del menor elemento es %i ", menor);
}