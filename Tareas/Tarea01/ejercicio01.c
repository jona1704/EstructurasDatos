#include <stdio.h>

// Función que aplica el algoritmo de la burbuja
void burbuja(int * arr, int n){
    int i, j, temp;
    // El bucle externo maneja el número de iteraciones
    // El bucle interno maneja el número de pasos por cada iteración
    for(i=0; i<n-1; i++){
        int swapped=0;
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
}

// Función que despliega los elementos de un arreglo
void desplegar(int * arr, int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main() {
    // Creamos un arreglo con números en desorden
    int arr[] = {3, 5, 9, 10, -3, -5, 12, 4, 29, -13};
    int n = sizeof(arr)/ sizeof(int);
    burbuja(arr, n);
    desplegar(arr,n);
    return 0;
}
