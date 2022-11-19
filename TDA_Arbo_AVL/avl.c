//
// Created by Jonathan Córdoba on 19/11/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "avl.h"

ArbolAVL * inicializarArbol(){
    ArbolAVL * arbol = (ArbolAVL *) malloc(sizeof(ArbolAVL));
    arbol->raiz = NULL;
    return arbol;
}

Nodo * crearNodo(double x){
    Nodo * nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->dato = x;
    nodo->hi = NULL;
    nodo->hd = NULL;
    return nodo;
}

// Altura del arbol
int altura(Nodo * enlace){
    if(enlace == NULL) return 0;
    else{
        int nodo_i, nodo_d;
        nodo_i = altura(enlace->hi);
        nodo_d = altura(enlace->hd);
        if(nodo_i > nodo_d) return (1 + nodo_i);
        else return (1 + nodo_d);
    }
}

int altura_arbol(ArbolAVL * bt){
    return altura(bt->raiz);
}

bool esBalanceado(Nodo * enlace){
    int altura_izq;
    int altura_der;

    // Si el arbol esta vacio se considera balanceado
    if(enlace == NULL) return true;

    altura_izq = altura(enlace->hi);
    altura_der = altura(enlace->hd);

    if(abs(altura_der-altura_izq) <= 1 && esBalanceado(enlace->hi) && esBalanceado(enlace->hd)) return true;

    // Si llegamos aquí el árbol entonces no esta balanceado
    return false;
}

bool es_arbol_balanceado(ArbolAVL * bt){
    return esBalanceado(bt->raiz);
}

int factor_balance(Nodo * enlace){
    int fb = 0;

    if(enlace->hi) fb += altura(enlace->hi);
    if(enlace->hd) fb -= altura(enlace->hd);

    return fb;
}

// Caso Izquierdo-Izquierdo
// Rotacion a la Derecha
Nodo * rotacion_izq_izq(Nodo * enlace){
    Nodo * y = enlace;
    Nodo * x = y->hi;

    y->hi = x->hd;
    x->hd = y;

    return x;
}

// Caso Derecho-Derecho
// Rotacion a la Izquierda
Nodo * rotacion_der_der(Nodo * enlace){
    Nodo * y = enlace;
    Nodo * x = y->hd;

    y->hd = x->hi;
    x->hi = y;

    return x;
}

// Caso Izquierda-Derecha
// Rotacion Izquierda-Derecha
Nodo * rotacion_izq_der(Nodo * enlace){
    Nodo * z = enlace;
    Nodo * y = z->hi;
    Nodo * x = y->hd;

    z->hi = x->hd;
    y->hd = x->hi;
    x->hi = y;
    x->hd = z;

    return x;
}

// Caso Derecha-Izquierda
// Rotacion Derecha-Izquierda
Nodo * rotacion_der_izq(Nodo * enlace){
    Nodo * z = enlace;
    Nodo * y = z->hd;
    Nodo * x = y->hi;

    z->hd = x->hi;
    y->hi = x->hd;
    x->hi = z;
    x->hd = y;

    return x;
}

// Balancear un Nodo Dado
Nodo * balancear_nodo(Nodo * nodo){
    Nodo * nuevaRaiz = NULL;
    // Balancear Hijos, si existen
    if(nodo->hi){
        nodo->hi = balancear_nodo(nodo->hi);
    }
    if(nodo->hd){
        nodo->hd = balancear_nodo(nodo->hd);
    }

    int fb = factor_balance(nodo);

    if(fb>=2){
        /* Más pesado a la Izquierda */
        if(factor_balance(nodo->hi) <= -1){
            nuevaRaiz = rotacion_izq_der(nodo);
        } else{
            nuevaRaiz = rotacion_izq_izq(nodo);
        }
    } else if(fb <= -2){
        /* Más pesado a la Derecha */
        if(factor_balance(nodo->hd) >= 1){
            nuevaRaiz = rotacion_der_izq(nodo);
        } else{
            nuevaRaiz = rotacion_der_der(nodo);
        }
    } else{
        nuevaRaiz = nodo;
    }

    return nuevaRaiz;
}

void balancear_arbol(ArbolAVL * bt){
    Nodo * nuevaRaiz = NULL;
    nuevaRaiz = balancear_nodo(bt->raiz);
    if(nuevaRaiz != bt->raiz){
        bt->raiz = nuevaRaiz;
    }
}

Nodo * insertar(Nodo * raiz, double x){
    if(raiz == NULL){
        raiz = crearNodo(x);
    } else if(x < raiz->dato){
        raiz->hi = insertar(raiz->hi, x);
    } else if(x > raiz->dato){
        raiz->hd = insertar(raiz->hd, x);
    }

    return raiz;
}

void insertar_en_arbol(ArbolAVL * arbol, double x){
    arbol->raiz = insertar(arbol->raiz, x);
    balancear_arbol(arbol);
}

void preorden(Nodo * raiz){
    if(raiz != NULL){
        printf("%.2lf ", raiz->dato);
        preorden(raiz->hi);
        preorden(raiz->hd);
    }
}

void preorden_arbol(ArbolAVL * arbol){
    preorden(arbol->raiz);
}

void inorden(Nodo * raiz){
    if(raiz != NULL){
        inorden(raiz->hi);
        printf("%.2lf ", raiz->dato);
        inorden(raiz->hd);
    }
}

void inorden_arbol(ArbolAVL * arbol){
    inorden(arbol->raiz);
}

void postorden(Nodo * raiz){
    if(raiz != NULL){
        postorden(raiz->hi);
        postorden(raiz->hd);
        printf("%.2lf ", raiz->dato);
    }
}

void postorden_arbol(ArbolAVL * arbol){
    postorden(arbol->raiz);
}


Nodo * valorMenor(Nodo * raiz){
    if(raiz == NULL) return raiz;
    else if(raiz->hi == NULL) return raiz;
    else return valorMenor(raiz->hi);
}

Nodo * borrar(Nodo * raiz, double x);

Nodo * borrar_nodo(Nodo * raiz){
    Nodo * temp;
    // Caso 1: El nodo no tiene hijos
    if((raiz->hi == NULL) && (raiz->hd == NULL)){
        free(raiz);
        return NULL;
    }
        // Caso 2a: El nodo solo tiene hijo derecho
    else if((raiz->hi == NULL) && (raiz->hd != NULL)){
        temp = raiz->hd;
        free(raiz);
        return temp;
    }
        // Caso 2b: El nodo solo tiene hijo izquierdo
    else if((raiz->hi != NULL) && (raiz->hd == NULL)){
        temp = raiz->hi;
        free(raiz);
        return temp;
    }
        // Caso 3: El nodo tiene sus dos hijos
    else{
        Nodo * sucesor = valorMenor(raiz->hd);
        int valorSucesivo = sucesor->dato;
        raiz = borrar(raiz, valorSucesivo);
        raiz->dato = valorSucesivo;
        return raiz;
    }
}

Nodo * borrar(Nodo * raiz, double x){
    if(raiz == NULL) return NULL;
    if(x == raiz->dato) raiz = borrar_nodo(raiz);
    if(x < raiz->dato) raiz->hi = borrar(raiz->hi, x);
    else raiz->hd = borrar(raiz->hd, x);
    return raiz;
}

void borrar_en_arbol(ArbolAVL * arbol, double x){
    arbol->raiz = borrar(arbol->raiz, x);
    balancear_arbol(arbol);
}


