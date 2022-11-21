// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define MAX 5
#define push(p, d)\
            push_(&p, d)
#define pop(p)\
            pop_(&p)

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
void push_(Pila ** p , int dato){
    if((*p)->tope == MAX-1){
        printf("\nPila esta Llena\n");
    } else{
        (*p)->tope++;
        (*p)->array[(*p)->tope] = dato;
    }
}

int pop_(Pila ** p){
    int valor;
    if((*p)->tope == -1){
        printf("\nPila esta Vacia\n");
        valor = INT_MIN;
    } else{
        valor = (*p)->array[(*p)->tope];
        (*p)->tope--;
    }
    return valor;
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
    push(p1, 6);
    push(p1, 7);
    push(p1, 8);
    push(p1, 9);
    push(p1, 10);
    push(p1, 11);
    desplegar(p1);
    pop(p1);
    pop(p1);
    pop(p1);
    desplegar(p1);

    limpiarPila(p1);

    return 0;
}
