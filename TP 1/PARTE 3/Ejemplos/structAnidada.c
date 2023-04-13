struct fecha {
    int dia;
    int mes;
    int anio;
};

typedef struct {
    int inicialNombre;
    float peso;
    struct fecha nacimiento;
} persona;

#include <stdio.h>

int main(int argv, char *argc[]) {
    persona unaPersona;

    printf("Ingrese la inicial del nombre de la persona: ");
    scanf("%c", &unaPersona.inicialNombre);
    fgetc(stdin);

    printf("Ingrese el peso: ");
    scanf("%f", &unaPersona.peso);

    /*Fecha de nacimiento*/
    printf("Ingresar anio de nacimiento: ");
    scanf("%i", &unaPersona.nacimiento.anio);
    printf("Ingresar mes de nacimiento: ");
    scanf("%i", &unaPersona.nacimiento.mes);
    printf("Ingresar dia de nacimiento: ");
    scanf("%i", &unaPersona.nacimiento.dia);

    printf("\nLa persona es %c ", unaPersona.inicialNombre);
    printf("\nPesa %f", unaPersona.peso);
    printf("\nLa persona nacio el %i del mes %i de %i ", unaPersona.nacimiento.dia, unaPersona.nacimiento.mes, unaPersona.nacimiento.anio);

    printf("\n\n");
    return 0;
}
