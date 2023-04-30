#include <ctype.h>
#include <stdio.h>

int isPosit(int numero);
void control(int numero);

int main(int argc, char const *argv[]) {
    int numero;
    char letra;

    do {
        printf("Ingrese la cantidad de letras que va a ingresar: ");
        scanf("%i", &numero);
    } while (isPosit(numero) == 0);
    while (getchar() != '\n')
        ;
    control(numero);

    return 0;
}
int isPosit(int numero) {
    int bandera = 0;
    if (numero > 0) {
        bandera = 1;
    }
    return bandera;
}
void control(int numero) {
    char letra;
    int contador;
    for (contador = 0; numero > contador; contador++) {
        printf("Ingrese una letra: ");
        scanf("%c", &letra);
        getchar();
        if (isalpha(letra)) {
            if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U' || letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
                letra = toupper(letra);
            } else {
                letra = tolower(letra);
            }
            printf("\n> %c\n", letra);
        }
    }
}