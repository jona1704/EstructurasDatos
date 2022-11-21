#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define MAX 5

struct cola{
    int * arr;
    int frente;
    int final;
    int len;
};

typedef struct cola Cola;

// Funcián de inicialización (ej de constructor)
Cola * init(){
    Cola * c = (Cola*) malloc(sizeof(Cola));
    //if(c == NULL) exit(1);
    assert(c!=NULL);
    c->arr = (int *) malloc(MAX * sizeof(int));
    assert(c->arr!=NULL);
    c->frente = c->final = -1;
    c->len = 0;
    return c;
}

/*bool esVacia(Cola c){
    if(c.frente == -1 && c.final == -1) return true;
    else return false;
}*/

bool esVacia(Cola * c){
    return (c->frente == -1) && (c->final == -1);
}

bool esLlena(Cola * c){
    return c->final == MAX-1;
}

Cola * encolar(Cola * c, int dato){
    if(esLlena(c)){
        printf("\nCola llena ...");
    } else{
        if(esVacia(c)){
            c->frente = c->final = 0;
        } else{
            c->final++;
        }
        // A donde apunta final ingresamos el datos
        c->arr[c->final] = dato;
        c->len++;
    }
    return c;
}

Cola * desencolar(Cola * c){
    if(esVacia(c)){
        printf("\nCola Vacia ...");
    } else{
        if(c->frente > c->final){
            // Esta condición solo se da cuando
            // removemos el último elemento
            // existente en la Col
            c->frente = -1;
            c->final = -1;
        } else{
            c->frente++;
        }
        c->len--;
    }

    return c;
}

void display(Cola * c){
    if(esVacia(c)){
        printf("\nCola vacia ...");
    } else{
        int i;
        for(i=c->frente; i<=c->final; i++){
            printf("%d ", c->arr[i]);
        }
        printf("\n");
    }
}

int frente(Cola * c){
    return c->arr[c->frente];
}

int final(Cola * c) {
    return c->arr[c->final];
}

void destroy(Cola * c){
    free(c->arr);
    free(c);
}

int main() {
    Cola * c1 = init();
    c1 = encolar(c1, 20);
    c1 = encolar(c1, 56);
    c1 = encolar(c1, 72);
    c1 = encolar(c1, 86);
    c1 = encolar(c1, 98);
    c1 = encolar(c1, -12);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    display(c1);

    return 0;
}
