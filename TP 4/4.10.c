/* Leer una cadena de caracteres que sólo puede contener dígitos y barra, con el formato
dd/mm/aaaa. Mostrar por pantalla un mensaje indicando si la cadena ingresada es una fecha
válida, es decir:
a. solo puede contener números y barra
b. los valores de día, mes y año se encuentran en los rangos permitidos:
■ el día debe estar entre 1 y 30 (para todos los meses).
■ el mes entre 1 y 12 .
■ el año debe ser menor o igual a 2023.
Por ejemplo: 34/05/2018, no es válida porque no hay meses de 34 días.
Sugerencia: investigar qué función de string.h puede servir para esto. */

#include <stdio.h>
#include <string.h>

#define MAX 50

int main(int argc, char *argv[]){
    char cadenaCar[MAX];

    printf("\nIngresar fecha (formato dd/mm/aa): ");
    
}