//
// Created by Jonthan Cordoba on 14/10/22.
//

#ifndef PILA_H
#define PILA_H

typedef struct pila * Pila;

Pila crearPila(unsigned);
void push(Pila, int);
int pop(Pila);

#endif // PILA_H
