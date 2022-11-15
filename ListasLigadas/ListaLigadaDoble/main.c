#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo * siguiente;
    struct nodo * previo;
} Nodo; // Definimos un tipo para la estructura

typedef struct lista_doble{
    Nodo * cabecera;
} ListaDoble;

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
    Nodo *temp = NULL; // Nodo a borrar
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

void desplegar_previo(ListaDoble * lista){
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
    Nodo * actual = lista->cabecera;
    while (actual != NULL) {
        Nodo * temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    free(lista);
}

int main() {
    // Declaramos múltiples instancias de lista
    ListaDoble * l1 = listaDoble();
    // Insertamos datos en la lista 1
    insertar_inicio(l1, 3);
    insertar_inicio(l1, 5);
    insertar_inicio(l1, 4);
    insertar_inicio(l1, 23);
    insertar_inicio(l1, 18);
    printf("\nRecorrido hacia adelante: "); desplegar_adelante(l1);
    printf("Recorrido hacia atrás: ");desplegar_previo(l1);
    insertar_final(l1, 18);
    insertar_final(l1, 23);
    insertar_final(l1, 4);
    insertar_final(l1, 23);
    insertar_final(l1, 3);
    printf("\nRecorrido hacia adelante: "); desplegar_adelante(l1);
    printf("Recorrido hacia atrás: ");desplegar_previo(l1);
    insertar_intermedio(l1, 0, 29);
    insertar_intermedio(l1, 11, 29);
    insertar_intermedio(l1, 6, 29);
    printf("\nRecorrido hacia adelante: "); desplegar_adelante(l1);
    printf("Recorrido hacia atrás: ");desplegar_previo(l1);
    borrar_inicio(l1);
    borrar_inicio(l1);
    borrar_inicio(l1);
    printf("\nRecorrido hacia adelante: "); desplegar_adelante(l1);
    printf("Recorrido hacia atrás: ");desplegar_previo(l1);
    borrar_final(l1);
    borrar_final(l1);
    borrar_final(l1);
    printf("\nRecorrido hacia adelante: "); desplegar_adelante(l1);
    printf("Recorrido hacia atrás: ");desplegar_previo(l1);
    borrar_intermedio(l1, 1);
    borrar_intermedio(l1, 5);
    borrar_intermedio(l1, 2);
    printf("\nRecorrido hacia adelante: "); desplegar_adelante(l1);
    printf("Recorrido hacia atrás: ");desplegar_previo(l1);

    limpiarLista(l1);

    return 0;
}
