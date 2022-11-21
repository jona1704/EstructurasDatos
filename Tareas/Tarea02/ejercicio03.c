#include <stdio.h>

long long int factorial_iterativo(int n){
    int fact = 1, i;
    for(i=1; i<=n; i++){
        fact = fact * i;
    }
    return fact;
}

long long int binomial_recursivo(int n, int k){
    if((k==0) || (k==n)) return 1;
    return binomial_recursivo(n-1, k-1) + binomial_recursivo(n-1, k);
}

void triangulo_pascal(int n){
    int i, j;
    for(i=0; i<=n; i++){
        for(j=0; j<=i; j++){
            printf(" %3lld", binomial_recursivo(i, j));
        }
        printf("\n");
    }
}

void triangulo_pascal_02(int n){
    int i, j;
    for(i=0; i<=n; i++){
        for(j = 0; j <= n-i; j++)
            printf("  ");
        for(j=0; j<=i; j++){
            printf(" %3lld", binomial_recursivo(i, j));
        }
        printf("\n");
    }
}


int main() {
    triangulo_pascal(7);
    printf("\n");
    triangulo_pascal_02(7);
    return 0;
}
