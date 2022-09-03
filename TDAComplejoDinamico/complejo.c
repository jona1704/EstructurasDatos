//
// Created by Jonathan Córdoba on 02/09/22.
//

#include "complejo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct complejos{
    double real;
    double img;
};

Complejo init(double d1, double d2){
    Complejo z = malloc(sizeof(Complejo));
    if(z == NULL) exit(1);
    z->real = d1;
    z->img = d2;
    return z;
}

Complejo suma(Complejo c1, Complejo c2){
    Complejo z = init(0.0, 0.0);
    z->real = (c1->real + c2->real);
    z->img = (c1->img + c2->img);
    return z;
}

Complejo resta(Complejo c1, Complejo c2){
    Complejo z = init(0.0, 0.0);
    z->real = (c1->real - c2->real);
    z->img = (c1->img - c2->img);
    return z;
}

Complejo multiplicacion(Complejo c1, Complejo c2){
    Complejo z = init(0.0, 0.0);
    z->real = (c1->real * c2->real) - (c1->img * c2->img);
    z->img = (c1->real * c2->img) + (c1->img * c2->real);
    return z;
}

Complejo division(Complejo c1, Complejo c2){
    Complejo z = init(0.0, 0.0);
    double d = (c2->real * c2->real) + (c2->img * c2->img);
    if(d == 0){
        z->real = z->img = INFINITY;
    } else{
        z->real = ((c1->real * c2->real) + (c1->img * c2->img))/d;
        z->img = ((c1->img * c2->real) - (c1->real * c2->img))/d;
    }

    return z;
}

void print(Complejo c){
    if((c->real == INFINITY) || (c->img == INFINITY)){
        printf("Division entre cero ...");
    }  else{
        if((c->real == 0.0) && (c->img == 0.0)){
            printf("%.2lf + %.2lfi", c->real, c->img);
        } else if(c->real == 0.0){
            printf("%.2lfi", c->img);
        } else if(c->img == 0.0){
            printf("%.2lf", c->real);
        } else if(c->img < 0){
            printf("%.2lf - %.2lfi", c->real,(-1)* c->img);
        } else{
            printf("%.2lf - %.2lfi", c->real, c->img);
        }
    }

    printf("\n");
}

void destroy(Complejo c){
    free(c);
}