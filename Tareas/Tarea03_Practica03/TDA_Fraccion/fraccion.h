//
// Created by Jonthan Cordoba on 16/09/22.
//

#ifndef FRACCION_H
#define FRACCION_H

// TDA Fracción

typedef struct fraccion{
    int numerador;
    int denominador;
} Fraccion;

Fraccion crearFraccion(int a, int b);
Fraccion suma(Fraccion, Fraccion);
Fraccion resta(Fraccion, Fraccion);
Fraccion multiplicacion(Fraccion, Fraccion);
Fraccion division(Fraccion, Fraccion);
void imprimir(Fraccion);

#endif // FRACCION_H
