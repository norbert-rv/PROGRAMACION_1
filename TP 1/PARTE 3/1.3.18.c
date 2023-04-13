/* Codificar un programa para ingresar la altura, el ancho y largo de una caja y los almacene en una
estructura. Luego calcular y presentar por pantalla el volumen de la caja. */

#include <stdio.h>

struct volumen {
    float altura;
    float ancho;
    float largo;
};

int main(int argc, char *argv[]) {
    struct volumen num_alt, num_anch, num_lar;
    float volumen_caja;

    printf("Ingresar altura: ");
    scanf("%f", &num_alt.altura);
    printf("Ingresar ancho: ");
    scanf("%f", &num_anch.ancho);
    printf("Ingresar largo: ");
    scanf("%f", &num_lar.largo);

    volumen_caja = num_alt.altura * num_anch.ancho * num_lar.largo;

    printf("El volumen de la caja es %.2f\n", volumen_caja);

    return 0;
}