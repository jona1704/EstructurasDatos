#include <stdio.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void desplegar(const int * arr, int n){
    int i;
    static int cont = 1;
    printf("%d: ", cont);
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    cont++;
}

void generate(int arr[] , int size, int n){
    int i;
    if(size == 1){
        desplegar(arr, n);
        return;
    }
    else {
        for(i=0; i<size; i++){
            generate(arr, size-1, n);
            if(size % 2 == 1) swap(&arr[0], &arr[size-1]);
            else swap(&arr[i], &arr[size-1]);
        }
    }
}

int main() {
    int num[] = {9, 7, 3, 6, 5};
    int n = sizeof(num)/ sizeof(num[0]);
    generate(num, n, n);
    return 0;
}
