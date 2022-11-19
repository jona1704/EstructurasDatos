//
// Created by Jonathan Córdoba on 19/11/22.
//

#ifndef AVL_H
#define AVL_H

#include <stdbool.h>

typedef struct nodo{
    double dato;
    struct nodo * hi;
    struct nodo * hd;
} Nodo;

typedef struct arbol_avl{
    Nodo * raiz;
} ArbolAVL;

ArbolAVL * inicializarArbol();
void insertar_en_arbol(ArbolAVL * arbol, double x);
void preorden_arbol(ArbolAVL * arbol);
void inorden_arbol(ArbolAVL * arbol);
void postorden_arbol(ArbolAVL * arbol);
int altura_arbol(ArbolAVL * bt);
bool es_arbol_balanceado(ArbolAVL * bt);
void borrar_en_arbol(ArbolAVL * arbol, double x);


#endif // AVL_H
