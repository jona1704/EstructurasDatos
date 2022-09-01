#include <stdio.h>
#include <stdlib.h>

// Programa para crear un arreglo 2D usando
// memoria dinámica y agrupando tareas en funciones

int ** crearArreglo(int filas, int columnas){
    int i;
    int ** arr = (int **) malloc(filas * sizeof(int *));
    if(arr == NULL) return NULL;
    for(i=0; i<filas; i++){
        arr[i] = (int *) malloc(columnas * sizeof(int));
        if(arr[i] == NULL) return NULL;
    }
    return arr;
}

void llenar(int ** arr, int filas, int columnas){
    // Llenando Array
    int i, j;
    for(i=0; i<filas; i++){
        for(j=0; j<columnas; j++)
            arr[i][j] = i+j;
    }
}

void desplegar( int ** arr, int filas, int columnas) {
    int i, j;
    for (i = 0; i < filas; i++) {
        printf("\n");
        for (j = 0; j < columnas; j++) {
            printf("%d ", arr[i][j]);
        }
    }
}

void limpiar(int ** arr, int filas){
    int i=0;
    for(i=0; i<filas; i++){
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int filas = 5;
    int columnas = 5;
    printf("Matriz de 5x5: \n");
    int ** arr = crearArreglo(filas,columnas);
    llenar(arr, filas, columnas);
    desplegar(arr, filas, columnas);
    printf("\n\nMatriz de 3x4: \n");
    filas = 3;
    columnas = 4;
    arr = crearArreglo(filas,columnas);
    llenar(arr, filas, columnas);
    desplegar(arr, filas, columnas);

    printf("\n");

    limpiar(matriz01, filas);

    return 0;
}
