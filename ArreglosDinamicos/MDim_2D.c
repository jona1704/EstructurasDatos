#include <stdio.h>
#include <stdlib.h>

// Programa para crear un arreglo 2D usando
// memoria dinámica

int main() {
    int filas = 5; // m = filas
    int columnas = 5; // n = columnas
    int i, j; // Para recorrer los índices del arreglo
    printf("Arreglo 2D de 5x5 elementos: \n");
    int ** arr = (int **) malloc(filas * sizeof(int *));
    if(arr == NULL) return NULL;
    for(i=0; i<filas; i++){
        arr[i] = (int *) malloc(columnas * sizeof(int));
        if(arr[i] == NULL) return NULL;
    }
    // Llenando Array
    for(i=0; i<filas; i++){
        for(j=0; j<columnas; j++)
            arr[i][j] = i+j;
    }
    // Desplegando elementos del arreglo
    for (i = 0; i < filas; i++) {
        printf("\n");
        for (j = 0; j < columnas; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    // Desasignando memoria para los arreglos de n elementos
    for(i=0; i<filas; i++){
        free(arr[i]);
    }
    // Desasignando memoria para el arreglo de m apuntadores
    free(arr);

    printf("\n");
    return 0;
}
