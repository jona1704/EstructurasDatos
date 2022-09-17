#include <stdio.h>
#include "fraccion.h"

// TDA Fracción

int main() {
    Fraccion f1 = crearFraccion(1,2); // f1 = 1/2
    Fraccion f2 = crearFraccion(3,4); // f2 = 3/4
    Fraccion suma_f = suma(f1, f2);
    Fraccion resta_f = resta(f1, f2);
    Fraccion multiplicacion_f = multiplicacion(f1, f2);
    Fraccion division_f = division(f1, f2);
    // Imprimiendo las operaciones
    printf("f1: ");
    imprimir(f1);
    printf("f2: ");
    imprimir(f2);
    printf("f1 + f2 = ");
    imprimir(suma_f);
    printf("f1 - f2 = ");
    imprimir(resta_f);
    printf("f1 * f2 = ");
    imprimir(multiplicacion_f);
    printf("f1 / f2 = ");
    imprimir(division_f);

    return 0;
}
