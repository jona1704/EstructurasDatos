#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Programa para generar números aleatorios:
// (1) Entre 0 y n
// (2) Entre 1 y n
// (3) Entre m y n

int imprimirAleatorio(int inferior, int superior){
    int num = rand() % (superior - inferior + 1) + inferior;
    return num;
}

int main() {
    //srand(7); // Inicializar con una constante siempre genera el mismo número aleatorio
    srand(time(NULL)); // Inicialización con generador que cambia
    int r = rand(); // Generar un entero pseudo-aletorio entre 0 y RAND_MAX
    printf("\nRAND_MAX: %d", RAND_MAX);
    printf("\nAleatorio: %d", r);
    printf("\nAleatorio entre 0 y 1000: %d", r%1000);
    printf("\nAleatorio entre 1 y 10: %d", (r%1000)+1);
    printf("\nAleatorio entre 250 y 600: %d", imprimirAleatorio(250, 600));
    printf("\n");

    return 0;
}
