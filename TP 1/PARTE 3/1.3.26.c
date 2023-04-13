/* Modificar el programa anterior para añadir un campo en la estructura teléfono que almacene un
carácter dependiendo si es un teléfono fijo o un celular. Podrá almacenar un carácter 'F' si es fijo
o 'C' si es un celular, en caso de ingresar otro carácter volver a solicitar su ingreso.
Modificar el programa para que muestre por pantalla el número de celular, indicando si es un un
número FIJO o CELULAR, de la persona que sea más grande en edad . */

#include <stdio.h>

// declaro globalmente los tipos de dato 'telefono' y 'persona'.

typedef struct {
    char fijo_o_celular;
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
        printf("\nIngresar el número de personas: ");
        scanf("%i", &N);
        if (N <= 0)
            printf("\n\n>>> El valor debe ser positivo. Volver a intentar <<<\n\n");
    } while (N <= 0);

    for (int i = 0; i < N; i++) {
        // Controlo cada ingreso de datos para que sea una entrada válida.
        printf("\nPersona %i \n\n", aux);
        do {
            printf("DNI: ");
            scanf("%i", &una_persona.dni);
            if (una_persona.dni < 1 || una_persona.dni > 99999999)  // DNI entre 1 y 8 dígitos.
                printf("\n\n>>> Ingresar un DNI válido!<<<\n\n");
        } while (una_persona.dni < 1 || una_persona.dni > 99999999);

        do {
            printf("Edad: ");
            scanf("%i", &una_persona.edad);
            if (una_persona.edad < 1 || una_persona.edad > 150)  // Edad entre 1 y 150 años para controlar la entrada.
                printf("\n\n>>> Ingresar una edad válida!<<<\n\n");
        } while (una_persona.edad < 1 || una_persona.edad > 150);

        do {
            while (fgetc(stdin) != '\n')
                ;
            printf("\n¿El número telefónico es celular o fijo? \n'F' si es fijo \n'C' si es celular \nOpción: ");
            scanf("%c", &una_persona.tel.fijo_o_celular);
            if (una_persona.tel.fijo_o_celular != 'F' && una_persona.tel.fijo_o_celular != 'C' && una_persona.tel.fijo_o_celular != 'f' && una_persona.tel.fijo_o_celular != 'c')
                printf("\n\n>>> Ingresar una opción válida! <<<\n\n");
        } while (una_persona.tel.fijo_o_celular != 'F' && una_persona.tel.fijo_o_celular != 'C' && una_persona.tel.fijo_o_celular != 'f' && una_persona.tel.fijo_o_celular != 'c');

        do {
            printf("\nCaracterística del número de teléfono: ");
            scanf("%i", &una_persona.tel.caracteristica);
            if (una_persona.tel.caracteristica < 1 || una_persona.tel.caracteristica > 9999)  // Característica entre 1 y 4 digitos.
                printf("\n\n>>> Ingresar un código de área válido! <<<\n\n");
        } while (una_persona.tel.caracteristica < 1 || una_persona.tel.caracteristica > 9999);

        do {
            printf("\nNúmero telefónico (sin el 15): ");
            scanf("%i", &una_persona.tel.numero);
            if (una_persona.tel.numero < 1000000 || una_persona.tel.numero > 9999999)  // Número de teléfono de 7 digitos (sin el 15).
                printf("\n\n>>> Ingresar un número telefónico válido! <<<\n\n");
        } while (una_persona.tel.numero < 1000000 || una_persona.tel.numero > 9999999);

        if (una_persona.edad > mas_grande) {
            mas_grande = una_persona.edad;
            caracteristica_mas_grande = una_persona.tel.caracteristica;
            numero_mas_grande = una_persona.tel.numero;
        }
        aux++;
    }

    if (una_persona.tel.fijo_o_celular == 'F' || una_persona.tel.fijo_o_celular == 'f')
        printf("\n  >>> El número de teléfono FIJO de la persona más grande es %i-%i\n\n", caracteristica_mas_grande, numero_mas_grande);
    else
        printf("\n  >>> El número de teléfono CELULAR de la persona más grande es %i-%i\n\n", caracteristica_mas_grande, numero_mas_grande);

    return 0;
}