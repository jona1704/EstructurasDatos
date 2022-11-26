//
// Created by Jonthan Cordoba on 24/09/22.
//

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "cola.h"

Cola crearCola(){
    Cola c;
    int i;
    for(i=0; i<MAX_COLA; i++){
        c.arr[i] = 0;
    }
    c.frente = -1;
    c.final = -1;
    c.len = 0;

    return c;
}

static bool esLlena(Cola c){
    if(c.final == MAX_COLA-1) return true;
    else return false;
}

static bool esVacia(Cola c){
    if((c.frente<0) || (c.frente>c.final))
        return true;
    else return false;
}

Cola encolar(Cola c, float dato){
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

float desencolar(Cola c){
    float valor_borrado;
    if(esVacia(c)){
        //printf("\nCola Vacia ...");
        valor_borrado = (float) INT_MIN;
    } else{
        if(c.frente > c.final){
            // Esta condición solo se da cuando
            // removemos el último elemento
            // existente en la Col
            c.frente = -1;
            c.final = -1;
            valor_borrado = (float) INT_MIN;
            c.len=0;
        } else{
            c.frente++;
            c.len++;
        }
        valor_borrado = c.arr[c.frente];
    }

    return valor_borrado;
}

void display_cola(Cola c){
    if(esVacia(c)){
        printf("\nCola Vacia ...");
    } else{
        int i;
        printf("[ ");
        for(i=c.frente; i<=c.final; i++){
            if(i == c.final) printf("%.2f", c.arr[i]);
            else printf("%.2f, ", c.arr[i]);
        }
        printf(" ]\n");
    }
}

float frente(Cola c){
    return c.arr[c.frente];
}

float final(Cola c){
    return c.arr[c.final];
}


