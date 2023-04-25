/* Codificar un programa que solicite al usuario un número complejo en la forma binómica y lo
almacene en una estructura como el siguiente formato:
typdef struct {
float real;
float imaginario;
}complejo;
Luego mostrar por pantalla el mismo.
Para resolver este problema debe utilizar funciones que:
a)Permita solicitar al usuario un número complejo
b)Muestre un número complejo dado por pantalla con el siguiente formato: "El número
ingresado es a + b i" (esta función no es necesario que retorne valor)
*/

#include <stdio.h>

typedef struct {
    float real;
    float imaginario;
} complejo;

complejo pedir_complejo();
void mostrar_complejo(complejo);

int main(int argc, char *argv[]) {
    complejo numero;

    numero = pedir_complejo();

    mostrar_complejo(numero);

    return 0;
}

complejo pedir_complejo() {
    complejo num;
    printf("\n\n> Ingresar un número complejo...\n\nIngresar la parte real: ");
    scanf("%f", &num.real);
    printf("\n> Ingresar la parte imaginaria: ");
    scanf("%f", &num.imaginario);

    return num;
}

void mostrar_complejo(complejo num) {
    if (num.imaginario < 0)
        printf("\n>> El número ingresado es %.2f - %.2f i \n\n", num.real, (-1) * num.imaginario);
    else
        printf("\n>> El número ingresado es %.2f + %.2f i \n\n", num.real, num.imaginario);
}