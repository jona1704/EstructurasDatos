#include <stdio.h>
#include <string.h>

// Potencia de un numero
// 3^6 = 3 * 3^5
// 3^5 = 3 ^ 3^4

// 3^0 = 1

// 3^-5 = 1/3^5
// 1/3^5 = 1/3*3^4
// 1/3*3^4 = 1/3*3*3^3


// x^y
double potencia(int base, int exponente){
    if(exponente == 0) return 1;
    else if(exponente>0) return base * potencia(base, exponente-1);
    else return 1/ potencia(base,-exponente);
}

// Hallar el número más pequeño en un arreglo
int minimo(int arr[], int n){
    int min;
    if(n==1) return arr[0];
    else{
        min = minimo(arr, n-1);
        if(min<arr[n-1]) return min;
        else return arr[n-1];
    }
}

/*  Suponer arr[] = {5, 3, -2, 6, -1};
 *
 *
 *    minimo(arr, 1); // arr[0]=5
 *    minimo(arr, 2); // arr[0]<arr[1]: 3
 *    minimo(arr, 3); // 3<arr[2]: -2
 *    minimo(arr, 4); // -2<arr[3]: -2
 *    minimo(arr, 5); // -2<arr[4]: -2
 */

// Hallar el número más pequeño en un arreglo
int maximo(int arr[], int n){
    int max;
    if(n==1) return arr[0];
    else{
        max = maximo(arr, n-1);
        if(max>arr[n-1]) return max;
        else return arr[n-1];
    }
}

// n es el tamaño del arreglo
// Primera llamada recursiva
// n = 15
// len = 15-n = 15-15 = 0
// if(arr[0] == arr[14]) esPalindromo(arr, 14)
// Segunda llamada recursiva
// n = 14
// len = 15-n = 15-14 = 1
// if(arr[1] == arr[13]) esPalindromo(arr, 13)


/* Implementación 1 de validar palindromo */
int esPalindromo01(char arr[], int n){
    int len = strlen(arr)-n; // Obtenemos el primer indice
    if(len >= n-1) return 1; // Caso base
    else if(arr[len] == arr[n-1]) return esPalindromo01(arr, n-1); // Caso recursivo
    else return 0;
}

/* Implementación 2 de validar palindromo */
int esPalindromo02(char arr[], int i, int j){
    if(j>=i) return 1;
    else if(arr[i] == arr[j])
        return esPalindromo02(arr,++i,--j);
    else return 0;
}

int main() {
    int arr[] = {5, 3, -2, 6, -1};
    char cadena01[] = "anitalavalatina";
    char cadena02[] = "ll";
    printf("\n3^-5=%lf", potencia(3, -5));
    printf("\nmin(arr)=%d", minimo(arr, 5));
    printf("\nmax(arr)=%d", maximo(arr, 5));
    printf("\nesPalindromo(cadena01)=%d", esPalindromo01(cadena01, 0, strlen(cadena01)-1));
    printf("\nesPalindromo(cadena02)=%d", esPalindromo02(cadena02, 0, strlen(cadena02)-1));
    return 0;
}
