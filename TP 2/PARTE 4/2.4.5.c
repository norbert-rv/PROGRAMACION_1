/* Se ingresan N números enteros. Determinar el mayor de los valores ingresados.
Ejemplo: N = 7, Se ingresan: -12, 5, -8, 30, 0, -20, 15
Mayor valor: 30.
Controlar que el valor de N sea positivo. Usar una función que emplee variables static
para encontrar el mayor. Verificar también el resultado si ingreso todos números
negativos.
Resolver utilizando una o más funciones que utilicen solamente un parámetro
por valor, que retorne un valor entero y que haga uso de variables static.
*/

#include <stdio.h>

int pedirN();
int mayorNumero(int);

int main(int argc, char *argv[]) {
    printf("\nDeterminar el mayor de N números... \n");

    int N = pedirN(), numero, mayor;

    printf("\n  ------------ \n");

    for (int i = 0; i < N; i++) {
        printf("\nIngresar un número: ");
        scanf("%i", &numero);

        mayor = mayorNumero(numero);
    }

    printf("\n> El mayor de los números ingresados es el %2i\n\n", mayor);

    return 0;
}

int mayorNumero(int numero) {
    static int mayor = -9999999;
    if (numero > mayor)
        mayor = numero;
    return mayor;
}

int pedirN() {
    int num;

    do {
        printf("\nIngresar el número N: ");
        scanf("%i", &num);

        if (num <= 0)
            printf("> Ingresar un número positivo! <\n\n");
    } while (num <= 0);

    return num;
}