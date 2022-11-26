//
// Created by Jonathan Córdoba on 26/10/22.
//
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "pila.h"

Pila crearPila(){
    Pila p;
    int i;
    for(i=0; i<MAX_PILA; i++){
        p.arr[i] = 0.0;
    }
    p.tope = -1;
    return p;
}

bool esVacia(Pila p){
    return p.tope == -1;
}

bool esLlena(Pila p){
    return p.tope == MAX_PILA-1;
}

Pila push(Pila p, float dato){
    if(esLlena(p)){
        //printf("\nPila Llena");
    } else{
        p.tope++;
        p.arr[p.tope] = dato;
    }
    return p;
}

float pop(Pila p){
    float valor_borrado;
    if(esVacia(p)){
        //printf("\nPila Vacia");
        valor_borrado = (float) INT_MIN;
    } else{
        valor_borrado = p.arr[p.tope];
        p.tope--;
    }
    return valor_borrado;
}

int len(Pila p){
    return p.tope;
}

void display_pila(Pila p){
    if(esVacia(p)){
        printf("\nPila Vacia ...");
    } else{
        int i;
        printf("[ ");
        for(i=p.tope; i>=0; i--){
            if(i == 0) printf("%.2f", p.arr[i]);
            else printf("%.2f, ", p.arr[i]);
        }
        printf(" ]\n");
    }
}

