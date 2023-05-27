/* Cargar caracteres en un arreglo de orden N. Luego contabilizar, usando funciones, cuántos
caracteres del arreglo son alfabéticos, cuántos son dígitos y cuántos son de otras categorías */

// se chinflia a veces cuando ingresas caracteres que no son del código ascii

#include <ctype.h>
#include <stdio.h>

// determino el maximo valor que puede tomar el arreglo como un macro... ?
#define MAX 50

int pedirOrden(int limite);
void ingresarArregloCar(int orden, char arreglo[]);
int contadorTipoCar(int orden, char arreglo[], int *digit, int *otro);
void mostrarArregloCar(int orden, char arreglo[]);
int isCode(char caracter);  // un intento de controlar que el caracter ingresado esté en el código ascii.

int main(int argc, char *argv[]) {
    char arregloCar[MAX];
    int orden = pedirOrden(MAX);
    int cantAlfa, cantDigit = 0, cantOtro = 0;

    ingresarArregloCar(orden, arregloCar);
    cantAlfa = contadorTipoCar(orden, arregloCar, &cantDigit, &cantOtro);

    // muestro los resultados por pantalla

    printf("\n> El arreglo ingresado es: ");
    mostrarArregloCar(orden, arregloCar);
    printf("\n> Caracteres alfabéticos: %i", cantAlfa);
    printf("\n> Caracteres que son digitos: %i", cantDigit);
    printf("\n> Caracteres que son de otro tipo: %i\n\n", cantOtro);

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
        do {
            printf("\n> Ingresar elemento %i: ", i + 1);
            arreglo[i] = getchar();
            while (getchar() != '\n')
                ;
            // controlo la entrada de caracter para que no pueda ingresar un caracter fuera de rango
            if (!isCode(arreglo[i]))
                printf("\n> El elemento debe ser un caracter de ascii! \n");
        } while (!isCode(arreglo[i]));
    }
}

int contadorTipoCar(int orden, char arreglo[], int *digit, int *otro) {
    int cantAlfa = 0;

    for (int i = 0; i < orden; i++) {
        if (isalpha(arreglo[i]))
            cantAlfa++;
        else if (isdigit(arreglo[i]))
            *digit = *digit + 1;
        else
            *otro = *otro + 1;
    }

    return cantAlfa;
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

int isCode(char caracter) {
    if (caracter < 32 || caracter > 255)
        return 0;
    else
        return 1;
}