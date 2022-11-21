//
// Created by Jonathan Córdoba on 04/11/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "pila.h"

struct pila{
    int array[MAX];
    int tope;
};

Pila init(){
    //printf("%s: ", __FUNCTION__);
    Pila p = (Pila) malloc(sizeof(struct pila));
    assert(p);
    int i;
    for(i=0; i<MAX; i++){
        p->array[i] = 0;
    }
    p->tope = -1;
    return p;
}

int esVacia(Pila p){
    return p->tope == -1;
}

int esLlena(Pila p){
    return p->tope == MAX-1;
}

// Operaciones de Pila
void push(Pila p , int dato){
    if(esLlena(p)){
        printf("\nPila esta Llena\n");
    } else{
        p->tope++;
        p->array[p->tope] = dato;
    }
}

void ingresar(Pila p, int dato){
    if(esLlena(p)){
        printf("\nPila esta Llena\n");
    } else{
        p->tope++;
        p->array[p->tope] = dato;
    }
}

int pop(Pila p){
    int valor;
    if(esVacia(p)){
        printf("\nPila esta Vacia\n");
        valor = INT_MIN;
    } else{
        valor = p->array[p->tope];
        p->tope--;
    }
    return valor;
}

void desplegar(Pila p){
    if(esVacia(p)){
        printf("\nPila esta Vacia\n");
    } else{
        int i;
        for(i=p->tope; i>=0; i--){
            printf("%d ", p->array[i]);
        }
        printf("\n");
    }
}

void limpiarPila(Pila p){
    free(p);
}
