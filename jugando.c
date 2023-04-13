#include <stdio.h>

int main (int argc, char *argv[]) {
	int edad;
	
	do {
		printf("Hola Mundo!\n\n¿Cuántos años tienes?  ");
		scanf("%i", &edad);
	} while (edad <= 0 || edad > 140);
	
	printf("Hola chico de %i años!!!\n", edad);
	printf("Me faltarían los colores en las palabras reservadas y en las variables!!! \n");
	// que cosa seria por dios!
	
	return 0;
}
