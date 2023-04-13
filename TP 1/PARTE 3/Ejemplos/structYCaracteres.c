/*
Definir una estructura cuyos campos permitan guardar la cantidad de caracteres que sean vocales,
la cantidad que sean consonantes y la cantidad que sean de otro tipo.

Ingresar N caracteres, y contabilizar en la estructura definida los caracteres de acuerdo a su tipo
(vocales o consonantes). Nota: Para resolver es importante Investigar!

�Qu� librer�a se requiere para el uso de funciones que permitan evaluar caracteres?

�Para qu� usamos el fgetc(stdin)? �Que otra instrucci�n se podr� utilizar?
*/

typedef struct{
	int vocales;
	int consonantes;
	int otros;
}caracteres;

#include<stdio.h>
#include<ctype.h>/*funciones para evaluar caracteres*/

int main(int argv, char *argc[])
{
	/*declaraci�n de variables*/
	caracteres variable;
	int N, i;
	char car;
	
	/*Valores iniciales*/
	variable.vocales=0;
	variable.consonantes=0;
	variable.otros=0;
	i=0;
	
	/*Datos de entrada:*/
	printf("Ingresar la cantidad de caracteres: ");
	scanf("%i",&N);
	/*al ejecutarse scanf, el numero se almacena en N y el enter queda en el buffer del teclado*/
	
	/*Tener en cuenta que el enter tambi�n es un caracter*/
	
	fgetc(stdin);
	/*toma el enter que estaba en el buffer (limpia el buffer) */
		
	
	while(i<N){
		printf("Ingresar un caracter: ");
		scanf("%c",&car);/*al ejecutarse scanf, el caracter se almacena en car y el enter queda en el buffer del teclado*/
		fgetc(stdin);/*toma el enter que estaba en el buffer (o limpia el buffer) */
		if(isalpha(car)!=0){/*isalpha es distinto de cero cuando car es alfabetico*/
			car=toupper(car);/*toupper pasa a mayuscula car*/
			if(car=='A' || car=='E' || car=='I' || car=='O' || car=='U'){
				variable.vocales = variable.vocales + 1;
			}else{
				variable.consonantes = variable.consonantes + 1;
			}
		}else{
		variable.otros = variable.otros + 1;
		}
		i=i+1;
	}
	
	/*Salida*/
	printf("\n\nVocales = %i",variable.vocales);
	printf("\n\nConsonantes = %i",variable.consonantes);
	printf("\n\nNinguna de las anteriores = %i",variable.otros);
	
	printf("\n\n");
	return 0;			
}

