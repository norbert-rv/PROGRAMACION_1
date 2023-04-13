#include <stdio.h>

int main(int argc, char *argv[]) {
    int num, suma = 0, cant_num = 1;

    for (int i = 0; i < 4; i++) {
        printf("Ingresar número %i: ", cant_num);
        scanf("%i", &num);
        suma += num;
        cant_num++;
    }

    printf("La media aritmética es: %i.\n", suma / 4);

    return 0;
}