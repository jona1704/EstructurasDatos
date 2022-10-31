// Implementacion
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Nodo * crearNodo(int dato){
	Nodo * n = (Nodo *) malloc(sizeof(Nodo));
	assert(n != NULL);
	n->dato = dato;
	n->siguiente = NULL;
	return n;
}

// Las listas ligadas se leen desde la cabecera
Nodo * insertar_inicio(Nodo * cabecera, int dato){
	Nodo * nuevo = crearNodo(dato);
	// Validar que la lista este vacia
	if(cabecera == NULL){
		cabecera = nuevo;
	} else{
		nuevo->siguiente = cabecera;
		cabecera = nuevo;
	}
	return cabecera;
}

// Recorrer la lista
void desplegar(Nodo * cabecera){
	Nodo * temp = cabecera;
	while(temp != NULL){
		printf("%d ", temp->dato);
		temp = temp->siguiente;
	}
}

void destruir(Nodo * nodo){
	free(nodo);
}
