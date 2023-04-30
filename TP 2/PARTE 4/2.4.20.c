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

// INCOMPLETO

#include <stdio.h>

typedef struct {
    int dni;
    float monto;
    char medio_pago;
} venta;

int ingresarVenta(venta *);
float totalVenta(venta *una_venta, float totalT, float *totalE, float *totalC);
void ventaMayor(venta ventaIngresada, venta *ventaMayor);
void porcentajes(float total, float individual, float *porcentaje);

int main(int argc, char *argv[]) {
    venta ventaIngresada;

    do {
        if (ingresarVenta(&ventaIngresada))
            break;

    } while (1);
}

int ingresarVenta(venta *ventaIngreso) {
    do {
        printf("Ingresar DNI: ");
        scanf("%i", &ventaIngreso->dni);

        if (ventaIngreso->dni == 'F')
            return 1;
    } while (ventaIngreso->dni < 1 || ventaIngreso->dni > 99999999);

    do {
        printf("Ingresar monto: ");
        scanf("%f", &ventaIngreso->monto);

        if (ventaIngreso->monto == 'F')
            return 1;
    } while (ventaIngreso->monto < 1);

    do {
        printf("Ingresar medio de pago (e para efectivo, c para cuenta corriente y d para tarjeta de crédito o débito): ");
        ventaIngreso->medio_pago = getchar();

        if (ventaIngreso->medio_pago == 'F')
            return 1;
    } while (ventaIngreso->medio_pago != 't' && ventaIngreso->medio_pago != 'c' && ventaIngreso->medio_pago != 'e');

    return 0;
}

float totalVenta(venta *una_venta, float totalT, float *totalE, float *totalC) {
    if (una_venta->medio_pago == 't')
        totalT += una_venta->monto;
    else if (una_venta->medio_pago == 'e')
        *totalE += una_venta->monto;
    else
        *totalC += una_venta->monto;
}

void ventaMayor(venta ventaIngresada, venta *ventaMayor) {
    if (ventaIngresada.monto > ventaMayor->monto)
        ventaMayor->monto = ventaIngresada.monto;
}

void porcentajes(float total, float individual, float *porcentaje) {
    *porcentaje = individual / total * 100;
}
