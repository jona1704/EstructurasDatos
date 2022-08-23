#include <stdio.h>
#include <string.h>

struct agenda{
    int id;
    char nombre[50];
    char apellido[50];
    char telefono[12];
};

void capturar(struct agenda * datos, int n){
    int i=0;
    printf("\n");
    // Capturando información
    for(i=0; i<n; i++){
        printf("\nIngrese ID: ");
        scanf("%d", &datos[i].id);
        printf("\nIngrese Nombre: ");
        scanf("%s", datos[i].nombre);
        printf("\nIngrese Apellido: ");
        scanf("%s", datos[i].apellido);
        printf("\nIngrese Telefono: ");
        scanf("%s", datos[i].telefono);
    }
}

void desplegar(struct agenda * datos, int n){
    // Desplegar la información
    printf("\n");
    int i;
    for(i=0; i<n; i++){
        printf("\n\nID: %d", datos[i].id);
        printf("\nNombre: %s", datos[i].nombre);
        printf("\nApellido: %s", datos[i].apellido);
        printf("\nTelefono: %s", datos[i].telefono);
    }
}

int main() {
    struct agenda a1, a2; // Variables de tipo struct agenda
    // Acceder a los miembros
    a1.id = 1;
    strcpy(a1.nombre, "Jonathan");
    strcpy(a1.apellido, "Cordoba");
    strcpy(a1.telefono, "5512345678");
    printf("\nID: %d", a1.id);
    printf("\nNombre: %s", a1.nombre);
    printf("\nApellido: %s", a1.apellido);
    printf("\nTelefono: %s", a1.telefono);
    // Calculando el tamaño en bytes
    printf("\n\nTamaño en bytes: %d bytes", sizeof(a1));
    // Usando apuntadores
    struct agenda * a3 = NULL;
    a3 = &a2;
    a3->id = 2;
    strcpy(a3->nombre, "Pedro");
    strcpy(a3->apellido, "Martinez");
    strcpy(a3->telefono, "55234567890");
    printf("\n\nID: %d", a3->id);
    printf("\nNombre: %s", a3->nombre);
    printf("\nApellido: %s", a3->apellido);
    printf("\nTelefono: %s", a3->telefono);
    // Usando arreglos
    struct agenda a4[2];
    capturar(a4, 2);
    desplegar(a4, 2);

    return 0;
}
