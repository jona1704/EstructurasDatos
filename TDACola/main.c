#include <stdio.h>
#include <limits.h>
#include "cola.h"

int main() {
	// Inicializando instancias de Cola
	Cola c1 = crearCola();
	Cola c2 = crearCola();
	
	// Valores en la Cola 1
	c1 = encolar(c1, 4);
	c1 = encolar(c1, 3);
	c1 = encolar(c1, 10);
	c1 = encolar(c1, 16);
	printf("\nElementos en Cola 1: \n");
	display(c1);
	if(frente(c1) != (double)INT_MIN){
		printf("\nElemento en el frente (cola 1): %.2lf", frente(c1));
	}
	if(final(c1) != (double)INT_MIN){
		printf("\nElemento en el final (cola 1): %.2lf", final(c1));
	}
	printf("\nNumero de Elementos en la cola 1: %d", len(c1));
	printf("\n\n");
	
	// Valores en la Cola 2
	c2 = encolar(c2, 3);
	c2 = encolar(c2, 9);
	c2 = encolar(c2, 6);
	c2 = encolar(c2, -14);
	c2 = encolar(c2, 8);
	printf("\nElementos en Cola 2: \n");
	display(c2);
	if(frente(c2) != (double)INT_MIN){
		printf("\nElemento en el frente (cola 2): %.2lf", frente(c2));
	}
	if(final(c2) != (double)INT_MIN){
		printf("\nElemento en el final (cola 2): %.2lf", final(c2));
	}
	printf("\nNumero de Elementos en la cola 2: %d", len(c2));
	printf("\n\n");
	
	// Removiendo valores de la Cola 1
	printf("\nRemoviendo elemento (Cola 1): %.2lf", frente(c1));
	c1 = desencolar(c1);
	printf("\nRemoviendo elemento (Cola 1): %.2lf", frente(c1));
	c1 = desencolar(c1);
	printf("\nElementos en Cola 1: \n");
	display(c1);
	if(frente(c1) != (double)INT_MIN){
		printf("\nElemento en el frente (cola 1): %.2lf", frente(c1));
	}
	if(final(c1) != (double)INT_MIN){
		printf("\nElemento en el final (cola 1): %.2lf", final(c1));
	}
	printf("\nNumero de Elementos en la cola 1: %d", len(c1));
	printf("\n\n");
	
	// Removiendo valores de la Cola 2
	printf("\nRemoviendo elemento (Cola 2): %.2lf", frente(c2));
	c2 = desencolar(c2);
	printf("\nRemoviendo elemento (Cola 2): %.2lf", frente(c2));
	c2 = desencolar(c2);
	printf("\nRemoviendo elemento (Cola 2): %.2lf", frente(c2));
	c2 = desencolar(c2);
	printf("\nElementos en Cola 2: \n");
	display(c2);
	if(frente(c2) != (double)INT_MIN){
		printf("\nElemento en el frente (cola 2): %.2lf", frente(c2));
	}
	if(final(c2) != (double)INT_MIN){
		printf("\nElemento en el final (cola 2): %.2lf", final(c2));
	}
	printf("\nNumero de Elementos en la cola 2: %d", len(c2));
	
	return 0;
}



