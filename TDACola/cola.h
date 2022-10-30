#ifndef COLA_H_
#define COLA_H_

#define MAX 30

struct cola{
	double arr[MAX];
	int frente;
	int final;
	int len;
};

typedef struct cola Cola;

Cola crearCola();
Cola encolar(Cola, double);
Cola desencolar(Cola);
int len(Cola);
double frente(Cola);
double final(Cola);
void display(Cola);

#endif



