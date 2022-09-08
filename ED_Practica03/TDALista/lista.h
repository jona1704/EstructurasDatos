//
// Created by Jonathan Córdoba on 08/09/22.
//

#ifndef LISTA_H
#define LISTA_H

typedef struct lista * Lista;

Lista init(); // Inicializa la lista
Lista insertar(Lista l, int pos, int valor);
Lista borrar(Lista l, int pos);
bool buscar(Lista l, int valor_buscado);
Lista ordenar(Lista l);
void desplegar(Lista l);
int len(Lista l);
void destroy(Lista l);

#endif // LISTA_H
