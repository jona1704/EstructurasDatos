#include "cola_circular.h"
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

static bool esVacia(ColaCircular c){
	if(c.frente == -1){
		return true;
	} else{
		return false;
	}
}

static bool esLlena(ColaCircular c){
	// c.frente == c.final+1 es equivalente a c.frente > c.final
	if((c.frente == 0) && (c.final == MAX-1) || (c.frente == c.final+1)) return true;
	else return false;
}

ColaCircular crearCola(){
	ColaCircular c = {{0},-1,-1,0};
	return c;
}

int frente(ColaCircular c){
	if(c.frente == -1) return INT_MIN;
	else return c.arr[c.frente];
}

int final(ColaCircular c){
	if(c.final == -1) return INT_MIN;
	else return c.arr[c.final];
}

void display(ColaCircular c){
	if(esVacia(c)){
		printf("\nCola Vacia ...");
	} else{
		// Necesitamos variables auxiliares
		int aux_frente = c.frente;
		int aux_final = c.final;
		int i;
		if(aux_frente <= aux_final){
			for(i=aux_frente; i<=aux_final; i++){
				printf("%d ", c.arr[i]);
			}
		} else{
			for(i=aux_frente; i<=MAX-1; i++){
				printf("%d ", c.arr[i]);
			}
			for(i=0; i<=aux_frente-1; i++){
				printf("%d ", c.arr[i]);
			}
		}
	}
}

ColaCircular encolar(ColaCircular c, int dato){
	if(esLlena(c)){
		printf("\nCola Llena ...");
	} else{
		if(esVacia(c)){
			c.frente = 0;
			c.final = 0;
		} else{
			if(c.final == MAX-1){
				// Reseteamos final cuando la cola no
				// esta llena ni vacia
				c.final = 0;
			} else{
				c.final++;
			}		
		}
		c.arr[c.final] = dato;
		c.len++;
	}
	return c;
}

ColaCircular desencolar(ColaCircular c){
	if(esVacia(c)){
		printf("\nCola Vacia ...");
	} else{
		// Esta condición solo sucede
		// cuando el ultimo elemento fue desencolado
		if(c.frente > c.final){
			c.frente = -1;
			c.final = -1;
			c.len = 0;
		} else{
			if(c.frente == MAX-1) c.frente = 0;
			c.frente++;
			c.len--;
		}
	}
	return c;
}

int len(ColaCircular c){
	return c.len;
}








