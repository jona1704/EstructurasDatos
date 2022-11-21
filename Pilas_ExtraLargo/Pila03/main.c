// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 5

struct pila{
    int array[MAX];
    int tope;
};

typedef struct pila Pila;

Pila * init(){
    Pila * p = (Pila *) malloc(sizeof(Pila));
    assert(p);
    int i;
    for(i=0; i<MAX; i++){
        p->array[i] = 0;
    }
    p->tope = -1;
    return p;
}

// Operaciones de Pila
Pila * push(Pila * p , int dato){
    if(p->tope == MAX-1){
        printf("\nPila esta Llena\n");
    } else{
        p->tope++;
        p->array[p->tope] = dato;
    }
    return p;
}

Pila * pop(Pila * p){
    if(p->tope == -1){
        printf("\nPila esta Vacia\n");
    } else{
        p->tope--;
    }
    return p;
}

void desplegar(Pila * p){
    if(p->tope == -1){
        printf("\nPila esta Vacia\n");
    } else{
        int i;
        for(i=p->tope; i>=0; i--){
            printf("%d ", p->array[i]);
        }
        printf("\n");
    }
}

void limpiarPila(Pila * p){
    free(p);
}

int main(){
    // Inicializar Pila
    Pila * p1 = init();
    // Insertar datos
    p1 =push(p1, 6);
    p1 =push(p1, 7);
    p1 =push(p1, 8);
    p1 =push(p1, 9);
    p1 =push(p1, 10);
    p1 =push(p1, 11);
    desplegar(p1);
    p1 =pop(p1);
    p1 =pop(p1);
    p1 =pop(p1);
    desplegar(p1);

    limpiarPila(p1);

    return 0;
}

