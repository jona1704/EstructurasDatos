#include <stdio.h>

void desplegar01(int matriz[4][3]){
    int i, j;
    for(i=0; i<4; i++){
        printf("\n");
        for(j=0; j<3; j++){
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\n");
}

void desplegar02(int m, int n, int matriz[m][n]){
    int i, j;
    for(i=0; i<m; i++){
        printf("\n");
        for(j=0; j<n; j++){
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\n");
}

void desplegar03(int m, int n, int * matriz){
    int i, j;
    for(i=0; i<m; i++){
        printf("\n");
        for(j=0; j<n; j++){
            printf("%d ", *((matriz+i*n)+j));
        }
    }
    printf("\n");
}

void desplegar04(int m, int n, int (*matriz)[n]){
    int i, j;
    for(i=0; i<m; i++){
        printf("\n");
        for(j=0; j<n; j++){
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\n");
}

int main() {
    int matriz01[4][3]; // No inicializada
    int matriz02[4][3] = {{1, 2, 3},
                          {4, 5, 6, },
                          {7, 8, 9},
                          {10, 11, 12}
    };
    int matriz03[4][3] = {1, 2, 3, 4, 5,
                          6, 7, 8, 9,
                          10, 11, 12
    };
    int matriz04[][3] = {1, 2, 3, 4, 5,
                          6, 7, 8, 9,
                          10, 11, 12
    };

    desplegar01(matriz02);
    int m = sizeof(matriz02)/sizeof(matriz02[0]); // 4 filas
    int n = sizeof(matriz02[0])/sizeof(int); // 3 filas
    desplegar02(m, n, matriz02);
    desplegar03(m, n, matriz03);
    desplegar04(m, n, matriz04);


    return 0;
}
