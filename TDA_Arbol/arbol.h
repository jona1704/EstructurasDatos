//
// Created by Jonathan Córdoba on 19/11/22.
//

#ifndef _ARBOL_H
#define _ARBOL_H

typedef int Elemento;
typedef struct arbol * Arbol;

// Prototipos para arbol
Arbol crearArbol();
void insertar_en_arbol(Arbol a, Elemento el);
void recorrer_preorden(Arbol a);
void recorrer_inorden(Arbol a);
void recorrer_postorden(Arbol a);
int no_nodos_arbol(Arbol a);
int altura_arbol(Arbol a);
int nivel_nodo_arbol(Arbol a, Elemento el);
void nodos_x_nivel(Arbol a, int nivel);
int nodo_menor_arbol(Arbol);
int nodo_mayor_arbol(Arbol);
void borrar_en_arbol(Arbol a, Elemento el);
void es_arbol_completo(Arbol a);
void buscar_arbol(Arbol a, Elemento el);

#endif

