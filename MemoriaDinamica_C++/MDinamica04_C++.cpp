#include <iostream>
using namespace std;

// Asignando memoria dinámica para un arreglo 3D de l*m*n datos en C++

int main() {
    int *** p = nullptr; // Inicializar p
    int paginas = 2; // l = páginas
    int filas = 3; // m = filas
    int cols = 3; // n = columnas
    // Asignar memoria para un arreglo de l dobles apuntadores
    p = new(nothrow) int**[paginas];
    if(p == nullptr) exit(1);
    for(int i=0; i<paginas; i++){
        // Cada doble apuntador en el arreglo de l dobles apuntadores
        // debe apuntar a un arreglo de m apuntadores
        // Asignamos memoria para un arreglo de m apuntadores
        p[i] = new(nothrow) int*[filas];
        if(p[i] == nullptr) exit(1);
        for(int j=0; j<filas; j++){
            // Cada apuntador en el arreglo de m apuntadores
            // debe apuntar a un arreglo de n elementos
            // Asignamos memoria para un arreglo de n elementos
            p[i][j] = new(nothrow) int[cols];
            if(p[i][j] == nullptr) exit(1);
        }
    }
    // Llenando Array
    for(int i=0; i<paginas; i++){
        for(int j=0; j<filas; j++){
            for(int k=0; k<cols; k++)
            p[i][j][k] = i+j+k;
        }
    }
    // Imprimiendo Array
    for(int i=0; i<paginas; i++){
        for(int j=0; j<filas; j++){
            for(int k=0; k<cols; k++) {
                cout << "Valor(p[" << i << "][" << j << "][" << k << "])=" << p[i][j][k] << " - Dir(p[" << i << "][" << j << "][" << k << "])= " << &p[i][j][k] << endl;
            }
        }
    }
    // Desasignar memoria para los arreglos de n elementos
    for(int i=0; i<paginas; i++){
        for(int j=0; j<filas; j++){
            delete[] p[i][j];
        }
        // Desasignar memoria para los arreglos de m apuntadores
        delete[] p[i];
    }
    // Desasignar memoria para el arreglo de l dobles apuntadores
    delete[] p;

    return 0;
}

