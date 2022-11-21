//
// Created by Jonthan Cordoba on 04/11/22.
//

#ifndef PILA_H
#define PILA_H

#define MAX 5

typedef struct pila * Pila; // Apuntador a tipo oculto

Pila init();
void push(Pila, int);
void ingresar(Pila p, int dato);
int pop(Pila);
void desplegar(Pila);
void limpiarPila(Pila);

#endif // PILA_H

