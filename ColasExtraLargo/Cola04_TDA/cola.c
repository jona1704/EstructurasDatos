//
// Created by Jonthan Cordoba on 24/09/22.
//

#include "cola.h"
#include <stdio.h>
#include <stdbool.h>

Cola crearCola(){
    Cola c;
    int i;
    for(i=0; i<MAX; i++){
        c.arr[i] = 0;
    }
    c.frente = -1;
    c.final = -1;
    c.len = 0;

    return c;
}

static bool esLlena(Cola c){
    if(c.final == MAX-1) return true;
    else return false;
}

static bool esVacia(Cola c){
    if((c.frente<0) || (c.frente>c.final))
        return true;
    else return false;
}

Cola encolar(Cola c, int dato){
    if(esLlena(c)){
        printf("\nCola Llena ...");
    } else{
        if(esVacia(c)){
            // Esta condición solo se da cuando
            // ingresamos el primer elemento
            c.frente = 0;
            c.final = 0;
        } else{
            c.final++;
        }
        c.arr[c.final] = dato;
        c.len++;
    }

    return c;
}

Cola desencolar(Cola c){
    if(esVacia(c)){
        printf("\nCola Vacia ...");
    } else{
        if(c.frente > c.final){
            // Esta condición solo se da cuando
            // removemos el último elemento
            // existente en la Col
            c.frente = -1;
            c.final = -1;
        } else{
            c.frente++;
        }
        c.len--;
    }

    return c;
}

void desplegar(Cola c){
    if(esVacia(c)){
        printf("\nCola Vacia ...");
    } else{
        int i;
        printf("[ ");
        for(i=c.frente; i<=c.final; i++){
            if(i == c.final) printf("%d", c.arr[i]);
            else printf("%d, ", c.arr[i]);
        }
        printf(" ]\n");
    }
}

int frente(Cola c){
    return c.arr[c.frente];
}

int final(Cola c){
    return c.arr[c.final];
}

int len(Cola c){
    return c.len;
}

