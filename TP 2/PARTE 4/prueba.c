#include <stdio.h>
/*5. Se ingresan N números enteros, presentar por pantalla un mensaje indicando cuál es el
promedio de los impares. No considerar el número cero como número impar. Resolver
empleando funciones:
○       Controlar que el valor de N con la función solicitarCantidad().
○       Usar además una función para determinar si un número es impar
○       Usar una función para calcular el promedio de solicitado*/

int ingresaNumeroPos();
int esPar(int NUMERO);
void sumaImpares(int n);                   // cuando pasamos de paso de parmetro por  valor a referencia recordar cambiar los parametros de declaracion y definicion acordemente
float calcularPromedio(float *, float *);  // cuando cambies la funcion de paso por valor a paso por referencia recordar cambiar el input en la declaracion de la funcion

int main() {
    int n, suma_impares;
    float promedio_impares;
    printf("ingrese la cantidad (positiva) de numeros a verificar");
    n = ingresaNumeroPos();
    // suma_impares=sumaImpares(n);elimino esta linea porque al hacer el calcula de suma_impares y de total en una sola funcion(que no puede retornar ambos valores) en vez de pasarselos por valor al main se los paso por referencia a la funcion que calcula el promedio
    // promedio_impares=calcularPromedio(suma_impares,total); recibo suma_impares y total por referencia con la funcion suma_impares
    printf("el promedio  de los numeros impares es %f", promedio_impares);  // retornado por valor con la funcion calcularPromedio
    return 0;
}

int ingresaNumeroPos() {
    int NUMERO;
    do {
        scanf("%d", &NUMERO);
        if (NUMERO <= 0) {
            printf("el numero no es positivo");
        }
    }

    while (NUMERO <= 0);
    return NUMERO;
}

int esPar(int NUMERO) {
    if (NUMERO % 2 == 0)
        return 1;
    else {
        return 0;
    }
}

void sumaImpares(int n) {
    int suma_impares = 0;
    int total = 0;
    int NUMERO;
    for (int i = 1; i <= n; i++) {
        printf("ingrese el numero numero %d\n", i);
        scanf("%d", &NUMERO);
        if (!esPar(NUMERO)) {
            suma_impares = suma_impares + NUMERO;
        }
        total = total + NUMERO;
    }
    calcularPromedio(&suma_impares, &total);  // siempre poner ; despues de las llamadas de funciones
}

float calcularPromedio(float *p_impares, float *p_total) {  // declaro el puntero con el * para que reciba la direccion de memoria suma_impares y total de la funcion

    float promedio_impares = *p_impares / *p_total * 100;
    return promedio_impares;
}