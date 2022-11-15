//
// Created by Jonthan Cordoba on 14/11/22.
//

#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

typedef struct nodo{
    int dato;
    struct nodo * siguiente;
} Nodo; // Definimos un tipo para la estructura

typedef struct lista{
    Nodo * cabecera;
} ListaCircular;

Nodo * crearNodo(int);
ListaCircular * listaCircular();
void insertar_inicio(ListaCircular *, int);
void insertar_final(ListaCircular *, int);
int no_nodos(ListaCircular *);
void insertar_intermedio(ListaCircular *, int, int);
void borrar_inicio(ListaCircular *);
void borrar_final(ListaCircular *);
void borrar_intermedio(ListaCircular *, int);
void desplegar(ListaCircular *);
void liberar(ListaCircular *);

#endif // LISTACIRCULAR_H
