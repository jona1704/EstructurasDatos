#include <stdio.h>
#include <stdlib.h>

// Programa para crear un arreglo 1D usando
// memoria dinámica

int main() {
    int n = 6;
    int i;
    printf("Arreglo de 6 elementos: \n");
    int * arr = (int *) malloc(n * sizeof(int));
    if(arr == NULL) exit(1);
    // Llenando Array
    for(i=0; i<n; i++){
        arr[i] = i+1;
    }
    // Desplegando elementos del arreglo
    for (i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    // Desasignando memoria para el arreglo de n elementos
    free(arr);
    printf("\n");

    return 0;
}

