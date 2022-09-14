#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para intercambiar 2 números
void intercambio(int * ptr1, int * ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

// Función para intercambiar 3 números
void sort3(int * ptr1, int * ptr2, int * ptr3){
    if(*ptr2 < *ptr1){
        intercambio(ptr1, ptr2);
    }
    if(*ptr3 < *ptr2){
        intercambio(ptr2, ptr3);
        if(*ptr2 < *ptr1){
            intercambio(ptr1, ptr2);
        }
    }
}

// Ordenamiento con burbuja
void ordenar(int * arr, int n){
    int i, j;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                intercambio(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Llenar con Aleatorios
void llenar(int * arr, int n){
    int i;
    for(i=0; i<n; i++){
        arr[i] = (rand()%100)+1;
    }
}

// Calcular la media
double media(int * arr, int n){
    int i;
    int contador=0;
    double media;
    for(i=0; i<n; i++){
        contador += arr[i];
    }
    media = (double)contador/(double)n;
    return media;
}

// Calcular la mediana
int mediana(int * arr, int n){
    double mediana;
    int mitad = n/2;
    // Obteniendo la mediana
    if(n%2 == 0){
        // Debemos promediar los elementos del centro
        mediana = (arr[mitad-1] + arr[mitad])/2;
    } else{
        mediana = arr[mitad];
    }

    return mediana;
}

int moda(int * arr, int n){
    int i, j;
    int valorMax=0;
    int cuentaMax=0;
    for(i=0; i<n; i++){
        int contador = 0;
        for(j=0; j<n; j++){
            if(arr[j] == arr[i]) contador++;
        }
        if(contador>cuentaMax){
            cuentaMax = contador;
            valorMax = arr[i];
        }
    }

    return valorMax;
}

void desplegar(int * arr, int n){
    int i;
    // Comparamos cada número contra los demás
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

double determinante(int n, double (*matriz)[n]){
    int i, j, k;
    double razon;
    double determinante_ = 1.0;
    if(n==2){
        determinante_ = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    } else{
        // Técnica de Eliminación Gaussiana para transformar
        // la matriz a una matriz triangular superior
        for(i=0; i<n; i++){
            if(matriz[i][i] == 0.0){
                exit(0);
            }
            for(j=i+1; j<n; j++){
                razon = matriz[j][i]/matriz[i][i];
                for(k=0; k<n; k++){
                    matriz[j][k]  -= (razon * matriz[i][k]);
                }
            }
        }

        for(i=0; i<n; i++){
            determinante_ *= matriz[i][i];
        }
    }
    return determinante_;
}



int main() {
    int a=7, b=4, c=2;
    sort3(&a, &b, &c);
    printf("After: a=%d, b=%d, c=%d\n", a, b, c);

    int arr[20];
    srand(time(NULL)); // Inicialización con generador que cambia
    llenar(arr, 20);
    desplegar(arr, 20);
    printf("\nLa media de los numeros es: %.2lf\n", media(arr, 20));
    // Ordenando Números
    ordenar(arr, 20);
    printf("\nLa mediana de los numeros es: %d\n", mediana(arr, 20));
    printf("\nLa moda de los numeros es: %d\n", moda(arr, 20));

    int matriz[4][4] = {{1,4,5,3},{9,0,12,-2}, {3,6,4,17},{4,5,6,7}};
    double matriz02[3][3] = {{-5,0,-1}, {1,2,-1}, {-3,4,1}};
    double matriz03[3][3] = {{1,3,2}, {-3,-1,-3}, {2,3,1}};
    double matriz04[2][2] = {{3,8},{4,6}};
    printf("\nEl determinante es: %.2lf\n", determinante(3, matriz02));

    return 0;
}

