#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo * siguiente;
} Nodo; // Definimos un tipo para la estructura

Nodo * crearNodo(int x){
    Nodo * nuevo = NULL;
    nuevo = (Nodo *) malloc(sizeof(Nodo));
    if(nuevo == NULL) return NULL;
    nuevo->dato = x;
    nuevo->siguiente = NULL;

    return nuevo;
}

void insertar_inicio(Nodo ** cabecera, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(*cabecera == NULL){
        *cabecera = nuevo;
    } else{
        nuevo->siguiente = *cabecera;
        *cabecera = nuevo;
    }
}

void insertar_final(Nodo ** cabecera, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(*cabecera == NULL){
        *cabecera = nuevo;
    } else{
        Nodo * temp = *cabecera;
        while (temp->siguiente != NULL){
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

int no_nodos(Nodo ** cabecera){
    if(*cabecera == NULL){
        return 0;
    } else{
        Nodo * temp = *cabecera;
        int cont = 0;
        while(temp != NULL){
            temp = temp->siguiente;
            cont++;
        }
        return cont;
    }
}

void insertar_intermedio(Nodo ** cabecera, int pos, int dato){
    Nodo * nuevo = crearNodo(dato);
    // Se toma el 0 como posición válida
    int noNodos = no_nodos(cabecera);
    if(pos<-1 || pos>noNodos+1){
        printf("Posición inválida\n");
    } else if(cabecera == NULL) {
        *cabecera = nuevo;
    } else if(pos == 0){
        nuevo->siguiente = *cabecera;
        *cabecera = nuevo;
    } else{
        Nodo * temp = *cabecera;
        int i=0;
        while(i<pos-1){
            temp = temp->siguiente; // (pos-1)-th nodo
            i++;
        }
        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
    }
}

void borrar_inicio(Nodo ** cabecera){
    if(*cabecera == NULL){
        printf("Lista Vacía!!\n");
    } else{
        Nodo * temp = *cabecera;
        *cabecera = (*cabecera)->siguiente;
        free(temp);
    }
}

void borrar_final(Nodo ** cabecera) {
    Nodo *temp; // Nodo a borrar
    Nodo *prev; // Nodo previo al ultimo
    if (*cabecera == NULL) {
        printf("Lista Vacía!!\n");
    } else {
        temp = *cabecera;
        // Recorremos hasta el último nodo de la Lista
        while (temp->siguiente != NULL) {
            prev = temp;
            temp = temp->siguiente;
        }
        if (temp == *cabecera) {
            *cabecera = NULL;
        } else {
            /* Desconectar el enlace */
            prev->siguiente = NULL;
        }
        free(temp); // Borramos el ultimo
    }
}

void borrar_intermedio(Nodo ** cabecera, int pos){
    if(*cabecera == NULL) {
        printf("Lista Vacía!!\n");
    } else {
        // Se toma el 0 como posición válida
        int noNodos = no_nodos(cabecera);
        if(pos<-1 || pos>noNodos){
            printf("Posición inválida\n");
        } else {
            Nodo * temp = NULL;
            if(pos == 0){
                temp = *cabecera;
                *cabecera = (*cabecera)->siguiente;
                free(temp);
            } else{
                int i=0;
                temp = *cabecera;
                while(i<pos-1){
                    temp = temp->siguiente; // (pos-1)-th nodo
                    i++;
                }
                Nodo * borrado = temp->siguiente; // (pos)-th nodo
                temp->siguiente = borrado->siguiente; // (pos+1)-th nodo
                free(borrado);
            }
        }
    }
}

void desplegar(Nodo * cabecera){
    Nodo * temp = cabecera;
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

void limpiarLista(Nodo * cabecera) {
    Nodo *actual = NULL;
    while (cabecera != NULL) {
        actual = cabecera;
        cabecera = cabecera->siguiente;
        free(actual);
    }
}

int main() {
    // Declaramos múltiples instancias de lista
    Nodo * cabecera01 = NULL;
    // Insertamos datos en la lista 1
    insertar_inicio(&cabecera01, 3);
    insertar_inicio(&cabecera01, 5);
    insertar_inicio(&cabecera01, 4);
    insertar_inicio(&cabecera01, 23);
    insertar_inicio(&cabecera01, 18);
    desplegar(cabecera01);
    insertar_final(&cabecera01, 18);
    insertar_final(&cabecera01, 23);
    insertar_final(&cabecera01, 4);
    insertar_final(&cabecera01, 23);
    insertar_final(&cabecera01, 3);
    desplegar(cabecera01);
    insertar_intermedio(&cabecera01, 0, 29);
    insertar_intermedio(&cabecera01, 11, 29);
    insertar_intermedio(&cabecera01, 6, 29);
    desplegar(cabecera01);
    borrar_inicio(&cabecera01);
    borrar_inicio(&cabecera01);
    borrar_inicio(&cabecera01);
    desplegar(cabecera01);
    borrar_final(&cabecera01);
    borrar_final(&cabecera01);
    borrar_final(&cabecera01);
    desplegar(cabecera01);
    borrar_intermedio(&cabecera01, 1);
    borrar_intermedio(&cabecera01, 5);
    borrar_intermedio(&cabecera01, 2);
    desplegar(cabecera01);

    limpiarLista(cabecera01);

    return 0;
}
