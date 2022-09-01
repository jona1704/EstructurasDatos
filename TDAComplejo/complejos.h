//
// Created by Jonathan Córdoba on 01/09/22.
//

#ifndef COMPLEJOS_H
#define COMPLEJOS_H

typedef struct complejos{
    double real;
    double img;
} Complejo;

Complejo init(double, double);
Complejo suma(Complejo, Complejo);
Complejo resta(Complejo, Complejo);
Complejo multiplicacion(Complejo, Complejo);
Complejo division(Complejo, Complejo);
void print(Complejo c);

#endif

