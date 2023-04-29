/* (Referencia ejercicio 9 del TP2-Parte 2) Codificar un programa en el que se solicita el ingreso
de un carácter alfabético, luego presentar por pantalla el carácter en mayúscula si el mismo fue
ingresado en minúscula y viceversa. Para resolver este ejercicio deberá implementar:
a- una función para ingresar el carácter y controlar que sea alfabético.
b- una función para devolver el carácter convertido (esta función no debe retornar
un valor)
c-una función para mostrar por pantalla el caracter convertido(esta función no es
necesario que retorno valor) */

#include <ctype.h>
#include <stdio.h>

char ingresoAlfa();
void convertirAlfa(char *);
void mostrarCar(char);

int main(int argc, char *argv[]) {
    char caracter;

    caracter = ingresoAlfa();
    convertirAlfa(&caracter);
    mostrarCar(caracter);

    return 0;
}

char ingresoAlfa() {
    char caracter;
    do {
        printf("Ingresar un caracter alfabético: ");
        caracter = getchar();
        while (getchar() != '\n')
            ;

        if (!isalpha(caracter))
            printf("\nEl caracter ingresado no es alfabético!\n");
    } while (!isalpha(caracter));

    return caracter;
}

void convertirAlfa(char *caracter) {
    if (islower(*caracter))
        *caracter = toupper(*caracter);
    else
        *caracter = tolower(*caracter);
}

void mostrarCar(char caracter) {
    printf("\n%c\n\n", caracter);
}