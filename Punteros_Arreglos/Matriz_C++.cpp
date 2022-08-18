#include <iostream>
using namespace std;

template <size_t m, size_t n>
void desplegar(int (&matriz)[m][n]){
    // Desplegando matriz usando la notación de corchete
    for(int i=0; i<m; i++){
        printf("\n");
        for(int j=0; j<n; j++){
            cout << " " << matriz[i][j];
        }
    }
    printf("\n");
}

void desplegar2(int matriz[][3], int m, int n){
    int i, j;
    // Desplegando matriz usando la notación de corchete
    for(i=0; i<m; i++){
        printf("\n");
        for(j=0; j<n; j++){
            cout << " " << matriz[i][j];
        }
    }
    printf("\n");
}

void desplegar3(int (*matriz)[3], int m, int n){
    int i, j;
    // Desplegando matriz usando la notación de corchete
    for(i=0; i<m; i++){
        printf("\n");
        for(j=0; j<n; j++){
            cout << " " << matriz[i][j];
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
    desplegar(mat);
    desplegar2(mat, 3, 3);
    desplegar3(mat, 3, 3);
    return 0;
}
