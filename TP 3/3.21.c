/* Para pensar: Escribir un programa que, dada una frase de tamaño máximo N, determine si es un
palíndromo o no. Un palíndromo es una frase que, atendiendo sólo a sus letras e ignorando los
espacios, acentos, signos de puntuación y tipo de letra (mayúscula o minúscula) expresa lo mismo
leída de izquierda a derecha que de derecha a izquierda. “dabale arroz a la zorra el abad”.
Utilizar funciones para:
● Controlar que el orden del arreglo que se va a cargar sea un entero positivo y que no
supere el valor máximo que puede contener el arreglo.
● Ingresar la frase caracter a caracter en un arreglo. (!!!)
● Evaluar si la frase es un palíndromo. */

// seguir haciendo. El problema era de arch, estaba lleno /tmp y no podía compilar. Ahora si, a corregir este codigo nomas

#include <ctype.h>
#include <stdio.h>

#define MAX 50

int pedirOrden(int limite);
void ingresarFrasePorCaracter(int orden, char arreglo[]);
int esPalindromo(int orden, char frase[]);

int main(int argc, char *argv[]) {
    char frase[MAX];
    int orden = pedirOrden(MAX);

    ingresarFrasePorCaracter(orden, frase);

    if (esPalindromo(orden, frase))
        printf("\n> Es palíndromo.\n");
    else
        printf("\n> No es palíndromo.\n");

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

void ingresarFrasePorCaracter(int orden, char arreglo[]) {
    while (getchar() != '\n')
        ;
    printf("\n> Ingresar una frase caracter por caracter... \n");
    for (int i = 0; i < orden; i++) {
        printf("\n> Ingresar caracter %i: ", i + 1);
        arreglo[i] = getchar();
        while (getchar() != '\n')
            ;
    }
}

int esPalindromo(int orden, char frase[]) {
    int indice_aux = (orden - 1);
    int contadorLetrasIguales = 0, restaNoLetras = 0;

    for (int i = 0; i < indice_aux; i++) {
        if (frase[i] == ' ' || frase[i] == '!') {
            i++;
            restaNoLetras++;
        }
        if (frase[indice_aux] == ' ' || frase[indice_aux] == '!') {
            indice_aux--;
            restaNoLetras++;
        }
        if (tolower(frase[i] == tolower(frase[indice_aux])))
            contadorLetrasIguales++;
    }

    if (contadorLetrasIguales + restaNoLetras == orden)
        return 1;
    else
        return 0;
}