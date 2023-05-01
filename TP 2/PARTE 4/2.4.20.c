/* Un proveedor de tecnología, registra sus ventas diarias en un sistema diseñado para
solicitar DNI del cliente, monto de la venta y el medio de pago de la misma ('t' para
tarjeta de crédito o débito, 'e' para pago en efectivo y 'c' para cuenta corriente).
Almacenar la venta en un dato tipo estructura con el siguiente formato:
typedef struct{
int dni;
float monto;
char medio_pago;
}venta;
La carga de ventas diarias finaliza al ingresar el caracter F
Al finalizar cada día el encargado necesita saber:
○ El total por cada medio de pago y el total vendido en el dia. El sistema debe
mostrar en la función principal los distintos totales. Para esto realizar la siguiente
función:
float totalVenta( venta *v, float totalT,float *totalE, float *totalC);
○ El importe de venta más alto y a que cliente perteneció.
El sistema debe comparar cada vez que se ingresa una venta, si es la mayor venta
ingresada, para poder mostrarla al final del ingreso. Realizar la siguiente función:
void ventaMayor(venta ventaIngresada, venta *ventaMayor);
○ El porcentaje de ingresos que representa cada condición, esto el sistema se lo
muestra en la función principal con una función que no retorna valor y que tiene
la siguiente declaración: void porcentajes(float total, float individual, float
*porcentaje);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dni;
    float monto;
    char medio_pago;
} venta;

void ingresarVenta(venta *, int *, int *, int *);
float totalVenta(venta *una_venta, float totalT, float *totalE, float *totalC);
void ventaMayor(venta ventaIngresada, venta *ventaMayor);
void porcentajes(float total, float individual, float *porcentaje);

int main(int argc, char *argv[]) {
    venta ventaIngresada, ventasMayor = {0, 99999999, 'x'};
    char inicio;
    float totalT = 0, totalE = 0, totalC = 0, TOTAL;
    float porcentajeT, porcentajeE, porcentajeC;
    int contT = 0, contE = 0, contC = 0;
    int finalizar = 0;

    do {
        do {
            // Inicio y finalización del programa.
            printf("\nOprima > Enter < para ingresar venta. > F < para finalizar el programa...\n\n");
            inicio = getchar();
            if (inicio == 'F' || inicio == 'f')
                finalizar = 1;
            else if (inicio != '\n')
                getchar();
        } while (inicio != '\n');

        if (finalizar)
            break;

        ingresarVenta(&ventaIngresada, &contT, &contE, &contE);
        totalT = totalVenta(&ventaIngresada, totalT, &totalE, &totalC);
        ventaMayor(ventaIngresada, &ventasMayor);
    } while (1);

    // Hago el cálculo de los porcentajes de cada medio de pago.
    TOTAL = totalT + totalE + totalC;
    porcentajes(TOTAL, totalT, &porcentajeT);
    porcentajes(TOTAL, totalE, &porcentajeE);
    porcentajes(TOTAL, totalC, &porcentajeC);

    // Muestro resultados por pantalla.
    // Total por cada medio de pago...
    printf("\n> El monto TOTAL del día es de %.2f.", TOTAL);
    printf("\n\n> El monto pagado por tarjeta es de %.2f.\n> El monto pagado en efectivo es de %.2f.\n> El monto pagado por cuenta corriente es de %.2f.\n\n", totalT, totalE, totalC);

    // La mayor venta ingresada...
    printf(
        "> La mayor venta ingresada fue de $%.2f con la opción de pago %c, por el cliente de dni %i", ventasMayor.monto, ventasMayor.medio_pago, ventasMayor.dni);

    // Porcentaje de ingresos por cada medio de pago...
    printf("\n\n> El porcentaje de ventas por cada medio de pago fue de...\n> Tarjetas: %.2f%%\n> Efectivo: %.2f%%\n> Cuenta corriente: %.2f%%", porcentajeT, porcentajeE, porcentajeC);

    printf("\n\nGracias por usar este programa...\n\n");
    return 0;
}

// función para ingresar venta con parámetro por referencia y devuelve un booleano dependiendo de si se ingresa 'F' o no.
void ingresarVenta(venta *ventaIngreso, int *contT, int *contE, int *contC) {
    do {
        printf("Ingresar DNI: ");
        scanf("%i", &ventaIngreso->dni);
    } while (ventaIngreso->dni < 1 || ventaIngreso->dni > 99999999);

    do {
        printf("Ingresar monto: ");
        scanf("%f", &ventaIngreso->monto);
    } while (ventaIngreso->monto < 1);

    do {
        getchar();
        printf("Ingresar medio de pago ('t' para crédito o débito, 'e' para efectivo y 'c' para cuenta corriente): ");
        ventaIngreso->medio_pago = getchar();
        getchar();
    } while (ventaIngreso->medio_pago != 't' && ventaIngreso->medio_pago != 'c' && ventaIngreso->medio_pago != 'e');

    if (ventaIngreso->medio_pago == 't')
        *contT++;
    else if (ventaIngreso->medio_pago == 'e')
        *contE++;
    else
        *contC++;
}

float totalVenta(venta *una_venta, float totalT, float *totalE, float *totalC) {
    if (una_venta->medio_pago == 't')
        totalT += una_venta->monto;
    else if (una_venta->medio_pago == 'e')
        *totalE += una_venta->monto;
    else
        *totalC += una_venta->monto;

    return totalT;
}

void ventaMayor(venta ventaIngresada, venta *ventaMayor) {
    if (ventaIngresada.monto > ventaMayor->monto) {
        ventaMayor->monto = ventaIngresada.monto;
        ventaMayor->dni = ventaIngresada.dni;
        ventaMayor->medio_pago = ventaIngresada.medio_pago;
    }
}

void porcentajes(float total, float individual, float *porcentaje) {
    *porcentaje = individual / total * 100;
}
