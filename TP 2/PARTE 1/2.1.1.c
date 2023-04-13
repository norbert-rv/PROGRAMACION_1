/* Ingresar caracteres e ir mostrando los mismos por pantalla hasta que el usuario ingrese
el carácter ‘n’(este último no debe mostrarse por pantalla). */

#include <stdio.h>

int main(int argc, char *argv[]) {
    char caracter;

    do {
        printf("Ingresar un caracter: ");
        scanf("%c", &caracter);
        fgetc(stdin);

        if (caracter == 'n')  // si el caracter es n el do-while finaliza.
            break;

        printf("\n %c \n\n", caracter);
    } while (1);

    printf("\nEl programá finalizó. \n");

    return 0;
}