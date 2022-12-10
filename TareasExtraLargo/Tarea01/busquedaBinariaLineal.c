#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Llenar arreglo
void llenar_arreglo(int arr[], int n){
    int i, num;
    for(i=0; i<n; i++){
        num = rand() % (n - 0 + 1) + 0; // Número entre 0 y 1000
        arr[i] = num;
    }
}

// Algoritmo de la burbuja
// Función que aplica el algoritmo de la burbuja
void burbuja(int * arr, int n){
    int i, j, temp;
    // El bucle externo maneja el número de iteraciones
    // El bucle interno maneja el número de pasos por cada iteración
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void desplegar(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

// El algoritmo busca si el valor buscado está del lado
// izquierdo del elemento medio o del lado derecho del elemento medio
int busquedaBinariaLineal(int arr[], int * comp, int n, int valor_buscado){
    int izquierdo, medio, derecho, numero_elementos, bandera;
    izquierdo = 0;
    derecho = n-1;
    bandera = 0;
    // LLevar a cabo la busqueda hasta que izquierdo <= derecho
    while(izquierdo <= derecho){
        medio = (izquierdo + derecho)/2;
        if(arr[medio] == valor_buscado){
            (*comp)++;
            return medio;
        }
        if(arr[medio] < valor_buscado){
            (*comp)++;
            izquierdo = medio+1;
            numero_elementos = derecho - izquierdo;
            if(numero_elementos < 15){
                bandera = 1;
                break;
            }
        }
        else{
            (*comp)++;
            derecho = medio-1;
            numero_elementos = derecho - izquierdo;
            if(numero_elementos < 15){
                bandera = 1;
                break;
            }
        }
    }

    if(bandera == 1){
        int i;
        for(i=izquierdo; i<=derecho; i++){
            (*comp)++;
            if(arr[i] == valor_buscado){
                return i;
            }
        }
    }

    return -1;
}


int main() {
    srand(time(NULL)); // Inicialización con generador que cambia
    int n = 1000;
    int arreglo[n];
    int comparaciones = 0;
    llenar_arreglo(arreglo, n);
    burbuja(arreglo, n);
    desplegar(arreglo, n);
    int indice = busquedaBinariaLineal(arreglo, &comparaciones, 1000, 19);
    printf("\nNumero de comparaciones: %d", comparaciones);
    if(indice == -1) printf("\nValor no encontrado");
    else  printf("\nValor encontrado en el indice %d", indice);

    return 0;
}
