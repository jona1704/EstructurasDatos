#include <stdio.h>

// Relaciones de Recurrencia

/*
 * F es una función definida de la siguiente manera
 *
 * F(1) = 1
 * F(n) = F(n-1) + 5, n>=1
 *
 *
 * Entonces:
 *
 * 1, 6, 11, 16, 21, ....
 *
 * F(2) converge a 6
 * F(3) converge a 11
 */

int F(int n){
    if(n==1) return 1; // Caso base
    else return F(n-1) + 5; // Caso recursivo
}

/*
 * Otra formula:
 *
 * T(𝑛) = 2𝑇 ( 𝑛 / 2 ) + n, 𝑇(1) = 1
 *
 *
 * 1, 4, ...
 *
 * */

int T(int n){
    if(n==1) return 1;
    else return 2*T(n/2) + n;
}

/*
 *  Función Factorial
 *
 *  f(n) = n*(n-1)!
 *  si n=1 o n=0 entonces return 1
 *
 *  7! = 7*6!
 *  6! = 6*5!
 *  .....
 *  1! = 1*0!
 *  0! = 1
 *
 */

long long int factorial(int n){
    if(n==0) return 1;
    else return n * factorial(n-1);
}

/*
 *
 * Sucesión de Fibonacci
 *
 *          1,1,2,3,5,8,13,21, .....
 * n        0,1,2,3,4,5,6,7, ....
 *
 * Caso base: n=0 retornar 1
 *            n=1 retornar 1
 *
 * Caso recursivo:  Fib(n) = F(n-2) + Fib(n-1)
 *
 *
 * Ejemplo:
 *
 *  Fib(2) = Fib(0) + Fib(1)
 */

int fibonacci(int n){
    if(n==0 || n==1) return 1;
    else return fibonacci(n-2) + fibonacci(n-1);
}


int main() {
    // Obteniendo un término de F
    printf("\nF(2)=%d", F(2));
    // Retornando toda la serie
    int i;
    printf("\nF = ");
    for(i=1; i<=10; i++){
        printf("%d ", F(i));
    }
    // Obteniendo la función T
    printf("\nT = ");
    for(i=1; i<=10; i++){
        printf("%d ", T(i));
    }
    printf("\n");
    // En el caso de mi computadora
    // Calcula correcto hasta el factorial de 20
    printf("20! = %lld", factorial(20));
    // Cálculo de la serie de Fibonacci
    printf("\nFibonacci = ");
    for(i=0; i<10; i++){
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
