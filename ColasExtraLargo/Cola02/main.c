#include <stdio.h>
#define MAX 5

struct cola{
	int arr[MAX];
	int frente;
	int final;
};

typedef struct cola Cola;

Cola init(){
    Cola c = {{0}, -1, -1};
    return c;
}

Cola encolar(Cola c, int dato){
    if(c.final==MAX-1){
        printf("\nCola Llena ...\n");
    } else{
        if((c.frente<0) || (c.frente>c.final)){
            // Esta condición solo se da cuando
            // ingresamos el primer elemento
            c.frente = 0;
            c.final = 0;
        } else{
            c.final++;
        }
        c.arr[c.final] = dato;
    }
    return c;
}

Cola desencolar(Cola c){
    if((c.frente<0) || (c.frente>c.final)){
        printf("\nCola Vacia ...\n");
    } else{
        if(c.frente > c.final){
            // Esta condición solo se da cuando
            // removemos el último elemento
            // existente en la Col
            c.frente = -1;
            c.final = -1;
        } else{
            c.frente++;
        }
    }
    return c;
}

void desplegar(Cola c){
    if((c.frente<0) || (c.frente>c.final)){
        printf("\nCola Vacia ...\n");
    } else{
        int i;
        printf("[ ");
        for(i=c.frente; i<=c.final; i++){
            if(i == c.final) printf("%d", c.arr[i]);
            else printf("%d, ", c.arr[i]);
        }
        printf(" ]\n");
    }
}

int frente_(Cola c){
    return c.arr[c.frente];
}

int final_(Cola c){
    return c.arr[c.final];
}

int main() {
	Cola c1 = init();
	// Insertar datos
    c1 = encolar(c1, 20);
    c1 = encolar(c1, 56);
    c1 = encolar(c1, 72);
    c1 = encolar(c1, 86);
    c1 = encolar(c1, 98);
    c1 = encolar(c1, -12);
    desplegar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    desplegar(c1);

    return 0;
}
