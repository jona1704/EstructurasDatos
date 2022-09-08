#include <stdio.h>
#include <stdlib.h>
#define N 5

struct T{
    int * arr; // Variable para crear un entero
    int cont;
};

int main() {
    // Variable de tipo struct T (Estática)
    struct T t1;
    int i;
    // Asignamos memoria para el miembro de tipo apuntador
    t1.arr = (int *) malloc(N * sizeof(int));
    if(t1.arr == NULL) exit(1);
    // Inicializamos el miembro cont con un valor
    t1.cont = 0;
    // Llenamos el arreglo
    for(i=0; i<N; i++){
        t1.arr[i] = i+1;
    }
    // Imprimimos miembros del arreglo
    printf("arr = [ ");
    for(i=0; i<N; i++){
        printf("%d ", t1.arr[i]);
    }
    printf("]\n");
    printf("cont= %d\n", t1.cont);
    // Liberamos memoria para el miembro arr;
    free(t1.arr);

    return 0;
}
