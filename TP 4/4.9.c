/* Ingresar una cadena de caracteres, en caso de que la misma se corresponda con un número decimal positivo,
es decir que posea solamente caracteres numéricos y el punto decimal,
realizar la conversión al formato número. Usar atof(). Presentar por pantalla la cadena ingresada
y el número convertido. */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int esDecimal(char cadenaCar[]);

int main(int argc, char *argv[]) {
    char cadenaCar[MAX];

    printf("\nIngresar una cadena de caracteres: ");
    fgets(cadenaCar, MAX, stdin);
    cadenaCar[strlen(cadenaCar) - 1] = '\0';

    if (esDecimal(cadenaCar)) {
        printf("\nLa cadena ingresada es: %s\n", cadenaCar);
        printf("\nEl número con coma flotante resultante es: %.2f\n\n", atof(cadenaCar));
    } else
        printf("\nLa cadena ingresada no se corresponde con un número decimal.\n\n");

    return 0;
}

// funcion para saber si la cadena es un numero decimal
int esDecimal(char cadenaCar[]) {
    int cantidadPuntosDecimales = 0;  // solo puede tener un punto decimal, sino estaría mal el número
    int decimal = 1;                  // el caso 0 es que es un número. Si encuentra un caracter que no corresponda, decimal es falso
    int i = 0;

    while (cadenaCar[i] != '\0') {
        if (decimal) {
            if (!isdigit(cadenaCar[i]) && cadenaCar[i] != '.') {
                decimal = 0;
                break;
            }
        }
        if (cadenaCar[i] == '.')
            cantidadPuntosDecimales++;
        i++;
    }

    if (decimal) {
        if (cantidadPuntosDecimales < 2)
            return 1;
    } else
        return 0;
}