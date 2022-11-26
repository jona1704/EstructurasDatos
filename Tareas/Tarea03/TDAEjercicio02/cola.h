//
// Created by Jonthan Cordoba on 25/11/22.
//

#ifndef COLA_H
#define COLA_H
#define MAX_COLA 30
#define DATASIZE 255

struct cola{
    char arr[MAX_COLA][DATASIZE];
    int frente;
    int final;
    int len;
};

typedef struct cola Cola;

Cola crearCola();
Cola encolar(Cola c, char[]);
char * desencolar(Cola c);
void display_cola(Cola c);
char * frente(Cola c);
char * final(Cola c);
int len_cola(Cola c);

#endif // COLA_H
