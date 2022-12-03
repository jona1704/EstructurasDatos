#ifndef LISTADOBLE_H
#define LISTADOBLE_H

typedef struct fecha{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct pasajero{
    char nombre[40];
    char ape_pat[40];
    char ape_mat[40];
    Fecha fecha_vuelo;
    int numero_vuelo;
    int numero_asiento;
    char origen[40];
    char destino[40];
} Pasajero;

typedef struct nodo{
    Pasajero dato;
    struct nodo * siguiente;
    struct nodo * previo;
} Nodo; // Definimos un tipo para la estructura

typedef struct lista_doble{
    Nodo * cabecera;
    Nodo * final;
} ListaDoble;

Nodo * crearNodo();
ListaDoble * listaDoble();
void insertar_inicio(ListaDoble *);
void insertar_final(ListaDoble *);
int no_nodos(ListaDoble *);
void insertar_intermedio(ListaDoble *, int);
void borrar_inicio(ListaDoble *);
void borrar_final(ListaDoble *);
void borrar_intermedio(ListaDoble *, int);
void desplegar_adelante(ListaDoble *);
void desplegar_atras(ListaDoble *);
void buscar_por_numero(ListaDoble *, int);
void limpiarLista(ListaDoble *);

#endif // LISTADOBLE_H

