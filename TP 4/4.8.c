/* Ingresar una cadena de caracteres, en caso de que la misma se corresponda con un entero,
realizar la conversión al formato número utilizando atoi(). Presentar por pantalla la cadena
ingresada y el número convertido. Tener en cuenta que para representar un entero debe poseer
solamente caracteres numéricos o el signo menos al principio. Ejemplo: Se ingresa 7291 ->
Muestra la cadena 7291 y el número 7291. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> // acá está definida la función atoi()

#define MAX 100

int esEntero(char cadena[]);

int main(int argc, char *argv[]){
char cadena[MAX];
int numeroConvertido;

printf("\nIngresar cadena de caracteres: ");
fgets(cadena, MAX, stdin);
cadena[strlen(cadena) - 1] = '\0';

if(esEntero(cadena)){
numeroConvertido = atoi(cadena);
printf("\nLa cadena ingresada es: %s y el número entero convertido es %i.\n\n", cadena, numeroConvertido);
}
else
printf("\nLa cadena ingresada no se corresponde con un entero. \n\n");

return 0;
}

int esEntero(char cadena[]){
int Entero = 1;

for(int i = 0; cadena[i] != '\0'; i++){
if(!isdigit(cadena[i]) && cadena[i] != '-')
Entero = 0;
}

return Entero;
}