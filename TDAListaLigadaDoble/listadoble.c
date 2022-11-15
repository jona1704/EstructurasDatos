//
// Created by Jonathan Córdoba on 14/11/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "listadoble.h"

Nodo * crearNodo(int x){
    Nodo * nuevo = NULL;
    nuevo = (Nodo *) malloc(sizeof(Nodo));
    if(nuevo == NULL) return NULL;
    nuevo->dato = x;
    nuevo->siguiente = NULL;
    nuevo->previo = NULL;

    return nuevo;
}

ListaDoble * listaDoble(){
    // Inicializamos la lista en NULL
    ListaDoble * lista = NULL;
    // Asignamos memoria para la lista
    lista = (ListaDoble *) malloc(sizeof(ListaDoble));
    if(lista == NULL) return NULL; // En caso de que no se le pueda asignar memoria
    lista->cabecera = NULL; // Asignamos valores

    return lista;
}

void insertar_inicio(ListaDoble * lista, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(lista->cabecera == NULL){
        lista->cabecera = nuevo;
    } else{
        lista->cabecera->previo = nuevo;
        nuevo->siguiente = lista->cabecera;
        lista->cabecera = nuevo;
    }
}

void insertar_final(ListaDoble * lista, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(lista->cabecera == NULL){
        lista->cabecera = nuevo;
    } else{
        Nodo * temp = lista->cabecera;
        while (temp->siguiente != NULL){
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
        nuevo->previo = temp;
    }
}

int no_nodos(ListaDoble * lista){
    if(lista->cabecera == NULL){
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

void insertar_intermedio(ListaDoble * lista, int pos, int dato){
    // Se toma el 0 como posición válida
    int noNodos = no_nodos(lista);
    if(pos<-1 || pos>noNodos){
        printf("Posición inválida\n");
        return;
    } else {
        Nodo * nuevo = crearNodo(dato);
        Nodo * temp = lista->cabecera;
        if(lista->cabecera == NULL) {
            lista->cabecera = nuevo;
        } else if(pos == 0){
            nuevo->siguiente = lista->cabecera;
            lista->cabecera->previo = nuevo;
            lista->cabecera = nuevo;
        } else if(pos == noNodos){
            while(temp->siguiente != NULL){
                temp = temp->siguiente;
            }
            nuevo->previo = temp;
            temp->siguiente = nuevo;
        } else{
            int i=0;
            while(i<pos-1){
                temp = temp->siguiente; // (pos-1)-th nodo
                i++;
            }
            nuevo->previo = temp;
            nuevo->siguiente = temp->siguiente;
            temp->siguiente->previo = nuevo;
            temp->siguiente = nuevo;
        }
    }
}

void borrar_inicio(ListaDoble * lista){
    if(lista->cabecera == NULL){
        printf("Lista Vacía!!\n");
    } else{
        Nodo * temp = lista->cabecera;
        if(temp->siguiente == NULL){
            lista->cabecera = NULL;
        } else{
            lista->cabecera = lista->cabecera->siguiente;
            lista->cabecera->previo = NULL;
        }
        free(temp);
    }
}


void borrar_final(ListaDoble * lista) {
    Nodo *temp; // Nodo a borrar
    if (lista->cabecera == NULL) {
        printf("Lista Vacía!!\n");
    } else {
        temp = lista->cabecera;
        // Recorremos hasta el último nodo de la Lista
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        if (temp == lista->cabecera) {
            lista->cabecera = NULL;
        } else {
            /* Desconectar el enlace */
            temp->previo->siguiente = NULL;
        }
        free(temp); // Borramos el último
    }
}

void borrar_intermedio(ListaDoble * lista, int pos){
    if(lista->cabecera == NULL) {
        printf("Lista Vacía!!\n");
    } else {
        // Se toma el 0 como posición válida
        int noNodos = no_nodos(lista);
        if(pos<-1 || pos>=noNodos){
            printf("Posición inválida\n");
            return;
        } else {
            Nodo * temp = NULL;
            if(pos == 0){
                temp = lista->cabecera;
                if(temp->siguiente == NULL){
                    lista->cabecera = NULL;
                } else{
                    lista->cabecera = lista->cabecera->siguiente;
                    lista->cabecera->previo = NULL;
                }
                free(temp);
            } else{
                int i=0;
                temp = lista->cabecera;
                while(i<pos-1){
                    temp = temp->siguiente; // (pos-1)-th nodo
                    i++;
                }
                Nodo * borrado = temp->siguiente; // (pos)-th nodo
                if(borrado->siguiente == NULL){
                    borrado->previo->siguiente = NULL;
                } else{
                    temp->siguiente = borrado->siguiente; // (pos+1)-th nodo
                    borrado->siguiente->previo = temp;
                }
                free(borrado);
            }
        }
    }
}

void desplegar_adelante(ListaDoble * lista){
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

void desplegar_atras(ListaDoble * lista){
    Nodo * temp = lista->cabecera;
    if(temp == NULL){
        printf("Lista Vacía!!\n");
        return;
    }
    // Ir al ultimo nodo
    while(temp->siguiente != NULL){
        temp = temp->siguiente;
    }
    while (temp != NULL){
        printf("%d ", temp->dato);
        temp = temp->previo;
    }
    printf("\n");
}

void limpiarLista(ListaDoble * lista) {
    Nodo * actual = NULL;
    int noNodos = no_nodos(lista);
    int i=0;
    while (i<noNodos) {
        actual = lista->cabecera;
        lista->cabecera = lista->cabecera->siguiente;
        free(actual);
        i++;
    }
    free(lista);
}
