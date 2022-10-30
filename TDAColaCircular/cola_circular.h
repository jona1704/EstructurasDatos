#ifndef COLA_CIRCULAR_H_
#define COLA_CIRCULAR_H_
#define MAX 5

struct cola_circular{
	int arr[MAX];
	int frente;
	int final;
	int len;
};

typedef struct cola_circular ColaCircular;

ColaCircular crearCola();
ColaCircular encolar(ColaCircular, int);
ColaCircular desencolar(ColaCircular);
int len(ColaCircular);
int frente(ColaCircular);
int final(ColaCircular);
void display(ColaCircular);

#endif
	
	
	
