/* Escribe un programa en C que reciba una cadena de caracteres como argumento en la función
main y muestre la longitud de la cadena por pantalla. */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("\n%d \n\n", strlen(argv[1]));

    return 0;
}