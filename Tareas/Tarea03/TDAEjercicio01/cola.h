//
// Created by Jonthan Cordoba on 21/11/22.
//

#ifndef COLA_H
#define COLA_H
#define MAX_COLA 30

struct cola{
    float arr[MAX_COLA];
    int frente;
    int final;
    int len;
};

typedef struct cola Cola;

Cola crearCola();
Cola encolar(Cola c, float);
float desencolar(Cola c);
void display_cola(Cola c);
float frente(Cola c);
float final(Cola c);

#endif // COLA_H
