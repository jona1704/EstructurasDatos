#include <stdio.h>
#include <stdlib.h>
#include "complejos.h"

int main(int argc, char *argv[]) {
    Complejo z1 = init(3.4, 2.1);
    Complejo z2 = init(-2.7, 4.6);
    Complejo s = suma(z1, z2);
    print(s);

    return 0;
}

