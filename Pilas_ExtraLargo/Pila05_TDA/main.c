#include "pila.h"

int main() {
    // Inicializar Pila
    Pila p1 = init();
    // Insertar datos
    push(p1, 6);
    push(p1, 7);
    push(p1, 8);
    push(p1, 9);
    push(p1, 10);
    push(p1, 11);
    desplegar(p1);
    pop(p1);
    pop(p1);
    pop(p1);
    desplegar(p1);

    limpiarPila(p1);

    return 0;
}
