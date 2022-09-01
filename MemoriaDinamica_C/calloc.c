#include <stdio.h>
#include <stdlib.h>

/* Asignación Dinámica de Memoria con calloc() */
int main() {

    // Asignando memoria dinámica para un solo valor
    printf("Memoria Dinámica para un elemento entero: \n\n");
    int n = 1;
    int * ptr = (int *)calloc(n, sizeof(int));
    if(ptr == NULL) exit(1);
    *ptr = 7;
    printf("*ptr = %d\n", *ptr); // Imprime valor
    printf("ptr = %p\n", ptr); // Imprime Dirección
    free(ptr); // Desasignando memoria
    ptr = NULL; // Permite usar ptr para asignarle otro espacio de memoria

    // Asignando memoria dinámica para un arreglo de n elementos
    printf("\n");
    printf("Memoria Dinámica para un arreglo de 7 elementos: \n\n");
    n = 7;
    int i;
    ptr = (int *) calloc(n, sizeof(int));
    if(ptr == NULL) exit(1);
    //  Llenando el arreglo con valores
    for(i=0; i<n; i++){
        ptr[i] = i+1;
    }
    // Imprimiendo valores
    for(i=0; i<n; i++){
        // Imprime valores y direcciones
        printf("Val(ptr[%d]) = %d -- Dir(ptr[%d]) = %p\n", i, ptr[i], i, &ptr[i]);
    }
    free(ptr); // Desasignando memoria

    return 0;
}

