#include <stdio.h>
#include <stdio.h>
#include "cola.h"

int main() {
    Cola c1= crearCola();
    c1 = encolar(c1, 20);
    c1 = encolar(c1, 56);
    c1 = encolar(c1, 72);
    c1 = encolar(c1, 86);
    c1 = encolar(c1, 98);
    c1 = encolar(c1, -12);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    c1 = desencolar(c1);
    desplegar(c1);

    return 0;
}
