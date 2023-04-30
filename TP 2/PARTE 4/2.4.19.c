/* Ingresar dos caracteres; controlar que los mismos sean letras del alfabeto; en caso de
que las letras ingresadas sean mayúsculas, convertirlas a minúsculas; luego presentar
por pantalla dichas letras pero ordenadas en forma alfabética, o un mensaje en caso de
que sean iguales (debe realizar una función para ordenar las letras y determinar si son
iguales). */

#include <ctype.h>
#include <stdio.h>

char pedirCaracter();
void convertirLetras(char *, char *);  // función para pasar mayusculas a minusculas y viceversa
void ordenarLetras(char, char);        // función para ordenar las letras y determinar si son iguales

int main(int argc, char *argv[]) {
    char car1 = pedirCaracter(), car2 = pedirCaracter();

    convertirLetras(&car1, &car2);
    ordenarLetras(car1, car2);

    return 0;
}

char pedirCaracter() {
    char car;
    do {
        printf("\nIngresar caracter 1: ");
        car = getchar();
        fgetc(stdin);

        if (!isalpha(car))
            printf("\nIngresar un caracter alfabético!\n");
    } while (!isalpha(car));

    return car;
}

void convertirLetras(char *car1, char *car2) {
    if (islower(*car1))
        *car1 = toupper(*car1);
    else
        *car1 = tolower(*car1);
    if (islower(*car2))
        *car2 = toupper(*car2);
    else
        *car2 = tolower(*car2);
}

void ordenarLetras(char car1, char car2) {
    if (car1 == car2)
        printf("\nLos dos caracteres son iguales...\n\n");
    else if (car1 > car2)
        printf("\n%c\t%c\n\n", car2, car1);
    else
        printf("\n%c\t%c\n\n", car1, car2);
}