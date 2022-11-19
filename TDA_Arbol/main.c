#include <stdio.h>
#include "arbol.h"

int main(int argc, char *argv[]) {
    Arbol arbol1 = crearArbol();
    insertar_en_arbol(arbol1, 30);
    insertar_en_arbol(arbol1, 25);
    insertar_en_arbol(arbol1, 45);
    insertar_en_arbol(arbol1, 10);
    insertar_en_arbol(arbol1, 27);
    insertar_en_arbol(arbol1, 38);
    insertar_en_arbol(arbol1, 47);
    printf("\nPreorden: ");
    recorrer_preorden(arbol1);
    printf("\nInorden: ");
    recorrer_inorden(arbol1);
    printf("\nPostorden: ");
    recorrer_postorden(arbol1);
    printf("\nNumero de Nodos en el arbol: %d", no_nodos_arbol(arbol1));
    printf("\nLa altura del arbol es: %d", altura_arbol(arbol1));
    printf("\nEl nivel del nodo 38 es: %d", nivel_nodo_arbol(arbol1, 38));
    printf("\nNodo de menor valor: %d", nodo_menor_arbol(arbol1));
    printf("\nNodo de mayor valor: %d", nodo_mayor_arbol(arbol1));
    buscar_arbol(arbol1, 12);
    buscar_arbol(arbol1, 27);
    borrar_en_arbol(arbol1, 45);
    borrar_en_arbol(arbol1, 30);
    printf("\nInorden: ");
    recorrer_inorden(arbol1);
    return 0;
}

