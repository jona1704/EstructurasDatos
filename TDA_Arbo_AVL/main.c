#include <stdio.h>
#include "avl.h"

int main(int argc, const char * argv[]) {
    ArbolAVL * arbol_avl = inicializarArbol();
    insertar_en_arbol(arbol_avl, 6.5);
    insertar_en_arbol(arbol_avl, 8.8);
    insertar_en_arbol(arbol_avl, -3.4);
    insertar_en_arbol(arbol_avl, 9.9);
    insertar_en_arbol(arbol_avl, 23.2);
    insertar_en_arbol(arbol_avl, 45.6);
    insertar_en_arbol(arbol_avl, 27.6);
    printf("Recorrido en Preorden: \n");
    preorden_arbol(arbol_avl);
    printf("\nRecorrido Inorden: \n");
    inorden_arbol(arbol_avl);
    printf("\nRecorrido en Postorden: \n");
    postorden_arbol(arbol_avl);
    printf("\nAltura del Arbol: %d", altura_arbol(arbol_avl));
    if(es_arbol_balanceado(arbol_avl)){
        printf("\nEl arbol está balanceado\n");
    } else{
        printf("\nEl arbol NO está balanceado\n");
    }
    borrar_en_arbol(arbol_avl, 9.9);
    printf("\n");
    printf("\nRecorrido Inorden: \n");
    inorden_arbol(arbol_avl);
    printf("\nAltura del Arbol: %d", altura_arbol(arbol_avl));
    if(es_arbol_balanceado(arbol_avl)){
        printf("\nEl arbol está balanceado\n");
    } else{
        printf("\nEl arbol NO está balanceado\n");
    }
    printf("\n\n");

    return 0;
}
