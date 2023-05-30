/* Ingresar dos cadenas de caracteres y presentarlas por pantalla en el orden en que se encuentran
en el diccionario. Usar strcmp(). Ejemplo se ingresan "Sanchez Mateo" y "Sanchez Mariana" y se
debe mostrar "Sanchez Mariana" , "Sanchez Mateo" */

#include <stdio.h>
#include <string.h>

#define MAX 100

int main(int argc, char *argv[]) {
    char cadena1[MAX], cadena2[MAX];

    printf("\nIngresar la primera cadena de caracteres: ");
    fgets(cadena1, MAX, stdin);
    cadena1[strlen(cadena1) - 1] = '\0';

    printf("\nIngresar segunda cadena de caracteres: ");
    fgets(cadena2, MAX, stdin);
    cadena2[strlen(cadena2) - 1] = '\0';

    if (strcmp(cadena1, cadena2) > 0)
        printf("\n\n%s , %s\n\n", cadena2, cadena1);
    else if (strcmp(cadena1, cadena2) < 0)
        printf("\n\n%s , %s\n\n", cadena1, cadena2);
    else
        printf("\n\n%s , %s (las cadenas son iguales)\n\n", cadena1, cadena2);

    return 0;
}