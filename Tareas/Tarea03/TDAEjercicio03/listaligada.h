//
// Created by Jonthan Cordoba on 26/11/22.
//

#ifndef LISTALIGADA_H
#define LISTALIGADA_H

typedef struct nodo{
    int dato;
    struct nodo * siguiente;
} Nodo; // Definimos un tipo para la estructura

typedef struct lista{
    Nodo * cabecera;
} ListaLigada;

Nodo * crearNodo(int);
ListaLigada * listaLigada();
void insertar_inicio(ListaLigada *, int);
void insertar_final(ListaLigada *, int);
int no_nodos(ListaLigada *);
void insertar_intermedio(ListaLigada *, int, int);
void borrar_inicio(ListaLigada *);
void borrar_final(ListaLigada *);
void borrar_intermedio(ListaLigada *, int);
void desplegar(ListaLigada *);
void limpiarLista(ListaLigada *);

#endif // LISTALIGADA_H

