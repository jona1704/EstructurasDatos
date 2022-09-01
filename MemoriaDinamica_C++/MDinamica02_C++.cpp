#include <iostream>
using namespace std;

// Asignando memoria dinámica para un arreglo de n datos en C++

int main() {
    int * p = nullptr; // Inicializar p
    int n = 10;
    p = new(nothrow) int[n]; // Asignar memoria para un arreglo de n elementos
    if(p == nullptr) exit(1);
    for(int i=0; i<n; i++){
        cout << "Valor(p[" << i <<"])=" << p[i] << " - Dir(p[" << i << "])= " << &p[i] << endl;
    }
    delete[] p; // Desasignar memoria

    return 0;
}

