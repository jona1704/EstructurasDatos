#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "listaligada.h"
#define MAX 31
#define MIN 0

void desplegar_pares(ListaLigada * lista){
    Nodo * temp = lista->cabecera;
    if(temp == NULL){
        printf("Lista Vacía!!\n");
        return;
    }
    while (temp != NULL){
        if(temp->dato%2 == 0){
            printf("%d ", temp->dato);
        }
        temp = temp->siguiente;
    }
    printf("\n");
}

int desplegar_suma(ListaLigada * lista){
    Nodo * temp = lista->cabecera;
    if(temp == NULL){
        printf("Lista Vacía!!\n");
        return 0;
    }
    int suma = 0;
    while (temp != NULL){
        suma += temp->dato;
        temp = temp->siguiente;
    }
    return suma;
}

float desplegar_promedio(ListaLigada * lista){
    Nodo * temp = lista->cabecera;
    if(temp == NULL){
        printf("Lista Vacía!!\n");
        return 0;
    }
    int suma = 0;
    float promedio;
    while (temp != NULL){
        suma += temp->dato;
        temp = temp->siguiente;
    }
    promedio = (float)suma/30;
    return promedio;
}

int main() {
    // Para generar la semilla de números aleatorios
    srand(time(NULL));
    // Declaramos múltiples instancias de lista
    ListaLigada * l1 = listaLigada();
    // El programa nos permite insertar datos al principio
    // o al final. Seleccionamos principio
    int i, n;
    for(i=0; i<30; i++){
        n = rand()%(MAX-MIN) + MIN;
        insertar_inicio(l1, n);
    }
    desplegar(l1);
    desplegar_pares(l1);
    printf("suma=%d", desplegar_suma(l1));
    printf("\npromedio=%.2f", desplegar_promedio(l1));

    limpiarLista(l1);

    return 0;
}
