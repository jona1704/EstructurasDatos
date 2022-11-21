#include <stdio.h>

long long int factorial_iterativo(int n){
    int fact = 1, i;
    for(i=1; i<=n; i++){
        fact = fact * i;
    }
    return fact;
}

long long int catalan_iterativo(int n){
    return (int)(factorial_iterativo(2*n))/(factorial_iterativo(n+1)*factorial_iterativo(n));
}

long long int catalan_recursivo(int n){
    if(n==0) return 1;
    else return ((2*((2*n)-1)) * catalan_recursivo(n-1))/(n+1);
}

void sucesionCatalan_iterativo(int n){
    int i;
    for (i=0; i<=n; i++){
        printf("%lld ", catalan_iterativo(i));
    }
}

void sucesionCatalan_recursivo(int n){
    int i;
    for (i=0; i<=n; i++){
        printf("%lld ", catalan_recursivo(i));
    }
}

int main() {
    // Procesador: Intel Core i5
    // Memoria RAM: 8GB

    // De forma iterativa solo se pudieron procesar los primeros 6 términos
    // La fórmula produce demasiadas productos para calcular los factoriales,
    // así que la memoria no tiene la capacidad para almacenar valores demasiados
    // grandes
    printf("%lld ", factorial_iterativo(12));
    printf("\n");
    sucesionCatalan_iterativo(6);
    printf("\n");
    // De forma recursiva solo se pudieron procesar los primeros 33 términos
    // La fórmula no calcula factoriales por lo tanto es posible procesar
    // valores bastantes grandes de n
    sucesionCatalan_recursivo(33);
    return 0;
}
