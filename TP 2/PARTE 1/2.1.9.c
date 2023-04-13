/* Codificar un programa en el que se solicita el ingreso de N carácteres, luego presentar
por pantalla un mensaje que indique cuántos carácteres son dígitos, cuántos son letra
del alfabeto en mayúscula, cuántos son letra del alfabeto en minúscula o de otro tipo de
carácter. */

// ME DA MAL EL RESULTADO, CORREGIR!

#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int N, contador_mayus = 0, contador_minus = 0, contador_digit = 0, contador_otro = 0, N_carac = 1;
    char caracter;
    int h;
    do {
        printf("¿Cuántos caracteres ingresará?  ");
        scanf("%i", &N);
    } while (N <= 0);

    for (int i = 0; i < N; i++) {
        printf("Ingrese caracter %i: ", N_carac);
        caracter = getchar();
        while (fgetc(stdin) != '\n')
            ;

        if (isdigit(caracter))
            contador_digit++;
        else if (isalpha(caracter) && isupper(caracter))
            contador_mayus++;
        else if (isalpha(caracter) && islower(caracter))
            contador_minus++;
        else
            contador_otro++;

        N_carac++;
    }

    printf("\nHay %i digitos, %i letras mayúscula, %i letras minúscula y %i caracteres de otro tipo.\n\n", contador_digit, contador_mayus, contador_minus, contador_otro);

    return 0;
}