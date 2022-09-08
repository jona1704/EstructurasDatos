//
// Created by Jonathan Córdoba on 08/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"
#define MAX 5

struct lista{
    int arr[MAX];
    int cont;
};

Lista init(){
    Lista l = malloc(sizeof(struct lista));
    if(l == NULL) exit(1);
    int i;
    for(i=0; i<MAX; i++){
        l->arr[i] = 0;
    }
    l->cont = 0;

    return l;
}

// Función que verifica que el número elemento en la
// lista no supere la capacidad máxima del arreglo
static bool esLlena(Lista l){
    if(l->cont == MAX) return true;
    else return false;
}

// Función que verifica si el número elemento en la
// lista es 0
static bool esVacia(Lista l){
    if(l->cont == 0) return true;
    else return false;
}

Lista insertar(Lista l, int pos, int valor){
    // Necesitamos validar que el contador sea menor a MAX
    // y que la posición esté entre 1 y len()
    // Si la lista está llena no se permite
    // insertar más elementos
    //if(esLlena(l) == false) --> Esta condición es válida también
    if(!esLlena(l)){
        //if (((pos-1)*(pos-len(l)) <= 0)) --> Esta condición es útil para validar que pos esté en un rango
        if (((1<=pos) && (pos<=len(l)+1))){
            int i;
            for(i=len(l)-1; i>=pos-1; i--){
                l->arr[i+1] = l->arr[i];
            }
            l->arr[pos-1] = valor;
            l->cont++;
        }

    }

    return l;
}

Lista borrar(Lista l, int pos){
    // Necesitamos validar que el contador sea mayor a 0
    // y que la posición esté entre 1 y len()
    // Si la lista está vacía no se permite
    // borrar más elementos
    if(!esVacia(l)){
        if((1<=pos) && (pos<=len(l)+1)){
            int i;
            for (i=pos-1; i<len(l); i++) {
                l->arr[i] = l->arr[i+1];
            }
            l->cont--;
        }
    }

    return l;
}

bool buscar(Lista l, int valor_buscado){
    // Aplicando el algoritmo de búsqueda Lineal
    int i;
    for(i=0; i< len(l); i++){
        if(l->arr[i] == valor_buscado){
            return true;
        }
    }
    return false;
}

Lista ordenar(Lista l){
    // Aplicando el algoritmo de la burbuja
    int i, j, temp;
    // Bucle externo cuenta el número de iteraciones
    for(i=0; i<len(l)-1; i++){
        // Bucle interno cuenta el número de pasos por iteración
        for(j=0; j<len(l)-i-1; j++){
            if(l->arr[j] > l->arr[j+1]){
                temp = l->arr[j];
                l->arr[j] = l->arr[j+1];
                l->arr[j+1] = temp;
            }
        }
    }

    return l;
}

void desplegar(Lista l){
    int i;
    for(i=0; i< len(l); i++){
        printf("%d ", l->arr[i]);
    }
    printf("\n");
}

int len(Lista l){
    return l->cont;
}

void destroy(Lista l){
    free(l);
}
