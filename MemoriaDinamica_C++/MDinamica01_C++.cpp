#include <iostream>
using namespace std;

// Asignando memoria dinámica a una sola variable en C++

int main() {
    int * p = nullptr; // Inicializar p
    // Si no se pone nothrow se lanza excepción de tipo
    // std::bad_alloc
    //p = new int; // Asignar memoria
    p = new(nothrow) int; // Asignar memoria usando (nothrow)
    if(p == nullptr) exit(1);
    *p = 7;
    cout << endl;
    cout << "Valor(p)=" << *p << endl;
    cout << "Dir(p)="<< p;
    delete p; // Desasignar memoria

    return 0;
}
