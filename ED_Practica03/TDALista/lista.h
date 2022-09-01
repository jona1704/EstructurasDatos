//
// Created by Jonathan Córdoba on 29/08/22.
//

#ifndef LISTA_H
#define LISTA_H

typedef struct lista * Lista;

Lista crearLista();
Lista insertar(Lista, double);
void desplegar(Lista);
int size(Lista);

#endif //LISTA_H

