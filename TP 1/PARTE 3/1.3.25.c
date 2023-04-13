/* Se deben guardar los datos de N personas. Mostrar por pantalla el número de teléfono (Por ej
"caracteristica - numero") de la persona que sea más grande. Utilizar una estructura como la
siguiente:
typdef struct{
int caracteristica;
int numero;
}telefono;
typdef struct{
int dni;
int edad;
telefono tel;
}persona;
*/

#include <stdio.h>

// declaro globalmente los tipos de dato 'telefono' y 'persona'.

typedef struct {
    int caracteristica;
    int numero;
} telefono;

typedef struct {
    int dni;
    int edad;
    telefono tel;
} persona;

int main(int argc, char *argv[]) {
    int N, mas_grande = 0, caracteristica_mas_grande, numero_mas_grande;
    int aux = 1;  // Variable para mostrar por pantalla el numero de persona cuyos datos se ingresarán.

    // declaro la variables de tipo 'persona'.

    persona una_persona;

    do {
        printf("Ingresar el número de personas: ");
        scanf("%i", &N);
        if (N <= 0)
            printf("\n>>> Ingresar un valor válido <<<\n\n");
    } while (N <= 0);

    for (int i = 0; i < N; i++) {
        // Controlo cada ingreso de datos para que sea una entrada válida.
        printf("\nPersona %i \n", aux);
        do {
            printf("DNI: ");
            scanf("%i", &una_persona.dni);
            if (una_persona.dni < 1 || una_persona.dni > 99999999)  // DNI entre 1 y 8 dígitos.
                printf("\n>>> Ingresar un DNI válido! <<<\n\n");
        } while (una_persona.dni < 1 || una_persona.dni > 999999999);

        do {
            printf("Edad: ");
            scanf("%i", &una_persona.edad);
            if (una_persona.edad < 1 || una_persona.edad > 150)  // Edad entre 1 y 150 años para controlar la entrada.
                printf("\n>>> Ingresar una edad válida!\n\n");
        } while (una_persona.edad < 1 || una_persona.edad > 150);

        do {
            printf("Característica del número telefónico: ");
            scanf("%i", &una_persona.tel.caracteristica);
            if (una_persona.tel.caracteristica < 1 || una_persona.tel.caracteristica > 9999)  // Característica entre 1 y 4 digitos.
                printf("\n>>> Ingresar un código de área válido! <<<\n\n");
        } while (una_persona.tel.caracteristica < 1 || una_persona.tel.caracteristica > 9999);

        do {
            printf("Número telefónico (sin el 15): ");
            scanf("%i", &una_persona.tel.numero);
            if (una_persona.tel.numero < 1000000 || una_persona.tel.numero > 9999999)  // Número de teléfono de 7 digitos (sin el 15).
                printf("\n>>> Ingresar un número telefónico válido! >>>\n\n");
        } while (una_persona.tel.numero < 1000000 || una_persona.tel.numero > 9999999);

        if (una_persona.edad > mas_grande) {
            mas_grande = una_persona.edad;
            caracteristica_mas_grande = una_persona.tel.caracteristica;
            numero_mas_grande = una_persona.tel.numero;
        }
        aux++;
    }

    printf("\nEl número de teléfono de la persona más grande es %i-%i\n\n", caracteristica_mas_grande, numero_mas_grande);

    return 0;
}