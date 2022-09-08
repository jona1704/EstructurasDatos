#include <stdio.h>
#define n 3

// Declaramos una estructura que nos ayude a almacenar puntos en 2D
struct punto{
    int x;
    int y;
};

int main() {
    // Creamos un arreglo de n elementos de tipo struct punto
    struct punto arr01[n];
    // Creamos otro arreglo pero con valores iniciales
    struct punto arr02[n] = {{4,5}, {3,-2}, {4,6}};
    int i;
    // Capturando puntos para el arreglo arr01
    for(i=0; i<n; i++){
        printf("\nIngrese el punto 1: ");
        scanf("%d", &arr01[i].x);
        printf("Ingrese el punto 2: ");
        scanf("%d", &arr01[i].y);
    }
    // Imprimiendo puntos en el arreglo arr01
    for(i=0; i<n; i++){
        printf("P%d = (%d, %d)\n", i+1, arr01[i].x, arr01[i].y);
    }
    // Imprimiendo puntos en el arreglo arr02
    printf("\n");
    for(i=0; i<n; i++){
        printf("P%d = (%d, %d)\n", i+1, arr02[i].x, arr02[i].y);
    }
    
    return 0;
}
