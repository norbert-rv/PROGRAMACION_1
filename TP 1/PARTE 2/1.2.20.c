/* Implementar un programa que solicite al usuario el ingreso de un signo del zodíaco de una
lista de opciones y le muestre por pantalla un mensaje que indique si es de agua, aire,
tierra, fuego o si ha seleccionado un valor inválido. Sugerencia: usar switch. Por ejemplo, si se ingresa el valor 1,
mostrar “El signo de Aries es de Fuego”, si se ingresa 15 mostrar “El
valor ingresado no corresponde a una opción válida”.*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    int signo;

    printf("Signo del zodíaco: \n1. Aries \n2. Tauro \n3. Géminis \n4. Cáncer \n5. Leo \n6. Virgo \n7. Libra \n8. Escorpio \n9. Sagitario \n10. Capricornio \n11. Acuario \n12. Piscis \nUsted elige: ");
    scanf("%i", &signo);

    switch (signo) {
        case 1:
            printf("El signo de Aries es de Fuego.\n");
            break;
        case 2:
            printf("El signo de Tauro es de Tierra.\n");
            break;
        case 3:
            printf("El signo de Géminis es de Aire.\n");
            break;
        case 4:
            printf("El signo de Cáncer es de Agua.\n");
            break;
        case 5:
            printf("El signo de Leo es de Fuego.\n");
            break;
        case 6:
            printf("El signo de Virgo es de Tierra.\n");
            break;
        case 7:
            printf("El signo de Libra es de Aire.\n");
            break;
        case 8:
            printf("El signo de Escorpio es de Agua.\n");
            break;
        case 9:
            printf("El signo de Sagitario es de Fuego.\n");
            break;
        case 10:
            printf("El signo de Capricornio es de Tierra.\n");
            break;
        case 11:
            printf("El signo de Acuario es de Aire.\n");
            break;
        case 12:
            printf("El signo de Piscis es de Agua.\n");
            break;
        default:
            printf("El valor ingresado no corresponde a una opción válida.\n");
            break;
    }

    return 0;
}