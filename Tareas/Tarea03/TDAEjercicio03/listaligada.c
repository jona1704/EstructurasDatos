//
// Created by Jonthan Cordoba on 26/11/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "listaligada.h"

Nodo * crearNodo(int x){
    Nodo * nuevo = NULL;
    nuevo = (Nodo *) malloc(sizeof(Nodo));
    if(nuevo == NULL) return NULL;
    nuevo->dato = x;
    nuevo->siguiente = NULL;

    return nuevo;
}

ListaLigada * listaLigada(){
    // Inicializamos la lista en NULL
    ListaLigada * lista = NULL;
    // Asignamos memoria para la lista
    lista = (ListaLigada *) malloc(sizeof(ListaLigada));
    if(lista == NULL) return NULL; // En caso de que no se le pueda asignar memoria
    lista->cabecera = NULL; // Asignamos valores

    return lista;
}

void insertar_inicio(ListaLigada * lista, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(lista->cabecera == NULL){
        lista->cabecera = nuevo;
    } else{
        nuevo->siguiente = lista->cabecera;
        lista->cabecera = nuevo;
    }
}

void insertar_final(ListaLigada * lista, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(lista->cabecera == NULL){
        lista->cabecera = nuevo;
    } else{
        Nodo * temp = lista->cabecera;
        while (temp->siguiente != NULL){
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

int no_nodos(ListaLigada * lista){
    if(lista->cabecera == 0){
        return 0;
    } else{
        Nodo * temp = lista->cabecera;
        int cont = 0;
        while(temp != NULL){
            temp = temp->siguiente;
            cont++;
        }
        return cont;
    }
}

void insertar_intermedio(ListaLigada * lista, int pos, int dato){
    Nodo * nuevo = crearNodo(dato);
    // Se toma el 0 como posición válida
    int noNodos = no_nodos(lista);
    if(pos<-1 || pos>noNodos+1){
        printf("Posición inválida\n");
        return;
    } else if(lista->cabecera == NULL) {
        lista->cabecera = nuevo;
    } else if(pos == 0){
        nuevo->siguiente = lista->cabecera;
        lista->cabecera = nuevo;
        return;
    } else{
        Nodo * temp = lista->cabecera;
        int i=0;
        while(i<pos-1){
            temp = temp->siguiente; // (pos-1)-th nodo
            i++;
        }
        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
    }
}

void borrar_inicio(ListaLigada * lista){
    if(lista->cabecera == NULL){
        printf("Lista Vacía!!\n");
    } else{
        Nodo * temp = lista->cabecera;
        lista->cabecera = lista->cabecera->siguiente;
        free(temp);
    }
}


void borrar_final(ListaLigada * lista) {
    Nodo *temp; // Nodo a borrar
    Nodo *prev; // Nodo previo al ultimo
    if (lista->cabecera == NULL) {
        printf("Lista Vacía!!\n");
    } else {
        temp = lista->cabecera;
        // Recorremos hasta el último nodo de la Lista
        while (temp->siguiente != NULL) {
            prev = temp;
            temp = temp->siguiente;
        }
        if (temp == lista->cabecera) {
            lista->cabecera = NULL;
        } else {
            /* Desconectar el enlace */
            prev->siguiente = NULL;
        }
        free(temp); // Borramos el ultimo
    }
}

void borrar_intermedio(ListaLigada * lista, int pos){
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
                temp = lista->cabecera;
                lista->cabecera = lista->cabecera->siguiente;
                free(temp);
                return;
            } else{
                int i=0;
                temp = lista->cabecera;
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

void desplegar(ListaLigada * lista){
    Nodo * temp = lista->cabecera;
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

void limpiarLista(ListaLigada * lista) {
    Nodo *actual = NULL;
    while (lista->cabecera != NULL) {
        actual = lista->cabecera;
        lista->cabecera = lista->cabecera->siguiente;
        free(actual);
    }
    free(lista);
}