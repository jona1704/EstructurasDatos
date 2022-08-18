#include <stdio.h>

// Fe de erratas:
/*
 * Reemplazar:
 * desplegar(int m, int n, int ** matriz);
 *
 * Por:
 * desplegar(int m, int n, int (*matriz)[n]);
 *
 * (*matriz)[n] Representa un arreglo de apuntadores
 * a apuntadores
 */

void desplegar(int m, int n, int (*matriz)[n]){
    int i, j;
    // Desplegando matriz usando la notación de corchete
    for(i=0; i<m; i++){
        printf("\n");
        for(j=0; j<n; j++){
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\n");
}

void desplegar2(int m, int n, int (*matriz)[n]){
    int i, j;
    // Desplegando matriz usando la notación de apuntador
    for(i=0; i<m; i++){
        printf("\n");
        for(j=0; j<n; j++){
            printf("%d ", *(*(matriz+i)+j));
        }
    }
    printf("\n");
}

int main() {
    int mat[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7,8,9}
    };
    desplegar(3, 3, mat);
    desplegar2(3, 3, mat);

    return 0;
}
