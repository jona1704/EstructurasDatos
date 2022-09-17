#include <stdio.h>
#include "set.h"

// TDA Set

int main() {
    Set * s1 = crearSet();
    s1 = addSet(s1, 2);
    s1 = addSet(s1, 7);
    s1 = addSet(s1, 5);
    printSet(s1);
    printf("Size(s1)=%d\n", size(s1));
    // Comprobando que no se acepten valores repetidos
    s1 = addSet(s1, 7);
    s1 = addSet(s1, 2);
    // Si los valores están repetidos no se insertan en el Conjunto
    printSet(s1);
    printf("Size(s1)=%d\n", size(s1));
    // Insertando otros valores
    s1 = addSet(s1, 8);
    s1 = addSet(s1, -2);
    printSet(s1);
    printf("Size(s1)=%d\n", size(s1));
    // Removiendo valores del Conjunto
    s1 = removeSet(s1, 7);
    s1 = removeSet(s1, -2);
    printSet(s1);
    printf("Size(s1)=%d\n", size(s1));
    // Tratando de remover valores que no están en el Conjunto
    s1 = removeSet(s1, 12);
    s1 = removeSet(s1, 1);
    printSet(s1);
    printf("Size(s1)=%d\n", size(s1));
    // Ordenando valores
    s1 = sort(s1);
    printSet(s1);
    printf("Size(s1)=%d\n", size(s1));
    // Ingresando valores
    s1 = addSet(s1, 3);
    s1 = addSet(s1, 4);
    s1 = addSet(s1, -1);
    printSet(s1);
    printf("Size(s1)=%d\n", size(s1));
    // Ordenando valores
    s1 = sort(s1);
    printSet(s1);
    printf("Size(s1)=%d\n", size(s1));

    destruirSet(s1);

    return 0;
}
