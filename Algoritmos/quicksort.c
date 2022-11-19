#include <stdio.h>

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particion(int arr[], int inicio, int final){
    int pivote = arr[final];
    int i = inicio-1, j;
    for(j=inicio; j<=final-1; j++){
        if(arr[j] < pivote){
            i = i+1;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[final]);
    return i+1;
}


void quicksort(int arr[], int inicio, int final){
    int p;
    if(inicio < final){
        p = particion(arr, inicio, final);
        quicksort(arr, inicio, p-1);
        quicksort(arr, p+1, final);
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
    quicksort(arr, 0, n-1);
    desplegar(arr, n);
    return 0;
}
