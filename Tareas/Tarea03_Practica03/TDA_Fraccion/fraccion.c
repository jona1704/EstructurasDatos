//
// Created by Jonthan Cordoba on 16/09/22.
//

#include "fraccion.h"
#include <stdio.h>

// TDA Fracción

static int min(a, b){
    int resultado;
    if(a<b) resultado = a;
    else resultado = b;
    return resultado;
}
static int MCD(int a, int b){
    // Si hay numeros negativos les cambiamos el signo
    a = (a>0)?a:-a;
    b = (b>0)?b:-b;
    // Calculamos el MCD
    while (a != b){
        if(a>b) a -= b;
        else b -= a;
    }
    return a;
}

Fraccion crearFraccion(int a, int b){
    Fraccion f;
    f.numerador = a;
    f.denominador = b;
    return f;
}

Fraccion suma(Fraccion f1, Fraccion f2){
    Fraccion suma;
    int num, den, MCD_;
    num = (f1.numerador * f2.denominador) + (f1.denominador * f2.numerador);
    den = f1.denominador * f2.denominador;
    MCD_ = MCD(num, den);
    suma.numerador = num/MCD_;
    suma.denominador = den/MCD_;
    return suma;
}

Fraccion resta(Fraccion f1, Fraccion f2){
    Fraccion resta;
    int num, den, MCD_;
    num = (f1.numerador * f2.denominador) - (f1.denominador * f2.numerador);
    den = f1.denominador * f2.denominador;
    MCD_ = MCD(num, den);
    resta.numerador = num/MCD_;
    resta.denominador = den/MCD_;
    return resta;
}

Fraccion multiplicacion(Fraccion f1, Fraccion f2){
    Fraccion multiplicacion;
    int num, den, MCD_;
    num = f1.numerador * f2.numerador;
    den = f1.denominador * f2.denominador;
    MCD_ = MCD(num, den);
    multiplicacion.numerador = num/MCD_;
    multiplicacion.denominador = den/MCD_;
    return multiplicacion;
}

Fraccion division(Fraccion f1, Fraccion f2){
    Fraccion division;
    int num, den, MCD_;
    num = f1.numerador * f2.denominador;
    den = f1.denominador * f2.numerador;
    MCD_ = MCD(num, den);
    division.numerador = num/MCD_;
    division.denominador = den/MCD_;
    return division;
}

void imprimir(Fraccion f){
    if(f.denominador == 1){
        printf("%d\n", f.numerador);
    } else{
        printf("%d/%d\n", f.numerador, f.denominador);
    }

}