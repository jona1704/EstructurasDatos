#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Probando el tiempo de ejecución
// generando un arreglo con
// memoria dinámica usando malloc

int * asignar(int n){
    int * ptr = malloc(n * sizeof(int));
    if(ptr == NULL) exit(1);
    return ptr;
}

void llenar(int * ptr, int n){
    int i;
    for(i=0; i<n; i++){
        ptr[i] = i+1;
    }
}

// Imprimimos valores y direcciones de
// los elementos del arreglo
void desplegar(int * ptr, int n){
    int i;
    for(i=0; i<n; i++){
        printf("\nptr[%d]=%d &ptr[%d]=%p ", i, ptr[i], i, &ptr[i]);
    }
    printf("\n");
}

int main() {
    int * ptr = NULL;
    clock_t start, end;
    double tiempo_cpu;

    // Probando el tiempo de ejecución
    // con diferentes valores de n
    start = clock();
    int n = 100;
    ptr = asignar(n);
    llenar(ptr, n);
    desplegar(ptr, n);
    end = clock();
    tiempo_cpu = ((double )(end - start))/CLOCKS_PER_SEC;
    printf("\nTiempo de CPU=%lf", tiempo_cpu);

    return 0;
}
