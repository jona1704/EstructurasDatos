#include <stdio.h>

// Función recursiva doble
int f(int x){
    if(x>100){
        return (x-10);
    } else{
        return f(f(x+11));

    }
}

// Juego de las torres de Hanoi
void torres_hanoi(int n, char origen, char destino, char auxiliar){
    if(n==1){
        printf("\nMover disco 1 de torre %c a torre %c", origen, destino);
    } else{
        torres_hanoi(n-1, origen, auxiliar, destino);
        printf("\nMover disco %d de torre %c a torre %c", n, origen, destino);
        torres_hanoi(n-1, auxiliar, destino, origen);
    }
}

int main() {
    // Doble recursividad
    f(90); // Cualquier valor imprime 91

    // Problema de las Torres de Hanoi
    // Cuando n=5
    //2^5 - 1 = 32 - 1 = 31
    torres_hanoi(5, 'A','C','B');

    return 0;
}

