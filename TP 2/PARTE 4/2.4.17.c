/* De un grupo de N personas se debe registrar el peso, altura y edad. Realizar un programa
que permita calcular el peso promedio, altura promedio y la edad promedio.
Utilizar funciones para:
● Verificar que N sea un número entero positivo.
● Ingresar las personas y controlar que sus atributos sean números positivos
● Calcular el promedio del peso, la altura y la edad.
Presentar por pantalla los resultados. Utilizar parámetros por valor y por referencia y
variables static si considera necesario.
Usar la siguiente estructura para almacenar la información de cada persona:
typedef struct {
float peso;
float altura;
int edad;
} persona;
*/

#include <stdio.h>

typedef struct {
    float peso;
    float altura;
    int edad;
} persona;

int es_positivo(int);
void ingresarPersona(persona *);
void promedio(persona, int, persona *);

int main(int argc, char *argv[]) {
    persona una_persona, suma = {0, 0, 0}, promedios;  // en suma voy acumulando los valores ingresados para sacar luego el promedio
    int N;

    // variable de control N
    do {
        printf("\nIngrese el número N de personas: ");
        scanf("%i", &N);
    } while (!es_positivo(N));

    // ingreso las personas y voy acumulando los valores para luego sacar el promedio
    for (int i = 0; i < N; i++) {
        ingresarPersona(&una_persona);
        suma.peso += una_persona.peso;
        suma.altura += una_persona.altura;
        suma.edad += una_persona.edad;
    }

    // saco el promedio con la función promedio
    promedio(suma, N, &promedios);

    // muestro los resultados por pantalla
    printf("\n> El promedio de peso es %.1f\n> El promedio de altura es %.1f\n> El promedio de edad es %i\n\n", promedios.peso, promedios.altura, promedios.edad);

    return 0;
}

void promedio(persona suma, int cantidad, persona *promedios) {
    promedios->peso = suma.peso / cantidad;
    promedios->altura = suma.altura / cantidad;
    promedios->edad = suma.edad / cantidad;
}

int es_positivo(int num) {
    if (num > 0)
        return 1;
    else
        return 0;
}

void ingresarPersona(persona *una_persona) {
    do {
        printf("\nIngresar el peso: ");
        scanf("%f", &una_persona->peso);

        if (!es_positivo(una_persona->peso))
            printf("\nIngrese un número válido!...\n");
    } while (!es_positivo(una_persona->peso));

    do {
        printf("\nIngrese la altura: ");
        scanf("%f", &una_persona->altura);

        if (!es_positivo(una_persona->altura))
            printf("\nIngrese un número válido!...\n");
    } while (!es_positivo(una_persona->altura));

    do {
        printf("\nIngrese la edad: ");
        scanf("%i", &una_persona->edad);

        if (!es_positivo(una_persona->edad))
            printf("\nIngrese un número válido!...\n");
    } while (!es_positivo(una_persona->edad));
}