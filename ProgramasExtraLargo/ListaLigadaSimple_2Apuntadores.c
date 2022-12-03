#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo * siguiente;
} Nodo; // Definimos un tipo para la estructura

typedef struct lista{
    Nodo * cabecera;
    Nodo * ultimo;
    int contador;
} ListaLigada;

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
    lista->ultimo = NULL;
    lista->contador = 0;

    return lista;
}

void insertar_inicio(ListaLigada * lista, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(lista->cabecera == NULL){
        // Se inserta el primer dato
        lista->cabecera = nuevo;
        lista->ultimo = nuevo;
    } else{
        // Solo modificamos entonces el apuntador cabecera
        nuevo->siguiente = lista->cabecera;
        lista->cabecera = nuevo;
    }
    lista->contador++;
}

void insertar_final(ListaLigada * lista, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(lista->cabecera == NULL){
        lista->cabecera = nuevo;
        lista->ultimo = nuevo;
    } else{
        // Al tener un apuntador al ultimo nodo no
        // requerimos recorrer la lista
        lista->ultimo->siguiente = nuevo;
        lista->ultimo = nuevo;
    }
    lista->contador++;
}

int no_nodos(ListaLigada * lista){
    if(lista->cabecera == NULL) return 0;
    else return lista->contador;
}

void insertar_intermedio(ListaLigada * lista, int pos, int dato){
    Nodo * nuevo = crearNodo(dato);
    // Se toma el 0 como posición válida
    int noNodos = no_nodos(lista);
    if(pos<-1 || pos>noNodos+1){
        printf("Posición inválida\n");
        return;
    } else if(lista->cabecera == NULL) {
        // Se ingresa el primer dato o nodo
        lista->cabecera = nuevo;
        lista->ultimo = nuevo;
        lista->contador++;
        return;
    } else if(pos == 0){
        nuevo->siguiente = lista->cabecera;
        lista->cabecera = nuevo;
        lista->contador++;
        return;
    } else{
        Nodo * temp = lista->cabecera;
        int i=0;
        while(i<pos-1){
            temp = temp->siguiente; // (pos-1)-th nodo
            i++;
        }
        // temp = El nodo donde actualmente nos encontramos despues del recorrido
        // temp->siguiente = El siguiente nodo
        if(temp->siguiente == NULL){
            // El nodo actualmentes Es el ultimo de la lista
            temp->siguiente = nuevo;
            lista->ultimo = nuevo;
        } else{
            nuevo->siguiente = temp->siguiente;
            temp->siguiente = nuevo;
        }
        lista->contador++;
    }
}

void borrar_inicio(ListaLigada * lista){
    if(lista->cabecera == NULL){
        printf("Lista Vacía!!\n");
    } else{
        Nodo * temp = lista->cabecera;
        lista->cabecera = lista->cabecera->siguiente;
        lista->contador--;
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
            // temp es el ultimo nodo en la lista
            lista->cabecera = NULL;
            lista->ultimo = NULL;
        } else {
            /* Desconectar el enlace */
            prev->siguiente = NULL;
            lista->ultimo = prev;
        }
        lista->contador--;
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
                lista->contador--;
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
                if(borrado->siguiente == NULL){
                    temp->siguiente = NULL;
                    lista->ultimo = temp;
                } else{
                    temp->siguiente = borrado->siguiente; // (pos+1)-th nodo
                }
                lista->contador--;
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

int main() {
    // Declaramos múltiples instancias de lista
    ListaLigada * l1 = listaLigada();
    // Insertamos datos en la lista 1
    insertar_inicio(l1, 3);
    insertar_inicio(l1, 5);
    insertar_inicio(l1, 4);
    insertar_inicio(l1, 23);
    insertar_inicio(l1, 18);
    desplegar(l1);
    printf("No_nodos=%d\n", no_nodos(l1));
    insertar_final(l1, 18);
    insertar_final(l1, 23);
    insertar_final(l1, 4);
    insertar_final(l1, 23);
    insertar_final(l1, 3);
    desplegar(l1);
    printf("No_nodos=%d\n", no_nodos(l1));
    insertar_intermedio(l1, 0, 29);
    insertar_intermedio(l1, 11, 29);
    insertar_intermedio(l1, 6, 29);
    desplegar(l1);
    printf("No_nodos=%d\n", no_nodos(l1));
    borrar_inicio(l1);
    borrar_inicio(l1);
    borrar_inicio(l1);
    desplegar(l1);
    printf("No_nodos=%d\n", no_nodos(l1));
    borrar_final(l1);
    borrar_final(l1);
    borrar_final(l1);
    desplegar(l1);
    printf("No_nodos=%d\n", no_nodos(l1));
    borrar_intermedio(l1, 1);
    borrar_intermedio(l1, 5);
    borrar_intermedio(l1, 2);
    desplegar(l1);
    printf("No_nodos=%d\n", no_nodos(l1));

    limpiarLista(l1);

    return 0;
}
