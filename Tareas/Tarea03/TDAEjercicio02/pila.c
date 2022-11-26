//
// Created by Jonthan Cordoba on 25/11/22.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "pila.h"

char buffer[DATASIZE];

Pila crearPila(){
    Pila p;
    int i;
    for(i=0; i<MAX_PILA; i++){
        strcpy(p.arr[i], "\0");
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

void push(Pila * p, char dato[]){
    if(esLlena(*p)){
        //printf("\nPila Llena");
    } else{
        p->tope++;
        strcpy(p->arr[p->tope], dato);
    }
}

char * pop(Pila * p){
    static char valor_borrado[DATASIZE];
    if(esVacia(*p)){
        //printf("\nPila Vacia");
        strcpy(valor_borrado, "\0");
    } else{
        strcpy(valor_borrado, p->arr[p->tope]);
        p->tope--;
    }
    return valor_borrado;
}

int len(Pila p){
    return p.tope+1;
}

void display_pila(Pila p){
    if(esVacia(p)){
        printf("\nPila Vacia ...");
    } else{
        int i;
        printf("[ ");
        for(i=p.tope; i>=0; i--){
            if(i == 0) printf("%s", p.arr[i]);
            else printf("%s, ", p.arr[i]);
        }
        printf(" ]\n");
    }
}

