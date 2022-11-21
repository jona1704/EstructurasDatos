//
// Created by Jonthan Cordoba on 19/11/22.
//

#ifndef COLA_H
#define COLA_H
#define MAX 5

struct cola{
    int arr[MAX];
    int frente;
    int final;
};

typedef struct cola Cola;

Cola crearCola();
Cola encolar(Cola c, int dato);
Cola desencolar(Cola c);
void display(Cola c);
int frente(Cola c);
int final(Cola c);

#endif // COLA_H
