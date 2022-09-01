#include <stdio.h>
#include <stdlib.h>

// Programa para crear un arreglo 3D usando
// memoria dinámica y agrupando tareas en funciones

int *** crearArreglo(int paginas, int filas, int columnas){
    int i, j;
    int *** arr = (int ***) malloc(paginas * sizeof(int **));
    if(arr == NULL) return NULL;
    for(i=0; i<paginas; i++){
        arr[i] = (int **) malloc(filas * sizeof(int*));
        if(arr[i] == NULL) return NULL;
        for(j=0; j<filas; j++){
            arr[i][j] = (int *) malloc(columnas * sizeof(int));
            if(arr[i][j] == NULL) return NULL;
        }
    }
    return arr;
}

void llenar(int *** arr, int paginas, int filas, int columnas){
    // Llenando Array
    int i, j, k;
    for(i=0; i<paginas; i++){
        for(j=0; j<filas; j++){
            for(k=0; k<columnas; k++)
                arr[i][j][k] = i+j+k;
        }
    }
}

void desplegar(int *** arr, int paginas, int filas, int columnas){
    int i, j, k;
    for(i=0; i<paginas; i++){
        printf("\n");
        for(j=0; j<filas; j++){
            printf("\n");
            for(k=0; k<columnas; k++) {
                printf("%d ", arr[i][j][k]);
            }
        }
    }
}

void liberar(int *** arr, int paginas, int filas){
    // Desasignar memoria
    int i, j;
    for(i=0; i<paginas; i++){
        for(j=0; j<filas; j++){
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);
}


int main() {
    int i, j, k; // Para recorrer los índices del arreglo
    int paginas = 2; // l = páginas
    int filas = 3; // m = filas
    int columnas = 3; // n = columnas
    printf("Arreglo 3D de 2x3x3 elementos: \n");
    int *** arr = (int ***) malloc(paginas * sizeof(int **));
    if(arr == NULL) return NULL;
    for(i=0; i<paginas; i++){
        arr[i] = (int **) malloc(filas * sizeof(int*));
        if(arr[i] == NULL) return NULL;
        for(j=0; j<filas; j++){
            arr[i][j] = (int *) malloc(columnas * sizeof(int));
            if(arr[i][j] == NULL) return NULL;
        }
    }
    // Llenando Array
    for(i=0; i<paginas; i++){
        for(j=0; j<filas; j++){
            for(k=0; k<columnas; k++)
                arr[i][j][k] = i+j+k;
        }
    }
    // Desplegando elementos del arreglo
    for(i=0; i<paginas; i++){
        printf("\n");
        for(j=0; j<filas; j++){
            printf("\n");
            for(k=0; k<columnas; k++) {
                printf("%d ", arr[i][j][k]);
            }
        }
    }
    // Desasignando memoria para los arreglos de n elementos
    for(i=0; i<paginas; i++){
        for(j=0; j<filas; j++){
            free(arr[i][j]);
        }
        // Desasignando memoria para los arreglos de m apuntadores
        free(arr[i]);
    }
    // Desasignando memoria para el arreglo de l dobles apuntadores
    free(arr);

    return 0;
}
