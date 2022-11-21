#include <stdio.h>
#define MAX 5

int arr[MAX], frente=-1, final=-1;

void encolar(int dato){
    if(final==MAX-1){
        printf("\nCola Llena ...\n");
    } else{
        if((frente<0) || (frente>final)){
            // Esta condición solo se da cuando
            // ingresamos el primer elemento
            frente = 0;
            final = 0;
        } else{
            final++;
        }
        arr[final] = dato;
    }
}

void desencolar(){
    if((frente<0) || (frente>final)){
        printf("\nCola Vacia ...\n");
    } else{
        if(frente > final){
            // Esta condición solo se da cuando
            // removemos el último elemento
            // existente en la Col
            frente = -1;
            final = -1;
        } else{
            frente++;
        }
    }
}

void desplegar(){
    if((frente<0) || (frente>final)){
        printf("\nCola Vacia ...\n");
    } else{
        int i;
        printf("[ ");
        for(i=frente; i<=final; i++){
            if(i == final) printf("%d", arr[i]);
            else printf("%d, ", arr[i]);
        }
        printf(" ]\n");
    }
}

int frente_(){
    return arr[frente];
}

int final_(){
    return arr[final];
}

int main() {
    encolar(20);
    encolar(56);
    encolar(72);
    encolar(86);
    encolar(98);
    encolar(-12);
    desplegar();
    desencolar();
    desencolar();
    desencolar();
    desencolar();
    desencolar();
    desencolar();
    desplegar();

    return 0;
}
