#ifndef _PILA_H
#define _PILA_H
#define MAX 30
#define push(p,d)\
			push_(&p,d)
#define pop(p)\
			pop_(&p)

struct pila{
	double arr[MAX];
	int tope;
};

typedef struct pila Pila;

Pila crearPila();
void push_(Pila *, double);
double pop_(Pila *);
double peak(Pila);
void display(Pila);

#endif
