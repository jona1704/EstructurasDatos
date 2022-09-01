//
// Created by Jonathan Córdoba on 01/09/22.
//

#include "complejos.h"
#include <stdio.h>

Complejo init(double d1, double d2){
    Complejo z;
    z.real = d1;
    z.img = d2;
    return z;
}

Complejo suma(Complejo c1, Complejo c2){
    Complejo z;
    z.real = (c1.real + c2.real);
    z.img = (c1.img + c2.img);
    return z;
}

Complejo resta(Complejo c1, Complejo c2){
    Complejo z;
    z.real = (c1.real - c2.real);
    z.img = (c1.img - c2.img);
    return z;
}

Complejo multiplicacion(Complejo c1, Complejo c2){
    Complejo z;
    z.real = (c1.real * c2.real) - (c1.img * c2.img);
    z.img = (c1.real * c2.img) + (c1.img * c2.real);
    return z;
}

Complejo division(Complejo c1, Complejo c2){
    Complejo z;
    double d = (c2.real * c2.real) + (c2.img * c2.img);
    z.real = (c1.real * c2.real) + (c1.img * c2.img)/d;
    z.img = (c1.img * c2.real) - (c1.real * c2.img)/d;
    return z;
}

void print(Complejo c){
    if(c.img < 0){
        printf("%.2lf - %.2lfi", c.real, (-1)*c.img);
    } else{
        printf("%.2lf - %.2lfi", c.real, c.img);
    }
}


