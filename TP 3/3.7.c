/* Realizar un programa que permita cargar un arreglo que contenga una cantidad N de caracteres
alfabéticos y luego lo presente por pantalla. Recordar que debe resolverse empleando una función
para cargar el arreglo y controlar los caracteres que se ingresan y otra función para presentar por
pantalla el arreglo resultante. */

#include <ctype.h>
#include <stdio.h>

int pedirOrdenArreglo();
void ingresarArregloCaracteres(int orden, char arreglo[]);
void mostrarArreglo(int orden, char arreglo[]);

int main(int argc, char *argv[]) {
    int ordenN = pedirOrdenArreglo();
    char caracteresAlfabeticos[ordenN];

    ingresarArregloCaracteres(ordenN, caracteresAlfabeticos);

    mostrarArreglo(ordenN, caracteresAlfabeticos);

    printf("\n\n");

    return 0;
}

int pedirOrdenArreglo() {
    int N;

    do {
        printf("\nIngresar el orden del arreglo: ");
        scanf("%i", &N);

        if (N <= 0)
            printf("\n>> El orden debe ser mayor que 0!\n");
    } while (N <= 0);

    return N;
}

void ingresarArregloCaracteres(int orden, char arreglo[]) {
    while (getchar() != '\n')
        ;
    for (int i = 0; i < orden; i++) {
        do {
            printf("\n> Ingresar elemento %i: ", i + 1);
            arreglo[i] = getchar();
            fgetc(stdin);
            if (!isalpha(arreglo[i]))
                printf("\n>>> El elemento debe ser un caracter alfabético!\n");
        } while (!isalpha(arreglo[i]));
    }
}

void mostrarArreglo(int orden, char arreglo[]) {
    printf("\n> El arreglo ingresado es:  |");

    for (int i = 0; i < orden; i++) {
        printf(" %c |", arreglo[i]);
    }
}