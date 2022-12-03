#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo * siguiente;
} Nodo; // Definimos un tipo para la estructura

typedef struct cola{
    Nodo * frente;
    Nodo * final;
    int contador;
} Cola;

Nodo * crearNodo(int x){
    Nodo * nuevo = NULL;
    nuevo = (Nodo *) malloc(sizeof(Nodo));
    if(nuevo == NULL) return NULL;
    nuevo->dato = x;
    nuevo->siguiente = NULL;

    return nuevo;
}

Cola * crearCola(){
    // Inicializamos la lista en NULL
    Cola * cola = NULL;
    // Asignamos memoria para la lista
    cola = (Cola *) malloc(sizeof(Cola));
    if(cola == NULL) return NULL; // En caso de que no se le pueda asignar memoria
    cola->frente = NULL; // Asignamos valores
    cola->final = NULL;
    cola->contador = 0;

    return cola;
}

void encolar(Cola * cola, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(cola->frente == NULL){
        cola->frente = nuevo;
        cola->final = nuevo;
    } else{
        // Al tener un apuntador al ultimo nodo no
        // requerimos recorrer la lista
        cola->final->siguiente = nuevo;
        cola->final = nuevo;
    }
    cola->contador++;
}

void desencolar(Cola * cola){
    if(cola->frente == NULL){
        printf("Cola Vacia!!\n");
    } else{
        Nodo * temp = cola->frente;
        cola->frente = cola->frente->siguiente;
        cola->contador--;
        free(temp);
    }
}

int obtenerFrente(Cola * cola){
	return cola->frente->dato;
}

int obtenerFinal(Cola * cola){
	return cola->final->dato;
}


void desplegar(Cola * cola){
    Nodo * temp = cola->frente;
    if(temp == NULL){
        printf("Lista Vacia!!\n");
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
    Cola * p1 = crearCola();
    // Insertamos datos en la lista 1
    encolar(p1, 3);
    encolar(p1, 5);
    encolar(p1, 4);
    encolar(p1, 23);
    encolar(p1, 18);
    desplegar(p1);
    printf("\nFrente()=%d", obtenerFrente(p1));
    printf("\nFinal()=%d", obtenerFinal(p1));
    desencolar(p1);
    desencolar(p1);
    printf("\nFrente()=%d", obtenerFrente(p1));
    printf("\nFinal()=%d", obtenerFinal(p1));

    return 0;
}
