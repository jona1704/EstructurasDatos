#include <stdio.h>
#include "listacircular.h"

int main() {
    // Declaramos múltiples instancias de lista
    ListaCircular * l1 = listaCircular();
    // Insertamos datos en la lista 1
    insertar_inicio(l1, 7);
    insertar_inicio(l1, 8);
    insertar_inicio(l1, 9);
    desplegar(l1);
    insertar_final(l1, 5);
    insertar_final(l1, 3);
    insertar_final(l1, -2);
    desplegar(l1);
    insertar_intermedio(l1, 0, 3);
    insertar_intermedio(l1, 1, 9);
    insertar_intermedio(l1, 2, 8);
    insertar_intermedio(l1, 2, 7);
    insertar_intermedio(l1, 4, 28);
    insertar_intermedio(l1, 5, 12);
    desplegar(l1);
    borrar_inicio(l1);
    borrar_inicio(l1);
    desplegar(l1);
    borrar_final(l1);
    borrar_final(l1);
    borrar_final(l1);
    desplegar(l1);
    borrar_intermedio(l1, 0);
    borrar_intermedio(l1, 5);
    borrar_intermedio(l1, 2);
    borrar_intermedio(l1, 3);
    borrar_intermedio(l1, 2);
    borrar_intermedio(l1, 1);
    desplegar(l1);
    primerNodo(l1);
    ultimoNodo(l1);
    printf("\nNumero de Nodos:  %d\n", no_nodos(l1));

    liberar(l1);

    return 0;
}

