//
// Created by Jonthan Cordoba on 21/11/22.
//

#ifndef PILA_H
#define PILA_H
#define MAX_PILA 30
#include <stdbool.h>

struct pila{
    float arr[MAX_PILA];
    int tope;
};

typedef struct pila Pila;

Pila crearPila();
bool esVacia(Pila);
bool esLlena(Pila);
Pila push(Pila, float);
float pop(Pila);
void display_pila(Pila);
int len(Pila);

#endif // PILA_H
