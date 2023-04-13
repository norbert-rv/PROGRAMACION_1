/*En una fábrica se registra la información del mantenimiento de las N máquinas que posee la
fábrica en una estructura como la siguiente:
struct maquina{
int numeroMaquina;
char sector;
int ultimoAnioMantenimiento;
};
Se pide calcular y mostrar el porcentaje de máquinas cuyo último año de mantenimiento fue en el
2020. */

#include <stdio.h>

struct maquina {
    int numeroMaquina;
    char sector;
    int ultimoAnioMantenimiento;
};

int main(int argc, char *argv[]) {
    int N, contador_maquinas = 0, aux = 1;
    struct maquina una_maquina;
    do {
        printf("Ingresar el número N de máquinas: ");
        scanf("%i", &N);
    } while (N <= 0);

    for (int i = 0; i < N; i++) {
        printf("Número de máquina %i: ", aux);
        scanf("%i", &una_maquina.numeroMaquina);
        getc(stdin);
        printf("Sector: ");
        scanf("%c", &una_maquina.sector);
        fgetc(stdin);
        do {
            printf("Último año de mantenimiento: ");
            scanf("%i", &una_maquina.ultimoAnioMantenimiento);
            if (una_maquina.ultimoAnioMantenimiento <= 1960)
                printf("Ingresar un año válido.\n");
        } while (una_maquina.ultimoAnioMantenimiento <= 1960);

        if (una_maquina.ultimoAnioMantenimiento == 2020)
            contador_maquinas++;

        aux++;
    }

    printf("El porcentaje de máquinas cuyo último mantenimiento fue en 2020 es del %i%%.\n", contador_maquinas * 100 / N);

    return 0;
}