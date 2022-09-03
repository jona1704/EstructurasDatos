#include <stdio.h>
#include <stdbool.h>

// Función que aplica el algoritmo de la burbuja
void ordenar(int * arr, int n){
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

// Función que aplica el algoritmo de búsqueda lineal
bool buscar(int * arr, int n, int num_buscado){
    int i;
    bool esBuscado = false;
    for(i=0; i<n; i++){
        if(arr[i] == num_buscado){
            esBuscado = true;
        }
    }
    return esBuscado;
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
    int arr[] = {3, 5, 9, 10, -3,
                 -5, 12, 4, 29, -13};
    int n=0;
    printf("Lista antes de ordenar: ");
    desplegar(arr, 9);
    printf("\nLista después de ordenar: ");
    ordenar(arr, 9);
    desplegar(arr, 9);
    printf("\nBuscando el número 8 en la lista: ");
    n=8;
    if(buscar(arr, 9, n)){
        printf("Encontrado");
    } else{
        printf("No Encontrado");
    }
    printf("\nBuscando el número 12 en la lista: ");
    n=12;
    if(buscar(arr, 9, n)){
        printf("Encontrado");
    } else{
        printf("No Encontrando");
    }

    printf("\n");
    
    return 0;
}
