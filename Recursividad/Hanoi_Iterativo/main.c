#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "pila/pila.h"

// x^y
/* NOTA: Si no se activa la función pow() de la
 * librería <math.h> descomentar la siguiente
 * función:
/*
 int pow(int x, int y){
    if(y!=0) return x * pow(x, y-1);
    else return 1;
}*/

void moverDisco(char origen, char destino, int disco){
    printf("\nMover disco %d de torre %c a torre %c", disco, origen, destino);
}

void moverDiscosEntreDosTorres(Pila src, Pila dest, char o, char d){
    int discoTopeTorre1 = pop(src);
    int discoTopeTorre2 = pop(dest);

    // Cuando la torre 1 está vacía
    if(discoTopeTorre1 == INT_MIN){
        push(src, discoTopeTorre2);
        moverDisco(d, o, discoTopeTorre2);
    }

    // Cuando la torre 2 está vacía
    else if(discoTopeTorre2 == INT_MIN){
        push(dest, discoTopeTorre1);
        moverDisco(o, d, discoTopeTorre1);
    }

    // Cuando el disco en el tope de la torre 1 > tope de la torre 2
    else if(discoTopeTorre1 > discoTopeTorre2){
        push(src, discoTopeTorre1);
        push(src, discoTopeTorre2);
        moverDisco(d, o, discoTopeTorre2);
    }

    // Cuando el disco en el tope de la torre 1 < tope de la torre 2
    else {
        push(dest, discoTopeTorre2);
        push(dest, discoTopeTorre1);
        moverDisco(o, d, discoTopeTorre1);
    }
}

void hanoi_iterativo(int n, Pila origen, Pila auxiliar, Pila destino){
    int i, total_movimientos;
    char o = 'A', d = 'C', a = 'B';

    if(n%2 == 0){
        char temp = d;
        d = a;
        a = temp;
    }
    total_movimientos = pow(2, n)-1;

    // Los discos más grandes serán ingresados primero
    for(i=n; i>=1; i--){
        push(origen, i);
    }

    for(i=1; i<=total_movimientos; i++){
        if(i%3 == 1) moverDiscosEntreDosTorres(origen, destino, o, d);
        else if(i%3 == 2) moverDiscosEntreDosTorres(origen, auxiliar, o, a);
        else if(i%3 == 0) moverDiscosEntreDosTorres(auxiliar, destino, a, d);
    }
}

int main() {
    // Declarando número de discos
    unsigned n=3;
    // Declarando la pila
    Pila origen, destino, auxiliar;
    // Inicializando valores
    origen = crearPila(n);
    auxiliar = crearPila(n);
    destino = crearPila(n);

    hanoi_iterativo(n, origen, auxiliar, destino);

    printf("\n");

    return 0;
}
