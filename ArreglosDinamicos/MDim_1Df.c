#include <stdio.h>
#include <stdlib.h>

// Programa para crear un arreglo 1D usando
// memoria dinámica y agrupando tareas en funciones

int * crearArreglo(int n){
    int i;
    int * matriz = (int *) malloc(n * sizeof(int));
    if(matriz == NULL) return NULL;

    return matriz;
}

void llenar(int * arr, int n){
    // Llenando Array
    int i, j;
    for(i=0; i<n; i++){
        arr[i] = i+1;
    }
}

void desplegar(int * arr, int n) {
    int i, j;
    for (i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

void limpiar(int * arr){
    free(arr);
}

int main() {
    int n = 6;
    printf("Arreglo de 6 elementos: \n");
    int * arr = crearArreglo(n);
    llenar(arr, n);
    desplegar(arr, n);
    printf("\n\nArreglo de 4 elementos: \n");
    n = 4;
    arr = crearArreglo(n);
    llenar(arr, n);
    desplegar(arr, n);
    printf("\n\nArreglo de 8 elementos: \n");
    n = 8;
    arr = crearArreglo(n);
    llenar(arr, n);
    desplegar(arr, n);

    printf("\n");

    limpiar(arr);

    return 0;
}
