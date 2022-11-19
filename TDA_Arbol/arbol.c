//
// Created by Jonathan Córdoba on 19/11/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "arbol.h"
#define NODO malloc(sizeof(Nodo))
#define ARBOL malloc(sizeof(Arbol))

typedef struct Nodo * Enlace;

typedef struct Nodo{
    Elemento dato;
    Enlace hi; // Hijo izquierdo
    Enlace hd; // Hijo derecho
} Nodo;

typedef struct arbol{
    Enlace raiz;
} arbol;

static Enlace crearNodo(Elemento el){
    Enlace temp = NODO;
    assert(temp!=NULL);
    temp->dato = el;
    temp->hi = NULL;
    temp->hd = NULL;
    return temp;
}

Arbol crearArbol(){
    Arbol temp = ARBOL;
    assert(temp!=NULL);
    temp->raiz = NULL;
    return temp;
}

static Enlace insertar(Enlace en, Elemento el){
    if(!en) return crearNodo(el);
    else{
        if(el < en->dato) en->hi = insertar(en->hi, el);
        else en->hd = insertar(en->hd, el);
    }
    return en;
}

void insertar_en_arbol(Arbol a, Elemento el){
    a->raiz = insertar(a->raiz, el);
}

// Recorridos

static void preorden(Enlace en){
    if(en){
        printf("%d ", en->dato);
        preorden(en->hi);
        preorden(en->hd);
    }
}

void recorrer_preorden(Arbol a){
    preorden(a->raiz);
}

static void inorden(Enlace en){
    if(en){
        inorden(en->hi);
        printf("%d ", en->dato);
        inorden(en->hd);
    }
}

void recorrer_inorden(Arbol a){
    inorden(a->raiz);
}

static void postorden(Enlace en){
    if(en){
        postorden(en->hi);
        postorden(en->hd);
        printf("%d ", en->dato);
    }
}

void recorrer_postorden(Arbol a){
    postorden(a->raiz);
}

// Contar Nodos
int no_nodos(Enlace en){
    if(!en) return 0;
    else return (1 + no_nodos(en->hi) + no_nodos(en->hd));
}

int no_nodos_arbol(Arbol a){
    return no_nodos(a->raiz);
}

// Altura del arbol
int altura(Enlace en){
    if(en == NULL) return 0;
    else{
        int nodo_i, nodo_d;
        nodo_i = altura(en->hi);
        nodo_d = altura(en->hd);
        if(nodo_i > nodo_d) return (1 + nodo_i);
        else return (1 + nodo_d);
    }
}

int altura_arbol(Arbol a){
    return altura(a->raiz);
}

// Obtener nivel de un nodo
int obtenerNivel(Enlace en, Elemento el, int nivel){
    if(!en) return 0;
    if(en->dato == el) return nivel;
    int nivel_abajo = obtenerNivel(en->hi, el, nivel+1);
    if(nivel_abajo != 0) return nivel_abajo;
    nivel_abajo = obtenerNivel(en->hd, el, nivel+1);
    return nivel_abajo;
}

int nivel_nodo_arbol(Arbol a, Elemento el){
    return obtenerNivel(a->raiz, el, 1);
}

// Encontrar el nodo con menor valor
Enlace valorMenor(Enlace en){
    if(!en) return en;
    else if(!(en->hi)) return en;
    return valorMenor(en->hi);
}

int nodo_menor_arbol(Arbol a){
    Enlace min = valorMenor(a->raiz);
    return min->dato;
}

// Encontrar el nodo con mayor valor
Enlace valorMayor(Enlace en){
    if(!en) return en;
    else if(!(en->hd)) return en;
    return valorMayor(en->hd);
}

int nodo_mayor_arbol(Arbol a){
    Enlace max = valorMayor(a->raiz);
    return max->dato;
}

Enlace borrar(Enlace en, Elemento el);

// Borrar Nodos del ·rbol
Enlace borrar_nodo(Enlace en){
    Enlace temp;
    // Caso 1: No tiene hijo el Nodo
    if(!(en->hi) && !(en->hd)){
        free(en);
        return NULL;
    }
        // Caso 2: El nodo solo tiene el hijo derecho
    else if(!(en->hi) && en->hd){
        temp = en->hd;
        free(en);
        return temp;
    }
        // Caso 3: El nodo solo tiene el hijo izquierdo
    else if(en->hi && !(en->hd)){
        temp = en->hi;
        free(en);
        return temp;
    }
        // Caso 4: El nodo tiene dos hijos
    else{
        Enlace sucesor = valorMenor(en->hd);
        // Duplicamos el nodo
        Elemento valorSucesivo = sucesor->dato;
        en = borrar(en, valorSucesivo);
        en->dato = valorSucesivo;
        return en;
    }
}

Enlace borrar(Enlace en, Elemento el){
    if(!en) return NULL;
    if(el == en->dato) en = borrar_nodo(en);
    else if(el < en->dato) en->hi = borrar(en->hi, el);
    else en->hd = borrar(en->hd, el);
    return en;
}

void borrar_en_arbol(Arbol a, Elemento el){
    a->raiz = borrar(a->raiz, el);
}

// Encontrar un elemento en el ·rbol
Enlace buscar(Enlace en, Elemento el){
    if(!en) return NULL;
    else if(el == en->dato) return en;
    else if(el < en->dato) return buscar(en->hi, el);
    else return buscar(en->hd, el);
}

void buscar_arbol(Arbol a, Elemento el){
    if(buscar(a->raiz, el)) printf("\nEl valor %d esta en el arbol", el);
    else printf("\nEl valor %d NO esta en el arbol", el);
}
