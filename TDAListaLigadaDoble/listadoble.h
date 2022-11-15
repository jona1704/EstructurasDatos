//
// Created by Jonthan Cordoba on 14/11/22.
//

#ifndef LISTADOBLE_H
#define LISTADOBLE_H

typedef struct nodo{
    int dato;
    struct nodo * siguiente;
    struct nodo * previo;
} Nodo; // Definimos un tipo para la estructura

typedef struct lista_doble{
    Nodo * cabecera;
} ListaDoble;

Nodo * crearNodo(int);
ListaDoble * listaDoble();
void insertar_inicio(ListaDoble *, int);
void insertar_final(ListaDoble *, int);
int no_nodos(ListaDoble *);
void insertar_intermedio(ListaDoble *, int, int);
void borrar_inicio(ListaDoble *);
void borrar_final(ListaDoble *);
void borrar_intermedio(ListaDoble *, int);
void desplegar_adelante(ListaDoble *);
void desplegar_atras(ListaDoble *);
void limpiarLista(ListaDoble *);

#endif // LISTADOBLE_H
