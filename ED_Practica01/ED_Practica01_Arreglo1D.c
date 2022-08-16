#include <stdio.h>

void desplegar01(int arr[5], int n){
    int i;
    //printf("Size(arr2)=%d\n", sizeof(arr));
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void desplegar02(int arr[], int n){
    int i;
    //printf("Size(arr2)=%d\n", sizeof(arr));
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void desplegar03(int * arr, int n){
    int i;
    //printf("Size(arr2)=%d\n", sizeof(arr));
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Declaración de Arreglos
    int arr[5];
    int arr2[5] = {1,2,3,4,5};
    int arr3[] = {1,2,3,4,5};
    // Desplegar los elementos del arreglo
    //printf("Size(arr2)=%d\n", sizeof(arr2));
    int n = sizeof(arr)/sizeof(int);
    desplegar01(arr2, n);
    desplegar02(arr2, n);
    desplegar03(arr2, n);

    return 0;
}
