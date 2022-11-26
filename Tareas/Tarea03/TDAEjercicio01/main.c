#include <stdio.h>
#include "pila.h"
#include "cola.h"

Pila funcion(Cola c){
    Pila p = crearPila();
    int i;
    for(i=0; i<c.len; i++){
        p = push(p, c.arr[i]);
    }
    return p;
}

int main() {
    Cola c = crearCola();
    float arr[] = {1.23, 5.34, 7.89, 6.45, 9.87, -3.12, -4.23, 5.98};
    int n = sizeof(arr)/ sizeof(float);
    // Llenando Cola
    int i;
    for(i=0; i<n; i++){
        c = encolar(c, arr[i]);
    }
    display_cola(c);
    // Llenando Pila
    funcion(c);
    //Imprimiendo Pila
    Pila p = funcion(c);
    display_pila(p);

    return 0;
}
