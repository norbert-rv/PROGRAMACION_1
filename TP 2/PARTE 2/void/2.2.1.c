/* Implementar un programa que utilice una función para realizar una presentación de la materia,
por ejemplo:
"Programacion I"
"Anio de cursada: 2023"
"Facultad de Ciencias Exactas y Tecnología"
Usar secuencias de escape para salto de línea (\n) y tabulaciones (\t).
*/

#include <stdio.h>

void presentacion_materia();

int main(int argc, char *argv[]) {
    presentacion_materia();
    return 0;
}

void presentacion_materia() {
    printf("\n\tProgramación I\n\n\tAño de cursada: 2023\n\n\tFacultad de Ciencias Exactas y Tecnología\n\n");
}