#include "cola.h"
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

static bool esVacia(Cola c){
	if((c.frente<0) || (c.frente>c.final)){
		return true;
	} else{
		return false;
	}
}

static bool esLlena(Cola c){
	if(c.final == MAX-1) return true;
	else return false;
}

Cola crearCola(){
	Cola c = {{0},-1,-1,0};
	return c;
}

double frente(Cola c){
	if(c.frente == -1) return (double)INT_MIN;
	else return c.arr[c.frente];
}

double final(Cola c){
	if(c.final == -1) return (double)INT_MIN;
	else return c.arr[c.final];
}

void display(Cola c){
	if(esVacia(c)){
		printf("\nCola Vacia ...");
	} else{
		int i;
		for(i=c.frente; i<=c.final; i++){
			printf("%.2lf ", c.arr[i]);
		}
	}
}

Cola encolar(Cola c, double dato){
	if(esLlena(c)){
		printf("\nCola Llena ...");
	} else{
		if(esVacia(c)){
			c.frente = 0;
			c.final = 0;
		} else{
			c.final++;
		}
		c.arr[c.final] = dato;
		c.len++;
	}
	return c;
}

Cola desencolar(Cola c){
	if(esVacia(c)){
		printf("\nCola Vacia ...");
	} else{
		if(c.frente > c.final){
			c.frente = -1;
			c.final = -1;
			c.len = 0;
		} else{
			c.frente++;
			c.len--;
		}
	}
	return c;
}

int len(Cola c){
	return c.len;
}








