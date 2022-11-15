//
// Created by Jonathan Córdoba on 14/11/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "listacircular.h"

Nodo * crearNodo(int x){
    Nodo * nuevo = NULL;
    nuevo = (Nodo *) malloc(sizeof(Nodo));
    if(nuevo == NULL) return NULL;
    nuevo->dato = x;
    nuevo->siguiente = NULL;

    return nuevo;
}

ListaCircular * listaCircular(){
    // Inicializamos la lista en NULL
    ListaCircular * lista = NULL;
    // Asignamos memoria para la lista
    lista = (ListaCircular *) malloc(sizeof(ListaCircular));
    if(lista == NULL) return NULL; // En caso de que no se le pueda asignar memoria
    lista->cabecera = NULL; // Asignamos valores

    return lista;
}

void insertar_inicio(ListaCircular * lista, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(lista->cabecera == NULL){
        nuevo->siguiente = nuevo;
        lista->cabecera = nuevo;
    } else{
        // Recorriendo la lista hasta el final
        Nodo * temp = lista->cabecera;
        while (temp->siguiente != lista->cabecera) {
            temp = temp->siguiente;
        };
        nuevo->siguiente = lista->cabecera;
        temp->siguiente = nuevo;
        lista->cabecera = nuevo;
    }
}

void insertar_final(ListaCircular * lista, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(lista->cabecera == NULL){
        nuevo->siguiente = nuevo;
        lista->cabecera = nuevo;
    } else{
        // Recorriendo la lista hasta el final
        Nodo * temp = lista->cabecera;
        while (temp->siguiente != lista->cabecera) {
            temp = temp->siguiente;
        };
        temp->siguiente = nuevo;
        nuevo->siguiente = lista->cabecera;
    }
}

int no_nodos(ListaCircular * lista){
    if(lista->cabecera == NULL){
        return 0;
    } else{
        Nodo * temp = lista->cabecera;
        int cont = 0;
        do {
            temp = temp->siguiente;
            cont++;
        } while(temp != lista->cabecera);
        return cont;
    }
}

void insertar_intermedio(ListaCircular * lista, int pos, int dato){
    Nodo * nuevo = crearNodo(dato);
    // Se toma el 0 como posición válida
    int noNodos = no_nodos(lista);
    if(pos<-1 || pos>noNodos){
        printf("Posición inválida\n");
        return;
    } else if(lista->cabecera == NULL) {
        nuevo->siguiente = nuevo;
        lista->cabecera = nuevo;
    } else if(pos == 0){
        // Recorriendo la lista hasta el final
        Nodo * temp = lista->cabecera;
        while (temp->siguiente != lista->cabecera) {
            temp = temp->siguiente;
        };
        nuevo->siguiente = lista->cabecera;
        temp->siguiente = nuevo;
        lista->cabecera = nuevo;
    } else{
        Nodo * temp = lista->cabecera;
        int i=0;
        while(i<pos-1){
            temp = temp->siguiente; // (pos-1)-th nodo
            i++;
        }
        if(temp->siguiente == lista->cabecera){
            temp->siguiente = nuevo;
            nuevo->siguiente = lista->cabecera;
        } else{
            nuevo->siguiente = temp->siguiente;
            temp->siguiente = nuevo;
        }

    }
}

void borrar_inicio(ListaCircular * lista){
    if(lista->cabecera == NULL){
        printf("Lista Vacía!!\n");
    } else{
        // Recorriendo la lista hasta el final
        Nodo * ultimo = lista->cabecera;
        Nodo * temp = lista->cabecera;
        while(temp->siguiente != lista->cabecera){
            temp = temp->siguiente;
        }
        if (temp == lista->cabecera) {
            lista->cabecera = NULL;
        } else{
            temp->siguiente = lista->cabecera->siguiente;
            lista->cabecera = lista->cabecera->siguiente;
        }

        free(ultimo);
    }
}

void borrar_final(ListaCircular * lista) {
    Nodo *temp; // Nodo a borrar
    Nodo *prev; // Nodo previo al ultimo
    if (lista->cabecera == NULL) {
        printf("Lista Vacía!!\n");
    } else {
        temp = lista->cabecera;
        // Recorremos hasta el último nodo de la Lista
        while (temp->siguiente != lista->cabecera) {
            prev = temp;
            temp = temp->siguiente;
        }
        if (temp == lista->cabecera) {
            lista->cabecera = NULL;
        } else {
            /* Desconectar el enlace */
            prev->siguiente = lista->cabecera;
        }
        free(temp); // Borramos el último
    }
}

void borrar_intermedio(ListaCircular * lista, int pos){
    if(lista->cabecera == NULL) {
        printf("Lista Vacía!!\n");
    } else {
        // Se toma el 0 como posición válida
        int noNodos = no_nodos(lista);
        if(pos<-1 || pos>noNodos){
            printf("Posición inválida\n");
            return;
        } else {
            Nodo * temp = NULL;
            if(pos == 0){
                // Recorriendo la lista hasta el final
                Nodo * ultimo = lista->cabecera;
                Nodo * temp = lista->cabecera;
                while(temp->siguiente != lista->cabecera){
                    temp = temp->siguiente;
                }
                if (temp == lista->cabecera) {
                    lista->cabecera = NULL;
                } else{
                    temp->siguiente = lista->cabecera->siguiente;
                    lista->cabecera = lista->cabecera->siguiente;
                }
                free(ultimo);
            } else{
                int i=0;
                temp = lista->cabecera;
                while(i<pos-1){
                    temp = temp->siguiente; // (pos-1)-th nodo
                    i++;
                }
                if(temp->siguiente == lista->cabecera){
                    free(temp);
                    lista->cabecera = NULL;
                } else{
                    Nodo * borrado = temp->siguiente; // (pos)-th nodo
                    temp->siguiente = borrado->siguiente; // (pos+1)-th nodo
                    free(borrado);
                }
            }
        }
    }
}

void desplegar(ListaCircular * lista){
    Nodo * temp = lista->cabecera;
    if(temp == NULL){
        printf("Lista Vacía!!\n");
        return;
    }
    int i=0;
    do{
        printf("%d ", temp->dato);
        temp = temp->siguiente;
        i++;
    } while (temp != lista->cabecera);
    printf("\n");
}

void liberar(ListaCircular * lista) {
    Nodo * actual = NULL;
    int noNodos = no_nodos(lista);
    int i=0;
    while(i<noNodos){
        actual = lista->cabecera;
        lista->cabecera = lista->cabecera->siguiente;
        free(actual);
        i++;
    }
    free(lista);
}