#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n;
    int * arr = NULL;
    printf("\nIngrese n: ");
    scanf("%d", &n);
    arr = malloc(n * sizeof(int));
    if(arr == NULL) exit(1);
    // Capturando valores
    for(i=0; i<n; i++){
        arr[i] = i+1;
    }
    // Desplegar los valores
    for(i=0; i<n; i++){
        printf("\narr[%d]=%d", i, arr[i]);
    }
    // **************************************** //
    // Redimensionando el arreglo
    printf("\n\nIngrese Otro valor de n: ");
    scanf("%d", &n);
    arr = realloc(arr, n * sizeof(int));
    if(arr == NULL) exit(1);
    // Capturando valores
    for(i=0; i<n; i++){
        arr[i] = i+1;
    }
    // Desplegar los valores
    for(i=0; i<n; i++){
        printf("\narr[%d]=%d", i, arr[i]);
    }
    printf("\n");
    // **************************************** //

    // Devolver memoria
    free(arr);

    return 0;
}
