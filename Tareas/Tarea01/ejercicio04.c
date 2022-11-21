#include <stdio.h>

int buaquedaLineal(int arr[], int n, int valor_buscado){
    int i;
    for(i=0; i<n; i++){
        if(arr[i] == valor_buscado){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {3, 5, 9, 10, -3, -5, 12, 4, 29, -13};
    int n = sizeof(arr)/ sizeof(int);
    int valorBuscado = 10;
    int indice = buaquedaLineal(arr, n, valorBuscado);
    if(indice != -1) printf("\nValor encontrado");
    else printf("\nValor No encontrado");
    ///
    valorBuscado = 32;
    indice = buaquedaLineal(arr, n, valorBuscado);
    if(indice != -1) printf("\nValor encontrado");
    else printf("\nValor No encontrado");
    return 0;
}
