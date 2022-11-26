//
// Created by Jonthan Cordoba on 26/11/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadoble.h"

Pasajero registrar(){
    Pasajero pasajero;
    char buffer[50];
    printf("\nIngrese el nombre(s) del pasajero: ");
    fgets(buffer, sizeof(buffer), stdin);
    strcpy(pasajero.nombre, buffer);
    printf("\nIngrese el apellido paterno del pasajero: ");
    fgets(buffer, sizeof(buffer), stdin);
    strcpy(pasajero.ape_pat, buffer);
    printf("\nIngrese el apellido materno del pasajero: ");
    fgets(buffer, sizeof(buffer), stdin);
    strcpy(pasajero.ape_mat, buffer);
    fflush(stdin);
    printf("\nIngrese el dia de viaje del pasajero: ");
    scanf("%d", &pasajero.fecha_vuelo.dia);
    fflush(stdin);
    printf("\nIngrese el mes de viaje del pasajero: ");
    scanf("%d", &pasajero.fecha_vuelo.mes);
    fflush(stdin);
    printf("\nIngrese el anio de viaje del pasajero: ");
    scanf("%d", &pasajero.fecha_vuelo.anio);
    fflush(stdin);
    printf("\nIngrese el numero de vuelo: ");
    scanf("%d", &pasajero.numero_vuelo);
    fflush(stdin);
    printf("\nIngrese el numero de asiento: ");
    scanf("%d", &pasajero.numero_asiento);
    fflush(stdin);
    printf("\nIngrese el lugar de origen del pasajero: ");
    fgets(buffer, sizeof(buffer), stdin);
    strcpy(pasajero.origen, buffer);
    printf("\nIngrese el lugar de destino del pasajero: ");
    fgets(buffer, sizeof(buffer), stdin);
    strcpy(pasajero.destino, buffer);

    printf("\nInsercion Realizada ...");

    return pasajero;
}

Nodo * crearNodo(){
    Nodo * nuevo = NULL;
    nuevo = (Nodo *) malloc(sizeof(Nodo));
    if(nuevo == NULL) return NULL;
    nuevo->dato = registrar();
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
    lista->final = NULL;

    return lista;
}

void insertar_inicio(ListaDoble * lista){
    Nodo * nuevo = crearNodo();
    if(lista->cabecera == NULL){
        lista->cabecera = nuevo;
        lista->final = nuevo;
    } else{
        lista->cabecera->previo = nuevo;
        nuevo->siguiente = lista->cabecera;
        lista->cabecera = nuevo;
    }
}

void insertar_final(ListaDoble * lista){
    Nodo * nuevo = crearNodo();
    if(lista->cabecera == NULL){
        lista->cabecera = nuevo;
        lista->final = nuevo;
    } else{
        lista->final->siguiente = nuevo;
        nuevo->previo = lista->final;
        lista->final = nuevo;
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

void insertar_intermedio(ListaDoble * lista, int pos){
    // Se toma el 0 como posición válida
    int noNodos = no_nodos(lista);
    if(pos<-1 || pos>noNodos){
        printf("Posición inválida\n");
        return;
    } else {
        Nodo * nuevo = crearNodo();
        Nodo * temp = lista->cabecera;
        if(lista->cabecera == NULL) {
            lista->cabecera = nuevo;
            lista->final = nuevo;
        } else if(pos == 0){
            nuevo->siguiente = lista->cabecera;
            lista->cabecera->previo = nuevo;
            lista->cabecera = nuevo;
        } else if(pos == noNodos){
            lista->final->siguiente = nuevo;
            nuevo->previo = lista->final;
            lista->final = nuevo;
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
            lista->final = NULL;
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
            lista->final = NULL;
        } else {
            /* Desconectar el enlace */
            lista->final = temp->previo;
            lista->final->siguiente = NULL;
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
                    lista->final = NULL;
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
                    // En este caso llegamos al ultimo nodo
                    lista->final = borrado->previo;
                    lista->final->siguiente = NULL;
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
        printf("Nombre: %s", temp->dato.nombre);
        printf("Apellido Paterno: %s", temp->dato.ape_pat);
        printf("Apellido Materno: %s", temp->dato.ape_mat);
        printf("Fecha de Vuelo: %.2d/%.2d/%.2d", temp->dato.fecha_vuelo.dia, temp->dato.fecha_vuelo.mes, temp->dato.fecha_vuelo.anio);
        printf("\nNumero de Vuelo: %d", temp->dato.numero_vuelo);
        printf("\nNumero de Asiento: %d", temp->dato.numero_asiento);
        printf("\nLugar de Origen: %s", temp->dato.origen);
        printf("Lugar de Destino: %s\n", temp->dato.destino);
        temp = temp->siguiente;
    }
    printf("\n");
}

void desplegar_atras(ListaDoble * lista){
    Nodo * temp = lista->final;
    if(temp == NULL){
        printf("Lista Vacía!!\n");
        return;
    }
    // Recorremos la lista desde el último nodo
    while (temp != NULL){
        printf("Nombre: %s", temp->dato.nombre);
        printf("Apellido Paterno: %s", temp->dato.ape_pat);
        printf("Apellido Materno: %s", temp->dato.ape_mat);
        printf("Fecha de Vuelo: %.2d/%.2d/%.2d", temp->dato.fecha_vuelo.dia, temp->dato.fecha_vuelo.mes, temp->dato.fecha_vuelo.anio);
        printf("\nNumero de Vuelo: %d", temp->dato.numero_vuelo);
        printf("\nNumero de Asiento: %d", temp->dato.numero_asiento);
        printf("\nLugar de Origen: %s", temp->dato.origen);
        printf("Lugar de Destino: %s\n", temp->dato.destino);
        temp = temp->previo;
    }
    printf("\n");
}

void buscar_por_numero(ListaDoble * lista, int numero_vuelo){
    Nodo * temp = lista->cabecera;
    if(temp == NULL){
        printf("Lista Vacía!!\n");
        return;
    }
    int no_encontrado = 0;
    while(temp != NULL){
        if(temp->dato.numero_vuelo == numero_vuelo){
            printf("Nombre: %s", temp->dato.nombre);
            printf("Apellido Paterno: %s", temp->dato.ape_pat);
            printf("Apellido Materno: %s", temp->dato.ape_mat);
            printf("Fecha de Vuelo: %.2d/%.2d/%.2d", temp->dato.fecha_vuelo.dia, temp->dato.fecha_vuelo.mes, temp->dato.fecha_vuelo.anio);
            printf("\nNumero de Vuelo: %d", temp->dato.numero_vuelo);
            printf("\nNumero de Asiento: %d", temp->dato.numero_asiento);
            printf("\nLugar de Origen: %s", temp->dato.origen);
            printf("Lugar de Destino: %s\n", temp->dato.destino);
            no_encontrado = 1;
        }
        temp = temp->siguiente;
    }
    if(no_encontrado == 0) printf("\nNo existe el registro buscado ...");
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
