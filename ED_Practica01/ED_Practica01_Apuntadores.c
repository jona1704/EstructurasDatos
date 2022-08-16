#include <stdio.h>

int main() {

    int a = 7;
    int * x = &a;
    printf("Valor(a)=%d", a);
    printf("\nValor(a)=%d", *x);
    printf("\nDir(a)=%p", &a);
    printf("\nDir(a)=%p", x);
    printf("\nDir(x)=%p", &x);
    *x = 15;
    printf("\nDespués de cambiar el apuntador: ");
    printf("\nValor(a)=%d", a);

    return 0;
}
