#include <stdio.h>

int paso_valor(int a){
    a = a * 8;
    return a;
}

int * paso_valor2(int * a){
    *a = *a * 8;
    return a;
}

void paso_referencia(int * a){
    *a = *a * 8;
}

void paso_referencia2(int ** a){
    **a = **a * 8;
}

int main() {
    int x = 7;
    int * y = &x;
    int ** z = &y;
    x = paso_valor(x);
    printf("x=%d", x); // 7*8=56
    paso_referencia(&x);
    printf("\nx=%d", x); // 56*8=448
    y = paso_valor2(y);
    printf("\nx=%d", x); // 448*8=3584
    printf("\n*y=%d", *y); // 448*8=3584
    paso_referencia2(&y);
    printf("\nx=%d", x); // 448*8=28672
    printf("\n*y=%d", *y); // 448*8=28672

    return 0;
}
