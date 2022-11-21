#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pila.h"

bool balanceados(Pila p, char cadena[]){
    int i;
    int length = strlen(cadena);
    for(i=0; i<length; i++){
        char valor_actual = cadena[i];
        // Checar si el paréntesis es '(', '[' ó '{'
        if(valor_actual == '(' || valor_actual == '[' || valor_actual == '{'){
            // Meter a la pila
            push(p, valor_actual);
            continue;
        }
        // Si la pila esta vacía
        if(esVacia(p)){
            return false;
        }
        // Usamos switch para sacar elementos de la pila
        // y si el caracter es '(', '[' ó '{', retornamos false
        char elementoSacado;
        switch (valor_actual) {
            case ')':
                elementoSacado = pop(p);
                printf("\npop=%c", elementoSacado);
                if(elementoSacado == '{' || elementoSacado == '[')
                    return false;
                break;
            case '}':
                elementoSacado = pop(p);
                if(elementoSacado == '(' || elementoSacado == '[')
                    return false;
                break;
            case ']':
                elementoSacado = pop(p);
                if(elementoSacado == '(' || elementoSacado == '{')
                    return false;
                break;
        }
    }

    return esVacia(p);
}

int main() {
    Pila p = crearPila();
    char expresion[] = "[4-2{4-8}+2]";
    if(balanceados(p, expresion)){
        printf("\nParentesis Balanceados");
    } else{
        printf("\nParentesis No Balanceados");
    }

    destroy(p);

    return 0;
}
