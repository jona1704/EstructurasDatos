#include <stdio.h>
#include <string.h>

long long int factorial(int n){
    if(n==1) return 1;
    else return n * factorial(n-1);
}

void funcion01(int n){
    if(n>0){
        printf("%d ", n);
        funcion01(n-1);
    }
}

void funcion02(int n){
    if(n>0){
        funcion02(n-1);
        printf("%d ", n);
    }
}

void funcion03(char arr[], int n){
    if(n != 1){
        printf("%c ", arr[n-2]);
        funcion03(arr, n-1);
    }
}

int convertir(int n){
    if(n>0){
        convertir(n/2);
        printf("%d", n%2);
    }
}

int convertir02(int n){
    if(n>0){
        convertir02(n/8);
        printf("%d", n%8);
    }
}

// Suma de 1 a n =>  1 + 2 + 3 + 4 + 5 + ... + n
int suma(int n){
    if(n==1) return 1;
    else return n + suma(n-1);
}

// Suma de los elementos de un arreglo
// arr[0] + arr[1] + ... + arr[n-1]
int suma_arreglo(int arr[], int n){
    if(n==1) return arr[0];
    else return arr[n-1] + suma_arreglo(arr, n-1);
}

int main(){
    // Se calculó hasta el factorial de 20
    printf("\nfact(20)=%lld", factorial(20));
    // Imprimimos del 40 al 1
    printf("\n");
    funcion01(40);
    // Imprimimos del 1 al 40
    printf("\n");
    funcion02(40);
    // Declarar una cadena
    printf("\n");
    char cadena[] = "fes acatlan";
    // Invertir una cadena
    funcion03(cadena, strlen(cadena)+1);
    // Convertir decimal a binario
    printf("\n");
    int d = 4523;
    convertir(d);
    // Convertir decimal a octal
    printf("\n");
    d = 4523;
    convertir02(d);
    // Suma hasta el 100
    printf("\nsuma(100)=%d", suma(100));
    // Suma de los elementos de un arreglo
    int arr[] = {1,2,3,4,5};
    printf("\nsuma_arreglo(arr)=%d", suma_arreglo(arr, 5));

    return 0;
}

