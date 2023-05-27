/* Ingresar un arreglo de caracteres de orden N, luego convertir los caracteres alfabéticos en
mayúscula a minúscula y viceversa. Presentar el arreglo original y el modificado por pantalla. No
utilizar un arreglo auxiliar */

#include <ctype.h>
#include <stdio.h>

#define MAX 50

int pedirOrden(int limite);
void ingresarArregloCar(int orden, char arreglo[]);
void convertirAlfa(int orden, char arreglo[]);
void mostrarArregloCar(int orden, char arreglo[]);

int main(int argc, char *argv[]) {
    char arregloCar[MAX];
    int orden = pedirOrden(MAX);

    ingresarArregloCar(orden, arregloCar);

    printf("\n> El arreglo ingresado es: ");
    mostrarArregloCar(orden, arregloCar);

    convertirAlfa(orden, arregloCar);

    printf("\n> El arreglo modificado es: ");
    mostrarArregloCar(orden, arregloCar);

    printf("\n\n");

    return 0;
}

int pedirOrden(int limite) {
    int orden;

    do {
        printf("\n> Ingresar el orden del arreglo de caracteres: ");
        scanf("%i", &orden);

        if (orden <= 0 || orden > limite)
            printf("\n> El orden debe estar entre 1 y 50! \n");
    } while (orden <= 0 || orden > limite);

    return orden;
}

void ingresarArregloCar(int orden, char arreglo[]) {
    while (getchar() != '\n')
        ;
    for (int i = 0; i < orden; i++) {
        printf("\n> Ingresar elemento %i: ", i + 1);
        arreglo[i] = getchar();
        getchar();
    }
}

void convertirAlfa(int orden, char arreglo[]) {
    for (int i = 0; i < orden; i++) {
        if (isalpha(arreglo[i]))
            if (isupper(arreglo[i]))
                arreglo[i] = tolower(arreglo[i]);
            else
                arreglo[i] = toupper(arreglo[i]);
    }
}

void mostrarArregloCar(int orden, char arreglo[]) {
    printf("(");

    for (int i = 0; i < orden; i++) {
        if (i < (orden - 1))
            printf("%c, ", arreglo[i]);
        else
            printf("%c)\n", arreglo[i]);
    }
}