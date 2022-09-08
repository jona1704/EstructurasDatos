#include <stdio.h>
#include <stdbool.h>
#include "lista.h"

int main() {
    Lista l1 = init();
    printf("Probando la función insertar: \n");
    l1 = insertar(l1, 1, 3);
    l1 = insertar(l1, 0, 4);
    l1 = insertar(l1, 5, 12);
    l1 = insertar(l1, 3, 5);
    l1 = insertar(l1, 1, 7);
    l1 = insertar(l1, 2, 4);
    l1 = insertar(l1, 1, 9);
    l1 = insertar(l1, 5, 9);
    l1 = insertar(l1, 4, 9);
    l1 = insertar(l1, 2, 15);
    l1 = insertar(l1, 2, 6);
    l1 = insertar(l1, 3, 27);
    l1 = insertar(l1, 5, 19);
    desplegar(l1);
    printf("#elementos=%d\n", len(l1));

    printf("\nOperaciones con la función buscar: ");
    if(buscar(l1, 7) == true){
        printf("\nEl elemento 7 se encuentra en la lista ...");
    } else{
        printf("\nEl elemento 7 no se encuentra en la lista ...");
    }
    if(buscar(l1, 2) == true){
        printf("\nEl elemento 2 se encuentra en la lista ...");
    } else{
        printf("\nEl elemento 2 no se encuentra en la lista ...");
    }
    printf("\n\nOperaciones con la función ordenar: \n");
    l1 = ordenar(l1);
    desplegar(l1);

    printf("\nProbando la función borrar: ");
    l1 = borrar(l1, 1);
    l1 = borrar(l1, 0);
    l1 = borrar(l1, 4);
    l1 = borrar(l1, 2);
    l1 = borrar(l1, 1);
    l1 = borrar(l1, 1);
    desplegar(l1);
    printf("#elementos=%d\n", len(l1));

    destroy(l1);

    return 0;
}

