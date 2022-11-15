#include <stdio.h>
#include "listaligada.h"

int main() {
    // Declaramos múltiples instancias de lista
    ListaLigada * l1 = listaLigada();
    // Insertamos datos en la lista 1
    insertar_inicio(l1, 3);
    insertar_inicio(l1, 5);
    insertar_inicio(l1, 4);
    insertar_inicio(l1, 23);
    insertar_inicio(l1, 18);
    desplegar(l1);
    insertar_final(l1, 18);
    insertar_final(l1, 23);
    insertar_final(l1, 4);
    insertar_final(l1, 23);
    insertar_final(l1, 3);
    desplegar(l1);
    insertar_intermedio(l1, 0, 29);
    insertar_intermedio(l1, 11, 29);
    insertar_intermedio(l1, 6, 29);
    desplegar(l1);
    borrar_inicio(l1);
    borrar_inicio(l1);
    borrar_inicio(l1);
    desplegar(l1);
    borrar_final(l1);
    borrar_final(l1);
    borrar_final(l1);
    desplegar(l1);
    borrar_intermedio(l1, 1);
    borrar_intermedio(l1, 5);
    borrar_intermedio(l1, 2);
    desplegar(l1);

    limpiarLista(l1);

    return 0;
}
