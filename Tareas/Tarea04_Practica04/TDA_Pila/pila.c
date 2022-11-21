//
// Created by Jonathan Córdoba on 26/10/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
#include "pila.h"

struct pila{
    char arr[MAX];
    int tope;
};

Pila crearPila(){
    Pila p = (Pila) malloc(sizeof(struct pila));
    assert(p!=NULL);
    int i;
    for(i=0; i<MAX; i++){
        p->arr[i] = '0';
    }
    p->tope = -1;
    return p;
}

bool esVacia(Pila p){
    return p->tope == -1;
}

bool esLlena(Pila p){
    return p->tope == MAX-1;
}

void push(Pila p, char dato){
    if(esLlena(p)){
        //printf("\nPila Llena");
        return;
    } else{
        p->tope++;
        p->arr[p->tope] = dato;
    }
}

char pop(Pila p){
    char valor_borrado;
    if(esVacia(p)){
        //printf("\nPila Vacia");
        valor_borrado = '0';
    } else{
        valor_borrado = p->arr[p->tope];
        p->tope--;
    }
    return valor_borrado;
}

void destroy(Pila p){
    free(p);
}