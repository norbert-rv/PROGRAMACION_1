/* Utilizando las funciones diseñadas en el ejercicio anterior, codificar un programa en el que se
solicita el ingreso de dos números complejos y muestre la suma de ambos. Para esto deberá
ingresar parte real y parte imaginaria de la forma binómica en una variable tipo estructura para
cada número complejo, luego utilizar otra función para calcular la suma de los mismos, además
debe retornar el resultado utilizando una variable tipo estructura. Presentar por pantalla los
números ingresados y el resultado.
*/

#include <stdio.h>

typedef struct {
    float real;
    float imaginario;
} complejo;

complejo pedir_complejo();
complejo suma_complejos(complejo, complejo);
void mostrar_complejo(complejo);

int main(int argc, char *argv[]) {
    complejo numero1, numero2, suma;

    printf("\nPrograma que suma dos números complejos... \n");

    numero1 = pedir_complejo();
    numero2 = pedir_complejo();

    suma = suma_complejos(numero1, numero2);
    mostrar_complejo(suma);

    return 0;
}

complejo pedir_complejo() {
    complejo num;
    printf("\n\n> Ingresar un número complejo...\n\nIngresar la parte real: ");
    scanf("%f", &num.real);
    printf("\nIngresar la parte imaginaria: ");
    scanf("%f", &num.imaginario);

    return num;
}

complejo suma_complejos(complejo num1, complejo num2) {
    complejo suma;
    suma.real = num1.real + num2.real;
    suma.imaginario = num1.imaginario + num2.imaginario;

    return suma;
}

void mostrar_complejo(complejo num) {
    if (num.imaginario < 0)
        printf("\n>> El número complejo es %.2f - %.2f i \n\n", num.real, (-1) * num.imaginario);
    else
        printf("\n>> El número complejo es %.2f + %.2f i \n\n", num.real, num.imaginario);
}