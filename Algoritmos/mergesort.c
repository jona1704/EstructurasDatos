#include <stdio.h>

void merge(int arr[], int inicio, int m, int final)
{
    int i, j, k;
    int n1 = m - inicio + 1;
    int n2 = final - m;
    // Creamos arreglo temporales
    int L[n1], R[n2];
    // Copianos datos a los arreglos temporales
    for (i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    // Mezclamos los arreglo temporales
    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copiamos el resto de elementos de L[]
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copiamos el resto de elementos de R[]
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int inicio, int final){
    if (inicio < final) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = inicio + (final - inicio) / 2;

        // Sort first and second halves
        mergeSort(arr, inicio, m);
        mergeSort(arr, m + 1, final);
        merge(arr, inicio, m, final);
    }
}

void desplegar(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}


int main() {
    int arr[] = {6, 9, 2, 5, -2, 3, 2, 1, 9, -4, 6};
    int n = sizeof(arr)/ sizeof(int);
    mergeSort(arr, 0, n-1);
    desplegar(arr, n);

    return 0;
}
