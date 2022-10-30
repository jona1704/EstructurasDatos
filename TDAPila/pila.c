#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "pila.h"

Pila crearPila(){
	Pila p = {{0.0},-1};
	return p;
}

static bool esVacia(Pila * p){
	return p->tope == -1;
}

static bool esLlena(Pila * p){
	return p->tope == MAX-1;
}

void push_(Pila * p, double dato){
	if(esLlena(p)){
		printf("\nPila Llena ...");
	} else{
		p->tope++;
		p->arr[p->tope] = dato;
	}
}

double pop_(Pila * p){
	int valor_borrado;
	if(esVacia(p)){
		printf("nPila Vacia ...");
		valor_borrado = (double)INT_MIN;
	} else{
		valor_borrado = p->arr[p->tope];
		p->tope--;
	}
	return valor_borrado;
}

double peak(Pila p){
	if(esVacia(&p)) return (double) INT_MIN;
	else return p.arr[p.tope];
	
}

void display(Pila p){
	if(esVacia(&p)){
		printf("nPila Vacia ...");
	} else{
		int i;
		for(i=p.tope; i>=0; i--){
			printf("%.2lf ", p.arr[i]);
		}
	}
}
