/* Ingresar N números enteros, luego presentar por pantalla la cantidad de series de
números impares ingresados. Se considera serie si tiene 2 o más elementos seguidos.
Ejemplo: 4, 9, 2, 5, 3, 2, 15, 3, 7, 9
|-----| |------------|
1 2 2 series
*/

#include <stdio.h>

int pedirN();
int esPar(int);
int contadorSeries(int);

int main (int argc, char *argv[]){
    printf("\nPrograma que muestra la cantidad de series de números impares ingresados...\n");

    int N = pedirN(), numero;

    for(int i = 0; i < N; i++){
        printf("Ingresar un número:  ");
        scanf("%i", &numero);
    }
}

int contadorSeries(int num){
    static int series = 0, auxiliar = 0;

    
}

int esPar(int num){
    if (num % 2 == 0)
        return 1;
    else
        return 0;
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