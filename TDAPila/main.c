#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(int argc, char *argv[]) {
	Pila p = crearPila();
	printf("\n\nInsertando elementos ...");
	push(p, 6.7);
	push(p, 5.6);
	push(p, -3.2);
	push(p, 4.6);
	push(p, -6.1);
	push(p, 9.4);
	printf("\nPila 1: ");
	display(p);
	double primerElemento = peak(p);
	if(primerElemento == (double)INT_MIN) printf("\nPila Vacía ...");
	else printf("\nElemento en el tope: %.2lf", primerElemento);
	
	printf("\n\nRemoviendo elementos ...");
	pop(p);
	pop(p);
	printf("\nPila 1: ");
	display(p);
	primerElemento = peak(p);
	if(primerElemento == (double)INT_MIN) printf("\nPila Vacía ...");
	else printf("\nElemento en el tope: %.2lf", primerElemento);
	
	return 0;
}
