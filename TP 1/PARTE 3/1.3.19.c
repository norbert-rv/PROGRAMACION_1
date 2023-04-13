/* Implementar un programa en el que se ingresan los datos de N personas. Calcular y presentar
por pantalla el promedio de edades de las personas ingresadas. Utilizar la estructura en la que se
represente la inicial del apellido y del nombre (1 caracter para cada uno) y la edad de una
persona. Controlar que la edad sea un valor positivo.
struct persona {
    char nombre;
    char apellido;
    int edad;
};
*/

#include <stdio.h>

struct persona {
    char nombre;
    char apellido;
    int edad;
};

int main(int argc, char *argv[]) {
    int N, suma_edades = 0;
    float promedio, contador = 0;
    struct persona letra_nombre, letra_apellido, anios;

    do {
        printf("Ingresar el número N de personas: ");
        scanf("%i", &N);
    } while (N <= 0);

    while (fgetc(stdin) != '\n')
        ;

    for (int i = 0; i < N; i++) {
        printf("Inicial del nombre: ");
        scanf("%c", &letra_nombre.nombre);

        while (fgetc(stdin) != '\n')
            ;

        printf("Inicial del apellido: ");
        scanf("%c", &letra_apellido.apellido);

        while (fgetc(stdin) != '\n')
            ;

        do {
            printf("Edad: ");
            scanf("%i", &anios.edad);
        } while (anios.edad <= 0);

        while (fgetc(stdin) != '\n')
            ;

        suma_edades += anios.edad;
        contador++;
    }

    promedio = suma_edades / contador;

    printf("El promedio de edades es: %.2f\n", promedio);

    return 0;
}