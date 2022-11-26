#include <stdio.h>
#include "pila.h"
#include "cola.h"

Cola funcion(Cola c){
    Pila p = crearPila();
    // Almacene el tamaño de la cola en una variable denominada len
    int n = len_cola(c);
    //Inserte los elementos de la cola en una pila, pero sin que la cola pierda sus elementos.
    int i=0;
    while(n != 0){
        push(&p, c.arr[i]);
        n--;
        i++;
    }
    //Inserte los elementos de la pila de regreso a la cola.
    while (!esVacia(p)){
        c = encolar(c, pop(&p));
    }

    return c;
}

int main() {
    char cadenas[][DATASIZE] = {"Hola", "Mundo", "Maravilloso"};
    int n = sizeof(cadenas)/ sizeof(cadenas[0]);
    // Llenando la Cola
    Cola c = crearCola();
    int i;
    for(i=0; i<n; i++){
        c = encolar(c, cadenas[i]);
    }
    c = funcion(c);
    display_cola(c);

    return 0;
}
