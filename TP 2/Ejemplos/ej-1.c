#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int sistema;

    printf("\nPrograma que muestra cómo borrar terminal.\n\nPresione <Enter> para continuar...");
    getchar();
    printf("¿Qué sistema operativo es? (1-WIN 2-LINUX): ");
    scanf("%i", &sistema);

    if (sistema == 1)
        system("cls");
    else
        system("clear");
    printf("\n Datos borrados \n");
    return 0;
}