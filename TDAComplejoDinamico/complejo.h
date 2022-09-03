//
// Created by Jonthan Cordoba on 02/09/22.
//

#ifndef COMPLEJO_H
#define COMPLEJO_H

typedef struct complejos * Complejo;

Complejo init(double, double);
Complejo suma(Complejo, Complejo);
Complejo resta(Complejo, Complejo);
Complejo multiplicacion(Complejo, Complejo);
Complejo division(Complejo, Complejo);
void print(Complejo c);
void destroy(Complejo c);



#endif // COMPLEJO_H
