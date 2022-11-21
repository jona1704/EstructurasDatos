#include <stdio.h>
#include <limits.h>
#include "cola_circular.h"

int main() {
	// Inicializando instancias de Cola
	ColaCircular c1 = crearCola();
	
	// Valores en la Cola 1
	// Insertando valores
	c1 = encolar(c1, 4);
	c1 = encolar(c1, 3);
	c1 = encolar(c1, 10);
	c1 = encolar(c1, 16);
	c1 = encolar(c1, 25);
	printf("\nInsertando Elementos ...");
	printf("\nElementos en Cola 1: \n");
	display(c1);
	if(frente(c1) != INT_MIN){
		printf("\nElemento en el frente (cola 1): %d", frente(c1));
	}
	if(final(c1) != INT_MIN){
		printf("\nElemento en el final (cola 1): %d", final(c1));
	}
	printf("\nNumero de Elementos en la cola 1: %d\n", len(c1));
	
	// Borrando valores
	c1 = desencolar(c1);
	printf("\nBorrando Elementos ...");
	printf("\nElementos en Cola 1: \n");
	display(c1);
	if(frente(c1) != INT_MIN){
		printf("\nElemento en el frente (cola 1): %d", frente(c1));
	}
	if(final(c1) != INT_MIN){
		printf("\nElemento en el final (cola 1): %d", final(c1));
	}
	printf("\nNumero de Elementos en la cola 1: %d\n", len(c1));
	
	printf("\n\nInsertando nuevamente Elementos ...");
	c1 = encolar(c1, 27);
	printf("\nElementos en Cola 1: \n");
	display(c1);
	if(frente(c1) != INT_MIN){
		printf("\nElemento en el frente (cola 1): %d", frente(c1));
	}
	if(final(c1) != INT_MIN){
		printf("\nElemento en el final (cola 1): %d", final(c1));
	}
	printf("\nNumero de Elementos en la cola 1: %d\n", len(c1));
	
	printf("\n\n");
	
	return 0;
}



