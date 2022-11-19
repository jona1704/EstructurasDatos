#include <stdio.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void seleccion(int arr[], int n){
    int i, j, indice_minimo;

    for (i = 0; i < n-1; i++){
        // Encontrar el elemento mínimo en un arreglo no ordenado
        indice_minimo = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[indice_minimo])
                indice_minimo = j;

        // Intercambiamos el elemento mínimo encontrado con el primer elemento
        if(indice_minimo != i)
            swap(&arr[indice_minimo], &arr[i]);
    }
}

void desplegar(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main() {
    // Creamos un arreglo con números en desorden
    int arr[] = {3, 5, 9, 10, -3, -5, 12, 4, 29, -13};
    int n = sizeof(arr)/ sizeof(int);
    seleccion(arr, n);
    desplegar(arr,n);
    return 0;
}
