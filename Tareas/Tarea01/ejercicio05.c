#include <stdio.h>

// Función que aplica el algoritmo de la burbuja
void burbuja(int * arr, int n){
    int i, j, temp;
    // El bucle externo maneja el número de iteraciones
    // El bucle interno maneja el número de pasos por cada iteración
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int buaquedaLineal(int arr[], int n, int valor_buscado){
    int i;
    for(i=0; i<n; i++){
        if(arr[i] > valor_buscado) return -1;
        else if(arr[i] == valor_buscado) return i;
    }
    return -1;
}

int main() {
    int arr[] = {3, 5, 9, 10, -3, -5, 12, 4, 29, -13};
    int n = sizeof(arr)/ sizeof(int);
    int valorBuscado = 10;
    burbuja(arr, n);
    int indice = buaquedaLineal(arr, n, valorBuscado);
    if(indice != -1) printf("\nValor encontrado");
    else printf("\nValor No encontrado");
    ///
    valorBuscado = 32;
    indice = buaquedaLineal(arr, n, valorBuscado);
    if(indice != -1) printf("\nValor encontrado");
    else printf("\nValor No encontrado");
    return 0;
}
