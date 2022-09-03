#include <stdio.h>
#include "complejo.h"

int main() {
    // Creamos las variables de tipo Complejo
    Complejo z1 = init(3.4, 2.1);
    Complejo z2 = init(-2.7, 4.6);
    Complejo z3 = init(0.0, 0.0);
    // Realizamos las operaciones con complejos
    Complejo r1 = suma(z1, z2);
    Complejo r2 = resta(z1, z2);
    Complejo r3 = multiplicacion(z1, z2);
    Complejo r4 = division(z3, z3);
    // Imprimimos los resultados
    print(r1);
    print(r2);
    print(r3);
    print(r4);

    // Desasignamos memoria para las variables usadas
    destroy(z1);
    destroy(z2);
    destroy(z3);
    destroy(r1);
    destroy(r2);
    destroy(r3);
    destroy(r4);

    return 0;
}
