//
// Created by Jonathan Córdoba on 14/10/22.
//

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "pila.h"

struct pila{
    int * arr;
    int tope;
    unsigned capacidad;
};

static bool esVacia(Pila p){
    return p->tope == -1;
}

static bool esLlena(Pila p){
    return p->tope == p->capacidad-1;
}

Pila crearPila(unsigned capacidad){
    // Inicializamos la pila
    Pila p = (Pila) malloc(sizeof(struct pila));
    if(p == NULL) exit(1);
    p->arr = (int *) malloc(p->capacidad * sizeof(int));
    p->capacidad = capacidad;
    p->tope = -1;
    return p;
}

void push(Pila p, int dato){
    if(esLlena(p)){
        //printf("\nPila Llena ...");
        return;
    } else{
        p->tope++;
        p->arr[p->tope] = dato;
    }
}

int pop(Pila p){
    int elemento;
    if(esVacia(p)){
        elemento = INT_MIN;
        //printf("\nPila Vacia ...");
    } else{
        elemento = p->arr[p->tope];
        p->tope--;
    }
    return elemento;
}




