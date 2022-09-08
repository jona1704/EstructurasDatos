#include <stdio.h>

// La enumeración o enum en C es un tipo especial de tipo de datos
// definido por el usuario. Consiste de números enteros a los que un
// usuario les da nombres. El uso de enum en C para nombrar los valores
// enteros hace que el programa sea fácil de aprender,
//  comprender y mantener por el mismo o incluso por otro programador.

enum dias{Domingo=1, Lunes, Miercoles, Jueves, Viernes, Sabado};
enum direcciones{Norte=1, Este, Oeste, Sur};

int main() {
    // Imprimiendo los valores de los días de la Semana
    for(int i=Domingo;i<=Sabado;i++){
        printf("%d, ", i);
    }
    // Usando enum con switch-case
    enum direcciones d;
    d = Sur;
    switch (d) {
        case Norte:
            printf("\nVoltea hacia el Norte ...");
            break;
        case Este:
            printf("\nVoltea hacia el Este ...");
            break;
        case Oeste:
            printf("\nVoltea hacia el Oeste ...");
            break;
        case Sur:
            printf("\nVoltea hacia el Sur ...");
            break;
    }

    return 0;
}
