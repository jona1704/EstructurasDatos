#include <stdio.h>
#include "lista.h"

int main() {
    // Lista 1
    Lista l1 = crearLista();
    // Lista 2
    Lista l2 = crearLista();
    // Insertar en la Lista 1
    l1 = insertar(l1, 5.6);
    l1 = insertar(l1, 8.7);
    l1 = insertar(l1, 4.9);
    desplegar(l1);
    printf("Elementos en l1: %d\n\n", size(l1));
    // Insertar en la Lista 2
    l2 = insertar(l2, 4.8);
    l2 = insertar(l2, -3.2);
    l2 = insertar(l2, 6.5);
    l2 = insertar(l2, 12.9);
    l2 = insertar(l2, -4.3);
    desplegar(l2);
    printf("Elementos en l2: %d\n", size(l2));
    
    return 0;
}
