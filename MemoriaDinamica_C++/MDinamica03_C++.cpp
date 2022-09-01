#include <iostream>
using namespace std;

// Asignando memoria dinámica para un arreglo 2D de m*n datos en C++

int main() {
    int ** p = nullptr; // Inicializar p
    int filas = 3; // m = filas
    int cols = 3; // n = columnas
    // Asignar memoria para un arreglo de m apuntadores
    p = new(nothrow) int*[filas];
    if(p == nullptr) exit(1);
    for(int i=0; i<filas; i++){
        // Cada apuntador en el arreglo de m apuntadores
        // debe apuntar a un arreglo de n elementos
        // Asignamos memoria para un arreglo de n elementos
        p[i] = new(nothrow) int[cols];
        if(p[i] == nullptr) exit(1);
    }
    // Llenando Array
    for(int i=0; i<filas; i++){
        for(int j=0; j<cols; j++){
            p[i][j] = i+j;
        }
    }
    // Imprimiendo Array
    for(int i=0; i<filas; i++){
        for(int j=0; j<cols; j++){
            cout << "Valor(p[" << i << "][" << j << "])=" << p[i][j] << " - Dir(p[" << i << "][" << j << "])= " << &p[i][j] << endl;
        }
    }
    // Desasignar memoria para los arreglos de n elementos
    for(int i=0; i<filas; i++){
        delete[] p[i];
    }
    // Desasignar memoria para el arreglo de m apuntadores
    delete[] p;

    return 0;
}

