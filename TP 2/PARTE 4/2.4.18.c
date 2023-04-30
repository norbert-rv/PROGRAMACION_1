/* Se ponen a la venta entradas para un partido de fútbol internacional, cuyo precio
depende de la ubicación o tribuna, así:
○ Tribuna norte y sur cuesta 4000 pesos,
○ Tribuna este cuesta 5000 pesos y
○ Tribuna oeste cuesta 6500 pesos.
Se debe elaborar un programa que controle la venta de dichas entradas.
Se realizan N ventas, por cada venta se solicita cantidad de entradas a comprar y en qué
tribuna.
Se pide resolver utilizando funciones: :
● Controlar el ingreso de un número N positivo.
● Elaborar un menú para que el usuario elija en qué tribuna quiere comprar sus
entradas, y luego debe seleccionar la cantidad. Se recomienda usar la siguiente
definición de función
void ingresarVenta(tribunas *t);
● El porcentaje de personas que se ubicaron en la tribuna norte. El porcentaje se
mostrará en main y deberá ser obtenido haciendo uso de una función que no
retorne un valor.
● El monto total recaudado por la venta de todas las entradas
Se recomienda el uso de una estructura para ir almacenando la cantidad de entradas
vendidas en cada tribuna
typedef struct {
int tribunaNorte;
int tribunaSur;
int tribunaEste;
int tribunaOeste;
} tribunas;
*/

// PROBLEMA CON LOS PORCENTAJES...

#include <stdio.h>

typedef struct {
    int tribunaNorte;
    int tribunaSur;
    int tribunaEste;
    int tribunaOeste;
} tribunas;

int pedirN();
void ingresarVenta(tribunas *t);
void porcentaje(int total, tribunas num, tribunas *);
char menu();

int main(int argc, char *argv[]) {
    tribunas ventaTribuna = {0, 0, 0, 0}, porcentajes;
    int N = pedirN(), recaudacion;

    for (int i = 0; i < N; i++) {
        ingresarVenta(&ventaTribuna);
    }

    porcentaje(N, ventaTribuna, &porcentajes);

    printf("El porcentaje de ventas es...\n\n> Tribuna norte: %i%%\n\n> Tribuna sur: %i%%\n\n> Tribuna Este: %i%%\n\n> Tribuna Oeste: %i%%\n\n", porcentajes.tribunaNorte, porcentajes.tribunaSur, porcentajes.tribunaEste, porcentajes.tribunaOeste);
    recaudacion = (ventaTribuna.tribunaNorte + ventaTribuna.tribunaSur) * 4000 + ventaTribuna.tribunaEste * 5000 + ventaTribuna.tribunaOeste * 6500;
    printf("Recaudación: $%i\n\n", recaudacion);

    return 0;
}

char menu() {
    char opcion;
    printf("\n----------------\n");
    printf("\nMenú de entradas a la venta:\n\na. Tribuna Norte > $4000 \n\nb. Tribuna Sur > $4000 \n\nc. Tribuna Este > $5000 \n\nd. Tribuna Oeste > $6500\n\n");

    do {
        fgetc(stdin);
        printf("\nElegir opción: ");
        opcion = getchar();
        if (opcion != 'a' && opcion != 'b' && opcion != 'c' && opcion != 'd')
            printf("\nIngresar una opción válida!...\n");
    } while (opcion != 'a' && opcion != 'b' && opcion != 'c' && opcion != 'd');

    return opcion;
}

int pedirN() {
    int N;
    do {
        printf("\nIngresar el número N de ventas: ");
        scanf("%i", &N);
    } while (N <= 0);

    return N;
}

void ingresarVenta(tribunas *t) {
    switch (menu()) {
        case 'a':
            t->tribunaNorte = t->tribunaNorte + 1;
            break;
        case 'b':
            t->tribunaSur = t->tribunaSur + 1;
            break;
        case 'c':
            t->tribunaEste = t->tribunaEste + 1;
            break;
        case 'd':
            t->tribunaOeste = t->tribunaOeste + 1;
            break;
    }
}

void porcentaje(int total, tribunas ventas, tribunas *porc) {
    porc->tribunaNorte = (ventas.tribunaNorte / total) * 100;
    porc->tribunaSur = (ventas.tribunaSur / total) * 100;
    porc->tribunaEste = (ventas.tribunaEste / total) * 100;
    porc->tribunaOeste = (ventas.tribunaOeste / total) * 100;
}