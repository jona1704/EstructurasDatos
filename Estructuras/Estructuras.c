#include <stdio.h>
#include <stdlib.h>

// Declaramos una estructura que nos ayude a almacenar puntos en 2D
struct punto{
    int x;
    int y;
};

int main() {
    // Declaración de una variable de tipo struct punto
    struct punto sp01;
    // Accediendo a los miembros del struct usando sp01
    sp01.x = 3;
    sp01.y = 7;
    // Imprimiendo contenido de sp01
    printf("P1 = (%d, %d)\n", sp01.x, sp01.y);

    // Declaración de una variable usando un apuntador a struct punto
    // Para una variable de tipo apuntador necesitamos tomar memoria
    struct punto * sp02 = (struct punto *) malloc(sizeof(struct punto));
    if(sp02 == NULL) exit(1);
    // Accediendo a los miembros del struct usando sp02
    sp02->x = 3;
    sp02->y = 9;
    // Imprimiendo contenido de sp02
    printf("P2 = (%d, %d)\n", sp02->x, sp02->y);
    // Debemos liberar la memoria que tomamos al inicio
    free(sp02);

    return 0;
}
