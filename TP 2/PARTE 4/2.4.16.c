/* Definir un tipo struct que contenga los siguientes atributos:
typedef struct{
char automovil; //letra que representa al automovil
float tiempo;
}participante;
Emplear esta estructura para resolver el siguiente problema: En una carrera, en donde
compiten N automóviles, se registra una letra que identifica a cada automóvil y el
tiempo que demora en llegar a la meta.
Utilizar funciones diferentes para:
● Verificar que N sea un número entero positivo.
● Ingresar un participante, controlando que el tiempo sea un real positivo. (esta
función no debe retornar valor).
● Determinar cuál es élautomóvil ganador, es decir el auto que llegó utilizando el
menor tiempo posible y en qué posición se lo ingresó, con una función con la
siguiente declaración:
void determinarGanador(participante *participanteIngresado,
participante *ganador, int *posicionGanador);
● Para mostrar por pantalla al automóvil ganador. Utilizar funciones de conversión
de caracteres, presente la letra en mayúscula y el tiempo que este demoró en
llegar a la meta. Revisar ctype.h
*/

#include <ctype.h>
#include <stdio.h>

typedef struct {
    char automovil;  // letra que representa al automovil
    float tiempo;
} participante;

int es_positivo(int);
void ingresarParticipante(participante *);
void determinarGanador(participante *participanteIngresado, participante *ganador, int *posicionGanador);
void mostrarGanador(participante, int);

int main(int argc, char *argv[]) {
    participante un_participante, ganador;
    ganador.tiempo = 99999999;
    int N, posicionGanador = 1;

    do {
        printf("\n¿Cuántos participantes ingresará? ");
        scanf("%i", &N);
    } while (!es_positivo(N));

    printf("\nIngreso de participantes...\n\n");

    for (int i = 0; i < N; i++) {
        ingresarParticipante(&un_participante);
        determinarGanador(&un_participante, &ganador, &posicionGanador);
    }

    mostrarGanador(ganador, posicionGanador);

    return 0;
}

int es_positivo(int num) {
    if (num > 0)
        return 1;
    else
        return 0;
}

void ingresarParticipante(participante *participante1) {
    printf("\nIngresar letra que representa al automovil: ");
    scanf("%c", &participante1->automovil);

    getchar();

    do {
        printf("\nIngresar el tiempo: ");
        scanf("%f", &participante1->tiempo);
        getchar();
    } while (participante1->tiempo <= 0);
}

void determinarGanador(participante *participanteIngresado, participante *ganador, int *posicionGanador) {
    static int posicion = 1;
    if (participanteIngresado->tiempo < ganador->tiempo) {
        ganador->automovil = participanteIngresado->automovil;
        ganador->tiempo = participanteIngresado->tiempo;
        *posicionGanador = posicion;
    }
    posicion++;
}

void mostrarGanador(participante ganador, int posicion) {
    printf("\nEl ganador es el auto > %c < en la posición > %i < con el tiempo > %i <\n\n", ganador.automovil, ganador.tiempo, posicion);
}