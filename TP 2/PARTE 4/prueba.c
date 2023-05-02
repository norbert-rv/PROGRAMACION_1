#include <stdio.h>

int main(){}

int numeroCreciente(){
    int numero;
    static int numeroControl, caso0 = 1, contadorConsec = 0, contadorSeries = 0;
    do {
        printf("\nIngresar número entero no negativo: ");
        scanf("%i", &numero);
    } while (numero < 0);

    if(caso0){
        numeroControl = numero;
        caso0 = 0;
    } else if(numero > numeroControl){
        contadorConsec++;
    } else{
        caso0 = 1;
        if(contadorConsec >= 1){
            contadorSeries++;
            contadorConsec = 0;
        }
    }

    return contadorSeries;
}