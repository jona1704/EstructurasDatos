//
// Created by Jonathan Córdoba on 29/08/22.
//
#include <stdio.h>
#include "lista.h"
#define MAX 30

struct lista{
    double arr[MAX];
    int len; // Contar cuantos elementos hay en la lista
};

// Inicializar los elementos de la lista
Lista crearLista(){
    Lista l;
    int i;
    for(i=0; i<MAX; i++){
        l->arr[i] = 0;
    }
    l->len = 0;
    return l;
}

static int esLleno(Lista l){
    /*if(l->len == MAX) return 1;
    else return 0;*/
    return l->len == MAX;
}

static int esVacia(Lista l){
    /*if(l->len == MAX) return 1;
    else return 0;*/
    return l->len == 0;
}

// Añade un nuevo valor a la lista
Lista insertar(Lista l, double num){
    if(esLleno(l) == 1){
        printf("\nLista Llena ...");
    } else{
        l->arr[l->len] = num;
        l->len++;
    }
    return l;
}

// Imprime los elementos de la Lista
void desplegar(Lista l){
    if(esVacia(l) == 1){
        printf("\nLista Vacía ...");
    } else{
        int i;
        for(i=0; i<l->len; i++){
            printf("%.2lf ", l->arr[i]);
        }
        printf("\n");
    }
}

// Retornar el número de elementos en la lista
int size(Lista l){
    return l->len;
}