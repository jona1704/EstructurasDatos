#include <stdio.h>

long long int factorial_iterativo(int n){
    int fact = 1, i;
    for(i=1; i<=n; i++){
        fact = fact * i;
    }
    return fact;
}

long long int binomial_iterativo(int n, int k){
    return (int)(factorial_iterativo(n))/(factorial_iterativo(n-k)*factorial_iterativo(k));
}

long long int binomial_recursivo(int n, int k){
    if((k==0) || (k==n)) return 1;
    return binomial_recursivo(n-1, k-1) + binomial_recursivo(n-1, k);
}


int main() {
    int n=4, k=2;
    printf("(4 2) = %lld\n", binomial_iterativo(4, 2));
    printf("(4 2) = %lld\n", binomial_recursivo(4, 2));
    printf("\n");
    return 0;
}
