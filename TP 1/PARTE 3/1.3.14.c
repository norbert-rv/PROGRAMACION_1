/* Dado un número natural de 4 dígitos(realizar este control), presentar por pantalla todos
sus divisores. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num;

    do {
        printf("Ingresar un número natural de 4 o más digitos: ");
        scanf("%i", &num);
    } while (num <= 999);

    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%i\n", i);
        }
    }

    return 0;
}