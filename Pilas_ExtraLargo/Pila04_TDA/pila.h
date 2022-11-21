//
// Created by Jonthan Cordoba on 04/11/22.
//

#ifndef PILA_H
#define PILA_H

#define MAX 5

struct pila{
    int array[MAX];
    int tope;
};

typedef struct pila Pila;

Pila * init();
void push(Pila *, int);
int pop(Pila *);
void desplegar(Pila *);
void limpiarPila(Pila *);

#endif // PILA_H
