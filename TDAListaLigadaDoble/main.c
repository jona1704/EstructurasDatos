#include <stdio.h>
#include "listadoble.h"

int main() {
    // Declaramos múltiples instancias de lista
    ListaDoble * l1 = listaDoble();
    insertar_inicio(l1, 8);
    insertar_inicio(l1, 12);
    insertar_inicio(l1, 4);
    printf("\nListado hacia adelante: ");
    desplegar_adelante(l1);
    printf("Listado hacia atras: ");
    desplegar_atras(l1);
    insertar_final(l1, 6);
    insertar_final(l1, 9);
    insertar_final(l1, 12);
    insertar_final(l1, 19);
    insertar_final(l1, 24);
    insertar_final(l1, 23);
    printf("\nListado hacia adelante: ");
    desplegar_adelante(l1);
    printf("Listado hacia atras: ");
    desplegar_atras(l1);
    insertar_intermedio(l1,4, 10);
    insertar_intermedio(l1,6, 5);
    insertar_intermedio(l1,7, 21);
    insertar_intermedio(l1, 9, 50);
    printf("\nListado hacia adelante: ");
    desplegar_adelante(l1);
    printf("Listado hacia atras: ");
    desplegar_atras(l1);
    borrar_inicio(l1);
    borrar_inicio(l1);
    borrar_inicio(l1);
    borrar_inicio(l1);
    printf("\nListado hacia adelante: ");
    desplegar_adelante(l1);
    printf("Listado hacia atras: ");
    desplegar_atras(l1);
    borrar_final(l1);
    borrar_final(l1);
    borrar_final(l1);
    printf("\nListado hacia adelante: ");
    desplegar_adelante(l1);
    printf("Listado hacia atras: ");
    desplegar_atras(l1);
    borrar_intermedio(l1, 4);
    borrar_intermedio(l1, 2);
    printf("\nListado hacia adelante: ");
    desplegar_adelante(l1);
    printf("Listado hacia atras: ");
    desplegar_atras(l1);

    limpiarLista(l1);

    return 0;
}
