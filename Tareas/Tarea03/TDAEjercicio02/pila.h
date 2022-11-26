//
// Created by Jonthan Cordoba on 25/11/22.
//

#ifndef PILA_H
#define PILA_H
#define MAX_PILA 30
#define DATASIZE 255
#include <stdbool.h>

struct pila{
    char arr[MAX_PILA][DATASIZE];
    int tope;
};

typedef struct pila Pila;

Pila crearPila();
bool esVacia(Pila);
bool esLlena(Pila);
void push(Pila *, char[]);
char * pop(Pila *);
void display_pila(Pila);
int len(Pila);

#endif // PILA_H
