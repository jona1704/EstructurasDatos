#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct nodo{
    int dato;
    struct nodo * siguiente;
} Nodo; // Definimos un tipo para la estructura

typedef struct pila{
    Nodo * tope;
} Pila;

Nodo * crearNodo(int x){
    Nodo * nuevo = NULL;
    nuevo = (Nodo *) malloc(sizeof(Nodo));
    if(nuevo == NULL) return NULL;
    nuevo->dato = x;
    nuevo->siguiente = NULL;

    return nuevo;
}

Pila * crearPila(){
    // Inicializamos la lista en NULL
    Pila * p = NULL;
    // Asignamos memoria para la lista
    p = (Pila *) malloc(sizeof(Pila));
    if(p == NULL) return NULL; // En caso de que no se le pueda asignar memoria
    p->tope = NULL; // Asignamos valores

    return p;
}

void push(Pila * p, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(p->tope == NULL){
        p->tope = nuevo;
    } else{
        nuevo->siguiente = p->tope;
        p->tope = nuevo;
    }
}

void pop(Pila *p){
    if(p->tope == NULL){
        printf("Lista Vacía!!\n");
    } else{
        Nodo * temp = p->tope;
        p->tope = p->tope->siguiente;
        free(temp);
    }
}

int obtenerTope(Pila *p){
    if(p->tope == NULL) return INT_MIN;
    return p->tope->dato;
}

void desplegar(Pila * p){
    Nodo * temp = p->tope;
    if(temp == NULL){
        printf("Lista Vacía!!\n");
        return;
    }
    while (temp != NULL){
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

int main() {
    // Declaramos múltiples instancias de lista
    Pila * p1 = crearPila();
    // Insertamos datos en la lista 1
    push(p1, 3);
    push(p1, 5);
    push(p1, 4);
    push(p1, 23);
    push(p1, 18);
    desplegar(p1);
    printf("\nTope()=%d", obtenerTope(p1));
    pop(p1);
    pop(p1);
    printf("\nTope()=%d", obtenerTope(p1));

    return 0;
}
