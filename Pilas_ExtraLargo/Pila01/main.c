// Online C compiler to run C program online
#include <stdio.h>
#define MAX 5

// Declarar las variables
int array[MAX], tope=-1;

// Operaciones de Pila
void push(int dato){
    if(tope == MAX-1){
        printf("\nPila esta Llena\n");
    } else{
        tope++;
        array[tope] = dato;
    }
}

void pop(){
    if(tope == -1){
        printf("\nPila esta Vacia\n");
    } else{
        tope--;
    }
}

void desplegar(){
    if(tope == -1){
        printf("\nPila esta Vacia\n");
    } else{
        int i;
        for(i=tope; i>=0; i--){
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}

int main(){

    // Insertar datos
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);
    push(11);
    desplegar();
    pop();
    pop();
    pop();
    pop();
    pop();
    desplegar();

    return 0;
}
