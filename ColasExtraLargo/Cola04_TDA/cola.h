//
// Created by Jonathan Cordoba on 24/09/22.
//

#ifndef COLA_H
#define COLA_H
#define MAX 5

typedef struct cola{
    int arr[MAX];
    int frente;
    int final;
    int len;
} Cola;

Cola crearCola();
Cola encolar(Cola c, int dato);
Cola desencolar(Cola c);
int frente(Cola c);
int final(Cola c);
int len(Cola c);
void desplegar(Cola c);



#endif // COLA_H
