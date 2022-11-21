//
// Created by Jonthan Cordoba on 19/11/22.
//

#ifndef PILA_H
#define PILA_H
#define MAX 30


typedef struct pila * Pila;

Pila crearPila();
bool esVacia(Pila);
bool esLlena(Pila);
void push(Pila, char);
char pop(Pila);
void destroy(Pila);

#endif // PILA_H
