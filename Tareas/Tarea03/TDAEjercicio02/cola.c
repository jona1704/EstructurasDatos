//
// Created by Jonthan Cordoba on 25/11/22.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "cola.h"

Cola crearCola(){
    Cola c;
    int i;
    for(i=0; i<MAX_COLA; i++){
        strcpy(c.arr[i], "\0");
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

Cola encolar(Cola c, char dato[]){
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
        strcpy(c.arr[c.final], dato);
        c.len++;
    }

    return c;
}

char * desencolar(Cola c){
    char valor_borrado[DATASIZE];
    if(esVacia(c)){
        //printf("\nCola Vacia ...");
        strcpy(valor_borrado, "\0");
    } else{
        if(c.frente > c.final){
            // Esta condición solo se da cuando
            // removemos el último elemento
            // existente en la Col
            c.frente = -1;
            c.final = -1;
            strcpy(valor_borrado, "\0");
            c.len=0;
        } else{
            c.frente++;
            c.len++;
        }
       strcpy(valor_borrado, c.arr[c.frente]);
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
            if(i == c.final) printf("%s", c.arr[i]);
            else printf("%s, ", c.arr[i]);
        }
        printf(" ]\n");
    }
}

char * frente(Cola c){
    return c.arr[c.frente];
}

char * final(Cola c){
    return c.arr[c.final];
}

int len_cola(Cola c){
    return c.len;
}

