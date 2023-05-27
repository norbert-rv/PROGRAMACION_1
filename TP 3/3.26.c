/* Los datos de un televisor se almacenan usando la siguiente estructura:
typedef struct{
char marca;
float precio;
int cantidad;
}televisores;
Realizar un programa que permita ingresar los datos de N televisores en un arreglo. Presentar por
pantalla el arreglo y luego permitir la modificación del precio en los casos en donde exista
coincidencia entre una inicial de una marca ingresada por teclado y la inicial registrada para el
televisor. Al realizar la búsqueda:
Si no existe en el arreglo un elemento con esa inicial presentar por pantalla el mensaje
correspondiente.
Si se encuentra coincidencia (una o más), se solicitará el ingreso del nuevo precio. Se debe presentar
por pantalla el contenido de dicho arreglo antes y después de la modificación.
Utilizar funciones para:
● Almacenar los datos de los televisores en el arreglo. Se sugiere además el uso de una
función para solicitar los datos de cada televisor.
● Realizar la búsqueda de las coincidencias y si es que hubiera, realizar el reemplazo del
valor del precio.
● Mostrar el arreglo de televisores.
*/

#include <ctype.h>
#include <stdio.h>
#include <unistd.h>  // librería para usar la función sleep()

#define MAX 50

typedef struct {
    char marca;
    float precio;
    int cantidad;
} televisores;

int pedirOrdenTV(int limite);
void ingresarTelevisor(televisores *unTV);  // ingresar los datos de un solo televisor
void cargarTelevisores(int cantidad, televisores catalogoTV[]);
void mostrarDatosTV(televisores unTV);
// función para cambiar el precio de los televisores de una cierta marca
int cambiarPrecioXMarca(char marca, int cantidadTV, televisores catalogoTV[]);
void mostrarCatalogoTV(int cantidad, televisores catalogoTV[]);

int main(int argc, char *argv[]) {
    televisores catalogoTelevisores[MAX];
    int cantidadTelevisores = pedirOrdenTV(MAX);
    char marca;
    int coincidencia = 0;

    cargarTelevisores(cantidadTelevisores, catalogoTelevisores);
    printf("\n> A continuación se muestra el catálogo completo... \n\n");
    sleep(2);  // hago una pausa en el programa de 2 segundos
    mostrarCatalogoTV(cantidadTelevisores, catalogoTelevisores);

    while (getchar() != '\n')
        ;
    printf("\n\n> A continuación ingrese la marca de la que desea modificar el precio: ");
    do {
        marca = getchar();
        getchar();
    } while (!isalnum(marca));

    printf("\n");
    coincidencia = cambiarPrecioXMarca(marca, cantidadTelevisores, catalogoTelevisores);

    if (!coincidencia)
        printf("\n> No hay ningún televisor registrado con esa marca. \n");

    return 0;
}

int pedirOrdenTV(int limite) {
    int orden;
    do {
        printf("\n> ¿Cuántos televisores ingresará en la base de datos? ");
        scanf("%i", &orden);

        if (orden <= 0 || orden > limite)
            printf("\n> La cantidad debe ser positiva y menor que %i! \n", limite);
    } while (orden <= 0 || orden > limite);

    return orden;
}

void ingresarTelevisor(televisores *unTV) {
    while (getchar() != '\n')
        ;  // limpio el buffer de entrada cada vez que se llama a la función

    do {
        printf("\n> Marca: ");
        unTV->marca = getchar();
        getchar();

        if (!isalnum(unTV->marca))  // supongo que la marca solo puede ser una letra o un número
            printf("\n> Ingresar una marca válida! \n");
    } while (!isalnum(unTV->marca));

    do {
        printf("\n> Precio: ");
        scanf("%f", &unTV->precio);

        if (unTV->precio <= 0)  // voy a suponer que no hay productos gratis
            printf("\n> Ingresar un precio válido! \n");
    } while (unTV->precio <= 0);

    do {
        printf("\n> Cantidad: ");
        scanf("%i", &unTV->cantidad);

        if (unTV->cantidad < 0)  // la cantidad puede ser 0 (no hay televisores)
            printf("\n> Ingresar una cantidad válida! \n");
    } while (unTV->cantidad < 0);
}

void cargarTelevisores(int cantidad, televisores catalogoTV[]) {
    for (int i = 0; i < cantidad; i++) {
        printf("\n> Carga TV %i: ", i + 1);
        ingresarTelevisor(&catalogoTV[i]);
    }
}

void mostrarDatosTV(televisores unTV) {
    printf("\n> Marca: %c <", unTV.marca);
    printf("\n> Precio: %.2f <", unTV.precio);
    printf("\n> Cantidad: %i <\n", unTV.cantidad);
}

int cambiarPrecioXMarca(char marca, int cantidadTV, televisores catalogoTV[]) {
    int coincidencia = 0;  // booleano para saber si hay o no una coincidencia con el caracter ingresado

    for (int i = 0; i < cantidadTV; i++) {
        if (catalogoTV[i].marca == marca) {
            printf("> Cambiar precio TV: ");
            printf("\n> Precio viejo: %.2f", catalogoTV[i].precio);
            do {
                printf("\n> Precio nuevo: ");
                scanf("%f", &catalogoTV[i].precio);

                if (catalogoTV[i].precio <= 0)  // voy a suponer que no hay productos gratis
                    printf("\n> Ingresar un precio válido! \n");
            } while (catalogoTV[i].precio <= 0);

            printf("\n> Nuevos datos del televisor: \n");
            mostrarDatosTV(catalogoTV[i]);

            coincidencia = 1;

            printf("\n------------------- \n\n");
        }
    }

    return coincidencia;
}

void mostrarCatalogoTV(int cantidad, televisores catalogoTV[]) {
    for (int i = 0; i < cantidad; i++) {
        printf("\n> Televisor %i <", i + 1);
        mostrarDatosTV(catalogoTV[i]);
    }
}